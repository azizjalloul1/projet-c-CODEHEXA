#include "mainwindowv.h"
#include "ui_mainwindowv.h"
#include "vehicules.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QtCharts>
#include <QDialog>
#include <QVBoxLayout>
#include <random>
#include <QDateTime>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSerialPort>






MainWindowv::MainWindowv(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowv)
{
    ui->setupUi(this);
    currentSolutionIndex.clear();
    // Initialize chart container
    if (!ui->chartContainer->layout()) {
        ui->chartContainer->setLayout(new QVBoxLayout());
    }

    // Connect table updates to chart refresh
    connect(ui->tableWidget, &QTableWidget::itemChanged,
            this, &MainWindowv::showStatistics);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindowv::on_searchTextChanged);

    // Connect the "Next Solution" button (if using Qt Designer)

    connect(ui->symptomSearchLineEdit, &QLineEdit::textChanged,
            this, &MainWindowv::filterSymptoms);
    ui->symptomListWidget->setSelectionMode(QAbstractItemView::MultiSelection);

    loadSymptomsToList(); // instead of loadSymptoms()

    // Initial data load
    updateTableWidget();
    ui->tabafficheerreur->setColumnCount(4);  // 6 columns: Symptome, Composant, Cause, Solution1, Solution2, Solution3
    ui->tabafficheerreur->setHorizontalHeaderLabels({"Symptome", "Composant", "Cause", "Solution 1", "Solution 2", "Solution 3"});
    ui->tabafficheerreur->setColumnWidth(0, 150);  // Column 0 (Symptome) = 150px
    ui->tabafficheerreur->setColumnWidth(1, 120);  // Column 1 (Composant)
    ui->tabafficheerreur->setColumnWidth(2, 200);  // Column 2 (Cause)
    ui->tabafficheerreur->setColumnWidth(3, 250);  // Column 3 (Solution 1)

    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/MapView.qml")));
    ui->quickWidget->show();

    connect(ui->btnViewLatestGPS, &QPushButton::clicked, this, &MainWindowv::on_btnViewLatestGPS_clicked);

    // Initialize QQmlApplicationEngine after MainWindow is set up
    QQmlApplicationEngine engine;

    // Pass a pointer to this MainWindow instance
    engine.rootContext()->setContextProperty("mainWindow", this);

    // Load the QML file
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    serial = new QSerialPort(this);
    serial->setPortName("COM4"); // Change to your Arduino port
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {
        connect(serial, &QSerialPort::readyRead, this, &MainWindowv::readFromArduino);
        qDebug() << "Serial port connected.";
    } else {
        qDebug() << "⚠️ Failed to open serial port:" << serial->errorString();
    }

}


void MainWindowv::setAccueil(Accueil *accueilWindow) {
    this->accueil = accueilWindow;
}

void MainWindowv::readFromArduino() {
    QByteArray data = serial->readAll();
    static QString buffer = "";

    buffer += QString::fromUtf8(data);
    if (buffer.contains("\n")) {
        QStringList lines = buffer.split("\n");
        for (int i = 0; i < lines.size() - 1; ++i) {
            QString line = lines[i].trimmed();
            if (line.startsWith("CHECK:")) {
                QStringList parts = line.split(":");
                if (parts.size() == 3) {
                    QString matricule = parts[1].trimmed();
                    int maxVehicles = parts[2].toInt();

                    qDebug() << "🔍 Received code:" << matricule << " Max allowed:" << maxVehicles;

                    QSqlQuery query;
                    query.prepare("SELECT STATUT FROM VEHICULE WHERE MATRICULE = :mat");
                    query.bindValue(":mat", matricule);

                    if (query.exec() && query.next()) {
                        QString statut = query.value(0).toString();
                        if (statut == "En livraison") {
                            // Count vehicles with status = 'Disponible'
                            QSqlQuery countQuery;
                            countQuery.prepare("SELECT COUNT(*) FROM VEHICULE WHERE STATUT = 'Disponible'");
                            if (countQuery.exec() && countQuery.next()) {
                                int currentInside = countQuery.value(0).toInt();
                                qDebug() << "🚗 Inside:" << currentInside << " / Max:" << maxVehicles;

                                if (currentInside >= maxVehicles) {
                                    serial->write("FULL\n");
                                    qDebug() << "🚫 FULL";
                                    return;
                                }
                            }

                            serial->write("GRANTED\n");
                            qDebug() << "✅ GRANTED";

                            QSqlQuery updateQuery;
                            updateQuery.prepare("UPDATE VEHICULE SET STATUT = 'Disponible' WHERE MATRICULE = :mat");
                            updateQuery.bindValue(":mat", matricule);
                            updateQuery.exec();
                        } else {
                            qDebug() << "❌ Not eligible (STATUT C'est Deja  'En Parking')";
                            serial->write("DENIED\n");
                        }
                    } else {
                        qDebug() << "❌ Matricule not found";
                        serial->write("DENIED\n");
                    }
                }
            }
        }
        buffer = lines.last(); // preserve unfinished line
    }

    updateTableWidget(); // Optional GUI update
}




MainWindowv::~MainWindowv() {
    delete ui;
}

// Function to update QTableWidget
void MainWindowv::updateTableWidget() {
    ui->tableWidget->setRowCount(0);  // Clear existing data

    QSqlQuery query("SELECT * FROM Vehicule");
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        // Set items in the table and make them read-only
        QTableWidgetItem *itemMatricule = new QTableWidgetItem(query.value("matricule").toString());
        itemMatricule->setFlags(itemMatricule->flags() & ~Qt::ItemIsEditable);  // Disable editing
        ui->tableWidget->setItem(row, 0, itemMatricule);

        QTableWidgetItem *itemIdTransporteur = new QTableWidgetItem(query.value("Id_transporteur").toString());
        itemIdTransporteur->setFlags(itemIdTransporteur->flags() & ~Qt::ItemIsEditable);  // Disable editing
        ui->tableWidget->setItem(row, 1, itemIdTransporteur);

        QTableWidgetItem *itemMarque = new QTableWidgetItem(query.value("marque").toString());
        itemMarque->setFlags(itemMarque->flags() & ~Qt::ItemIsEditable);  // Disable editing
        ui->tableWidget->setItem(row, 2, itemMarque);

        QTableWidgetItem *itemType = new QTableWidgetItem(query.value("type").toString());
        itemType->setFlags(itemType->flags() & ~Qt::ItemIsEditable);  // Disable editing
        ui->tableWidget->setItem(row, 3, itemType);

        QTableWidgetItem *itemStatut = new QTableWidgetItem(query.value("statut").toString());
        itemStatut->setFlags(itemStatut->flags() & ~Qt::ItemIsEditable);  // Disable editing
        ui->tableWidget->setItem(row, 5, itemStatut);

        QTableWidgetItem *itemVolumeCoffre = new QTableWidgetItem(query.value("volume_coffre").toString());
        itemVolumeCoffre->setFlags(itemVolumeCoffre->flags() & ~Qt::ItemIsEditable);  // Disable editing
        ui->tableWidget->setItem(row, 4, itemVolumeCoffre);

        row++;
    }
}

// Add a new vehicle
void MainWindowv::on_addButton_clicked() {
    // Retrieve inputs
    QString matricule1 = ui->matricule1->text().trimmed();
    QString matricule2 = ui->matricule2->text().trimmed();
    QString marque = ui->marque->currentText();
    QString type = ui->type->currentText();
    QString statut = ui->statut->currentText();
    QString volumeCoffreStr = ui->vcoffre->text().trimmed();
    QString idTransporteurStr = ui->idtransporteur->text().trimmed();

    // Validation flags
    bool valid = true;
    QString errorMessage;

    // Validate Matricule (both parts must be numeric and non-empty)
    QRegularExpression regexNum("^[0-9]+$");
    if (!regexNum.match(matricule1).hasMatch() || !regexNum.match(matricule2).hasMatch()) {
        valid = false;
        errorMessage += "- Matricule must contain only numbers.\n";
    }

    // Validate Volume Coffre (should be a positive number)
    bool volumeOk;
    double volume_coffre = volumeCoffreStr.toDouble(&volumeOk);
    if (!volumeOk || volume_coffre <= 0) {
        valid = false;
        errorMessage += "- Volume du coffre must be a positive number.\n";
    }

    // Validate ID Transporteur (should be a positive integer)
    bool idOk;
    int Id_transporteur = idTransporteurStr.toInt(&idOk);
    if (!idOk || Id_transporteur <= 0) {
        valid = false;
        errorMessage += "- ID Transporteur must be a positive integer.\n";
    }

    // Validate ComboBoxes (Ensure an item other than the placeholder is selected)
    if (ui->marque->currentIndex() == 0) {
        valid = false;
        errorMessage += "- Please select a valid marque.\n";
    }
    if (ui->type->currentIndex() == 0) {
        valid = false;
        errorMessage += "- Please select a valid type.\n";
    }
    if (ui->statut->currentIndex() == 0) {
        valid = false;
        errorMessage += "- Please select a valid statut.\n";
    }

    // If validation fails, show error message
    if (!valid) {
        QMessageBox::warning(this, "Input Error", "Please correct the following errors:\n" + errorMessage);
        return;
    }

    // Check if the ID_TRANSPORTEUR exists in EMPLOYEE and has role TRANSPORTEUR
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYEE WHERE ID = :id AND ROLE = 'transporteur'");
    checkQuery.bindValue(":id", Id_transporteur);

    if (!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Error", "The given ID is not a valid TRANSPORTEUR.");
        return;
    }

    // Construct final matricule
    QString matricule = matricule1 + "TN" + matricule2;

    // Database Transaction
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    // Start transaction
    db.transaction();

    // Insert into VEHICULE
    query.prepare("INSERT INTO VEHICULE (MATRICULE, MARQUE, TYPE, STATUT, VOLUME_COFFRE, ID_TRANSPORTEUR) "
                  "VALUES (:matricule, :marque, :type, :statut, :volume_coffre, :id_transporteur)");
    query.bindValue(":matricule", matricule);
    query.bindValue(":marque", marque);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":volume_coffre", volume_coffre);
    query.bindValue(":id_transporteur", Id_transporteur);

    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Error", "Failed to add vehicle.");
        return;
    }

    // Insert into CONDUIRE (ID_TRANSPORTEUR as the driver)
    query.prepare("INSERT INTO CONDUIRE (ID, MATRICULE) VALUES (:id, :matricule)");
    query.bindValue(":id", Id_transporteur);
    query.bindValue(":matricule", matricule);

    if (!query.exec()) {
        db.rollback();
        QMessageBox::critical(this, "Error", "Failed to add vehicle to CONDUIRE.");
        return;
    }

    // Commit transaction
    db.commit();

    QMessageBox::information(this, "Success", "Vehicle and CONDUIRE record added successfully!");
    updateTableWidget();

    // ✅ Reset all input fields
    ui->matricule1->clear();
    ui->matricule2->clear();
    ui->marque->setCurrentIndex(0);
    ui->type->setCurrentIndex(0);
    ui->statut->setCurrentIndex(0);
    ui->vcoffre->clear();
    ui->idtransporteur->clear();
}




// Modify an existing vehicle
void MainWindowv::on_mod_button_clicked() {
    QString matricule = ui->matricule1_2->text().trimmed() + "TN" + ui->matricule2_2->text().trimmed();
    QString marque = ui->marque_2->currentText();
    QString type = ui->type_2->currentText();
    QString statut = ui->statut_2->currentText();
    double volume_coffre = ui->vcoffre_2->text().toDouble();
    int Id_transporteur = ui->idtransporteur_2->text().toInt();
    // Input validation
    if (ui->matricule1_2->text().isEmpty() || ui->matricule2_2->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Matricule fields cannot be empty.");
        return;
    }
    if (volume_coffre <= 0) {
        QMessageBox::warning(this, "Input Error", "Volume de coffre must be greater than 0.");
        return;
    }

   Vehicule v(matricule, marque, type, statut, volume_coffre, Id_transporteur);
    if (v.modifier(matricule)) {
        QMessageBox::information(this, "Success", "Vehicle updated successfully!");
        updateTableWidget();

        //  Reset all input fields
        ui->matricule1_2->clear();
        ui->matricule2_2->clear();
        ui->marque_2->setCurrentIndex(0);
        ui->type_2->setCurrentIndex(0);
        ui->statut_2->setCurrentIndex(0);
        ui->vcoffre_2->clear();
        ui->idtransporteur_2->clear(); // Reset Id_transporteur
    } else {
        QMessageBox::critical(this, "Error", "Failed to update vehicle.");
    }
}

// Load vehicle data into modification tab
void MainWindowv::on_matricule_valider_clicked() {
    QString matricule = ui->matricule1_2->text() + "TN" + ui->matricule2_2->text();
    // 🔍 Debug statement to check the generated matricule
    qDebug() << "Matricule being searched: " << matricule;

    QSqlQuery query;
    query.prepare("SELECT * FROM Vehicule WHERE matricule = :matricule");
    query.bindValue(":matricule", matricule);

    if (query.exec() && query.next()) {
        //  Fill the fields with database values
        ui->marque_2->setCurrentText(query.value("marque").toString());
        ui->type_2->setCurrentText(query.value("type").toString());
        ui->statut_2->setCurrentText(query.value("statut").toString());
        ui->vcoffre_2->setText(query.value("volume_coffre").toString());
        ui->idtransporteur_2->setText(query.value("Id_transporteur").toString()); // Load Id_transporteur

        QMessageBox::information(this, "Success", "Vehicle found! You can now modify.");
    } else {
        QMessageBox::warning(this, "Error", "Vehicle not found. Check the matricule.");
    }
}


// Delete a vehicle
void MainWindowv::on_Supp_Button_clicked() {
    QString matricule = ui->matricule->text().trimmed();

    // Debug: Check if matricule is being read correctly
    qDebug() << "Matricule to delete:" << matricule;

    if (matricule.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Matricule field cannot be empty.");
        return;
    }

    // Check if the matricule exists in the database
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Vehicule WHERE matricule = :matricule");
    checkQuery.bindValue(":matricule", matricule);

    if (!checkQuery.exec()) {
        // Log the database error
        qDebug() << "Database error during matricule check:" << checkQuery.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to check if the vehicle exists.");
        return;
    }

    checkQuery.next(); // Move to the first result
    int count = checkQuery.value(0).toInt();

    if (count == 0) { // If count is 0, matricule does not exist
        QMessageBox::warning(this, "Error", "The specified matricule does not exist.");
        return;
    }

    // Confirm deletion with the user
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Deletion",
                                  "Are you sure you want to delete the vehicle with matricule: " + matricule + "?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return; // User chose not to delete
    }

    // Proceed to delete the vehicle
    Vehicule v;
    if (v.supprimer(matricule)) {
        QMessageBox::information(this, "Success", "Vehicle deleted successfully!");
        updateTableWidget();  // Refresh the table

        // Reset all input fields
        ui->matricule->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete vehicle.");
        // Log the error for debugging
        qDebug() << "Error deleting vehicle with matricule:" << matricule;
    }
}
void MainWindowv::on_triButton_clicked() {
    QString order = sortAsc ? "ASC" : "DESC";
    sortAsc = !sortAsc; // Toggle the order for next click

    QSqlQuery query;
    query.prepare("SELECT * FROM VEHICULE ORDER BY MARQUE " + order);

    if (!query.exec()) {
        QMessageBox::warning(this, "Sort Error", "Failed to sort vehicles.");
        return;
    }

    ui->tableWidget->setRowCount(0); // Clear table
    int row = 0;

    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("MATRICULE").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("MARQUE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("STATUT").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("VOLUME_COFFRE").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("ID_TRANSPORTEUR").toString()));
        row++;
    }

    // Optional: update button text/icon
    ui->triButton->setText(sortAsc ? "Trier (Z-A)" : "Trier (A-Z)");
}
void MainWindowv::on_exportButton_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf")) fileName += ".pdf";

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300); // High resolution
    QPainter painter(&writer);

    if (!painter.isActive()) {
        QMessageBox::warning(this, "Erreur", "Impossible de créer le PDF");
        return;
    }

    // Font sizes from exportToPDF()
    const int titleSize = 24;
    const int headerSize = 13;
    const int contentSize = 12;
    const int footerSize = 10;

    // Margins from exportToPDF()
    const int margin = 70;
    int yPos = margin;

    // Colors (keeping your original scheme)
    QColor titleColor(Qt::black);
    QColor headerColor(Qt::darkBlue);
    QColor oddRowColor(240, 240, 240);
    QColor evenRowColor(Qt::white);

    // Draw title (using the large 24pt font)
    painter.setFont(QFont("Arial", titleSize, QFont::Bold));
    painter.setPen(titleColor);
    painter.drawText(writer.width() / 2 - 500, yPos, "LISTE DES VÉHICULES");
    yPos += 50;

    // Draw table headers (using 14pt font)
    painter.setFont(QFont("Arial", headerSize, QFont::Bold));
    painter.setPen(Qt::white);
    QRect headerRect(margin, yPos, writer.width() - 2 * margin, 50);
    painter.fillRect(headerRect, headerColor);

    QStringList headers = {"MATRICULE", "ID TRANSP.", "MARQUE", "TYPE", "VOLUME", "STATUT"};
    const int columnWidth = (writer.width() - 2 * margin) / headers.size();

    int headerPosX = margin;
    for (const QString& header : headers) {
        painter.drawText(headerPosX + (columnWidth - painter.fontMetrics().boundingRect(header).width()) / 2,
                         yPos + 50, header);
        headerPosX += columnWidth;
    }
    yPos += 70;

    // Draw content (using 12pt font)
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", contentSize));

    const int rowHeight = 60;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        // Alternate row colors
        if (row % 2 == 1) {
            painter.fillRect(QRect(margin, yPos, writer.width() - 2 * margin, rowHeight), oddRowColor);
        }

        int rowPosX = margin;
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item) {
                QString data = item->text();
                painter.drawText(rowPosX + (columnWidth - painter.fontMetrics().boundingRect(data).width()) / 2,
                                 yPos + 40, data);
            }
            rowPosX += columnWidth;
        }
        yPos += rowHeight;

        // Page break handling
        if (yPos > writer.height() - margin - rowHeight) {
            writer.newPage();
            yPos = margin;

            // Redraw headers on new page
            painter.setFont(QFont("Arial", headerSize, QFont::Bold));
            painter.setPen(Qt::white);
            QRect newHeaderRect(margin, yPos, writer.width() - 2 * margin, 50);
            painter.fillRect(newHeaderRect, headerColor);

            int newHeaderPosX = margin;
            for (const QString& header : headers) {
                painter.drawText(newHeaderPosX + (columnWidth - painter.fontMetrics().boundingRect(header).width()) / 2,
                                 yPos + 35, header);
                newHeaderPosX += columnWidth;
            }
            yPos += 48;

            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", contentSize));
        }
    }

    // Footer with generation date (using 10pt font)
    yPos += 50;
    QString dateTime = "Généré le: " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    painter.setFont(QFont("Arial", footerSize, QFont::StyleItalic));
    painter.drawText(margin, yPos, dateTime);

    painter.end();
    QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
}
void MainWindowv::showStatistics() {
    // Clear previous chart if exists - SAFE deletion
    if (ui->chartContainer->layout()) {
        QLayoutItem* child;
        while ((child = ui->chartContainer->layout()->takeAt(0))) {  // Fixed parenthesis
            if (child->widget()) {
                child->widget()->setParent(nullptr);
                delete child->widget();
            }
            delete child;
        }
    } else {
        // Initialize layout if it doesn't exist
        ui->chartContainer->setLayout(new QVBoxLayout());
    }

    // 1. Count vehicles by status - PROPERLY DECLARED
    QMap<QString, int> statusCount;  // Explicit declaration

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem* statusItem = ui->tableWidget->item(row, 5); // STATUT column
        if (statusItem && !statusItem->text().isEmpty()) {
            QString status = statusItem->text();
            statusCount[status]++;  // Now properly using declared map
        }
    }

    // Only proceed if we have data
    if (statusCount.isEmpty()) {
        qDebug() << "No data available for chart";
        return;
    }

    // 2. Create pie series
    QPieSeries* series = new QPieSeries();
    const QList<QColor> colors = {QColor("#4285F4"), QColor("#EA4335"),
                                  QColor("#FBBC05"), QColor("#34A853")};

    int colorIndex = 0;
    for (auto it = statusCount.constBegin(); it != statusCount.constEnd(); ++it) {
        QPieSlice* slice = series->append(it.key(), it.value());
        slice->setBrush(colors[colorIndex % colors.size()]);
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1\n%2 vehicles").arg(it.key()).arg(it.value()));
        colorIndex++;
    }

    // 3. Configure chart
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Vehicle Status Distribution");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    // 4. Create chart view
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400, 200);

    // 5. Add to container
    ui->chartContainer->layout()->addWidget(chartView);
}
void MainWindowv::on_searchTextChanged(const QString &searchTerm) {
    QString input = searchTerm.trimmed();
    bool hasTN = input.contains("TN", Qt::CaseInsensitive);

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QString matricule = ui->tableWidget->item(row, 0)->text(); // e.g. 120TN212

        QString number1 = matricule.section("TN", 0, 0).trimmed(); // part before TN
        QString number2 = matricule.section("TN", 1, 1).trimmed(); // part after TN

        bool match = false;

        if (hasTN) {
            QString input1 = input.section("TN", 0, 0).trimmed(); // before TN
            QString input2 = input.section("TN", 1, 1).trimmed(); // after TN

            // 💡 Exact match on number1 only if TN is in search!
            bool match1 = (number1 == input1);
            bool match2 = number2.startsWith(input2, Qt::CaseInsensitive) || input2.isEmpty();

            match = match1 && match2;
        } else {
            // No TN → search number1 normally
            match = number1.startsWith(input, Qt::CaseInsensitive);
        }

        ui->tableWidget->setRowHidden(row, !match);
    }
}
void MainWindowv::loadSymptomsToList() {
    QFile file("pannes.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "❌ Could not open pannes.txt!";
        return;
    }

    QTextStream in(&file);
    QSet<QString> uniqueSymptoms;
    bool skipHeader = true;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (skipHeader) {
            skipHeader = false;
            continue;
        }

        QStringList parts = line.split(';');
        if (parts.size() >= 1) {
            uniqueSymptoms.insert(parts[0].trimmed());
        }
    }

    file.close();

    allSymptoms = QStringList(uniqueSymptoms.begin(), uniqueSymptoms.end());
    ui->symptomListWidget->addItems(allSymptoms);

    // Enable multi-selection
    ui->symptomListWidget->setSelectionMode(QAbstractItemView::MultiSelection);

    // Connect list click to updateErrorTable for multiple selections
    connect(ui->symptomListWidget, &QListWidget::itemSelectionChanged, this, &MainWindowv::updateErrorTable);

}

void MainWindowv::filterSymptoms(const QString &text) {
    ui->symptomListWidget->clear();
    for (const QString &symptom : allSymptoms) {
        if (symptom.contains(text, Qt::CaseInsensitive)) {
            ui->symptomListWidget->addItem(symptom);
        }
    }
}


void MainWindowv::updateErrorTable() {
    // Clear the table first to avoid appending data on previous ones
    ui->tabafficheerreur->clearContents();
    ui->tabafficheerreur->setRowCount(0);

    // Get selected symptoms
    QStringList selectedSymptoms;
    QList<QListWidgetItem*> selectedItems = ui->symptomListWidget->selectedItems();
    for (QListWidgetItem* item : selectedItems) {
        selectedSymptoms << item->text();
    }


    // Debugging the selected symptoms
    qDebug() << "Selected Symptoms: " << selectedSymptoms;

    if (selectedSymptoms.isEmpty()) {
        qDebug() << "No symptoms selected!";
        return;
    }

    // Open the file to filter symptoms based on the selection
    QFile file("pannes.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "❌ Failed to open pannes.txt!";
        return;
    }

    QTextStream in(&file);
    bool skipHeader = true;
    int row = 0;

    // Process the file
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (skipHeader) {
            skipHeader = false;
            continue;
        }

        QStringList parts = line.split(';');
        if (parts.size() < 7) continue;

        QString symptom = parts[0].trimmed();

        // Debugging to see what's happening inside the loop
        qDebug() << "Reading line: " << line;
        qDebug() << "Current symptom: " << symptom;

        // If the symptom is in the selected list, add it to the table
        if (selectedSymptoms.contains(symptom)) {
            qDebug() << "Matching symptom found: " << symptom;
            ui->tabafficheerreur->insertRow(row);
            for (int col = 0; col < 4; ++col) {
                ui->tabafficheerreur->setItem(row, col, new QTableWidgetItem(parts[col].trimmed()));
            }

            QTableWidgetItem *solItem = new QTableWidgetItem(parts[3].trimmed());
            solItem->setData(Qt::UserRole, QList<QString>{parts[3].trimmed(), parts[4].trimmed(), parts[5].trimmed()});
            solItem->setData(Qt::UserRole + 1, parts[6].toInt());
            ui->tabafficheerreur->setItem(row, 3, solItem);

            currentSolutionIndex[row] = 0;
            row++;
        }
    }

    file.close();
    qDebug() << "Table updated!";
}





void MainWindowv::on_btnNextSolution_clicked() {
    int row = ui->tabafficheerreur->currentRow();
    if (row == -1) {
        QMessageBox::information(this, "Info", "Please select a row first");
        return;
    }

    QTableWidgetItem *solItem = ui->tabafficheerreur->item(row, 3);
    if (!solItem) return;

    // Get current index
    int currentIdx = currentSolutionIndex.value(row, 0);

    // Convert QVariant list to QString list
    QList<QVariant> variantList = solItem->data(Qt::UserRole).toList();
    QStringList solutions;
    for (const QVariant &variant : variantList) {
        solutions << variant.toString();
    }

    // Calculate next index (0→1→2→0)
    int nextIdx = (currentIdx + 1) % 3;
    currentSolutionIndex[row] = nextIdx;

    // Update the cell with new solution
    solItem->setText(solutions[nextIdx]);

    // Optional: Change color/style
    QColor colors[3] = {Qt::white, QColor(240,240,255), QColor(255,240,240)};
    solItem->setBackground(colors[nextIdx]);
}






void MainWindowv::on_btnSimulateGPS_clicked()
{
    // Fetch the selected vehicle's matricule
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    if (item) {
        QString matricule = item->text(); // Assuming matricule is in the first column

        // Simulate GPS for the selected vehicle
        simulateAndInsertGPS(matricule);
    }
}

// Function to simulate GPS and insert into the database
void MainWindowv::simulateAndInsertGPS(const QString &matricule) {
    // Fetch the last known position from the database
    QSqlQuery query;
    query.prepare(R"(
    SELECT latitude, longitude
    FROM (
        SELECT latitude, longitude
        FROM vehicule_gps
        WHERE matricule = :matricule
        ORDER BY timestamp_gps DESC
    )
    WHERE ROWNUM = 1
)");    query.bindValue(":matricule", matricule);

    double lastLat = 0.0, lastLon = 0.0;
    if (query.exec() && query.next()) {
        lastLat = query.value(0).toDouble();
        lastLon = query.value(1).toDouble();
    } else {
        // Default coordinates if no previous location exists
        lastLat = 36.850;
        lastLon = 10.150;
    }

    // Add random small variations to simulate movement
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> latDist(-0.001, 0.001);
    std::uniform_real_distribution<> lonDist(-0.001, 0.001);

    double lat = lastLat + latDist(gen);
    double lon = lastLon + lonDist(gen);

    // Get the current timestamp in Qt format
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");  // Format timestamp to string

    // Prepare the query to insert the GPS point
    query.prepare(R"(
        INSERT INTO vehicule_gps (id, matricule, timestamp_gps, latitude, longitude)
        VALUES (VEHICULE_GPS_SEQ.NEXTVAL, :matricule, TO_TIMESTAMP(:timestamp_gps, 'YYYY-MM-DD HH24:MI:SS'), :latitude, :longitude)
    )");

    query.bindValue(":matricule", matricule);
    query.bindValue(":timestamp_gps", timestamp);  // Binding the timestamp as a string
    query.bindValue(":latitude", lat);
    query.bindValue(":longitude", lon);

    // Execute the query and handle the result
    if (!query.exec()) {
        qDebug() << "Failed to insert GPS point:" << query.lastError().text();
        QMessageBox::warning(this, "Erreur", "Impossible de Localiser Le vehicule !");
    } else {
        qDebug() << "Inserted GPS for " << matricule << ": (" << lat << ", " << lon << ")";
        QMessageBox::information(this, "Succès", "Vehicule Localiser !");
    }
}



void MainWindowv::on_btnViewLatestGPS_clicked()
{

    // Fetch the selected vehicle's matricule
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    if (item) {
        QString matricule = item->text(); // Assuming matricule is in the first column

        // Retrieve and view the latest GPS location
        viewLatestGPS(matricule);
    }
}

// Function to retrieve and display the latest GPS location on the map

void MainWindowv::viewLatestGPS(const QString &matricule)
{

    QSqlQuery query;
    query.prepare(R"(
    SELECT latitude, longitude
    FROM (
        SELECT latitude, longitude
        FROM vehicule_gps
        WHERE matricule = :matricule
        ORDER BY timestamp_gps DESC
    )
    WHERE ROWNUM = 1
)");
    query.bindValue(":matricule", matricule);

    if (query.exec()) {
        if (query.next()) {
            double latitude = query.value(0).toDouble();
            double longitude = query.value(1).toDouble();

            // Envoi des coordonnées au QML
            QVariant returnedValue;
            QVariant lat = latitude;
            QVariant lon = longitude;

            QObject *rootObject = ui->quickWidget->rootObject();
            QMetaObject::invokeMethod(rootObject, "setPinLocation",
                                      Q_RETURN_ARG(QVariant, returnedValue),
                                      Q_ARG(QVariant, lat),
                                      Q_ARG(QVariant, lon));

        } else {
            QMessageBox::warning(this, "Erreur", "Aucun projet trouvé avec cet ID.");
        }
    } else {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
    }
}
// Function to update the map with the new coordinates

void MainWindowv::setPinLocation(double lat, double lon) {
    // Find the QML map view
    QQuickItem *mapItem = ui->quickWidget->findChild<QQuickItem*>("mapView");

    if (mapItem) {
        QVariantMap params;
        params["latitude"] = lat;
        params["longitude"] = lon;

        // Call the QML function setPinLocation to update the pin
        QMetaObject::invokeMethod(mapItem, "setPinLocation", Q_ARG(QVariantMap, params));
    }
}


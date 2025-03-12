#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connecter les actions des boutons
     connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::ajouterEmploye);
     connect(ui->SuppButton, &QPushButton::clicked, this, &MainWindow::supprimerEmploye);
     connect(ui->exportButton, &QPushButton::clicked, this, &MainWindow::exportPdf);
     connect(ui->triButton, &QPushButton::clicked, this, &MainWindow::trierParSalaire);
     connect(ui->valider, &QPushButton::clicked, this, &MainWindow::validerMotDePasse);
     connect(ui->id_valide, &QPushButton::clicked, this, &MainWindow::verifierIdExistant);
     connect(ui->mod_bouton, &QPushButton::clicked, this, &MainWindow::modifierEmploye);
     connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MainWindow::rechercherEmploye);

    afficherEmployes();
    afficherStatistiques();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::resetInputs()
{
    ui->idInput->clear();
    ui->MDPInput->clear();
    ui->nomInput->clear();
    ui->email->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->spinBox->setValue(0);

    ui->SuppID->clear();

    ui->mod_id->clear();
    ui->mod_nom->clear();
    ui->mod_mail->clear();
    ui->mod_salaire->setValue(0);

    ui->searchLineEdit->clear();
}


bool MainWindow::validerMotDePasse()
{
    QString mdp = ui->MDPInput->text().trimmed();

     static int lettreCount = mdp.count(QRegularExpression("[a-zA-Z]"));
     static int chiffreCount = mdp.count(QRegularExpression("\\d"));

    if (mdp.length() >= 6 && lettreCount >= 2 && chiffreCount >= 1) {
        ui->validation->setText("Fort ✅");
        ui->validation->setStyleSheet("color: green; font-weight: bold;");
        return true;
    } else {
        ui->validation->setText("Faible ❌ ");
        ui->validation->setStyleSheet("color: red; font-weight: bold;");
        return false;
    }
}

bool MainWindow::validerEmail(QString &email) {

    QRegularExpression regex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return regex.match(email).hasMatch();
}



MainWindow::PasswordData MainWindow::crypterMotDePasse(const QString &mdp) {
    // Étape 1 : Diviser en deux et inverser
    int mid = mdp.length() / 2;
    QString part1 = mdp.left(mid);
    QString part2 = mdp.mid(mid);
    QString inverse = part2 + part1;

    // Étape 2 : Remplacer les caractères successifs identiques par "#"
    QString result;
    for (int i = 0; i < inverse.length(); ++i) {
        if (i > 0 && inverse[i] == inverse[i - 1]) {
            result += "#";
        } else {
            result += inverse[i];
        }
    }

    // Étape 3 : Générer un sel unique
    QString caracteresSpeciaux = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
    QRandomGenerator *generator = QRandomGenerator::global();
    QString salt;
    for (int i = 0; i < 8; i++) { // Sel de 8 caractères
        salt += caracteresSpeciaux[generator->bounded(caracteresSpeciaux.length())];
    }

    // Étape 4 : Ajouter le sel au mot de passe transformé
    QString motDePasseTransforme = salt + result + salt;

    // Étape 5 : Hacher avec SHA-256
    QByteArray hash = QCryptographicHash::hash(motDePasseTransforme.toUtf8(), QCryptographicHash::Sha256);

    // Retourner le hachage et le sel
    PasswordData data;
    data.hashedPassword = QString(hash.toHex());
    data.salt = salt;
    return data;
}

void MainWindow::crypterMotDePasse(const QString &mdp, QString &hashedPassword, QString &salt) {
    PasswordData data = crypterMotDePasse(mdp);
    hashedPassword = data.hashedPassword;
    salt = data.salt;
}

bool MainWindow::verifierIdExistant()
{
    QString id = ui->mod_id->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID !");
    }

    QString nom, email;
    int salaire;
    Employee emp;

    if (emp.recupererEmploye(id, nom, email, salaire)) {
        ui->mod_nom->setText(nom);
        ui->mod_mail->setText(email);
        ui->mod_salaire->setValue(salaire);
        QMessageBox::information(this, "Succès", "Employé trouvé !");
        return true;
    } else {
        QMessageBox::critical(this, "Erreur", "ID introuvable !");
        return false;
    }
}


void MainWindow::ajouterEmploye()
{
    // Récupérer les valeurs des inputs
    QString id = ui->idInput->text();
    QString mdp = ui->MDPInput->text();
    QString nom = ui->nomInput->text();
    QString email = ui->email->text();
    QString role = ui->comboBox->currentText();
    int salaire = ui->spinBox->value();

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Il faut insérer un Identifiant !");
        return;
    }
    if (mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Il faut insérer un mot de passe !");
        return;
    }
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Il faut insérer un e-mail !");
        return;
    }
    if (!validerEmail(email)) {
        QMessageBox::warning(this, "Erreur", "L'adresse e-mail n'est pas valide !");
        return;
    }
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Il faut insérer un Nom !");
        return;
    }
    if (!validerMotDePasse()) {
        QMessageBox::warning(this, "Erreur", "Le mot de passe est trop faible !");
        return;
    }

    // Crypter le mot de passe avant de l'ajouter
    PasswordData passwordData = crypterMotDePasse(mdp);
    Employee emp(id, passwordData.hashedPassword, nom, role, salaire, email, passwordData.salt);
    if (emp.ajouterEmploye()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès !");
        afficherEmployes();
        afficherStatistiques();
        resetInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'employé !");
    }
}



void MainWindow::afficherEmployes()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Nom", "Rôle", "Salaire"});

    // Appeler directement la méthode statique sans instancier Employee
    QList<Employee> employes = Employee::afficherEmployes();

    // Trier en fonction de la variable triCroissant
    std::sort(employes.begin(), employes.end(), [this](const Employee &a, const Employee &b) {
        return triCroissant ? (a.getSalaire() < b.getSalaire()) : (a.getSalaire() > b.getSalaire());
    });

    //
    for (int i = 0; i < employes.size(); i++) {
        const Employee& e = employes[i];
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(e.getId()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(e.getNom()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(e.getRole()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(e.getSalaire())));
    }
}


// Méthode pour supprimer un employé
void MainWindow::supprimerEmploye()
{
    QString id = ui->SuppID->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID ne peut pas être vide.");
        return;
    }

    // Vérifier si l'ID existe
    QSqlQuery query;
    query.prepare("SELECT NOM, ROLE FROM EMPLOYEE WHERE ID = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        QString nom = query.value(0).toString();
        QString role = query.value(1).toString();
        int x = QMessageBox::question(this, "Confirmation de Suppression",
                                        "L'enregistrement suivant sera supprimé :\n"
                                        "Nom : " + nom + "\n"
                                        "Role : " + role + "\n\n "
                                        "Êtes-vous sûr de vouloir continuer ? ",
                                        QMessageBox::Yes | QMessageBox::No);

        if (x == QMessageBox::No) {
            return;
        }

        // Supprimer directement via la méthode statique
        bool success = Employee::supprimerEmploye(id);

        if (success) {
            QMessageBox::information(this, "Succès", "L'employé a été supprimé avec succès.");
            afficherEmployes();
            afficherStatistiques();
            resetInputs();
        }
        else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression de l'employé.");
        }
    }
    else {
        QMessageBox::warning(this, "Erreur", "L'ID n'existe pas ! ");
    }
}

void MainWindow::modifierEmploye()
{
    QString id = ui->mod_id->text();
    QString nom = ui->mod_nom->text();
    QString email = ui->mod_mail->text();
    int salaire = ui->mod_salaire->value();

    if(!verifierIdExistant()){
        QMessageBox::critical(this, "Erreur", "ID introuvable !");
        return;
    }

    if (id.isEmpty() ) {
        QMessageBox::warning(this, "Erreur", "Il faut inséser un Identifiant à modifier !");
        return;
    }

    if ( nom.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    Employee emp;
    if (emp.modifierEmploye(id, nom, email, salaire)) {
        QMessageBox::information(this, "Succès", "Employé modifié avec succès !");
        afficherEmployes();
        afficherStatistiques();
        resetInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification !");
    }
}




void MainWindow::trierParSalaire()
{
    // Inverser l'état du tri
    triCroissant = !triCroissant;

    // Modifier le texte du bouton pour refléter l'ordre du tri
    if (triCroissant) {
        ui->triButton->setText("Trier par Salaire (↑)");
    } else {
        ui->triButton->setText("Trier par Salaire (↓)");
    }

    afficherEmployes(); // Rafraîchir l'affichage
}


void MainWindow::exportPdf()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le fichier PDF.");
        return;
    }

    int margin = 30;
    int rowHeight = 25;
    int columnWidth = 100;
    int currentY = margin;

    QRect pageRect = printer.pageLayout().paintRectPixels(printer.resolution());

    // **Ajout d'un titre centré**
    painter.setFont(QFont("Arial", 14, QFont::Bold));
    painter.drawText(QRect(margin, currentY, pageRect.width() - 2 * margin, 30), "Tableau des Employées : ");
    currentY += 40;

    // **Définition des couleurs et styles**
    QPen borderPen(Qt::black);
    borderPen.setWidth(2);
    QBrush headerBrush(QColor(200, 200, 250)); // Fond bleu clair pour les en-têtes
    QBrush cellBrush(QColor(250, 250, 250));   // Fond gris clair pour les lignes

    // **Dessiner les en-têtes avec un fond coloré**
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setBrush(headerBrush);
    painter.setPen(borderPen);

    for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
        QString header = ui->tableWidget->horizontalHeaderItem(col)->text();
        QRect cellRect(margin + col * columnWidth, currentY, columnWidth, rowHeight);
        painter.drawRect(cellRect);
        painter.drawText(cellRect, Qt::AlignCenter, header);
    }
    currentY += rowHeight;

    // **Dessiner les données avec alternance de couleurs**
    painter.setFont(QFont("Arial", 10));

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        painter.setBrush(row % 2 == 0 ? cellBrush : Qt::white); // Alternance des couleurs

        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            QRect cellRect(margin + col * columnWidth, currentY, columnWidth, rowHeight);

            // Dessiner la cellule avec une bordure
            painter.drawRect(cellRect);

            if (item) {
                painter.drawText(cellRect, Qt::AlignCenter, item->text());
            }
        }
        currentY += rowHeight;

        // **Gestion de la pagination**
        if (currentY > pageRect.height() - margin) {
            printer.newPage();
            currentY = margin + 40; // Reprendre après le titre
        }
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Le tableau a été exporté en PDF avec succès.");
}



void MainWindow::rechercherEmploye()
{
    QString searchTerm = ui->searchLineEdit->text();  // Récupère le texte saisi dans le champ de recherche

    if (searchTerm.isEmpty()) {
        afficherEmployes();  // Si aucun texte n'est saisi, afficher tous les employés
        return;
    }

    // Rechercher dans la liste d'employés
    Employee emp;
    QList<Employee> employes = emp.afficherEmployes();
    QList<Employee> resultats;

    for (const Employee& e : employes) {
        if (e.getNom().contains(searchTerm, Qt::CaseInsensitive)) {
            resultats.append(e);  // Ajouter les employés qui correspondent à la recherche
        }
    }

    // Afficher les résultats dans le tableau
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Nom", "Rôle", "Salaire"});

    int row = 0;
    for (const Employee& e : resultats) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(e.getId()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(e.getNom()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(e.getRole()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(e.getSalaire())));
        row++;
    }
}

void MainWindow::afficherStatistiques()
{
    // Effacer tous les widgets du layout chartLayout avant d'ajouter un nouveau graphique
    QLayoutItem *child;
    while ((child = ui->chartLayout->takeAt(0)) != nullptr) {
        delete child->widget();  // Supprimer les widgets existants dans le layout
        delete child;  // Supprimer l'élément du layout
    }

    // Récupérer les statistiques des salaires
    int salaire100_500 = 0;
    int salaire500_1000 = 0;
    int salairePlus1000 = 0;

    Employee emp;
    QList<Employee> employes = emp.afficherEmployes();

    // Calculer le nombre d'employés dans chaque tranche de salaire
    for (const Employee& e : employes) {
        int salaire = e.getSalaire();
        if (salaire >= 100 && salaire < 500) {
            salaire100_500++;
        } else if (salaire >= 500 && salaire < 1000) {
            salaire500_1000++;
        } else if (salaire >= 1000) {
            salairePlus1000++;
        }
    }

    // Créer un ensemble de barres pour chaque tranche de salaire
    QBarSet *set = new QBarSet("Nombre d'employés");
    *set << salaire100_500 << salaire500_1000 << salairePlus1000;

    // Créer une série de barres et y ajouter l'ensemble
    QBarSeries *series = new QBarSeries();
    series->append(set);

    // Créer un graphique à barres
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Analyse des salaires des employés");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Créer un axe des X
    QStringList categories;
    categories << "100-499" << "500-999" << "+1000";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Calculer la valeur maximale de l'axe Y et ajuster à l'entier supérieur
    int maxSalaire = qMax(salaire100_500, qMax(salaire500_1000, salairePlus1000));
    int maxY = std::ceil(maxSalaire); // Utiliser ceil pour arrondir à l'entier supérieur

    // Créer un axe des Y avec la valeur ajustée
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxY);
    axisY->setTickCount(maxY + 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Afficher le graphique dans un QChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400, 300);  // Ajustez la taille selon votre besoin

    // Ajouter le graphique à votre layout (par exemple, un QVBoxLayout)
    ui->chartLayout->addWidget(chartView);  // Assurez-vous d'avoir un layout nommé chartLayout dans votre interface
}



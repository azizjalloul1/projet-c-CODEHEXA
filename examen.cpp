#include "examen.h"
#include <QSqlQuery>
#include <QVariant> // var dynamique
#include <QSqlError>
#include <QDate>
#include <QDebug>

Examen::Examen(const QString& id_examen, const QString& matiere, const QString& niveau, const QString& exam_date, const QString& heure, const int quantite)
    : id_examen(id_examen), matiere(matiere), niveau(niveau), exam_date(exam_date), heure(heure), quantite(quantite)
{
    //initialisation  des variables
}

QString Examen::getCodeExamen() const { return id_examen; }
QString Examen::getMatiere() const { return matiere; }
QString Examen::getNiveau() const { return niveau; }
QString Examen::getDate() const { return exam_date; }
QString Examen::getHeure() const { return heure; }
int Examen::getQuantite() const { return quantite; }

void Examen::setCodeExamen(const QString& id_examen) { this->id_examen = id_examen; }
void Examen::setMatiere(const QString& matiere) { this->matiere = matiere; }
void Examen::setNiveau(const QString& niveau) { this->niveau = niveau; }
void Examen::setDate(const QString& exam_date) { this->exam_date = exam_date; }
void Examen::setHeure(const QString& heure) { this->heure = heure; }
void Examen::setQuantite(const int quantite) { this->quantite = quantite; }

void Examen::setFichierPdf(const QString& path) {
    fichier_pdf = path;
}

QString Examen::getFichierPdf() const {
    return fichier_pdf;
}

bool Examen::codeExisteDeja(const QString& id_examen)
{
    QSqlQuery query;
    query.prepare("SELECT ID_EXAMEN FROM EXAMEN WHERE ID_EXAMEN = :code LIMIT 1");
    query.bindValue(":code", id_examen);

    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}


bool Examen::ajouterExamen()
{
    if (codeExisteDeja(id_examen)) {
        QMessageBox::critical(nullptr, "Erreur", "Le code de l'examen existe déjà !");
        return false;
    }

    QSqlQuery query;

    qDebug() << "Préparation requête avec fichier PDF: " << fichier_pdf;

    query.prepare("INSERT INTO EXAMEN (ID_EXAMEN, MATIERE, NIVEAU, DATE_EXAMEN, HEURE, QUANTITE, FICHIER_PDF) "
                  "VALUES (:code, :matiere, :niveau, TO_DATE(:exam_date, 'YYYY-MM-DD'), :heure, :quantite, :pdf)");

    query.bindValue(":code", id_examen);
    query.bindValue(":matiere", matiere);
    query.bindValue(":niveau", niveau);
    query.bindValue(":exam_date", exam_date);
    query.bindValue(":heure", heure);
    query.bindValue(":quantite", quantite);
    query.bindValue(":pdf", fichier_pdf);

    if (!query.exec()) {
        qDebug() << "SQL Error: " << query.lastError().text();
        return false;
    }

    qDebug() << "Examen ajouté avec PDF: " << fichier_pdf;
    return true;
}


bool Examen::modifierExamen(const QString& code) {
    QSqlQuery query;

    query.prepare("UPDATE EXAMEN SET MATIERE = :matiere, NIVEAU = :niveau, DATE_EXAMEN = :exam_date, HEURE = :heure, QUANTITE = :quantite WHERE ID_EXAMEN = :code");

    query.bindValue(":code", code);

    qDebug() << "Executing query: " << query.lastQuery();

    qDebug() << "Values being bound:";
    qDebug() << "Code: " << code;
    qDebug() << "Matiere: " << matiere;
    qDebug() << "Niveau: " << niveau;
    qDebug() << "Exam Date: " << exam_date;
    qDebug() << "Heure: " << heure;
    qDebug() << "Quantite: " << quantite;

    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        return false;
    }


    return true;
}






bool Examen::supprimerExamen(const QString& id_examen)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EXAMEN WHERE ID_EXAMEN = :code");
    query.bindValue(":code", id_examen);

    if (!query.exec()) {
        qDebug() << "SQL Error: " << query.lastError().text();
        return false;
    }

    return true;
}

QList<Examen> Examen::afficherExamens()
{
    QList<Examen> examens;
    QSqlQuery query("SELECT ID_EXAMEN, MATIERE, NIVEAU, DATE_EXAMEN, HEURE, QUANTITE, FICHIER_PDF FROM EXAMEN");

    while (query.next()) {
        QString code = query.value(0).toString();
        QString matiere = query.value(1).toString();
        QString niveau = query.value(2).toString();
        QString date = query.value(3).toDate().toString("yyyy-MM-dd");
        QString heure = query.value(4).toString();
        int quantite = query.value(5).toInt();
        QString fichier_pdf = query.value(6).toString();
        Examen e(code, matiere, niveau, date, heure, quantite);
        e.setFichierPdf(fichier_pdf);
        examens.append(e);
    }

    return examens;
}


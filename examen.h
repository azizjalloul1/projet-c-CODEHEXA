#ifndef EXAMEN_H
#define EXAMEN_H
#include <QString>
#include <QSqlQuery> //requete sql
#include <QMessageBox>
#include <QList>

class Examen
{
public:
    // Constructeur
    Examen(const QString& id_examen = "", const QString& matiere = "", const QString& niveau = "", const QString& exam_date = "", const QString& heure = "", const int quantite = 0);


    QString getCodeExamen() const;
    QString getMatiere() const;
    QString getNiveau() const;
    QString getDate() const;
    QString getHeure() const;
    int getQuantite() const;


    void setCodeExamen(const QString& id_examen);
    void setMatiere(const QString& matiere);
    void setNiveau(const QString& niveau);
    void setDate(const QString& exam_date);
    void setHeure(const QString& heure);
    void setQuantite(const int quantite);

    void setFichierPdf(const QString& fichier);


    bool codeExisteDeja(const QString& id_examen);
    bool ajouterExamen();
    bool modifierExamen(const QString& id_examen);
    bool supprimerExamen(const QString& id_examen);
    static QList<Examen> afficherExamens();

    QString getFichierPdf() const;

private:
    QString id_examen;
    QString matiere;
    QString niveau;
    QString exam_date;
    QString heure;
    int quantite;
    QString fichier_pdf;

};

#endif

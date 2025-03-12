#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QList>

class Employee
{

private:
    QString id, mdp, nom, role, email, salt;
    int salaire;

public:
    Employee();
    Employee(QString i, QString m, QString n, QString r, int s, QString e, QString slt = "");

    // Getters
    QString getId() const;
    QString getMdp() const;
    QString getNom() const;
    QString getRole() const;
    QString getEmail() const;
    int getSalaire() const;

    // Setters
    void setId(QString id);
    void setMdp(QString mdp);
    void setNom(QString nom);
    void setRole(QString role);
    void setEmail(QString email);
    void setSalaire(int salaire);

    // Méthodes CRUD
    QString hasherMotDePasse(const QString& motDePasse);
    bool idExisteDeja(const QString& id);
    bool ajouterEmploye();
    bool modifierEmploye(const QString& id);
    static bool supprimerEmploye(const QString& id);
    static QList<Employee> afficherEmployes();
    bool recupererEmploye(const QString& id, QString& nom, QString& email, int& salaire);
    bool modifierEmploye(const QString& id, const QString& nom, const QString& email, int salaire);

};

#endif // EMPLOYEE_H

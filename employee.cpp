#include "employee.h"
#include <QCryptographicHash>

//constructeur
Employee::Employee()
{
    id="";
    mdp="";
    nom="";
    role="";
    email="";
    salt="";
    salaire=0;
}
Employee::Employee(QString i, QString m, QString n, QString r, int s, QString e, QString slt)
{
    id=i;
    mdp=m;
    nom=n;
    role=r;
    email=e;
    salt=slt;
    salaire=s;
}
// Getters
QString Employee::getId() const  { return id; }
QString Employee::getMdp() const { return mdp; }
QString Employee::getNom() const  { return nom; }
QString Employee::getRole() const  { return role; }
QString Employee::getEmail() const  { return email; }
int Employee::getSalaire() const { return salaire; }
// Setters
void Employee::setId(QString id) { this->id = id; }
void Employee::setMdp(QString mdp) { this->mdp = mdp; }
void Employee::setNom( QString nom) { this->nom = nom; }
void Employee::setRole(QString role) { this->role = role; }
void Employee::setEmail(QString email) { this->email = email; }
void Employee::setSalaire(int salaire) { this->salaire = salaire; }


bool Employee::idExisteDeja(const QString& id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYEE WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int existe = query.value(0).toInt();
        return existe > 0;
    }
    return false;
}

// Méthode pour ajouter un employé avec vérification d'unicité de l'ID
bool Employee::ajouterEmploye()
{
    // Vérifier si l'ID existe déjà
    if (idExisteDeja(id)) {
        QMessageBox::critical(nullptr, "Erreur", "L'ID de l'employé existe déjà !");
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEE (ID, MOT_DE_PASSE, NOM, ROLE, SALAIRE, EMAIL, SALT) "
                    "VALUES (:id, :mdp, :nom, :role, :salaire, :email, :salt)");
    query.bindValue(":id", id);
    query.bindValue(":mdp", mdp);
    query.bindValue(":nom", nom);
    query.bindValue(":role", role);
    query.bindValue(":salaire", salaire);
    query.bindValue(":email", email);
    query.bindValue(":salt", salt);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur SQL:" << query.lastError().text(); // Affiche l'erreur SQL
        QMessageBox::critical(nullptr, "Erreur", "Erreur lors de l'ajout de l'employé: " + query.lastError().text());
        return false;
    }
}

QList<Employee> Employee::afficherEmployes()
{
    QList<Employee> employes;
    QSqlQuery query("SELECT ID, NOM, ROLE, SALAIRE FROM EMPLOYEE");

    while (query.next()) {
        Employee emp(query.value(0).toString(),  // ID
                     "",                         // MOT_DE_PASSE (non utilisé ici, )
                     query.value(1).toString(),  // NOM
                     query.value(2).toString(),  // ROLE
                     query.value(3).toInt(),     // SALAIRE
                     "",                         // EMAIL (non utilisé ici, donc vide)
                     "");                        // SALT (non utilisé ici, donc vide)
        employes.append(emp);
    }

    return employes;
}

bool Employee::supprimerEmploye(const QString& id) {
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM EMPLOYEE WHERE ID = :id");
    checkQuery.bindValue(":id", id);

    if (!checkQuery.exec() || !checkQuery.next()) {
        return false;
    }

    int count = checkQuery.value(0).toInt();
    if (count == 0) {
        qDebug() << "L'ID" << id << "n'existe pas dans la base de données.";
        return false;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEE WHERE ID = :id");
    query.bindValue(":id", id);

    return query.exec();
}

bool Employee::recupererEmploye(const QString& id, QString& nom, QString& email, int& salaire) {
    QSqlQuery query;
    query.prepare("SELECT NOM, EMAIL, SALAIRE FROM EMPLOYEE WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        nom = query.value(0).toString();
        email = query.value(1).toString();
        salaire = query.value(2).toInt();
        return true;
    }
    return false;
}

bool Employee::modifierEmploye(const QString& id, const QString& nom, const QString& email, int salaire) {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYEE SET NOM = :nom, EMAIL = :email, SALAIRE = :salaire WHERE ID = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":email", email);
    query.bindValue(":salaire", salaire);

    return query.exec();
}



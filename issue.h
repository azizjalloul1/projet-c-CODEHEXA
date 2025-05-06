#ifndef ISSUE_H
#define ISSUE_H

#include <QString> // Include QString header

class Issue {
public:
    QString symptome;
    QString composant;
    QString cause;
    QString solution1;
    QString solution2;
    QString solution3;

    // Default constructor
    Issue() : symptome(""), composant(""), cause(""), solution1(""), solution2(""), solution3("") {}

    // Constructor with parameters (if needed)
    Issue(const QString &symptome, const QString &composant, const QString &cause,
          const QString &solution1, const QString &solution2, const QString &solution3)
        : symptome(symptome), composant(composant), cause(cause),
        solution1(solution1), solution2(solution2), solution3(solution3) {}
};


#endif // ISSUE_H

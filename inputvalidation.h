#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <QString>

class InputValidation
{
public:
    InputValidation();
    QString validateTrailZeros(QChar, QChar, QString);
    QString validateOperators(QChar, QChar, QString);
private:
    bool isDotValid(QChar, QString);
};

#endif // INPUTVALIDATION_H

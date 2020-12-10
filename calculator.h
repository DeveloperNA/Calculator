#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<QString>
#include "calculatorservice.h"
#include "inputvalidation.h"
class Calculator
{
public:
    QChar lastPrev;
    QChar last;
    Calculator();
    Calculator(const Calculator &);
    Calculator &operator=(const Calculator &);

    void setInputExp(QString data);
    QString getInputExp();

    void setResult();
    double getResult();

    void clear();
    void clearAll();

    ~Calculator();

private:
    QString inputExp;
    double result;

    InputValidation val;
    CalculatorService *calcService = new CalculatorService();
};

#endif // CALCULATOR_H

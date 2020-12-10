#ifndef CALCULATORSERVICE_H
#define CALCULATORSERVICE_H

#include <QString>

class CalculatorService
{

public:
    CalculatorService();

    double postfixEvaluation(QString infix);

private:
    QString postfixExp;

    QString infixToPostfix(QString infix);

};

#endif // CALCULATORSERVICE_H

#include "header/utils/utils.h"
#include "header/core/calculator.h"
#include <QDebug>
#include <QString>
#include <iostream>

Calculator::Calculator()
{
    inputExp = "";
    result = 0;
}

void Calculator::setInputExp(QString data)
{
    QChar digit = data[0];

    if(!inputExp.isEmpty())
        lastPrev = inputExp[(inputExp.size()-1)];  // gets last character in exp.
    else
        lastPrev = '0';

    inputExp = (isNum(digit) || isZero(digit))?
                val.validateTrailZeros(digit, lastPrev, inputExp):
                 val.validateOperators(digit, lastPrev, inputExp);

    if(!inputExp.isEmpty())
        last = inputExp[(inputExp.size()-1)];
    else
        last = '0';
    qDebug() << "Inputexp" << inputExp;
    qDebug() << "lastPrev" << lastPrev << "   " << "last" << last;
}

QString Calculator::getInputExp()
{
    return inputExp;
}

void Calculator::setResult()
{
    if(!inputExp.isEmpty())
        result = calcService->postfixEvaluation(inputExp);
    else
        result = 0;
}

double Calculator::getResult()
{
    return result;
}


void Calculator::clear()
{

    inputExp.remove(inputExp.size()-1, 1);

    if(!inputExp.isEmpty())
        last = inputExp[(inputExp.size()-1)];
    else{
        last = '0';
    }

}

void Calculator::clearAll()
{
    inputExp.clear();
    inputExp = "";
}



Calculator::~Calculator()
{

}



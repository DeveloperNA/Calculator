#include "header/utils/utils.h"
#include "header/core/inputvalidation.h"
#include <QString>
#include <QDebug>

InputValidation::InputValidation()
{

}

QString InputValidation::validateTrailZeros(QChar presentDigit, QChar lastPrev, QString exp)
{
    static bool zeroDisabled;
    qDebug() << "In Validate Zeros";
    if(exp.isEmpty()){
        qDebug() << "zero true";
        zeroDisabled = true;
        exp.append(presentDigit);
        return exp;

    }
    else if (isZero(lastPrev) && zeroDisabled){
        exp.replace(exp.size()-1, 1, presentDigit);
        return exp;
    }
    else if(isNum(lastPrev)){
        zeroDisabled = false;
        exp.append(presentDigit);
        return exp;
    }
    else if(isOp(lastPrev)){
        zeroDisabled = true;
        exp.append(presentDigit);
        return exp;
    }
    else if(isDot(lastPrev)){
        exp.append(presentDigit);
        zeroDisabled = false;
        return exp;
    }
    else if(isZero(lastPrev) && !zeroDisabled){
        exp.append(presentDigit);
        return exp;
    }
    return exp;
}

QString InputValidation::validateOperators(QChar presentDigit, QChar lastPrev, QString exp)
{
    qDebug() << "In OP ";
    if(!exp.isEmpty()){

        if(isOp(lastPrev) && !isDot(presentDigit)){
            exp.replace(exp.size()-1, 1, presentDigit);
            return exp;
        }
//        else if(isZero(exp[0])&& !isDot(presentDigit)){
//            return "0";
//        }
        else if(isDot(presentDigit)){
            if(isDotValid(lastPrev, exp)){
                exp.append(".");
                return exp;
            }
            else{
                return exp;
            }
        }
        else{        //Must be a number...
            exp.append(presentDigit);
            return exp;
        }
    }

    else {
        return "";
    }
}

bool InputValidation::isDotValid(QChar lastPrev, QString exp)
{
    qDebug() << "In dot Valid";
    int i = exp.size()-1;

    if(isOp(lastPrev)){
        return false;
    }

    while(i>=0 && !isOp(exp[i])){
        if(isDot(exp[i])){
            qDebug() << "false in dot";
            return false;
        }
        i--;
    }
    qDebug() << "true in dot";
    return true;
}


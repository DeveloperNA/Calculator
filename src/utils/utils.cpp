#include "header/utils/utils.h"
#include <QChar>
int isZero(QChar ch){
    if(ch == 48){
        return 1;
    }
    else
        return 0;
}

int isNum(QChar ch){
    if(ch >=49 && ch <= 57){            //Numbers 1 - 9
        return 1;
    }
    else
        return 0;
}

int isOp(QChar ch){
    if(ch == 42 || ch == 43 || ch == 45 || ch == 47){           // operators *,+,-,/
        return 1;
    }
    else
        return 0;
}

int isDot(QChar ch){
    if(ch == '.'){
        return 1;
    }
    else
        return 0;
}

int precedence(QChar n) {
    if (n == '+' || n == '-') { return 1; }
    else if (n == '*' || n == '/') { return 2; }
    else if (n == '^') { return 3; }
    return 1;
}

double compute(double num1, double num2, char op)
{
    double res;

    switch(op) {
        case '+': {
            res = num1 + num2;
            break;
        }
        case '-': {
            res = num1 - num2;
            break;
        }
        case '*': {
            res = num1 * num2;
            break;
        }
        case '/': {
            res = num1 / num2;
            break;
        }
    }

    return res;
}

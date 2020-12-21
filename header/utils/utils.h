#ifndef UTILS_H
#define UTILS_H
#include <QChar>

int isNum(QChar);
int isZero(QChar);
int isOp(QChar);
int precedence(QChar);
int isDot(QChar);
double compute(double, double, char);
#endif // UTILS_H

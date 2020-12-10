#include "calculatorservice.h"
#include "utils.h"
#include <QStack>
#include <QString>
#include <QDebug>
#include <QChar>


CalculatorService::CalculatorService()
{

}

double CalculatorService::postfixEvaluation(QString exp)
{
    postfixExp = infixToPostfix(exp);
    QStack<double> numStack;
    double result;

    for (int i = 0; i < postfixExp.size(); i++) {

        if (postfixExp[i] >= '0' && postfixExp[i] <= '9') {
            QString temp;
            while (postfixExp[i] != ',') {
                temp.push_back(postfixExp[i]);
                i++;
            }
            numStack.push(temp.toDouble());
        }

        else {
            double operand1, operand2, res;

            operand2= numStack.top();
            numStack.pop();

            operand1= numStack.top();
            numStack.pop();

            res = compute(operand1, operand2, postfixExp[i].toLatin1());
            numStack.push(res);
        }

    }
    result = numStack.top();
    numStack.pop();

    return result;
}

QString CalculatorService::infixToPostfix(QString exp)
{
    QString postfix;
    QStack<QChar> stack;

    for (int i = 0; i < exp.size(); i++) {

        if (exp[i] >= '0' && exp[i] <= '9') {
            QString temp;

            while ((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.') {
                temp.push_back(exp[i]);
                i++;
            }
            i -= 1;
            postfix.append(temp);
            postfix.push_back(',');
        }
        else if (exp[i] == '(')
        {
            stack.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while ((!stack.isEmpty()) && (stack.top() != '(')) {
                postfix.push_back(stack.top());
                stack.pop();
            }
        }
        else {											// must be an operator...
            if (stack.isEmpty()) { stack.push(exp[i]); }

            else if (precedence(exp[i]) > stack.top()) { stack.push(exp[i]); }

            else if (exp[i] == '^' && precedence(exp[i]) == precedence(stack.top())) { stack.push(exp[i]); }

            else{
                int a = precedence(stack.top());
                int b = precedence(exp[i]);
                while ((!stack.isEmpty()) && (a >= b)) {
                    postfix.push_back(stack.top());
                    stack.pop();
                }
                stack.push(exp[i]);
            }
        }
    }

    while (!stack.empty()) {								// poping remaining operators from stack...
        postfix.push_back(stack.top());
        stack.pop();
    }
    qDebug() << "Postfix : " << postfix;
    return postfix;
}

#ifndef INPUTSCREEN_H
#define INPUTSCREEN_H

#include "header/core/calculator.h"
#include <QLabel>
#include <QPushButton>

class InputScreen
{
public:
    InputScreen(QLabel *label, QLabel *resultLabel);

    void showInput(QPushButton*);
    void showResult();
    void clearScreen();
    void clearAllScreen();

private:
    Calculator cal;
    QLabel *label;
    QLabel *resultLabel;
};

#endif // INPUTSCREEN_H

#include "inputscreen.h"
#include "utils.h"

InputScreen::InputScreen(QLabel *label, QLabel *resultLabel)
{
    this->label = label;
    this->resultLabel = resultLabel;
}

void InputScreen::showInput(QPushButton *button)
{

    cal.setInputExp(button->text());
    label->setText(cal.getInputExp());
    if(cal.getInputExp()!= "")
        showResult();
    else
        label->setText("0");
}


void InputScreen::showResult()
{
    if(!isOp(cal.last) && !isDot(cal.last)){
        cal.setResult();
        resultLabel->setText(QString::number(cal.getResult()));
    }
}

void InputScreen::clearScreen()
{
    if(cal.getInputExp()!= ""){
        cal.clear();
        label->setText(cal.getInputExp());
        showResult();
    }
    else
        label->setText("0");
}

void InputScreen::clearAllScreen()
{
    cal.clearAll();
    label->setText("0");
    resultLabel->setText("");
}


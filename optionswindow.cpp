#include "optionswindow.h"
#include "ui_optionswindow.h"

static QString helpSize = "4";
static QString helpEndGoal = "2048";
QString Size = "4";
QString End_Goal = "2048";

OptionsWindow::OptionsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);
    if(Size != "")
    {
        ui -> boardSize -> setText(Size);
        ui -> sizeLabel -> setText(Size + "x" + Size);
    }
    if(End_Goal != "")
    {
        ui -> endGoal -> setText(End_Goal);
        ui -> goalLabel -> setText(End_Goal);
    }
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::MSWindowsFixedSizeDialogHint);
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}

void OptionsWindow::on_backToMenu_clicked()
{
    hide();
    parentWidget()->show();
}

void OptionsWindow::on_boardSize_textChanged(const QString &arg1)
{
    helpSize = arg1;
}

void OptionsWindow::on_endGoal_textChanged(const QString &arg1)
{
    helpEndGoal = arg1;
}

void OptionsWindow::on_applyButton_clicked()
{
    try
    {
        Size = helpSize;
        if(Size.toInt() <= 1)
            throw 0;
        ui -> boardSize -> setText(Size);
        ui -> sizeLabel -> setText(Size + "x" + Size);

        //non-positive integer
        bool power_of_2 = false;
        End_Goal = helpEndGoal;
        if(End_Goal.toInt() <= 2)
            throw 1;

        //Size of the board <50
        if(Size.toInt() > 50)
            throw 2;

        //power of 2 case
        int power = End_Goal.toInt();
        while(power%2 == 0)
        {
            power /= 2;
        }
        if(power == 1)
            power_of_2 = true;
        else
        {
            power_of_2 = false;
        }
        if(!power_of_2)
            throw 3;
        ui -> endGoal -> setText(End_Goal);
        ui -> goalLabel -> setText(End_Goal);

    }
    catch(int i)
    {
        if(i == 0)
        {
            QMessageBox::warning(this,"Warning!","Incorrect value. The value must be a positive integer greater than 1.", QMessageBox::Ok);
            ui -> boardSize -> setText("4");
            ui -> sizeLabel -> setText("4x4");
            Size = "4";
        }
        if(i == 1)
        {
            QMessageBox::warning(this,"Warning!","Incorrect value. The value must be a positive integer greater than 2.", QMessageBox::Ok);
            ui -> endGoal -> setText("2048");
            ui -> goalLabel -> setText("2048");
            End_Goal = "2048";
        }
        if(i == 2)
        {
            QMessageBox::warning(this,"Warning!","Incorrect value. The board can not be larger than 50x50.", QMessageBox::Ok);
            ui -> boardSize -> setText("4");
            ui -> sizeLabel -> setText("4x4");
            Size = "4";
        }
        if(i == 3)
        {
            QMessageBox::warning(this,"Warning!","Incorrect value. The value must be a power of 2.", QMessageBox::Ok);
            ui -> endGoal -> setText("2048");
            ui -> goalLabel -> setText("2048");
            End_Goal = "2048";
        }
    }
    catch(...)
    {
        QMessageBox::warning(this,"Warning!","Unexpected warning!", QMessageBox::Ok);
    }
}

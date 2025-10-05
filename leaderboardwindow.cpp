#include "leaderboardwindow.h"
#include "ui_leaderboardwindow.h"

void LeaderBoardWindow::complete(leader *&help, int i)
{
    QString text  = help->nickname + " " + QString::number(help->points);
    switch(i)
    {
    case 1:
        ui -> Place_1 -> setText(text);
        break;
    case 2:
        ui -> Place_2 -> setText(text);
        break;
    case 3:
        ui -> Place_3 -> setText(text);
        break;
    case 4:
        ui -> Place_4 -> setText(text);
        break;
    case 5:
        ui -> Place_5 -> setText(text);
        break;
    case 6:
        ui -> Place_6 -> setText(text);
        break;
    case 7:
        ui -> Place_7 -> setText(text);
        break;
    case 8:
        ui -> Place_8 -> setText(text);
        break;
    case 9:
        ui -> Place_9 -> setText(text);
        break;
    case 10:
        ui -> Place_10 -> setText(text);
        break;
    }
    help = help -> next;
}
LeaderBoardWindow::LeaderBoardWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeaderBoardWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(400,600));
    leader *help = head;
    int counter = 0;
    while(help != nullptr)
    {
        counter++;
        help = help -> next;
    }
    help = head;
    for(int i = 1; i <= counter; i++)
    {
        complete(help,i);
    }
}

LeaderBoardWindow::~LeaderBoardWindow()
{
    delete ui;
}

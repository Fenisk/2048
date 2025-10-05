#include "leaderboard.h"
#include "ui_leaderboard.h"
QString Nickname;

bool LeaderBoard::spaceNickname(QString nick)
{
    for(int i = 0; i < nick.size(); i++)
    {
        if(nick[i] == " ")
        {
            return true;
        }
    }
    return false;
}
void LeaderBoard::addToList()
{
    //saving score to leaderboard.txt
    QFile leaderboardFile("leaderboard.txt");
    if (!leaderboardFile.open(QFile::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
            QMessageBox::warning(this,"Warning!","Could not find leaderboard.txt", QMessageBox::Ok);
    }
    QTextStream text(&leaderboardFile);
    text << Nickname + " " + QString::number(Score) + "\n";
    leaderboardFile.close();

    //new score in the right place of linked list
    leader *help = head;
    leader *help2 = nullptr;
    leader *p = new leader;
    p->nickname = Nickname;
    p->points = Score;
    if(help != nullptr)
    {
        if(head->next != nullptr)
        {
            bool entered = false;
            while(help != nullptr)
            {
                if(help->points < Score)
                {
                    if(help == head)
                    {
                        p->next = head;
                        head = p;
                        entered = true;
                        break;
                    }
                    else
                    {
                        p->next = help;
                        help2->next = p;
                        entered = true;
                        break;
                    }
                }
                help2 = help;
                help = help->next;
            }
            if(!entered)
            {
                help2->next = p;
                p->next = nullptr;
            }
        }
        else
        {
            if(head->points > Score)
            {
                head->next = p;
                p->next = nullptr;
            }
            else
            {
                p->next = head;
                head = p;
            }
        }
    }
    else
    {
        head = new leader;
        head->nickname = Nickname;
        head->points = Score;
        head->next = nullptr;
    }
}
LeaderBoard::LeaderBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeaderBoard)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::MSWindowsFixedSizeDialogHint);
}

LeaderBoard::~LeaderBoard()
{
    delete ui;
}

void LeaderBoard::on_pushButton_2_clicked()
{
    close();
}

void LeaderBoard::on_pushButton_clicked()
{
    try
    {
        //Nickname without space and from 1 to 15
        if(spaceNickname(Nickname))
        {
            throw 1;
        }
        if(Nickname.size() > 15)
        {
            throw 2;
        }
        if(Nickname.size() <= 0)
        {
            throw 3;
        }

        addToList();
        close();
    }
    catch (int i)
    {
        if(i == 1)
        {
            QMessageBox::warning(this,"Warning!","Incorrect nickname. The nickname can not have a space in it.", QMessageBox::Ok);
        }
        if(i == 2)
        {
            QMessageBox::warning(this,"Warning!","Incorrect nickname. The nickname is too long.", QMessageBox::Ok);
        }
        if(i == 3)
        {
            QMessageBox::warning(this,"Warning!","Incorrect nickname. The nickcname can not be empty.", QMessageBox::Ok);
        }
    }

}
void LeaderBoard::on_nicknameBox_textChanged(const QString &arg1)
{
    Nickname = arg1;
}

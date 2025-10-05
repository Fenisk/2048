#include "mainmenu.h"
#include "ui_mainmenu.h"
void MainMenu::sortingLinkedList()
{
    int counter = 0;
    QFile file("leaderboard.txt");
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            counter++;
            in.readLine();
        }
        in.seek(0);
        int *score = new int [counter];
        QString *name = new QString [counter];
        for(int i = 0; i < counter; i++)
        {
            in >> name[i] >> score[i];
        }

        //sorting leaderboard
        int min_idx = 0;
        for (int i = 0; i < counter-1; i++)
        {
            min_idx = i;
            for (int j = i+1; j < counter; j++)
            {
                if (score[j] < score[min_idx])
                    min_idx = j;
            }
            int temp = score[min_idx];
            score[min_idx] = score[i];
            score[i] = temp;
            QString temp1 = name[min_idx];
            name[min_idx] = name[i];
            name[i] = temp1;
        }
        file.close();

        //creating sorted linked list
        leader *help = head;
        for(int i = counter-1; i >= 0; i--)
        {

            if(head == nullptr)
            {
                head = new leader;
                head -> nickname = name[i];
                head -> points = score[i];
                head -> next = nullptr;
                help = head;
            }
            else
            {
                leader *p = new leader;
                p -> nickname = name[i];
                p -> points = score[i];
                p -> next = nullptr;
                help -> next = p;
                help = p;
            }
        }
        delete [] score;
        delete [] name;
    }
}
leader *head = nullptr;
MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(1000, 650));
    //setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::MSWindowsFixedSizeDialogHint);

    sortingLinkedList();
}

MainMenu::~MainMenu()
{
    delete ui;
    while(head)
    {
        leader *p = head;
        head = head->next;
        delete p;
    }
}

void MainMenu::on_QuitButton_clicked()
{
    close();
}

void MainMenu::on_OptionsButton_clicked()
{
    optionsWindow = new OptionsWindow(this);
    optionsWindow->show();
    this -> hide();
}

void MainMenu::on_PlayButton_clicked()
{
    gameWindow = new GameWindow(this,false);
    gameWindow->show();
    this -> hide();
}

void MainMenu::on_LeaderBoardButton_clicked()
{
    leaderWindow = new LeaderBoardWindow(this);
    leaderWindow -> show();
}

void MainMenu::on_LoadGame_clicked()
{
    gameWindow = new GameWindow(this,true);
    gameWindow->show();
    this -> hide();
}

#include "gamewindow.h"
#include "ui_gamewindow.h"

int Score = 0;

void GameWindow::debug_check(int **tab)
{
    for(int i = 0; i < rows; i++)
    {
        for(int g = 0; g < columns; g++)
        {
            qDebug() << tab[i][g];
        }
        qDebug() << " ";
    }
}

void GameWindow::win()
{
    int ret = QMessageBox::information(this,"Congratulations!",
                                       "You win! Do you want to save your score in the leaderboard?",
                                       QMessageBox::Yes | QMessageBox::No);
    switch(ret)
    {
    case QMessageBox::Yes:
        leaderboard = new LeaderBoard(this);
        leaderboard -> show();
        break;
    case QMessageBox::No:
        break;
    }
}

void GameWindow::synchronize_board()
{
    ui -> ScoreLabel -> setText(QString::number(Score));
    /** nie pozwala aby okno z opcją wpisania nicku do tabeli
     *  wyświetliło się więcej niż jeden raz
     */
    bool one_window = false;
    for(int i = 0; i < rows; i++)
    {
        for(int g = 0; g < columns; g++)
        {
            if(tab[i][g] != 0)
            {
                QString x = QString::number(tab[i][g]);
                Button[i][g].setText(x);

                QString font = "font: Bahnschrift Light SemiCondensed; font-size: 20px;";
                //synch colors
                switch(tab[i][g])
                {
                case 2:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #BC73FF;");
                    break;
                case 4:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #BCB8FF;");
                    break;
                case 8:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #5CA6FF;");
                    break;
                case 16:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #55D53D;");
                    break;
                case 32:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #9DFF74;");
                    break;
                case 64:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #F591BB;");
                    break;
                case 128:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #FF94A2;");
                    break;
                case 256:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #FFBEA2;");
                    break;
                case 512:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #5BF0C3;");
                    break;
                case 1024:
                    Button[i][g].setStyleSheet(font + "color: black; background-color: #F8F0C3;");
                    break;
                case 2048:
                    Button[i][g].setStyleSheet(font + "color: white; background-color: #F25C05;");
                    break;
                case 4096:
                    Button[i][g].setStyleSheet(font + "color: white; background-color: rgb(0, 0, 0);");
                    break;
                default:
                    Button[i][g].setStyleSheet(font + "color: white; background-color: rgb(0, 0, 0);");
                    break;
                }
                if(x == End_Goal && one_window == false)
                {
                    one_window = true;
                    win();
                }
            }
            else
            {
                Button[i][g].setStyleSheet("font: Bahnschrift Light SemiCondensed; font-size: 20px; color: black;"
                                           "background-color: rgb(204, 204, 204)");
                Button[i][g].setText("");
            }
        }
    }

    //restarting lost game
    if(game_over(tab,columns,rows))
    {
        QMessageBox::information(this,"Game Over!","No more moves. You lost!", QMessageBox::Ok);
        for(int i = 0; i < rows; i++)
        {
            for(int g = 0; g < columns; g++)
            {
                tab[i][g] = 0;
                Button[i][g].setText("");
            }
        }
        for(int j = 0; j < 2; j++)
        {
            one_random_number(tab,Button);
        }
        synchronize_board();
        Score = 0;
    }
}

void GameWindow::one_random_number(int **tab, QPushButton **Button)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    bool random = true;
    while(random)
    {
        int x = rand()%columns;
        int y = rand()%rows;
        if(tab[x][y] == 0)
        {
            int random_4 = 1 + rand() % 8;
            if(random_4 == 1)
            {
                tab[x][y] = 4;
                Button[x][y].setText("4");
                Button[x][y].setStyleSheet("font: Bahnschrift Light SemiCondensed; font-size: 20px; color: black;"
                                           "background-color: #BCB8FF;");
            }
            else
            {
                tab[x][y] = 2;
                Button[x][y].setText("2");
                Button[x][y].setStyleSheet("font: Bahnschrift Light SemiCondensed; font-size: 20px; color: black;"
                                           "background-color: #BC73FF;");
            }
            random = false;
        }
        else
        {
            random = true;
        }
    }
}
GameWindow::GameWindow(QWidget *parent, bool load) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::MSWindowsFixedSizeDialogHint);

    rows = Size.toInt();
    columns = Size.toInt();
    Score = 0;
    ui -> ScoreLabel -> setText(QString::number(Score));

    //making dynamic buttons array
    Button = new QPushButton*[rows];
    tab = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        Button[i] = new QPushButton[columns];
        tab[i] = new int[columns];
    }
    if(load == true)
    {
        on_loadButton();
    }
    else
    {
        //creating a grid of buttons
        for(int i = 0; i < rows; i++)
        {
            for(int g = 0; g < columns; g++)
            {
                Button[i][g].setText("");
                Button[i][g].setStyleSheet("font: Bahnschrift Light SemiCondensed;"
                                        "font-size: 20px;"
                                        "color: black;"
                                        "background-color: rgb(204, 204, 204)");
                ui -> gameBoard -> addWidget(&Button[i][g],i,g);
                Button[i][g].setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
                Button[i][g].setFocusPolicy(Qt::NoFocus);
                Button[i][g].setEnabled(false);
                tab[i][g] = 0;
            }
        }

        //random 2 numbers for start of a game
        srand(static_cast <unsigned int>(time(nullptr)));
        for(int j = 0; j < 2; j++)
        {
            one_random_number(tab,Button);
        }
    }
}

void GameWindow::keyPressEvent(QKeyEvent * event)
{
    //functions in gamelogic.cpp
    if(event->key() == Qt::Key_Left)
    {
        moveToTheLeft(tab,columns,rows);
    }
    else if(event->key() == Qt::Key_Right)
    {
        moveToTheRight(tab,columns,rows);
    }
    else if(event->key() == Qt::Key_Up)
    {
        moveUp(tab,columns,rows);
    }
    else if(event->key() == Qt::Key_Down)
    {
        moveDown(tab,columns,rows);
    }
    //add new number and synchronize arrays with colors
    if(available_space(tab,columns,rows))
    {
        one_random_number(tab,Button);
    }
    synchronize_board();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_back_to_menuButton_clicked()
{
    for(int i = 0; i < rows; i++)
    {
        delete [] Button[i];
        delete [] tab[i];
    }
    delete [] Button;
    delete [] tab;
    parentWidget() -> show();
    close();
}

void GameWindow::on_loadButton()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the file", nullptr, "Text (*.txt)");
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning!", "Can not open file: " + file.errorString());
        parentWidget() -> show();
        close();
    }
    else
    {
        for(int i = 0; i < rows; i++)
        {
            delete [] Button[i];
            delete [] tab[i];
        }
        delete [] Button;
        delete [] tab;

        QTextStream in(&file);
        in >> rows >> columns >> Score >> End_Goal;
        ui -> ScoreLabel -> setText(QString::number(Score));

        //making dynamic buttons array
        Button = new QPushButton*[rows];
        tab = new int*[rows];
        for(int i = 0; i < rows; i++)
        {
            Button[i] = new QPushButton[columns];
            tab[i] = new int[columns];
        }

        for(int i = 0; i < rows; i++)
        {
            for(int g = 0; g < columns; g++)
            {
                in >> tab[i][g];
            }
        }
        synchronize_board();

        //creating a grid of buttons
        for(int i = 0; i < rows; i++)
        {
            for(int g = 0; g < columns; g++)
            {
                ui -> gameBoard -> addWidget(&Button[i][g],i,g);
                Button[i][g].setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
                Button[i][g].setFocusPolicy(Qt::NoFocus);
                Button[i][g].setEnabled(false);
            }
        }
    }
    file.close();
}

void GameWindow::on_saveButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", nullptr, "Text (*.txt)");
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning!", "Can not save file: " + file.errorString());
    }
    QTextStream out(&file);
    out << rows << " " << columns << " " << Score << " " << End_Goal << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int g = 0; g < columns; g++)
        {
            out << tab[i][g] << " ";
        }
        out << endl;
    }
    file.close();
}

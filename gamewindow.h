#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QGridLayout>
#include <QPushButton>
#include <QKeyEvent>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "leaderboard.h"
#include "gamelogic.h"
/**
 * \file gamewindow.h
 * \brief Plik nagłówkowy okna gry
 */
/// Wielkość planszy
extern QString Size;
/// Ilość punktów które musi uzyskać gracz
extern QString End_Goal;
/// Nick gracza
extern QString Nickname;
/// Ilość punktów które posiada gracz
extern int Score;

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr,bool load = false);
    ~GameWindow();

private slots:
    /** \brief Powrót do main menu.
    * Funkcja powracająca do main menu
    */
    void on_back_to_menuButton_clicked();
    /** \brief Wydarzenie naciśnięcia strzałek.
    * Funkcja odpowiednio zmieniająca planszę w zależności od ruchu gracza
    * \param *event pozwala sprawdzić jaki klawisz został wciśnięty
    */
    void keyPressEvent(QKeyEvent * event);
    /** \brief Synchronizacja planszy.
    * Funkcja synchronizująca pomocniczą tabelę z planszą
    *  wraz z dodaniem kolorów odpowiednich
    */
    void synchronize_board();
    /** \brief Debug.
    * Funkcja pozwalająca wyświetlić tablice planszy(debugowanie)
    * \param **tab wskaźnik do pierwszego wyrazu pomocniczej tablicy
    */
    void debug_check(int **tab);
    /** \brief Losowanie jeden liczby.
    * Funkcja wpisująca losową liczbę 2 lub 4 (większa szansa na 2)
    * do tabeli w pustym miejscu
    * \param **tab wskaźnik do pierwszego wyrazu pomocniczej tablicy
    * \param **Button wskaźnik do pierwszego przycisku planszy
    */
    void one_random_number(int **tab, QPushButton **Button);
    /** \brief Odczyt.
    * Funkcja odpowiednio przygotowująca planszę po odczycie zapisu z pliku
    */
    void on_loadButton();
    /** \brief Zapis.
    * Funkcja pozwalająca zapisać stan gry do pliku txt
    */
    void on_saveButton_clicked();
    /** \brief Wygrana.
    * Funkcja w przypadku wygranej wyświetla opcję
    * wpisania nicku do tabeli wyników
    */
    void win();

private:
    /// \internal
    Ui::GameWindow *ui;
    /// Wskaźnik do okna wpisywania nicku do rankingu
    LeaderBoard *leaderboard;
    /// Wiersze tabeli pomocniczej
    int rows;
    /// Kolumny tabeli pomocniczej
    int columns;
    /// Wskaźnik do planszy
    QPushButton **Button = nullptr;
    /// Wskaźnik do tabeli pomocniczej
    int **tab = nullptr;
};

#endif // GAMEWINDOW_H

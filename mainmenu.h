#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QDebug>
#include "optionswindow.h"
#include "gamewindow.h"
#include "struct.h"
#include "leaderboardwindow.h"
/**
 * \mainpage
 * \par Gra 2048
 * Gra 2048 z możliwością wyboru wielkości planszy oraz z rankingiem graczy
 * \author Artur Broński
 * \date 14.06.2020
 * \version 1.0
 */

/**
 * \file mainmenu.h
 * \brief Plik nagłówkowy okna głównego menu
 */
/// Wielkość planszy
extern QString Size;
/// Ilość punktów które musi uzyskać gracz
extern QString End_Goal;
/// Wskaźnik do listy z tabelą wyników
extern leader *head;

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    /** \brief Guzik Quit.
    * Funkcja wychodząca z programu
    */
    void on_QuitButton_clicked();
    /** \brief Guzik Options.
    * Funkcja wchodząca do opcji
    */
    void on_OptionsButton_clicked();
    /** \brief Guzik Play.
    * Funkcja rozpoczynająca grę
    */
    void on_PlayButton_clicked();
    /** \brief Guzik Leaderboard.
    * Funkcja wchodząca do tabeli najlepszych wyników
    */
    void on_LeaderBoardButton_clicked();
    /** \brief Guzik Load.
    * Funkcja pozwalająca wczytać zapisaną grę
    */
    void on_LoadGame_clicked();
    /** \brief Sortowanie Listy.
     * Funkcja wpisująca oraz sortująca dane z
     * pliku do listy jednokierunkowej
     */
    void sortingLinkedList();
private:
    /// \internal
    Ui::MainMenu *ui;
    /// Wskaźnik do okna opcji
    OptionsWindow *optionsWindow;
    /// Wksaźnik do okna gry
    GameWindow *gameWindow;
    /// Wksaźnik do okna rankingu
    LeaderBoardWindow *leaderWindow;
};
#endif // MAINWINDOW_H

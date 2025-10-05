#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include "struct.h"
/**
 * \file leaderboard.h
 * \brief Plik nagłówkowy okna do wpisania nicku do tabeli
 */
/// Nick gracza
extern QString Nickname;
/// Ilość punktów które posiada gracz
extern int Score;
/// Wskaźnik do listy z tabelą wyników
extern leader *head;

namespace Ui {
class LeaderBoard;
}

class LeaderBoard : public QDialog
{
    Q_OBJECT

public:
    explicit LeaderBoard(QWidget *parent = nullptr);
    ~LeaderBoard();

private slots:
    /** \brief Przycisk wyjścia
    * Funkcja wychodząca
    */
    void on_pushButton_2_clicked();
    /** \brief Zapis do tabeli
    * Funkcja zapisująca nazwę oraz wynik gracza w odpowiednim miejscu listy dynamicznej
    */
    void on_pushButton_clicked();
    /** \brief Spacja w nikcu
     * Funkcja sprawdzająca czy nick zawiera spację
    * \param nick nick gracza
    * \return true jeżeli nick zawiera spację, false jeżeli jej nie zawiera
    */
    bool spaceNickname(QString nick);
    /**
     * \brief Zmiana nicku.
     * Funkcja wpisaująca do zmiennej QString nick gracza po zmianie tekstu w polu
     * \param &arg1 zmienna do której wpisywana jest wartość
     */
    void on_nicknameBox_textChanged(const QString &arg1);
    /**
     * \brief Dodaj do listy.
     * Funkcja dodająca w odpowiednie miejsce nowy wynik do listy jednokierunkowej
     */
    void addToList();
private:
    /// \internal
    Ui::LeaderBoard *ui;

};

#endif // LEADERBOARD_H

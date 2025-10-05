#ifndef LEADERBOARDWINDOW_H
#define LEADERBOARDWINDOW_H

#include <QDialog>
#include "struct.h"
/**
 * \file leaderboardwindow.h
 * \brief Plik nagłówkowy okna tabeli wyników
 */
/// Wskaźnik do listy z tabelą wyników
extern leader *head;
namespace Ui {
class LeaderBoardWindow;
}

class LeaderBoardWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LeaderBoardWindow(QWidget *parent = nullptr);
    ~LeaderBoardWindow();

private:
    /// \internal
    Ui::LeaderBoardWindow *ui;
    /** \brief Uzupełnienie.
    * Funkcja uzupełniająca tabelę wyników 10 najwyższymi wynikami
    * \param *&help pomocnicza do listy dynamicznej
    * \param i miejsce z kolei
    */
    void complete(leader *&help, int i);
};

#endif // LEADERBOARDWINDOW_H

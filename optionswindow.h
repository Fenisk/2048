#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
/**
 * \file optionswindow.h
 * \brief Plik nagłówkowy okna opcji
 */
/// Wielkość planszy
extern QString Size;
/// Ilość punktów które musi uzyskać gracz
extern QString End_Goal;

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsWindow(QWidget *parent = nullptr);
    ~OptionsWindow();

private slots:
    /// \par Funkcje
    /** \brief Guzik Back to menu.
    * Funkcja powracająca do main menu
    */
    void on_backToMenu_clicked();
    /** \brief Zmiana tekstu wielkości planszy.
    * Funkcja wpisująca do zmiennej QString informację o wielkości
    * \param &arg1 zmienna do której wpisywany jest rozmiar planszy
    */
    void on_boardSize_textChanged(const QString &arg1);
    /** \brief Guzik Apply.
    * Funkcja potwierdzająca wybrane opcje
    */
    void on_applyButton_clicked();
    /** \brief Zmiana tekstu końcowego wyniku.
    * Funkcja wpisująca do zmiennej QString informację o końcowym wyniku
    * jaki gracz musi uzyskać aby wygrać
    * \param &arg1 zmienna do której wpisywany jest końcowy wynik jaki gracz musi uzyksać
    */
    void on_endGoal_textChanged(const QString &arg1);

private:
    /// \internal
    Ui::OptionsWindow *ui;
};

#endif // OPTIONSWINDOW_H

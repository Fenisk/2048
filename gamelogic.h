#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <QString>
/**
  * \file gamelogic.h
  * \brief Plik nagłówkowy głównych funkcji.
  * Definicje głównych funkcji sterujących logiką gry
  */
/// Ilość punktów które posiada gracz
extern int Score;

//functions
/** \brief Dostępne miejsce.
* Funkcja sprawdzająca czy istnieje miejsce dla następnego numeru,
* który ma się pojawić
* \param **tab wskaźnik do pierwszego wyrazu pomocniczej tablicy
* \param columns ilość kolumn na planszy
* \param rows ilość wierszy na planszy
* \return wartość true dla dostępnego miejsca, false dla niedostępnego miejsca
*/
bool available_space(int **tab, int columns, int rows);
/** \brief Przegrana.
* Funkcja sprawdzająca czy gracz przegrał grę
* \param **tab wskaźnik do pierwszego wyrazu pomocniczej tablicy
* \param columns ilość kolumn na planszy
* \param rows ilość wierszy na planszy
* \return wartość true dla przegranej gracza
*/
bool game_over(int **tab, int columns, int rows);
/** \brief Porusz w lewo.
* Funkcja poruszająca wszystkie elementy w lewo wraz
* z ich sumowaniem w przypadku gdy obie liczby się równają
* \param **tab wskaźnik do pierwszego wyrazu pomocniczej tablicy
* \param columns ilość kolumn na planszy
* \param rows ilość wierszy na planszy
* \see moveToTheRight(int **tab, int columns, int rows)
* \see moveUp(int **tab, int columns, int rows)
* \see moveDown(int **tab, int columns, int rows)
*/
void moveToTheLeft(int **tab, int columns, int rows);
/** \brief Porusz w prawo.
* Funkcja poruszająca wszystkie elementy w prawo wraz
* z ich sumowaniem w przypadku gdy obie liczby się równają
* \param **tab wskaźnik do pierwszego wyrazu pomocniczej tablicy
* \param columns ilość kolumn na planszy
* \param rows ilość wierszy na planszy
* \see moveToTheLeft(int **tab, int columns, int rows)
* \see moveUp(int **tab, int columns, int rows)
* \see moveDown(int **tab, int columns, int rows)
*/
void moveToTheRight(int **tab, int columns, int rows);
/** \brief Porusz do góry.
* Funkcja poruszająca wszystkie elementy do góry wraz
* z ich sumowaniem w przypadku gdy obie liczby się równają
* \param **tab wskaźnik do pierwszego wyrazu pomocniczej tablicy
* \param columns ilość kolumn na planszy
* \param rows ilość wierszy na planszy
* \see moveToTheRight(int **tab, int columns, int rows)
* \see moveToTheLeft(int **tab, int columns, int rows)
* \see moveDown(int **tab, int columns, int rows)
*/
void moveUp(int **tab, int columns, int rows);
/** \brief Porusz w dół.
* Funkcja poruszająca wszystkie elementy w dół wraz
* z ich sumowaniem w przypadku gdy obie liczby się równają
* \param **tab wskaźnik do pierwszego wyrazu pomocniczej tablicy
* \param columns ilość kolumn na planszy
* \param rows ilość wierszy na planszy
* \see moveToTheRight(int **tab, int columns, int rows)
* \see moveToTheLeft(int **tab, int columns, int rows)
* \see moveUp(int **tab, int columns, int rows)
*/
void moveDown(int **tab, int columns, int rows);

#endif // GAMELOGIC_H

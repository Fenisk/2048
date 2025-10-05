#ifndef STRUCT_H
#define STRUCT_H
#include <QString>
/**
  * \file struct.h
  * \brief Lista jednokierunkowa.
  *
  * Definicja listy dynamicznej dla rankingu
  */
//leaderboard linked list
struct leader
{
    /// Nick osoby
    QString nickname;
    /// Punkty zdobyte przez daną osobę
    int points;
    /// Wskaźnik na następny element
    leader *next;
};

#endif // STRUCT_H

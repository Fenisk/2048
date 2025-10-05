#include "gamelogic.h"

bool available_space(int **tab, int columns, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int g = 0; g < columns; g++)
        {
            if(tab[i][g] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool game_over(int **tab, int columns, int rows)
{
    bool game_over = true;

    //checking if there is space for another number
    for(int i = 0; i < rows; i++)
    {
        for(int g = 0; g < columns; g++)
        {
            if(tab[i][g] == 0)
            {
                game_over = false;
                break;
            }
        }
        if(!game_over) break;
    }

    //checking if there is an available move
    if(game_over)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int g = 0; g < columns; g++)
            {
                if(g == columns-1 && i != rows-1)
                {
                    if(tab[i][g] == tab[i+1][g])
                        game_over = false;
                }
                else if(i == rows-1 && g != columns-1)
                {
                    if(tab[i][g] == tab[i][g+1])
                        game_over = false;
                }
                else if(i == rows-1 && g == columns-1)
                {
                    break;
                }
                else
                {
                    if(tab[i][g] == tab[i][g+1] || tab[i][g] == tab[i+1][g])
                        game_over = false;
                }
            }
        }
    }
    return game_over;
}

void moveToTheLeft(int **tab, int columns, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int g = 0; g < columns; g++)
        {
            if(tab[i][g] != 0)
            {
                for(int j = g; j > 0; j--)
                {
                    if(tab[i][j-1] == 0)
                    {
                        int help = tab[i][j-1];
                        tab[i][j-1] = tab[i][j];
                        tab[i][j] = help;
                    }
                    else if((tab[i][j-1] != 0) && (tab[i][j-1] != tab[i][j]))
                    {
                        break;
                    }
                    else if(tab[i][j-1] == tab[i][j])
                    {
                        tab[i][j-1] = tab[i][j-1] * 2;
                        Score += tab[i][j-1];
                        tab[i][j] = 0;
                    }
                }
            }
        }
    }
}

void moveToTheRight(int **tab, int columns, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int g = columns-1; g >= 0; g--)
        {
            if(tab[i][g] != 0)
            {
                for(int j = g; j < columns-1; j++)
                {
                    if(tab[i][j+1] == 0)
                    {
                        int help = tab[i][j+1];
                        tab[i][j+1] = tab[i][j];
                        tab[i][j] = help;
                    }
                    else if((tab[i][j+1] != 0) && (tab[i][j+1] != tab[i][j]))
                    {
                        break;
                    }
                    else if(tab[i][j+1] == tab[i][j])
                    {
                        tab[i][j+1] = tab[i][j+1] * 2;
                        Score += tab[i][j+1];
                        tab[i][j] = 0;
                    }
                }
            }
        }
    }
}

void moveUp(int **tab, int columns, int rows)
{
    for(int g = 0; g < columns; g++)
    {
        for(int i = 0; i < rows; i++)
        {
            if(tab[i][g] != 0)
            {
                for(int j = i; j > 0; j--)
                {
                    if(tab[j-1][g] == 0)
                    {
                        int help = tab[j-1][g];
                        tab[j-1][g] = tab[j][g];
                        tab[j][g] = help;
                    }
                    else if((tab[j-1][g] != 0) && (tab[j-1][g] != tab[j][g]))
                    {
                        break;
                    }
                    else if(tab[j-1][g] == tab[j][g])
                    {
                        tab[j-1][g] = tab[j-1][g] * 2;
                        Score += tab[j-1][g];
                        tab[j][g] = 0;
                    }
                }
            }
        }
    }
}

void moveDown(int **tab, int columns, int rows)
{
    for(int g = 0; g < columns; g++)
    {
        for(int i = rows-1; i >= 0; i--)
        {
            if(tab[i][g] != 0)
            {
                for(int j = i; j < rows-1; j++)
                {
                    if(tab[j+1][g] == 0)
                    {
                        int help = tab[j+1][g];
                        tab[j+1][g] = tab[j][g];
                        tab[j][g] = help;
                    }
                    else if((tab[j+1][g] != 0) && (tab[j+1][g] != tab[j][g]))
                    {
                        break;
                    }
                    else if(tab[j+1][g] == tab[j][g])
                    {
                        tab[j+1][g] = tab[j+1][g] * 2;
                        Score += tab[j+1][g];
                        tab[j][g] = 0;
                    }
                }
            }
        }
    }
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// constante das pontuações
const int PONTUACOES[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// protótipos
int calcular_pontuacao(string palavra);

int main(void)
{

    string palavra1 = get_string("Jogador 1: ");
    string palavra2 = get_string("Jogador 2: ");

    int scorejogador1 = calcular_pontuacao(palavra1);
    int scorejogador2 = calcular_pontuacao(palavra2);

    if (scorejogador1 > scorejogador2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (scorejogador1 == scorejogador2)
    {
        printf("Tie!\n");
    }
    else
        printf("Player 2 Wins!\n");
}

int calcular_pontuacao(string palavra)
{

    int score = 0;

    for (int i = 0; i < strlen(palavra); i++)
    {
        if (isupper(palavra[i]))
        {
            score = score + PONTUACOES[palavra[i] - 65];
        }
        else if (islower(palavra[i]))
        {
            score = score + PONTUACOES[palavra[i] - 97];
        }
    }

    return score;
}

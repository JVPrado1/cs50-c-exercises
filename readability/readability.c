#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int contar_letras(string frase);
int contar_sentencas(string frase);
int contar_palavras(string frase);
float calcular_L(int letras, int palavras);
float calcular_S(int sentencas, int palavras);

int main(void)
{
    string frase = get_string("Digite uma frase: ");

    int quantidade_letras = contar_letras(frase);
    int quantidade_sentencas = contar_sentencas(frase);
    int quantidade_palavras = contar_palavras(frase);
    float L = calcular_L(quantidade_letras, quantidade_palavras);
    float S = calcular_S(quantidade_sentencas, quantidade_palavras);

    float media = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (media < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (media >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", media);
    }
}

int contar_letras(string frase)
{
    int quantidade = 0;

    for (int i = 0; i < strlen(frase); i++)
    {
        if (isalpha(frase[i]))
        {
            quantidade++;
        }
    }
    return quantidade;
}

int contar_sentencas(string frase)
{
    int sentencas = 0;

    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] == '.' || frase[i] == '!' || frase[i] == '?')
        {
            sentencas++;
        }
    }
    return sentencas;
}

int contar_palavras(string frase)
{
    int palavras = 1; // Começa com 1 pois a última palavra não tem espaço depois

    for (int i = 0; i < strlen(frase); i++)
    {
        if (frase[i] == ' ' && frase[i + 1] != ' ')
        {
            palavras++;
        }
    }
    return palavras;
}

float calcular_L(int letras, int palavras)
{
    return (float) letras / palavras * 100;
}

float calcular_S(int sentencas, int palavras)
{
    return (float) sentencas / palavras * 100;
}

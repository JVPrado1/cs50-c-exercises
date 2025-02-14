#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int change);
int calculate_nickels(int change);
int calculate_pennies(int change);

int main(void)
{
    int change;
    int qntd_quarters = 0;
    int qntd_dimes = 0;
    int qntd_nickels = 0;
    int qntd_pennies = 0;
    int qntd_moedas = 0;

    // prompt user a int number > 0
    do
    {
        change = get_int("Change owed: ");
        printf("%i\n", change);
    }
    while (change < 0);

    do
    {
        if (change >= 25)
        {
            qntd_quarters = calculate_quarters(change);
            change = change - (qntd_quarters * 25);
        }
        else if (change >= 10 && change < 25)
        {
            qntd_dimes = calculate_dimes(change);
            change = change - (qntd_dimes * 10);
        }
        else if (change >= 5)
        {
            qntd_nickels = calculate_nickels(change);
            change = change - (qntd_nickels * 5);
        }
        else if (change >= 1 && change <= 5)
        {
            qntd_pennies = calculate_pennies(change);
            change = change - (qntd_pennies * 1);
        }
        else
        {
            break;
        }
    }
    while (change > 0);
    qntd_moedas = qntd_quarters + qntd_dimes + qntd_nickels + qntd_pennies;
    printf("Troco sobra: %i\n Numero de moedas: %i\n", change, qntd_moedas);
}

// função cents
int calculate_quarters(int change)
{
    int i = 0;
    for (i = 0; change >= 25; i++)
    {
        change = change - 25;
    }
    return i;
}

// função dimes

int calculate_dimes(int change)
{
    int i = 0;
    for (i = 0; change >= 10; i++)
    {
        change = change - 10;
    }
    return i;
}

// função nickels

int calculate_nickels(int change)
{
    int i = 0;
    for (i = 0; change >= 5; i++)
    {
        change = change - 5;
    }
    return i;
}

// função pennies
int calculate_pennies(int change)
{
    int i = 0;
    for (i = 0; change >= 1; i++)
    {
        change = change - 1;
    }
    return i;
}

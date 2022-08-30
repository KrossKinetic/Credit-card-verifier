#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{


    long CDNUM;
    CDNUM = get_long("Enter the card number: ");
    int CDLen = 0;
    long CardNumberPH = CDNUM;
    while (CardNumberPH != 0)
    {
        CardNumberPH = CardNumberPH / 10;
        CDLen++;
    }
    CardNumberPH = CDNUM;
    int FirstSum = 0;
    int SecondSum = 0;
    int digit;
    int LDigit;
    int L2Digit;
    int CDSwitch;

    if (CDLen == 16)
    {
        CDSwitch = 15;
    }
    else if (CDLen == 15)
    {
        CDSwitch = 13;
    }
    else
    {
        CDSwitch = 11;
    }

    CardNumberPH = CDNUM;
    for (int i = 0 ; i < CDSwitch ; i += 2)
    {
        CardNumberPH = CardNumberPH / 10;
        digit = (CardNumberPH % 10) * 2;
        FirstSum = FirstSum + digit / 10 + digit % 10;
        CardNumberPH = CardNumberPH / 10;
        if (i == CDSwitch - 3)
        {
            if (CDLen == 16)
            {
                L2Digit = CardNumberPH;
                LDigit = L2Digit / 10;
            }
            else if (CDLen == 15)
            {
                L2Digit = CardNumberPH / 10;
                LDigit = L2Digit / 100;
            }
            else
            {
                L2Digit = CardNumberPH / 10;
                LDigit =  L2Digit / 10;
            }
        }
    }

    CardNumberPH = CDNUM;
    for (int i = 0 ; i < (CDSwitch - 1) ; i++)
    {
        SecondSum = SecondSum + CardNumberPH % 10;
        CardNumberPH = CardNumberPH / 10;
        CardNumberPH = CardNumberPH / 10;
    }

    int TotalSum = FirstSum + SecondSum;
    if (TotalSum % 10 == 0)
    {
        if (LDigit == 4)
        {
            printf("VISA\n");
        }
        else if (L2Digit == 51  || L2Digit == 52 || L2Digit == 53 || L2Digit == 54 || L2Digit == 55 || L2Digit == 22)
        {
            printf("MASTERCARD\n");
        }
        else if (L2Digit == 37 || L2Digit == 34)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

#include <cs50.h>
#include <math.h>
#include <stdio.h>
int main(void)
{ 
    // Ask for input
    long long cardnumber;
    do
    {
        cardnumber = get_long_long("Number: ");
    }
    while (cardnumber < 0);
    //Count the number of digits 
    int count = 0;
    long long i = cardnumber;
    while (i > 0)
    {
        i = i / 10;
        count++;
    }
    //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together. Add the sum to the sum of the digits that weren’t multiplied by 2.
    long long j = cardnumber;
    int sum1 = 0; 
    int remainder1;
    int remainder0;
    while (j != 0)
    {
        remainder1 = 2 * ((j % 100) / 10);
        remainder0 = remainder1 % 10 + round(remainder1 / 10);
        sum1 = sum1 + remainder0 ;
        j = j / 100;
    }
    //Add the sum to the sum of the digits that weren’t multiplied by 2.
    long long k = cardnumber;
    int sum2 = 0; 
    int remainder2;
    while (k != 0)
    {
        remainder2 = k % 10;
        sum2 = sum2 + remainder2;
        k = k / 100;
    }
    int checksum = sum1 + sum2;
    //If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (checksum % 10 == 0 && count == 15 && (floor(cardnumber / 10000000000000) == 37 || floor(cardnumber / 10000000000000) == 34))
    {
        printf("AMEX\n");
    }
    else if (checksum % 10 == 0 && count == 13 && floor(cardnumber / 1000000000000) == 4)
    {
        printf("VISA\n");
    }
    else if (checksum % 10 == 0 && count == 16 && floor(cardnumber / 1000000000000000) == 4)
    {
        printf("VISA\n");
    }
    else if (checksum % 10 == 0 && count == 16 && (floor(cardnumber / 100000000000000) == 51 || floor(cardnumber / 100000000000000) == 52 || floor(cardnumber / 100000000000000) == 53 || floor(cardnumber / 100000000000000) == 54 || floor(cardnumber / 100000000000000) == 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get user's input
    int n;
    do
    
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //print the result

    //count rows
    for (int i = 0; i < n; i++)
    {
        //count spaces
        for (int j = 0; j < n; j++)
        {
            //first part of the row
            if (j < n - i - 1)
            {
                printf(" ");
            }
            //second part of the row
            else
            {
                printf("#");
            }
        }
        printf("\n");
    } 
}

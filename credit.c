#include <stdio.h>
#include <cs50.h>

int main (void)
{
    long long number, temp, temp_2;
    int sum_1, sum_2, control_sum;

    // get user's CC number ;)
    do
    {

        number = get_long("Number:");
    }
    while ( number < 0 );

    // sum every other digit starting w/ the the last. Сумма всех остальных чисел, не участвующих в подсчёте контрольной суммы, начиная с последнего числа.
    for ( temp = number, sum_1 = 0; temp > 0; temp /= 100 )
        sum_1 += temp % 10;

    // double every other digit starting w/ 2nd to last. Перемножение чисел, начиная со второго с конца на 2.
    // then sum the individual digits of these products. Затем прибавление отдельных цифр из полученных чисел.
    for ( temp_2 = number / 10, sum_2 = 0; temp_2 > 0; temp_2 /= 100 )
    {
        if ( 2 * (temp_2 % 10) > 9 )
        {
            sum_2 += (2 * (temp_2 % 10)) / 10;
            sum_2 += (2 * (temp_2 % 10)) % 10;
        }
        else
            sum_2 += 2 * (temp_2 % 10);
    }
    //Подсчёт контрольной суммы.
    control_sum = sum_1 + sum_2;

    // check to see if the CC number is in the appropriate range. Проверка диапазонов и первых цифр в номерах валидных карт.
    if ( control_sum % 10 == 0 )
    {
        if ( (number >= 340000000000000 && number < 350000000000000) || (number >= 370000000000000 && number < 380000000000000) )
            printf("AMEX\n");
        else if ( number >= 5100000000000000 && number < 5600000000000000 )
            printf("MASTERCARD\n");
        else if ( (number >= 4000000000000 && number < 5000000000000) || (number >= 4000000000000000 && number < 5000000000000000) )
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");

    return 0;
}

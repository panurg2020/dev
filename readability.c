#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float letter;
int word=1;
float sentence;


int main(void)
{

// prompt the user with the question

    string article = get_string("What's the article?: ");

// set the length of article

    int n = strlen(article);

// counting

    for (int i = 0; i < n;  i++)
    {
        // count letters

        if (isalnum(article[i]))
        {
            letter++;
        }

        // count words

        if (i < n-1 && isspace(article[i]) )                                 //&& ( isalnum(article[i + 1]) || isascii(article[i+1])) ) - old version
        {
            word++;
        }

        // count sentences

        if (i > 0 && (article[i] == '!' || article[i] == '?' || article[i] == '.') && isalnum(article[i - 1]))
        {
            sentence++;
        }

    }

// calculate Coleman-Liau index

    double a = (float)(letter / word);
    double b = (float)(sentence / word);
    int grade = round(5.88 * a - 29.6 * b - 15.8);

// debugger

 printf("Letters: %lf\n Words: %i\n Sentences: %lf\n", letter, word, sentence);

// print result
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

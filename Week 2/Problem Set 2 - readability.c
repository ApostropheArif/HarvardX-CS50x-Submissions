#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    // Calculating statistics of the text provided.
    int total_letters = count_letters(text);
    int total_words = count_words(text);
    int total_sent = count_sentences(text);

    // Calculating Coleman-Liau index.
    float L = total_letters / (float) total_words * 100;
    float S = total_sent / (float) total_words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Determining final grade level.
    int final_grade = (int) round(index);

    // Printing grade level.
    if (final_grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (final_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", final_grade);
    }

}

int count_letters(string text)
{
    int textlen = strlen(text);
    int letters_count = 0; // Initialising a counter for letters.
    for (int i = 0; i < textlen; i++)
    {
        if isalpha(text[i])
        {
            letters_count ++;
        }
    }
    return letters_count;
}

int count_words(string text)
{
    int textlen = strlen(text);
    int words_count = 1; // Initialising a counter for words, starts at 1 because a word already exists prior to the first space.
    for (int i = 0; i < textlen; i++)
    {
        if (text[i] == ' ') // Words are defined as groups of letters separated by a space.
        {
            words_count ++;
        }
    }
    return words_count;
}

int count_sentences(string text)
{
    int textlen = strlen(text);
    int sent_count = 0;
    for (int i = 0; i < textlen; i++)
    {
        if (text[i] == '.' || text[i] == '!'
            || text[i] == '?') // Sentences are defined as groups of words separated by a period, exclamation mark or question mark.
        {
            sent_count ++;
        }
    }
    return sent_count;
}

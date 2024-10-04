//status: completed - uploaded
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float L(string text);
float S(string text);
int main(void)
{
    // Prompt the user for some text
    string text = get_string("Upload text you would like assessed: ");

    // Compute the Coleman-Liau index
    const double index = 0.0588 * L(text) - 0.296 * S(text) - 15.8;

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}
// Count the number of letters, words, and sentences in the text
// Count the number of letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// count the number of words
int count_words(string text)
{
    int spaces = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            spaces++;
        }
    }
    return spaces = spaces + 1;
}

// count the number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

// Function to calculate the average letters per 100 words
float L(string text)
{
    int letters = count_letters(text);
    int words = count_words(text);

    if (words == 0)
    {
        return 0; // Avoid division by zero
    }

    double average = (double) letters / words * 100; // Calculate average per 100 words
    return (average);                                // Round up and return as float
}

// Function to calculate the average sentences per 100 words
float S(string text)
{
    int sentences = count_sentences(text);
    int words = count_words(text);

    if (words == 0)
    {
        return 0; // Avoid division by zero
    }

    double average = (double) sentences / words * 100; // Calculate average per 100 words
    return (average);                                  // Round up and return as float
}

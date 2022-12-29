#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30

int getword(char w[])
{

    int count = 0;

    for (int i = 0; i < WORD; i++)
    {
        scanf("%c", &w[i]);

        if (w[i] != ' ' && w[i] != '\n' && w[i] != '\t')
        {
            count++;
        }
    }
    return count;
}

int substring(char *str1, char *str2)
{

    int index = 0;

    if (strlen(str2) > strlen(str1))
    {
        return 0;
    }
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] == str2[index])
        {
            index++;
            if (index == strlen(str2))
            {
                return 1;
            }
        }
        else
        {
            index = 0;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n)
{

    int index = 0;
    int skip = 0;

    if (strlen(t) > strlen(s))
    {
        return 0;
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == t[index])
        {
            index++;
        }
        else
        {
            skip++;
        }
    }
    if (skip == n && index == strlen(t))
    {
        return 1;
    }
    return 0;
}

int get_line(char s[])
{
    int count = 0;
    for (int i = 0; i < LINE; i++)
    {
        scanf("%c", &s[i]);
        count++;
        if (s[i] == '\n')
        {
            break;
        }
    }
    s[count + 1] = '\0';

    return count + 1;
}

void print_lines(char *str)
{
    char line[LINE] = {'\0'};
    for (int i = 0; i < 250; i++)
    {
        if (get_line(line) == 0)
        {
            break;
        }
        if (substring(line, str) == 1)
        {
            printf("%s", line);
        }
    }
}

void print_similar_words(char *str)
{
    char line[LINE] = {'\0'};
    char word[WORD] = {'\0'};
    int size = 0;
    int j = 0;

    for (int i = 0; i < 256; i++)
    {
        if (get_line(line) == 0)
        {
            break;
        }
        if (substring(line, str) == 1)
        {
            j = 0;
            size = 0;
            while (line[j] != '\0')
            {
                if (line[j] == ' '  || line[j] == '\n')
                {
                    if (similar(word, str, 1) == 1)
                    {
                        printf("%s\n", word);
                    }
                    if (similar(word, str, 0) == 1)
                    {
                        printf("%s\n", word);
                    }
                    bzero(word, WORD);
                    size = 0;
                }
                else
                {
                    word[size] = line[j];
                    size++;
                }
                j++;
                if (j == strlen(line))
                {
                    if (similar(word, str, 1) == 1)
                    {
                        printf("%s\n", word);
                        size = 0;
                    }
                    if (similar(word, str, 0) == 1)
                    {
                        printf("%s\n", word);
                        size = 0;
                    }
                }
            }
        }
    }
}

int main()
{
    char word[WORD]; // String
    char ans;
    scanf("%s %c", word, &ans);
    if (ans == 'a')
    {
        print_lines(word);
    }
    if (ans == 'b')
    {
        print_similar_words(word);
    }
    return 0;
}

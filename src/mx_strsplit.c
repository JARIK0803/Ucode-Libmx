#include "../inc/libmx.h"

static int count_letters(const char *s, char c)
{
    int i = 0;

    while (s[i] != c && s[i])
    {
        i++;
    }

    return i;
}

char **mx_strsplit(const char *s, char c)
{
    if (!s)
    {
        return NULL;
    }

    char **arr = (char **)malloc(sizeof(char *) * (mx_count_words(s, c) + 1));
    int word_len = 0;
    int i = 0;

    while ((*s) && (*s != '\0'))
    {
        if (*s != c)
        {
            word_len = count_letters(s, c);
            arr[i++] = mx_strndup(s, word_len);
            s += word_len;
            continue;
        }
        s++;
    }
    arr[i] = NULL;
    
    return arr;
}

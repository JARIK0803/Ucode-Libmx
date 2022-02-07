#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }
    
    char *tmp = mx_strnew(mx_strlen(str));

    int x = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!mx_isspace(str[i]))
        {
            tmp[x++] = str[i];
        }
        if ((!mx_isspace(str[i])) && mx_isspace(str[i + 1]))
        {
            tmp[x++] = ' ';
        }
    }

    char *result = mx_strtrim(tmp);
    mx_strdel(&tmp);

    return result;
}

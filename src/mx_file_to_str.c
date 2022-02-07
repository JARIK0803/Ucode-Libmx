#include "../inc/libmx.h"

static int get_file_len(const char *file)
{
    short fl = open(file, O_RDONLY);
    int len = 0;
    char buf;

    while (read(fl, &buf, 1) > 0)
    {
        len++;
    }
    close(fl);

    return len;
}

char *mx_file_to_str(const char *file)
{
    int fl = open(file, O_RDONLY);
    int file_len = 0;

    if (fl == -1)
    {
        close(fl);
        return NULL;
    }

    file_len = get_file_len(file);
    if (file_len == 0)
    {
        return NULL;
    }

    char *str = mx_strnew(file_len);
    read(fl, str, file_len);
    close(fl);

    return str;
}

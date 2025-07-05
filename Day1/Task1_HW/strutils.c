#include "strutils.h"

void str_reverse(char *str)
{
    if (!str)
        return;

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void str_trim(char *str)
{
    if (!str)
        return;

    char *start = str;
    while (*start == ' ')
        start++;

    char *end = str + strlen(str) - 1;
    while (end > start && *end == ' ')
        end--;

    *(end + 1) = '\0';

    memmove(str, start, end - start + 2);
}

int str_to_int(const char *str, int *out_num)
{
    if (!str || !out_num)
        return -1;

    long long result = 0; // dùng kiểu lớn hơn int
    int sign = 1;

    while (*str == ' ' || *str == '\t')
        str++;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
    {
        str++;
    }

    if (*str < '0' || *str > '9')
        return -1;

    while (*str >= '0' && *str <= '9')
    {
        int digit = *str - '0';
        result = result * 10 + digit;
        str++;
    }

    result *= sign;

    // Kiểm tra sau khi hoàn tất
    if (result < INT_MIN || result > INT_MAX)
        return -1;

    if (*str != '\0')
        return -1;

    *out_num = (int)result;
    return 0;
}
#include "strutils.h"

int main()
{
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    str_reverse(str);
    printf("Reversed string: %s\n", str);

    char str2[] = "   ";
    printf("Original string with spaces: '%s'\n", str2);
    str_trim(str2);
    printf("Trimmed string: '%s'\n", str2);

    char str3[] = "-12345";
    int num;
    int result = str_to_int(str3, &num);
    if (result == 0)
    {
        printf("Converted string to integer: %d\n", num);
    }
    else
    {
        printf("Failed to convert string to integer.\n");
    }
    return 0;
}
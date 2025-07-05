#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void print_file_type(mode_t mode)
{
    if (S_ISREG(mode))
    {
        printf("File Type: Regular File\n");
    }
    else if (S_ISDIR(mode))
    {
        printf("File Type: Directory\n");
    }
    else if (S_ISLNK(mode))
    {
        printf("File Type: Symbolic Link\n");
    }
    else
    {
        printf("File Type: Other\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) // Nếu người dùng không truyền đúng 1 đối số (bên cạnh tên chương trình), thì...
    {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return -1;
    }

    const char *file_path = argv[1];
    struct stat st;

    if (lstat(file_path, &st) == -1)
    {
        perror("lstat");
        return -1;
    }

    // In đường dẫn
    printf("File Path: %s\n", file_path);

    // In loại file
    print_file_type(st.st_mode);

    // In kích thước
    printf("Size: %lld bytes\n", (long long)st.st_size);

    // In thời gian sửa đổi cuối cùng
    char timebuf[100];
    struct tm *tm_info = localtime(&st.st_mtime);
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last Modified: %s\n", timebuf);

    return 0;
}

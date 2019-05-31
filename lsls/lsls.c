#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

/**
 * print_entries
 * accepts a pointer to a DIR, string with path to that dir, and an offset string and prints contents of the directory
 */
int print_entries(DIR *dir, char *path, char *ofst)
{
    // Repeatedly read and print entries
    struct dirent *dent;
    struct stat buf;
    char file_w_path[1024];
    while ((dent = readdir(dir)) != NULL)
    {
        strcpy(file_w_path, path);
        strcat(file_w_path, dent->d_name);
        // printf("FWP: %s\n", file_w_path);
        stat(file_w_path, &buf);
        if (buf.st_mode & S_IFDIR)
        {
            printf("%s    <DIR>  ", ofst);
            printf("%s\n", dent->d_name);
            // print contents of directory if we encounter one
            // only if we're 1 layer deep
            if (strlen(ofst) == 0)
            {
                DIR *dir2 = opendir(file_w_path);
                strcat(file_w_path, "/");
                print_entries(dir2, file_w_path, "       ");
                closedir(dir2);
            }
        }
        else
        {
            printf("%s%9lld  ", ofst, buf.st_size);
            printf("%s\n", dent->d_name);
        }
    };
    return 0;
}

/**
 * Main
 */
int main(int argc, char **argv)
{
    // default to current directory
    char *dir_to_print = "./";
    // store directory stream pointer
    DIR *dir;
    // Parse command line
    if (argc == 2)
    {
        dir_to_print = argv[1];
        printf("attempt to print directory: %s\n", dir_to_print);
    }
    else if (argc > 2)
    {
        printf("** More than one arg passed in, taking first only. **\n");
        dir_to_print = argv[1];
        printf("attempt to print directory: %s\n", dir_to_print);
    }
    else
    {
        printf("Print current directory: %s\n", dir_to_print);
    }

    // Open directory
    dir = opendir(dir_to_print);
    if (dir != NULL)
    {
        printf("directory '%s' opened successfully.\n", dir_to_print);
        // print contents
        print_entries(dir, dir_to_print, "");
        // // Repeatedly read and print entries
        // struct dirent *dent;
        // struct stat buf;
        // char file_w_path[1024];
        // while ((dent = readdir(dir)) != NULL)
        // {
        //     strcpy(file_w_path, dir_to_print);
        //     strcat(file_w_path, dent->d_name);
        //     // printf("%s\n", file_w_path);
        //     stat(file_w_path, &buf);
        //     if (buf.st_mode & S_IFDIR)
        //     {
        //         printf("     <DIR>  ");
        //         // print contents of directory if we encounter one
        //         dir2 = opendir(file_w_path);
        //         print_entries(dir2);
        //         closedir(dir2);
        //     }
        //     else
        //     {
        //         printf("%10lld  ", buf.st_size);
        //     }
        //     printf("%s\n", dent->d_name);
        // };
        // Close directory
        closedir(dir);
    }
    else
    {
        printf("error opening directory: %s\n", dir_to_print);
        exit(-1);
    }

    return 0;
}
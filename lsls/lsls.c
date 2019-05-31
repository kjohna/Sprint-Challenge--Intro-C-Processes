#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

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
        // Repeatedly read and print entries
        struct dirent *dent;
        while ((dent = readdir(dir)) != NULL)
        {
            printf("%s\n", dent->d_name);
        };
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
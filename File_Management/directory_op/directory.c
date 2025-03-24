#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    char d[50];
    int c, op;
    DIR *dir;
    struct dirent *entry;

    printf("** Menu **\n");
    printf("1. Create Directory\n");
    printf("2. Remove Directory\n");
    printf("3. Read Directory\n");
    printf("Enter your choice: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Enter directory name to create: ");
            scanf("%s", d);
            // Create directory with permission 0777
            c = mkdir(d);
            if (c < 0)
                perror("Directory not created");
            else
                printf("Directory '%s' created successfully.\n", d);
            break;
        case 2:
            printf("Enter directory name to remove: ");
            scanf("%s", d);
            c = rmdir(d);
            if (c < 0)
                perror("Directory not removed");
            else
                printf("Directory '%s' removed successfully.\n", d);
            break;
        case 3:
            printf("Enter directory name to read: ");
            scanf("%s", d);
            dir = opendir(d);
            if (dir == NULL) {
                perror("Directory does not exist or cannot be opened");
            } else {
                printf("Directory '%s' contents:\n", d);
                while ((entry = readdir(dir)) != NULL) {
                    printf("%s\t", entry->d_name);
                }
                printf("\n");
                closedir(dir);
            }
            break;
        default:
            printf("Invalid option.\n");
    }
    return 0;
}

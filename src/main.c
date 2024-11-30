#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 256
#define CONF_FILE "mozartConf.txt"
#define INSTALL_FILE "mozartInstall.txt"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("mozart version 0.0.1");
    }

    if (strcmp(argv[1], "init") == 0) {
        system("mkdir src");
        char res1[MAX_INPUT_SIZE] = "";
        system("cls");

        while (true) {
            printf("add includeFolder: ");
            scanf("%s", res1);
            system("cls");
            if (strcmp(res1, "y") == 0 || strcmp(res1, "yes") == 0) {
                break;
            } else if (strcmp(res1, "n") == 0 || strcmp(res1, "no") == 0) {
                break;
            }
        }

        if (strcmp(res1, "y") == 0 || strcmp(res1, "yes") == 0) {
            system("cd src && mkdir include && cd ..");
            char filePath[MAX_INPUT_SIZE];
            snprintf(filePath, sizeof(filePath), "./src/include/main.h");
            FILE *file = fopen(filePath, "w");
            fclose(file);
        }

        char res2[MAX_INPUT_SIZE] = "";
        system("cls");

        while (true) {
            printf("add includeFolder: %s\n", res1);
            printf("add mainFile: ");
            scanf("%s", res2);
            system("cls");
            if (strcmp(res2, "y") == 0 || strcmp(res2, "yes") == 0) {
                break;
            } else if (strcmp(res2, "n") == 0 || strcmp(res2, "no") == 0) {
                break;
            }
        }

        if (strcmp(res2, "y") == 0 || strcmp(res2, "yes") == 0) {
            char filePath[MAX_INPUT_SIZE];
            snprintf(filePath, sizeof(filePath), "./src/main.c");
            FILE *file = fopen(filePath, "w");
            fclose(file);
        }

        char res3[MAX_INPUT_SIZE] = "";
        system("cls");

        while (true) {
            printf("add includeFolder: %s\n", res1);
            printf("add mainFile: %s\n", res2);
            printf("add mozartInstallFile: ");
            scanf("%s", res3);
            system("cls");
            if (strcmp(res3, "y") == 0 || strcmp(res3, "yes") == 0) {
                char filePath[MAX_INPUT_SIZE];
                snprintf(filePath, sizeof(filePath), "./mozartInstall.txt");
                FILE *file = fopen(filePath, "w");
                fclose(file);
                system("cls");

                char res4[MAX_INPUT_SIZE] = "";
                for (size_t k = 1; true; k++) {
                    printf("%i. ", k);
                    scanf("%s", res4);

                    if (strcmp(res4, "exit") == 0) {
                        break;
                    }

                    FILE *file = fopen(filePath, "a");
                    fprintf(file, "%s\n", res4);
                    fclose(file);
                }
                break;
            }

            if (strcmp(res3, "n") == 0 || strcmp(res3, "no") == 0) {
                break;
            }
        }
    }

    if (strcmp(argv[1], "conf") == 0) {
        char res1[MAX_INPUT_SIZE];
        char res2[MAX_INPUT_SIZE];
        char res3[MAX_INPUT_SIZE];
        bool logic = true;

        system("cls");
        while (logic) {
            printf("includeFolderFile: ");
            scanf("%s", res1);
            system("cls");
            if (strcmp(res1, "") != 0) {
                logic = false;
            }
        }

        system("cls");
        logic = true;
        while (logic) {
            printf("includeFolderPath: %s\n", res1);
            printf("mainFilePath: ");
            scanf("%s", res2);
            system("cls");
            if (strcmp(res2, "") != 0) {
                logic = false;
            }
        }

        system("cls");
        logic = true;
        while (logic) {
            printf("includeFolderPath: %s\n", res1);
            printf("mainFilePath: %s\n", res2);
            printf("finalProgramName: ");
            scanf("%s", res3);
            system("cls");
            if (strcmp(res3, "") != 0) {
                logic = false;
            }
        }

        FILE *file = fopen(CONF_FILE, "w");
        fprintf(file, "%s\n", res1);
        fprintf(file, "%s\n", res2);
        fprintf(file, "%s\n", res3);
        fclose(file);
    }

    if (strcmp(argv[1], "run") == 0) {
        char line[MAX_INPUT_SIZE];
        FILE *file = fopen(CONF_FILE, "r");

        if (file == NULL) {
            printf("Please, initialize the %s file first.\n", CONF_FILE);
            return 1;
        }

        char n[3][MAX_INPUT_SIZE];
        int k = 0;
        while (k < 3 && fgets(line, sizeof(line), file) != NULL) {
            line[strcspn(line, "\n")] = 0;
            strcpy(n[k], line);
            k++;
        }

        fclose(file);
        char command[MAX_INPUT_SIZE * 4];
        snprintf(command, sizeof(command), "gcc -o %s %s -I%s", n[2], n[1], n[0]);
        system(command);
    }

    if (strcmp(argv[1], "install") == 0) {
        char line[MAX_INPUT_SIZE * 5];
        FILE *file = fopen(INSTALL_FILE, "r");

        if (file == NULL) {
            printf("Please, initialize the %s file first.\n", INSTALL_FILE);
            return 1;
        }

        char urls[100][MAX_INPUT_SIZE * 5];
        size_t k = 0;

        while (fgets(line, sizeof(line), file) != NULL) {
            line[strcspn(line, "\n")] = 0;
            if (strlen(line) > 0) {
                strcpy(urls[k], line);
                k++;
            }
        }

        fclose(file);

        for (size_t i = 0; i < k; i++) {
            char command[MAX_INPUT_SIZE + 20];
            snprintf(command, sizeof(command), "git clone %s", urls[i]);
            system("cd ./src/include/");
            system(command);
        }
    }

    return 0;
}

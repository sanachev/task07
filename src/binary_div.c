#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count = 1;
    char* data;
    data = (char*)malloc(sizeof(char) * count);

    // читаем строку
    while (1) {
        int step = getchar();
        if (step == 10) {
            break;
        } else {
            count++;
            const char* n_data = (char*)realloc(data, sizeof(char) * count);
            if (n_data) {
                data[count - 2] = step;
            } else {
                free(data);
                printf("Закончилась свободная память");
                break;
            }
        }
    }

    // выводим исходную строку
    for (int i = 0; i < count - 1; i++) {
        printf("%c", data[i]);
    }
    putchar('\n');

    // уменьшаем если строка больше 2х символов
    while (count > 1) {
        if ((count % 2) != 0) {
            count = (count / 2) + 1;
        } else {
            count /= 2;
        }

        for (int i = 0; i < count; i++) {
            printf("%c", data[i]);
        }
        if (count > 1) {
            putchar('\n');
        }
    }
    free(data);
    return 0;
}
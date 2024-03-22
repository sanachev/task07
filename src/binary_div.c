#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count = 1;
    char* data;
    data = (char*)malloc(sizeof(char) * count);
    int length;

    // читаем строку
    while (1) {
        int step = getchar();
        if (step == 10) {
            break;
        } else {
            count++;
            char* n_data = (char*)realloc(data, sizeof(char) * count);
            if (n_data) {
                data = n_data;
                data[count - 2] = step;
            } else {
                free(data);
                printf("Закончилась свободная память");
                break;
            }
        }
    }
    // количство печатаемых символов в массиве
    length = count - 1;

    // выводим исходную строку
    for (int i = 0; i < length; i++) {
        printf("%c", data[i]);
    }

    putchar('\n');

    // уменьшаем если строка больше 2х символов
    while (length > 1) {
        if ((length % 2) != 0) {
            length = (length / 2) + 1;
        } else {
            length /= 2;
        }

        for (int i = 0; i < length; i++) {
            printf("%c", data[i]);
        }
        if (length > 1) {
            putchar('\n');
        }
    }
    free(data);
    return 0;
}
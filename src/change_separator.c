#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count = 1;
    char* data;
    char separator[2];
    data = (char*)malloc(sizeof(char) * count);

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
            }
        }
    }

    // читаем разделитель
    fgets(separator, 2, stdin);

    // преобразуем пробелы в строке
    for (int i = 0; i < count - 1; i++) {
        if (data[i] == 32) {
            data[i] = separator[0];
        }
    }

    // выводим результат
    for (int i = 0; i < count - 1; i++) {
        printf("%c", data[i]);
    }

    free(data);
    return 0;
}
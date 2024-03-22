#include <sqlite3.h>
#include <stdio.h>

int callback(void *, int, char **, char **);

int main(void) {
    sqlite3 *db;
    char *err_msg = 0;

    sqlite3_open("../data-samples/task007.db", &db);

    char *sql = "SELECT id, name, age, email FROM Students WHERE id=7";

    sqlite3_exec(db, sql, callback, 0, &err_msg);

    sqlite3_close(db);

    return 0;
}

int callback(void *notUsed, int colCount, char **columns, char **colNames) {
    for (int i = 0; i < colCount; i++) {
        printf("%s", columns[i]);

        if (i < colCount - 1) {
            printf(" ");
        }
    }

    return 0;
}
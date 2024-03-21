#include <stdio.h>
#include <sqlite3.h>


int callback(void*, int, char**, char**);

int main(void){
    sqlite3 *db;
    char *err_msg = 0;

    sqlite3_open("../data-samples/task007.db", &db);

    char *sql = "SELECT * FROM Students";

    sqlite3_exec(db, sql, callback, 0, &err_msg);

    sqlite3_close(db);

    return 0;
}

int callback(void *notUsed, int colCount, char **columns, char **colNames)
{
    for (int i = 0; i < colCount; i++)
    {
        printf("%s = %s\n", colNames[i], columns[i] ? columns[i] : "NULL");
    }
    printf("\n");
    return 0;
}
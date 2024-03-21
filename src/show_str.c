#include <stdio.h>
#include <sqlite3.h>

int main(void){
    sqlite3 *db;
    int result = sqlite3_open("../data-samples/tasck007.db", &db);
    printf("%d\n", result);
    sqlite3_close(db);

    return 0;
}
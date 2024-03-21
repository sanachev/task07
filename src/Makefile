CC=gcc
FLAGS=-std=c11 -Wall -Werror -Wextra

show_str: 
	$(CC) $(FLAGS) show_str.c -o ../bin/show_str -l sqlite3

set-format:
	clang-format -style='{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}' -i *.c
	clang-format -style='{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}' -i *.h

check-format:
	clang-format -style='{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}' -n *.c
	clang-format -style='{BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 110}' -n *.h

cpp-check:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
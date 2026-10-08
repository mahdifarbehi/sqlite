#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { STATEMENT, COMMAND} LineType;
typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;
typedef enum { COMMAND_EXIT } CommandType;
typedef enum { RECOGNIZED, UNRECOGNIZED } PrepareResult;
typedef struct { StatementType type; } Statement;

void  execute_statement(Statement *s) {
    if (s->type == STATEMENT_SELECT) {
        printf("This is where we would do a select\n");
    } else if (s->type == STATEMENT_INSERT) {
        printf("This is where we would do a insert\n");
    }
}

int prepare_statement(Statement *s, char *line) {
    if (strcmp(line, "select") == 0) {
        s->type = STATEMENT_SELECT;
        return RECOGNIZED;
    } else if (strncmp(line, "insert ", 7) == 0) {
        s->type = STATEMENT_INSERT;
        return RECOGNIZED;
    } else {
        return UNRECOGNIZED;
    }
}

int main(void) {
    char *line = NULL;
    size_t cap = 0;

    while (1) {
        printf("db > ");
        fflush(stdout);
        ssize_t len = getline(&line, &cap, stdin);
        if (len == -1) {
            free(line);
            exit(EXIT_SUCCESS);
        }

        line[len - 1] = '\0';
        if (line[0] == '.') {
            if (strcmp(line, ".exit") == 0) {
                free(line);
                exit(EXIT_SUCCESS);
            } else {
                printf("Unrecognized command '%s'\n", line);
            }
        } else {
            Statement stm;
            int result = prepare_statement(&stm, line);
            if (result == 0) {
                printf("Unrecognized statement '%s'\n", line);
            } else {
                execute_statement(&stm);
            }
        }
    }
    return 0;
}

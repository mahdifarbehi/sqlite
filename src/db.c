#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum { STATEMENT, COMMAND} LineType;
typedef enum { STATEMENT_NONE, STATEMENT_INSERT, STATEMENT_SELECT } StatementType;
typedef enum { COMMAND_EXIT } CommandType;
typedef enum { RECOGNIZED, UNRECOGNIZED, SYNTAX_ERROR } PrepareResult;

typedef struct { uint32_t id; char username[33]; char email[256]; } Row;
typedef struct { StatementType type; Row row; } Statement;

void execute_statement(Statement *s) {
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
        int result = sscanf(
            line,
            "insert %u %32s %255s",
            &s->row.id,
            s->row.username,
            s->row.email
        );
        if (result == 3) {
            return RECOGNIZED;
        }
        return SYNTAX_ERROR;
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

        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        if (line[0] == '.') {
            if (strcmp(line, ".exit") == 0) {
                free(line);
                exit(EXIT_SUCCESS);
            } else {
                printf("Unrecognized command '%s'\n", line);
            }
        } else {
            Statement stm = {.type = STATEMENT_NONE};
            int result = prepare_statement(&stm, line);
            if (result == UNRECOGNIZED) {
                printf("Unrecognized statement '%s'\n", line);
            } else if (result == SYNTAX_ERROR) {
                printf("syntax error\n");
            } else {
                execute_statement(&stm);
                printf("%u %s %s\n", stm.row.id, stm.row.username, stm.row.email);

            }
        }
    }
    return 0;
}

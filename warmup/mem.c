#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[32];
} Row;

void fill(Row *r, int id, char *name) {
    r->id = id;
    strcpy(r->name, name);
}

int main(void) {
    Row r;
    fill(&r, 1, "alice");

    FILE *f = fopen("test.db", "wb");
    fwrite(&r, sizeof(r), 1, f);
    fclose(f);

    Row r2;

    FILE *f2 = fopen("test.db", "rb");
    fread(&r2, sizeof(r2), 1, f2);
    fclose(f2);


    printf("id: %d, name: %s\n", r2.id, r2.name);
    return 0;
}
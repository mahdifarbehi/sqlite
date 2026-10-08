# Progress — read this first

So a gap never means being lost. The top always says where you are.

## Where you are
- **Version:** v0.1 (REPL) — nearly done
- **Last did:** wrote a working REPL (`src/db.c`); reorganized repo (src/ warmup/ build/ + Makefile)
- **Next:** add `fflush(stdout)` after the prompt, then start v0.2 (insert & select)
- **Build:** `make` → `./build/db`

## C you know
Things you've written and understood. Anything here, I may write for you. Anything not, you write.

- compile + run: `clang x.c -o x && ./x`
- `#include`, `int main(void)`, `return 0;`
- `printf` with plain text, `\n`, `;` ends every statement
- types + `printf` codes (`%d %f %c %s`)
- structs (`.` and `->`), strings (char arrays + `\0`, `strcpy`)
- file I/O: `fopen` modes, `fread`/`fwrite(ptr,size,count,f)`, `fseek`, file position, check `fopen != NULL`

**Still building intuition:** stack vs heap, pointers in varied situations.

## Database ideas you know

_(empty)_

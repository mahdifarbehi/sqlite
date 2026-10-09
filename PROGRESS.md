# Progress — read this first

So a gap never means being lost. The top always says where you are.

## Where you are
- **Version:** v0.2 (insert & select in memory), step 1 of ~4
- **Last did:** finished v0.1. Fixed all REPL bugs yourself: enum compare, newline strip, zero-value `STATEMENT_NONE`. Learned how `getline`'s buffer works, that strings end at the first `\0`, and what is and isn't a memory leak.
- **Now:** step 1, parse `insert 1 alice a@b.com` into a `Row` with `sscanf`. Almost done. All written by you: sscanf, `&s->row.id`, `== 3` check, `%u` for `uint32_t`, and sizes 33/256 with widths 32/255 (a 32-char username fits exactly; tested).
- **Next action (start here tomorrow):** move the row `printf` from `main` (line ~76) into the insert branch of `execute_statement`, replacing the placeholder. Why: `select` currently prints an empty row `0`, and `main` shouldn't know the row layout (front-end/back-end split). Then start step 2: a Table holding many Rows.
- **Understood this session:** `sscanf` returns the number of slots filled; `&` on field paths; array size = max chars + 1; who adds `\0`; `-1` wraps to 4294967295 in `uint32_t`; C has no "missing field", every field always has bytes.
- **Seen, for step 4:** too-long username spills into email (data corruption, no crash); extra words accepted; `-1` id.
- **Later steps in v0.2:** 2) a Table holding many Rows; 3) `select` prints them all; 4) errors: table full, negative id, string too long.
- **Build:** `make` → `./build/db` (`-std=c17 -Wall -Wextra -Wpedantic -g`).
- **Small leftover:** `prepare_statement` returns `int`, not `PrepareResult`. `LineType`/`CommandType` are kept on purpose for later.

## C you know
Things you've written and understood. Anything here, I may write for you. Anything not, you write.

- compile + run: `clang x.c -o x && ./x`
- `#include`, `int main(void)`, `return 0;`
- `printf` with plain text, `\n`, `;` ends every statement
- types + `printf` codes (`%d %f %c %s`)
- integer arithmetic; `/` on ints drops the fraction (toward zero, unlike Python's `//` for negatives)
- structs (`.` and `->`), strings (char arrays + `\0`, `strcpy`)
- file I/O: `fopen` modes, `fread`/`fwrite(ptr,size,count,f)`, `fseek`, file position, check `fopen != NULL`
- enums, `typedef`, `strcmp`/`strncmp`, `getline` + `free`, `exit`
- C strings end at the first `\0`; `getline` keeps the `\n` and adds `\0`; one buffer reused across calls
- initializers `{.field = value}` (unlisted fields become 0); zero value should mean "none"
- `sscanf` with widths (`%32s`) and checking its return count; `&` for addresses (`&s->row.id`), arrays without `&`
- `<stdint.h>` / `uint32_t` with `%u`

**Still building intuition:** stack vs heap, pointers in varied situations, struct copies vs pointers, uninitialized values.

**Unassessed (explained or given, not yet shown in your own code):** writing boundary/edge-case checks, error handling on every I/O call.

## Database ideas you know
- A **page** is a fixed-size block; only whole rows fit after the page header (practiced in computer-systems exercises).

## Postgres connections seen
_(empty: add one per version, e.g. "Postgres pages are 8 KB")_

# On-disk format is explicit bytes, not struct dumps

Writing a struct straight to a file (`fwrite(&row, sizeof row, ...)`) depends on the
compiler's padding, int sizes, and the machine's byte order. The file might not read
back correctly with another compiler, flags, or CPU, and padding bytes can hold garbage.

We define the row and page format byte by byte: fixed-width ints (`uint32_t`), a chosen
byte order, and length checks on every read. Postgres and SQLite both define their
on-disk formats exactly.

Rejected: raw struct dumps (what `warmup/mem.c` does). They're fine for a warmup but
not for a real file format.

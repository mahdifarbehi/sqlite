# Glossary — small SQLite

The words we use, defined once. (Database internals are the domain here, so those terms belong.)

- **db** — the program we build. Run as `./db mydata.db`.
- **REPL** — the loop: print prompt, read a line, act, repeat.
- **Meta-command** — input starting with `.` (like `.exit`), handled by the REPL, not stored.
- **Statement** — a parsed insert or select, made from the input text.
- **Front-end / Back-end** — front-end turns text into a Statement; back-end runs it.
- **Row** — one record, fixed schema `(id, username, email)`.
- **Table** — all the Rows. An array early on, a B-tree later.
- **Page** — a fixed-size block of bytes (e.g. 4096). The unit we read and write.
- **Pager** — moves Pages between the file and memory. The only part that touches the file.
- **Serialize / Deserialize** — Row to bytes / bytes back to Row.
- **Cursor** — points at a spot in the Table (start, end, or a Row) and can move forward.
- **Node** — a Page seen as part of the B-tree. One node = one page.
- **Leaf node** — a Node holding real key→Row Cells, sorted by key.
- **Internal node** — a Node holding keys + child pointers; routes a search to the right Leaf.
- **Cell** — one entry in a Node (in a leaf: a key + its Row).
- **Key** — the value rows are sorted and looked up by: our `id`. Unique.
- **B-tree** — the on-disk tree of Nodes that keeps Rows sorted and fast to find. What makes this a database.

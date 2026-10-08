# Roadmap — a small SQLite in C

## Goal
Build `./db`: a prompt that speaks a tiny SQL, stores rows in a real **B-tree on
disk**, and keeps your data after restart. Not real SQLite — its core ideas, built by hand.

## How we work
- Ship a working `./db` at the end of every version.
- C first (briefly, in v0), then one new thing at a time.
- You write anything new to you. I only pre-write what's already on your "C you know" list (`PROGRESS.md`).
- Any phase can be picked up cold — `PROGRESS.md` always says where you are.

## Reference
Our versions follow the *"Let's Build a Simple Database"* (cstack) tutorial. It's a
safety net when things get hard — we build and understand it, not copy it.

## Versions
- **v0 — Foundations.** Write & compile tiny C programs. *Learn:* compiling, structs, pointers, memory, file I/O. *Ship:* small programs + confidence.
- **v0.1 — REPL.** `./db` shows a prompt, loops, handles `.exit`. *Ship:* a prompt you can type in and quit.
- **v0.2 — Insert & select (in memory).** Store rows in an array, print them. *Learn:* Row/Table, front-end vs back-end. *Ship:* insert & list (lost on exit).
- **v0.3 — Persistence.** Save rows to a file in pages. *Learn:* page, pager, serialize. *Ship:* data survives restart.
- **v0.4 — Cursor.** A thing that points at a row (start/end/one). *Ship:* same as v0.3, restructured for the B-tree.
- **v0.5 — B-tree leaf.** Store rows sorted in one leaf node; look up by key. *Learn:* node layout, binary search. *Ship:* sorted storage + duplicate-key errors.
- **v0.6 — B-tree grows (finish).** Split a full leaf, add internal nodes. *Ship:* more rows than one page, tree grows, select stays ordered.
- **v1.0 — Polish.** Cleanup, small extras, a short README you write.

## Stretch (optional)
Real SQL: a parser, `WHERE`, many tables, indexes. A separate, bigger project.

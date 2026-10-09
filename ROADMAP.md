# Roadmap — a small database in C, on the way to Postgres

## Goal
Build `./db`: a prompt that speaks a tiny SQL, stores rows in a real **B-tree on
disk**, and keeps your data after a restart **and after a crash**. Then grow it toward
how real databases work, and finish by reading and contributing to PostgreSQL.

## How we work
- Ship a working `./db` at the end of every version.
- C first (briefly, in v0), then one new thing at a time.
- You write anything new to you. I only pre-write what's already on your "C you know" list (`PROGRESS.md`).
- Any phase can be picked up cold: `PROGRESS.md` always says where you are.

## Reference
Part 1 follows the *"Let's Build a Simple Database"* (cstack) tutorial. It's a safety net
when things get hard: we build and understand it, not copy it. We differ from it where it
takes shortcuts (see ADR 0005). Parts 2–3 go beyond it.

## Part 1 — A working database (cstack path)
- **v0 — Foundations.** Tiny C programs. *Learn:* compiling, structs, pointers, memory, file I/O.
- **v0.1 — REPL.** `./db` shows a prompt, loops, handles `.exit`.
- **v0.2 — Insert & select (in memory).** Rows in an array. *Learn:* Row/Table, front-end vs back-end, parsing input safely.
- **v0.3 — Persistence.** Rows saved to a file in pages. *Learn:* page, pager, **explicit byte format** (fixed-width ints, byte order, length checks), not raw struct dumps. Partial reads/writes and I/O errors. *Ship:* data survives a clean restart.
- **v0.4 — Cursor.** Points at a row (start/end/one). Restructure for the B-tree.
- **v0.5 — B-tree leaf.** Sorted rows in one leaf; lookup by key. *Learn:* node layout, binary search.
- **v0.6 — B-tree grows.** Leaf/internal/root splits. *Ship:* more rows than one page, still ordered. Test against a simple reference (e.g. a sorted array).

## Part 2 — Make it a real storage engine
- **v0.7 — Testing & tools.** `make test`, AddressSanitizer, a debugger, and a script that inserts many random rows and checks them. (Start small tests earlier; this makes them systematic.)
- **v0.8 — Crash recovery.** Define what a successful write promises. Learn `fsync`, write ordering, and a **write-ahead log (WAL)** like Postgres. Kill the program mid-write and prove recovery works. *Ship:* first truly durable release.
- **v0.9 — Buffer pool.** Cache pages in memory with a fixed size and eviction. Compare with Postgres's shared buffers.
- **v1.0 — Polish.** Cleanup, a short README and an architecture note you write.

## Part 3 — Toward Postgres
- **v1.1 — Query execution.** `WHERE` filters, table scan vs index scan, a tiny planner that picks one. Compare with Postgres's `EXPLAIN`.
- **v1.2 — Transactions.** `BEGIN`/`COMMIT`/`ROLLBACK` on top of the WAL. Test atomicity and durability.
- **v1.3 — Concurrency.** Threads, locks, then overlapping transactions. Pick an isolation approach together (locking vs MVCC, like Postgres).
- **v1.4 — Measure.** Benchmark real workloads and find the slow parts.
- **v2 — PostgreSQL.** Build Postgres from source, compare each of our designs with theirs, read one focused area (e.g. the B-tree in `src/backend/access/nbtree`), and find a small first contribution.

## Postgres along the way
At each version, take a short look at how Postgres does the same thing, e.g. pages (v0.3),
B-tree (v0.5), WAL (v0.8), buffers (v0.9), planner (v1.1), MVCC (v1.3). Reading real
code early makes v2 much easier.

## Optional
Real SQL parser, many tables, secondary indexes, networking (a wire protocol), replication.

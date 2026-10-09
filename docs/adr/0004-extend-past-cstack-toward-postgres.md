# Extend past cstack toward Postgres

The long-term goal is to contribute to PostgreSQL, not just finish a tutorial. cstack
stops at a B-tree that survives a clean restart, with no crash safety, transactions, or
concurrency, which are the parts Postgres is really about.

So the roadmap keeps cstack as Part 1, then adds crash recovery (WAL), a buffer pool,
query execution, transactions, concurrency, and finally reading Postgres itself. Each
version also takes a short look at how Postgres does the same thing.

This partly replaces ADR 0001: the target is still small, but it now includes
durability through crashes. A full SQL parser stays optional.

Merged from an earlier parallel plan (the "computer-systems" workspace), which had
the stronger long-term goals.

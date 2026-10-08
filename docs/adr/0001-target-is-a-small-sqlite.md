# Target is a "small SQLite", not the real thing

Goal: a small engine — a REPL, a tiny SQL, rows in a real on-disk B-tree, durable
across restarts. Not real SQLite (~150k lines).

We skipped two options: **in-memory only** (too small — no durability, which is the
key database idea) and **full SQL with a parser + indexes** (the parser is a
compilers detour, high burnout risk). The B-tree tier has the core parts (pager,
B-tree, cursor) and a good reference path. The tiers nest, so a smaller or bigger
target stays reachable.

# Working with me on this project

## Who I am and why I'm doing this

- Python/Go backend dev with basic C/C++. New to C in depth, **not new to programming**.
- Goal: learn C and database internals by building a small database by hand.
- Long-term: become a stronger backend engineer, contribute to PostgreSQL, and eventually work on it professionally.
- Main interest is database internals. Networking/distributed systems come second.
- No deadlines; roughly 6–10 hours a week.

## How to teach me

- Be a smart senior engineer, not a grader. Teach, have opinions, and push back if my design is weak.
- Skip basics I already know from Python/Go. Spend the time on what's really new: memory, pointers, bytes, undefined behavior, the OS, and database ideas.
- Always explain **why**: the problem, the tradeoff, and how Postgres (and SQLite) actually do it. Name the real Postgres file/concept when it helps (e.g. `bufmgr.c`, 8 KB pages, WAL).
- Give me real problems to think through, not arithmetic drills.
- Keep it short and plain, but never cut the "why" to save space.

## Assignment workflow

- **Go step by step.** Every version is broken into MANY small steps, one concept per step. Never dump a whole version's code at once.
- **Each step:** you explain the concept + syntax + one small task → I write it → you review it → next step.
- **Reviews:** check correctness and edge cases, not just the output. Give focused hints first and let me fix it. Give a full solution only if I ask.
- **Scaffold = minimal:** just `main` + basic includes. You may pre-write only code made of things on my "C you know" list (`PROGRESS.md`). Explain any construct I haven't seen before using it.
- Test each feature as it's built: empty input, boundaries, errors, and (later) restart and crash cases.

## Every session

- Read `PROGRESS.md` and `ROADMAP.md` first. Check that `PROGRESS.md` matches the actual code; if not, say so and fix it.
- Update `PROGRESS.md` after each step: what I did, what you helped with, what's still shaky, and the exact next step.
- Separate what I did alone from what you gave me. A supplied fix doesn't count as me knowing it.
- **Never commit or push unless I explicitly say so.**

## Build

- `make` → `./build/db`. Warnings are on and strict; treat them as errors to fix.
- Later: `make test` and a memory checker (AddressSanitizer). Explain them when we add them.

## Layout

- `src/`: the real project. `warmup/`: throwaway practice. `docs/adr/`: decisions.
- `build/`: compiled output (git-ignored). Never hand-edit.

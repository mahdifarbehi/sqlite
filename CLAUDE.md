# Working with me on this project

- Keep everything short and simple — answers, explanations, and docs. Short beats complete. Plain words over jargon.
- I'm a Python dev learning C. Explain C things plainly, no assumed background.
- This is a git repo. **Never commit or push unless I explicitly say so.**
- When it fits, tie a concept back to how real databases (e.g. Postgres) do it — this journey is also about deepening my database-internals knowledge.

## Assignment workflow

- **Go step by step.** Every phase is broken into MANY small steps — one concept per step. Never dump a whole phase's code at once.
- **Each step:** you (Claude) explain the concept + the syntax + one small task → I write that bit → you review it → next step.
- **Scaffold = minimal only:** just `main` + basic includes, like a hello-world file. No pre-written structs, functions, enums, or logic — I write all of that myself, one step at a time. Never write code using a construct I haven't seen yet without explaining it first.
- I build with `make` and run `./build/db`.

## Layout

- `src/` — the real project source. `warmup/` — throwaway v0 practice. `docs/adr/` — decisions.
- `build/` — compiled output (git-ignored). Never hand-edit.

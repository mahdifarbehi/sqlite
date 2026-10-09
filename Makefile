# Build the database. Run:  make        -> compiles src/*.c into build/db
#                          ./build/db   -> runs it
#                          make clean   -> deletes build/

CC = clang
# -std=c17: use the C17 standard.  -Wall -Wextra -Wpedantic: many useful warnings.
# -g: keep debug info so a debugger (lldb) can show your source lines.
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -g

build/db: src/*.c
	mkdir -p build
	$(CC) $(CFLAGS) src/*.c -o build/db

clean:
	rm -rf build

# build/db is .PHONY so it always recompiles -- you see every warning, every time.
.PHONY: clean build/db

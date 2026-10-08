# Build the database. Run:  make        -> compiles src/*.c into build/db
#                          ./build/db   -> runs it
#                          make clean   -> deletes build/

CC = clang
CFLAGS = -Wall

build/db: src/*.c
	mkdir -p build
	$(CC) $(CFLAGS) src/*.c -o build/db

clean:
	rm -rf build

# build/db is .PHONY so it always recompiles -- you see every warning, every time.
.PHONY: clean build/db

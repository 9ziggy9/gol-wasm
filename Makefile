CC=clang
CFLAGS=--target=wasm32 --no-standard-libraries -Wl,--export-all -Wl,--no-entry -Wl,--allow-undefined
INCLUDES=-I './game.h'

all: clean game

game: game.c
	$(CC) $(INCLUDES) $(CFLAGS) ./game.c  -o ./build/game.wasm

clean:
	rm -rf ./build/*.wasm

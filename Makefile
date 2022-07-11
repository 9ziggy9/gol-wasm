CC=clang
CFLAGS=--target=wasm32 --no-standard-libraries -Wl,--export-all -Wl,--no-entry -Wl,--allow-undefined
INCLUDES=-I './include/render.h'

all: render

render: src/render.c
	$(CC) $(INCLUDES) $(CFLAGS) ./src/render.c  -o ./build/render.wasm

clean:
	rm -rf ./build/*.wasm

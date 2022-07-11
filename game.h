#ifndef WORLD_H_
#define WORLD_H_

#define FACTOR 50
#define WIDTH (16*FACTOR)
#define HEIGHT (9*FACTOR)
#define CELL_SIZE 25
#define COLS (WIDTH/CELL_SIZE)
#define ROWS (WIDTH/CELL_SIZE)

// hexcodes are little endian
#define COLOR_BG 0xFFFF0000 // blue
#define COLOR_FG 0xFFFFFFFF // white
#define COLOR_CELL1 COLOR_BG
#define COLOR_CELL2 COLOR_FG

typedef unsigned int u32;
typedef int i32;

typedef enum {
  DEAD,
  ALIVE
} CellState;

typedef struct {
  i32 x, y;
  CellState state;
} Cell;

typedef struct {
  i32 width;
  i32 height;
  Cell** grid;
} WorldState;

void platform_fill_rect(i32 x, i32 y, i32 w, i32 h, u32 color);
int view_width(void);
int view_height(void);
void render_background(void);
void view_render(void);
void render_cell(i32 x, i32 y);
WorldState initialize_world(void);

#endif // WORLD_H_

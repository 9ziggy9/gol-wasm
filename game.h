#ifndef WORLD_H_
#define WORLD_H_

#define FACTOR 50
#define PADDING 5
#define WIDTH (16*FACTOR)
#define HEIGHT (9*FACTOR)
#define CELL_SIZE 25
#define COLS (WIDTH/CELL_SIZE)
#define ROWS (HEIGHT/CELL_SIZE)
#define TIME_STEP 0.1f

// hexcodes are little endian
#define COLOR_BG 0xFF606060 // dark gray
#define COLOR_FG 0xFF909090 // light gray
#define COLOR_CELL1 COLOR_BG
#define COLOR_CELL2 COLOR_FG
#define COLOR_ALIVE 0xFF43B03C // green

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
  Cell grid[COLS][ROWS];
  float cooldown;
} WorldState;

void platform_fill_rect(i32 x, i32 y, i32 w, i32 h, u32 color);
int view_width(void);
int view_height(void);
void render_background(void);
void view_render(WorldState *world);
void render_cell(Cell cell);
WorldState initialize_world(void);
void state_transition(WorldState *world);
void give_life(Cell* cell);
void give_death(Cell* cell);
void game_render(void);
void world_transition(WorldState *world);
void game_update(WorldState *world, float dt);

#endif // WORLD_H_

#include "game.h"

int view_width(void) {
  return WIDTH + PADDING;
}

int view_height(void) {
  return HEIGHT + PADDING;
}

void render_background(void) {
  platform_fill_rect(0, 0, WIDTH + PADDING, HEIGHT + PADDING, COLOR_BG);
}

void render_cell(Cell cell) {
  if (cell.state == ALIVE) {
    platform_fill_rect(cell.x, cell.y, CELL_SIZE - PADDING,
		       CELL_SIZE - PADDING, COLOR_ALIVE);
  } else {
    platform_fill_rect(cell.x, cell.y, CELL_SIZE - PADDING,
		       CELL_SIZE - PADDING, COLOR_FG);
  }
}

WorldState initialize_world(void) {
  WorldState world;
  for (i32 y = 0; y < ROWS; y++) {
    for (i32 x = 0; x < COLS; x++) {
      Cell current = {.x = CELL_SIZE * x + PADDING,
		      .y = CELL_SIZE * y + PADDING,
		      .state = ALIVE};
      world.grid[x][y] = current;
    }
  }
  return world;
}

void render_world(WorldState *world) {
  for (i32 y = 0; y < ROWS; y++) {
    for (i32 x = 0; x < COLS; x++) {
      render_cell(world->grid[x][y]);
    }
  }
}

void give_life(Cell* cell) {
  cell->state = ALIVE;
}

void give_death(Cell* cell) {
  cell->state = DEAD;
}

void view_render(WorldState *world) {
  render_background();
  render_world(world);
}

void game_run() {
  WorldState world = initialize_world();
  view_render(&world);
}

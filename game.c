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
		       CELL_SIZE - PADDING, COLOR_FG);
  } else {
    platform_fill_rect(cell.x, cell.y, CELL_SIZE - PADDING,
		       CELL_SIZE - PADDING, COLOR_BG);
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

void view_render(void) {
  render_background();
  WorldState world = initialize_world();
  render_world(&world);
}

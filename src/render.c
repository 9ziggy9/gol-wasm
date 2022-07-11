#include "../include/world.h"

int view_width(void) {
  return WIDTH;
}

int view_height(void) {
  return HEIGHT;
}

void render_background(void) {
  platform_fill_rect(0, 0, WIDTH, HEIGHT, COLOR_BG);
}

void render_cell(i32 x, i32 y) {
  platform_fill_rect(x, y, CELL_SIZE, CELL_SIZE, COLOR_FG);
}

void view_render(void) {
  render_background();
  render_cell(10,10);
}


#include "../include/render.h"

int view_width(void) {
  return WIDTH;
}

int view_height(void) {
  return HEIGHT;
}

void render_background(void) {
  platform_fill_rect(0, 0, WIDTH, HEIGHT, COLOR_BG);
}

void view_render(void) {
  render_background();
}


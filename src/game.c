#include "../include/world.h"

WorldState initialize_world(void) {
  WorldState world;
  for (int y = 0; y < world.height; y += CELL_SIZE) {
    for(int x = 0; x < world.width; x += CELL_SIZE) {
      world.grid[y][x].x = x;
      world.grid[y][x].y = y;
      world.grid[y][x].state = ALIVE;
    }
  }
  return world;
}

#include <iostream>
#include <cstdlib>

// Original implmentation: http://codereview.stackexchange.com/questions/47167/conways-game-of-life-in-c

const int size = 75;

void Display(bool grid[size + 1][size + 1]){
  char block = '#';
  int a, b;
  
  for (a = 1; a < size; a++) {
    for (b = 1; b < size; b++) {
      if (grid[a][b]) std::cout << block;
      else std::cout << " ";

      if (b == size - 1) std::cout << std::endl;
    }
  }
}

void CopyGrid(bool grid[size + 1][size + 1], bool grid2[size + 1][size + 1]){
  for(int a = 0; a < size; a++)
    for(int b = 0; b < size; b++)
      grid2[a][b] = grid[a][b];
}

void liveOrDie(bool grid[size+1][size+1]) {
  int a, b, c, d, life;
  bool grid2[size+1][size+1] = {};

  CopyGrid(grid, grid2);

  for (a = 1; a < size; a++) {
    for (b = 1; b < size; b++) {
      life = 0;
      for (c = -1; c < 2; c++)
	for (d = -1; d < 2; d++)
	  if ((c != 0 || d != 0) && (grid2[a+c][b+d])) life++;
	
      if (life == 3) grid[a][b] = true;
      else if (life > 3 || life < 2) grid[a][b] = false;
    }
  }
}

int main(){
  bool grid[size + 1][size + 1] = {};

  grid[size/2][size/2] = true;
  grid[size/2-1][size/2] = true;
  grid[size/2][size/2+1] = true;
  grid[size/2][size/2-1] = true;
  grid[size/2+1][size/2+1] = true;

  while (true) {
    Display(grid);    
    liveOrDie(grid);
    system("clear");
  }
}

#include <iostream>
#include <cstdlib>

const int size = 75;

void Display(bool grid[size + 1][size + 1]){
  for (int a = 1; a < size; a++) {
    for (int b = 1; b < size; b++) {
      if (grid[a][b] == true) std::cout << " *";
      else std::cout << "  ";

      if (b == size - 1) std::cout << std::endl;
    }
  }
}

void CopyGrid(bool grid[size + 1][size + 1], bool grid2[size + 1][size + 1]){
  for(int a = 0; a < size; a++)
    for(int b = 0; b < size; b++)
      grid2[a][b] = grid[a][b];
}

void liveOrDie(bool grid[size+1][size+1]){
  bool grid2[size+1][size+1] = {};
  CopyGrid(grid, grid2);
  for(int a = 1; a < size; a++) {
    for(int b = 1; b < size; b++) {
      int life = 0;
      for (int c = -1; c < 2; c++)
	for (int d = -1; d < 2; d++)
	  if (!(c == 0 && d == 0))
	    if (grid2[a+c][b+d]) ++life;
      if (life < 2)  grid[a][b] = false;
      else if (life == 3) grid[a][b] = true;
      else if (life > 3) grid[a][b] = false;
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

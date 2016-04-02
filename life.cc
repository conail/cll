#include <iostream>
#include <cstdlib>
#include <unistd.h>

// Original implmentation: http://codereview.stackexchange.com/questions/47167/conways-game-of-life-in-c
class Life {
  static const int size = 50;

  bool frame[2][size][size];
  int current;

public:
  Life() {
    int current = 0;
    int mid = size/2;    
    frame[current][mid  ][mid  ] = 1;
    frame[current][mid-1][mid  ] = 1;
    frame[current][mid  ][mid+1] = 1;
    frame[current][mid  ][mid-1] = 1;
    frame[current][mid+1][mid+1] = 1;
        
    while (true) {
      system("clear");
      display();    
      iterate();
      usleep(200000);
    }
  }
  
private:
  void display() {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++)
	std::cout << ((frame[current][i][j]) ? '#' : ' ');
      std::cout << std::endl;
    }
  }
  
  void iterate() {
    int alive, next = (current + 1) % 2; 
    
    for (int i = 1; i < size; i++) {
      for (int j = 1; j < size; j++) {
        alive = 0;

	for (int di = -1; di < 2; di++)
	  for (int dj = -1; dj < 2; dj++)
	    if (di != 0 || dj != 0)
	      if (frame[current][i+di][j+dj]) alive++;
	
	if      (alive == 3)             frame[next][i][j] = 1;
	else if (alive > 3 || alive < 2) frame[next][i][j] = 0;
	else frame[next][i][j] = frame[current][i][j];
      }
    }
    current = next;
  }
};

int main()
{
  new Life();  
}

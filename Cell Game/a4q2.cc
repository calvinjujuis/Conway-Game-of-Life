#include "lifegame.h"
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
      cout << "Usage: " << argv[0] << " width height" << endl;
      return 1;
    }
    istringstream w{argv[1]};
    istringstream h{argv[2]};
    int width, height;
    w >> width;
    h >> height;
    LifeGame g{width, height};
    g.play();
}
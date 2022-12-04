
#include <iostream>
#include <cstdlib>

#include "Game.h"

using namespace std;

int main(int argc, char** argv) {
    int width = 20, height = 20;
    
    srand(time(0));
    
//    cout << "Type the map width: ";
//    cin >> width;
//    
//    cout << "Type the map height: ";
//    cin >> height;
    
    Game game(width, height);
    
    game.create();
    
    game.mainLoop();
    
    
    
    
    
    return 0;
}


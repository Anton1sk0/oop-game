#include <iostream>
#include "Water.h"

using namespace std;

Water::Water() {

}



Water::~Water() {

}

void Water::print() {
    printf("%-3s", "\033[1;32m⛲\033[0m ");
}

bool Water::accessible() {
    return false;
}
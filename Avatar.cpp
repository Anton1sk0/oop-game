#include <iostream>

#include "Avatar.h"

using namespace std;

Avatar::Avatar() { 

}


Avatar::~Avatar() {

}

void Avatar::print() {
//    printf("%4s", "\033[31m♚\033[0m");
    printf("%-3s", "\033[1;33m🤺\033[0m ");
//    printf("%-3s", "  🤺");
}


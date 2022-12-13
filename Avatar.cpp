#include <iostream>

#include "Avatar.h"
#include "Tags.h"

using namespace std;

Avatar::Avatar() : Entity(AVATAR_TAG), potions(1) {
}

Avatar::~Avatar() {
}

#pragma once

#include "../draw.h"
#include <SFML/Audio.hpp>

int binarySearch(unsigned char a[], int l, int r, int x);

void insertionSortB(unsigned char a[], sf::RenderWindow* window, sf::Sound* sound);

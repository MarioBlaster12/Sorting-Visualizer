#pragma once

#include "../draw.h"
#include <SFML/Audio.hpp>

void mergeArr(unsigned char a[], sf::RenderWindow* window, int l, int m, int r, sf::Sound* sound);

void mergeSort(unsigned char a[], sf::RenderWindow* window, int l, int r, sf::Sound* sound);

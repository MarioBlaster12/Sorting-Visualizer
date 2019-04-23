#pragma once

#include "../draw.h"
#include <SFML/Audio.hpp>

int splitArr(unsigned char a[], sf::RenderWindow* window, int l, int h, sf::Sound* sound);

void quickSort(unsigned char a[], sf::RenderWindow* window, int l, int h, sf::Sound* sound);

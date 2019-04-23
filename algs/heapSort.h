#pragma once

#include "../draw.h"
#include <SFML/Audio.hpp>

void heapify(unsigned char a[], sf::RenderWindow* window, int n, int i, sf::Sound* sound);

void heapSort(unsigned char a[], sf::RenderWindow* window, sf::Sound* sound);

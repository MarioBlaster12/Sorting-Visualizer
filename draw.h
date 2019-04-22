#pragma once

#include <SFML/Graphics.hpp>

int mapBetween(int input, int in_min, int in_max, int out_min, int out_max);

void draw(unsigned char a[], sf::RenderWindow* window);

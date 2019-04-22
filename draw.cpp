#include "draw.h"

#define SCREENW 1280
#define SCREENH 720

int mapBetween(int input, int in_min, int in_max, int out_min, int out_max) {
    return floor(input - in_min) * (out_max-out_min)/(in_max-in_min) + out_min;
}

void draw(unsigned char a[], sf::RenderWindow* window){
    window->clear();
    for(int i = 0; i < 256; i++){
        sf::RectangleShape rect;
        if(a[i] == i)
            rect.setFillColor(sf::Color::Green);
        else
            rect.setFillColor(sf::Color::Red);
        rect.setSize(sf::Vector2f(SCREENW/256,-mapBetween(a[i],0,255,0,SCREENH)));
        rect.setPosition(sf::Vector2f((SCREENW/256)*i, SCREENH));

        window->draw(rect);
    }
}

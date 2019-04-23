#include "draw.h"

#define SCREENW 1280
#define SCREENH 720

void draw(unsigned char a[], sf::RenderWindow* window){
    window->clear();
    for(int i = 0; i < 256; i++){
        sf::RectangleShape rect;
        if(a[i] == i)
            rect.setFillColor(sf::Color::Green);
        else
            rect.setFillColor(sf::Color::Red);
        rect.setSize(sf::Vector2f(SCREENW/256,-(a[i]*720/255)));
        rect.setPosition(sf::Vector2f((SCREENW/256)*i, SCREENH));

        window->draw(rect);
    }
}

#include "gnomeSort.h"

void gnomeSort(unsigned char a[], sf::RenderWindow* window, sf::Sound* sound) {
    for(int i = 1; i < 256; i++){
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
        if(i != 0 || a[i] >= a[i-1]){
            if(a[i] < a[i-1]){
                std::swap(a[i], a[i-1]);
                sound->setPitch(1+(a[i]/20));
                sound->play();
                draw(a, window);
                window->display();
                i-=2;
            }
        }
    }
}

#include "oddEvenSort.h"

void oddEvenSort(unsigned char a[], sf::RenderWindow* window, sf::Sound* sound){
    bool swapped = true;
    while(swapped){
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);

        swapped = false;

        for(int i = 1; i <= 254; i+=2){
            if(a[i] > a[i+1]){
                std::swap(a[i], a[i+1]);
                sound->setPitch(1+(a[i]/20));
                sound->play();
                draw(a, window);
                window->display();
                swapped = true;
            }
        }

        for(int i = 0; i <= 254; i+=2){
            if(a[i] > a[i+1]){
                std::swap(a[i], a[i+1]);
                sound->setPitch(1+(a[i]/20));
                draw(a, window);
                window->display();
                swapped = true;
            }
        }
    }
}

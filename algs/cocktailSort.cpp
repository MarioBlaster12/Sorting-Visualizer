#include "cocktailSort.h"

void cocktailSort(unsigned char a[], sf::RenderWindow* window){
    bool swapped = true;
    int start = 0;
    int end = 255;

    while(swapped){
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);

        swapped = false;

        for(int i = start; i < end; i++) {
            if(a[i] > a[i+1]){
                std::swap(a[i], a[i+1]);
                swapped = true;
                draw(a, window);
                window->display();
            }
        }

        if(!swapped)
            break;

        end--;

        for(int i = end-1; i >= start; i--){
            if(a[i] > a[i+1]){
                std::swap(a[i], a[i+1]);
                draw(a, window);
                window->display();
            }
        }

        start++;
    }
}

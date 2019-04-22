#include "bubbleSort.h"

void bubbleSort(unsigned char a[], sf::RenderWindow* window){
    bool swapped;
    for(int i = 0; i < 255; i++){
        swapped = false;
        for(int j = 0; j < 256-i-1; j++){
            if(a[j]>a[j+1]){
                std::swap(a[j],a[j+1]);
                // constantly polling for events because if I don't sfml will just give up
                sf::Event temp;
                window->pollEvent(temp);
                draw(a, window);
                window->display();
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

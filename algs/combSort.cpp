#include "combSort.h"

int nextGap(int gap) {
    gap = (gap*10)/13;

    if(gap<1)
        return 1;
    return gap;
}

void combSort(unsigned char a[], sf::RenderWindow* window){
    int gap = 256;

    bool swapped = false;

    while(gap != 1 || swapped == true){
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
        gap = nextGap(gap);

        swapped = false;

        for(int i = 0; i < 256-gap; i++){
            if(a[i] > a[i+gap]){
                std::swap(a[i], a[i+gap]);
                draw(a, window);
                window->display();
                swapped = true;
            }
        }
    }
}

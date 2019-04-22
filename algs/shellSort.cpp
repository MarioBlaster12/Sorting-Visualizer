#include "shellSort.h"

void shellSort(unsigned char a[], sf::RenderWindow* window) {
    for(int gap = 128; gap > 0; gap /= 2){
        for(int i = gap; i < 256; i += 1){
            int temp = a[i];
            int j;
            for(j = i; j >= gap && a[j- gap] > temp; j -= gap)
                a[j] = a[j - gap];
                draw(a, window);
                window->display();
            a[j] = temp;
            draw(a, window);
            window->display();
        }
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
    }
}

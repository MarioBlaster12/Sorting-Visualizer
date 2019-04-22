#include "quickSort.h"

int splitArr(unsigned char a[], sf::RenderWindow* window, int l, int h){
    int pivot = a[h];
    int i = l-1;

    for(int j = l; j <= h-1; j++){
        if(a[j] <= pivot){
            i++;
            std::swap(a[i], a[j]);
            draw(a, window);
            window->display();
        }
    }
    std::swap(a[i+1], a[h]);
    draw(a, window);
    window->display();
    return i+1;
}

void quickSort(unsigned char a[], sf::RenderWindow* window, int l, int h){
    if(l < h){
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
        int partIndex = splitArr(a, window, l, h);

        quickSort(a, window, l, partIndex-1);
        quickSort(a, window, partIndex+1, h);
    }
}

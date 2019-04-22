#include "heapSort.h"

void heapify(unsigned char a[], sf::RenderWindow* window, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && a[l] > a[largest])
        largest = l;

    if(r<n && a[r] > a[largest])
        largest = r;

    if(largest != i){
        std::swap(a[i], a[largest]);
        draw(a, window);
        window->display();
        heapify(a, window, n, largest);
    }
}

void heapSort(unsigned char a[], sf::RenderWindow* window){
    for(int i = 256/2-1; i >= 0; i--)
        heapify(a, window, 256, i);

    for(int i = 255; i >= 0; i--){
        std::swap(a[0], a[i]);
        draw(a, window);
        window->display();
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
        heapify(a, window, i, 0);
    }
}

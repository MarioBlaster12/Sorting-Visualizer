#include "heapSort.h"

void heapify(unsigned char a[], sf::RenderWindow* window, int n, int i, sf::Sound* sound){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && a[l] > a[largest])
        largest = l;

    if(r<n && a[r] > a[largest])
        largest = r;

    if(largest != i){
        std::swap(a[i], a[largest]);
        sound->setPitch(1+(a[i]/20));
        sound->play();
        draw(a, window);
        window->display();
        heapify(a, window, n, largest, sound);
    }
}

void heapSort(unsigned char a[], sf::RenderWindow* window, sf::Sound* sound){
    for(int i = 256/2-1; i >= 0; i--)
        heapify(a, window, 256, i, sound);

    for(int i = 255; i >= 0; i--){
        std::swap(a[0], a[i]);
        sound->setPitch(1+(a[i]/20));
        sound->play();
        draw(a, window);
        window->display();
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
        heapify(a, window, i, 0, sound);
    }
}

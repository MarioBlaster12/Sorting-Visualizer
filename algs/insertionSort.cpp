#include "insertionSort.h"

void insertionSort(unsigned char a[], sf::RenderWindow* window, int l, int r, sf::Sound* sound){
    int k, j;

    for(int i = l+1; i <= r; i++){
        k = a[i];
        j = i-1;

        while(j >= l && a[j] > k){
            a[j+1] = a[j];
            sound->setPitch(1+(a[j]/20));
            sound->play();
            j = j-1;
            draw(a, window);
            window->display();
        }
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
        a[j+1] = k;
        sound->setPitch(1+(a[k]/20));
        sound->play();
    }
}

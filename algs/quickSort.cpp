#include "quickSort.h"

int splitArr(unsigned char a[], sf::RenderWindow* window, int l, int h, sf::Sound* sound){
    int pivot = a[h];
    int i = l-1;

    for(int j = l; j <= h-1; j++){
        if(a[j] <= pivot){
            i++;
            std::swap(a[i], a[j]);
            sound->setPitch(1+(a[i]/20));
            sound->play();
            sound->setPitch(1+(a[j]/20));
            sound->play();
            draw(a, window);
            window->display();
        }
    }
    std::swap(a[i+1], a[h]);
    sound->setPitch(1+(a[i+1]/20));
    sound->play();
    sound->setPitch(1+(a[h]/20));
    sound->play();
    draw(a, window);
    window->display();
    return i+1;
}

void quickSort(unsigned char a[], sf::RenderWindow* window, int l, int h, sf::Sound* sound){
    if(l < h){
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
        int partIndex = splitArr(a, window, l, h, sound);

        quickSort(a, window, l, partIndex-1, sound);
        quickSort(a, window, partIndex+1, h, sound);
    }
}

#include "selectionSort.h"

void selectionSort(unsigned char a[], sf::RenderWindow* window, sf::Sound* sound){
    int mindex;
    for(int i = 0; i < 255; i++){
        mindex = i;
        for(int j = i+1; j<256;j++){
            if(a[j] < a[mindex])
                mindex = j;
        }
        std::swap(a[i],a[mindex]);
        sound->setPitch(1+(a[i]/20));
        sound->play();
        sound->setPitch(1+(a[mindex]/20));
        sound->play();
        draw(a, window);
        window->display();
    }
}

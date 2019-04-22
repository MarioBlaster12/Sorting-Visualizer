#include "selectionSort.h"

void selectionSort(unsigned char a[], sf::RenderWindow* window){
    int mindex;
    for(int i = 0; i < 255; i++){
        mindex = i;
        for(int j = i+1; j<256;j++){
            if(a[j] < a[mindex])
                mindex = j;
        }
        std::swap(a[i],a[mindex]);
        draw(a, window);
        window->display();
    }
}

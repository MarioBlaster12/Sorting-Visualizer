#include "insertionSortB.h"

int binarySearch(unsigned char a[], int l, int r, int x){
    if(r > l){
        int m = (l+r)/2;
        if(x == a[m])
            return m+1;

        if(x > a[m])
            return binarySearch(a, m+1, r, x);
        return binarySearch(a, l, m-1, x);
    }
    return (x > a[l]) ? (l+1):l;
}

void insertionSortB(unsigned char a[], sf::RenderWindow* window){
    int j, selected, index;
    for(int i = 1; i < 256; i++){
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);

        j = i-1;
        selected = a[i];

        index = binarySearch(a, 0, j, selected);

        while(j >= index){
            a[j+1] = a[j];
            j--;
            draw(a, window);
            window->display();
        }
        a[j+1] = selected;
        draw(a, window);
        window->display();
    }
}

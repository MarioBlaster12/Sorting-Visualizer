#include "mergeSort.h"

void mergeArr(unsigned char a[], sf::RenderWindow* window, int l, int m, int r, sf::Sound* sound){
    int n1 = m - l + 1;
    int n2 = r - m;

    unsigned char L[n1],R[n2];

    for(int i = 0 ; i < n1 ; i++)
        L[i] = a[l+i];
    for(int j = 0 ; j < n2 ; j++)
        R[j] = a[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            sound->setPitch(1+(a[k]/20));
            sound->play();
            i++;
        } else {
            a[k] = R[j];
            sound->setPitch(1+(a[k]/20));
            sound->play();
            j++;
        }
        k++;
        draw(a, window);
        window->display();
    }

    while(i < n1) {
        a[k] = L[i];
        sound->setPitch(1+(a[k]/20));
        sound->play();
        i++;
        k++;
        draw(a, window);
        window->display();
    }

    while(j < n2) {
        a[k] = R[j];
        sound->setPitch(1+(a[k]/20));
        sound->play();
        j++;
        k++;
        draw(a, window);
        window->display();
    }
    // constantly polling for events because if I don't sfml will just give up
    sf::Event temp;
    window->pollEvent(temp);
}

void mergeSort(unsigned char a[], sf::RenderWindow* window, int l, int r, sf::Sound* sound){
    if(l < r) {
        int m = l+(r-l)/2;

        mergeSort(a, window, l, m, sound);
        mergeSort(a, window, m+1, r, sound);

        mergeArr(a, window, l, m, r, sound);
    }
}

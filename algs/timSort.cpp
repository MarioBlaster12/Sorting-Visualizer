#include "timSort.h"

#define RUN 32
void timSort(unsigned char a[], sf::RenderWindow* window, sf::Sound* sound) {
    for(int i = 0; i < 256; i+=RUN)
        insertionSort(a, window, i, std::min((i+RUN-1), (255)), sound);

    for(int s = RUN; s < 256; s*=2){
        for(int l = 0; l < 256; l += 2*s){
            int m = l+s-1;
            int r = std::min((l + 2*s - 1), (255));

            mergeArr(a, window, l, m, r, sound);
        }
    }
}

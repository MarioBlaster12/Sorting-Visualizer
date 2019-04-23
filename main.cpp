// Sorting algorithm visualizer
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <SFML/Audio.hpp>

#include "sortingAlgs.h"

unsigned char values[256];

#define SCREENW 1280
#define SCREENH 720

std::string sortingAlgs[] = {
    "Bubble Sort",
    "Insertion Sort",
    "Selection Sort",
    "Merge Sort",
    "Quick Sort",
    "Cocktail Shaker Sort",
    "Heap Sort",
    "Comb Sort",
    "Shell Sort",
    "Gnome Sort",
    "Binary Insertion Sort",
    "Odd Even Sort",
    "TimSort"
};

int algIndex = 0;

void randSwap(sf::RenderWindow* window) {
    for(int i = 0; i < 256; i++){
        std::swap(values[i], values[rand() % 256]);
        // constantly polling for events because if I don't sfml will just give up
        sf::Event temp;
        window->pollEvent(temp);
        draw(values, window);
        window->display();
    }
}
int main() {
    // Initialize array values
    for(int i = 0; i < 256; i++){
        values[i] = i;
    }

    // Set up sound
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("220.wav")){
        printf("Could not load sound");
        return -1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(3);
    //sound.play();

    // Set up SFML window
    sf::RenderWindow window(sf::VideoMode(SCREENW, SCREENH), "Sorting");

    // Randomly swap values
    randSwap(&window);

    // Set up text
    sf::Font font;
    // If you need a font to work just get any font and put it in the same folder as the main.cpp file, and then change the string in this line to whatever the filename of your font is
    if (!font.loadFromFile("ariblk.ttf")){
        printf("Could not load font");
        return 1;
    }

    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(30);
    text.setString(sortingAlgs[algIndex]);

    draw(values, &window);

    // SFML loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code){
                        case sf::Keyboard::Space:
                            // I'd use a switch statement if C++ let me use one on strings

                            if(sortingAlgs[algIndex] == "Bubble Sort")
                                bubbleSort(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "Insertion Sort")
                                insertionSort(values, &window, 0, 255, &sound);
                            if(sortingAlgs[algIndex] == "Selection Sort")
                                selectionSort(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "Merge Sort")
                                mergeSort(values, &window, 0, 255, &sound);
                            if(sortingAlgs[algIndex] == "Quick Sort")
                                quickSort(values, &window, 0, 255, &sound);
                            if(sortingAlgs[algIndex] == "Cocktail Shaker Sort")
                                cocktailSort(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "Heap Sort")
                                heapSort(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "Comb Sort")
                                combSort(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "Shell Sort")
                                shellSort(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "Gnome Sort")
                                gnomeSort(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "Binary Insertion Sort")
                                insertionSortB(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "Odd Even Sort")
                                oddEvenSort(values, &window, &sound);
                            if(sortingAlgs[algIndex] == "TimSort")
                                timSort(values, &window, &sound);
                            sound.stop();
                            break;

                        case sf::Keyboard::Enter:
                            randSwap(&window);
                            break;

                        case sf::Keyboard::Up:
                            algIndex++;
                            if(algIndex >= sizeof(sortingAlgs)/sizeof(std::string))
                                algIndex = 0;
                            break;

                        case sf::Keyboard::Down:
                            algIndex--;
                            if(algIndex < 0)
                                algIndex = sizeof(sortingAlgs)/sizeof(std::string)-1;
                            break;

                        default:
                            break;
                    }

                    text.setString(sortingAlgs[algIndex]);
                    printf("%i %i\n", algIndex, sizeof(sortingAlgs)/sizeof(std::string));
                    break;
                default:
                    break;
            }
        }

        draw(values, &window);
        window.draw(text);
        window.display();
    }

    return 0;
}

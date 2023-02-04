#include <iostream>
#include <random>
#include "histogram.h"

#define MAX_CYCLE 100
#define MIN_RAND 0
#define MAX_RAND 10
#define FNAME "histogram"
#define SET 3

int main() {
    unsigned cycle;
    Histogram<unsigned> *hist;
    hist = new Histogram<unsigned>[SET];
    for (int i=0; i<SET; i++) {
        hist[i].setCycle(&cycle);
        hist[i].setFname(FNAME + std::to_string(i));
    }

    // Random device
    std::random_device rd;
    // Initialize random engine
    std::mt19937 gen(rd());
    // Setting random configuration
    std::uniform_int_distribution<int> dis(MIN_RAND, MAX_RAND);

    for (int set=0; set<SET; set++) {
        for (cycle=0; cycle<MAX_CYCLE; cycle++) {
            hist[set].setVal(dis(gen));
        }
        hist[set].printHistogram();
        hist[set].makeCSV();
    }
}

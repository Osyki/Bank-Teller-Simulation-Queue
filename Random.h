//
// Created by Jonathan Rubio on 10/28/21.
// Copyright [2021]

#ifndef HW4_BANK_TELLER_QUEUE_RANDOM_H
#define HW4_BANK_TELLER_QUEUE_RANDOM_H


#include <cstdlib>
#include <ctime>

/** Class to encapsulate the standard random number generator. */
class Random {

public:

    /** Initializes the random number generator using the time
        as the seed.
    */
    Random() {
        srand(std::time(0));
    }

    /** Initializes the randon mumber generator using a
        supplied seed.
    */
    explicit Random(int seed) {
        srand(seed);
    }

    /** Returns a random integer in the range 0 â€“ n. */
    int next_int(int n) {
        return int(next_double() * n);
    }

    /** Return a random double in the range 0 â€“ 1. */
    double next_double() {
        return double(rand()) / RAND_MAX;
    }

};


#endif //HW4_BANK_TELLER_QUEUE_RANDOM_H

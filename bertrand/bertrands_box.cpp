#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "box.h"

bool pick_2();

int main() {
    std::srand(time(0));

    int iterations;
    std::cout << "Iterations (N): ";
    std::cin >> iterations;

    int num_2golds = 0;
    for (int i = 0; i < iterations; i++) {
        if (pick_2()) {
            num_2golds++;
        }
    }

    float percent = num_2golds / float(iterations) * 100;

    std::cout << num_2golds << " out of " << iterations;
    std::cout << " (" << percent << "%)" << std::endl;

    return 0;
}

bool pick_2() {
    Box boxes[] = { Box(true, true), Box(true, false), Box(false, false) };
    bool is_c1_gold = false;
    bool is_c2_gold = false;

    while (!is_c1_gold) {
        int i = std::rand() % 3;
        is_c1_gold = boxes[i].pick_coin();
        if (is_c1_gold) {
            is_c2_gold = boxes[i].pick_coin();
        }
    }

    return (is_c1_gold && is_c2_gold);
}

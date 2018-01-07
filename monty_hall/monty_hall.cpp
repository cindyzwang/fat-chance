#include <iostream>
#include <stdlib.h>
#include <time.h>

bool play(bool);

int main() {
    std::srand(time(0));

    int iterations;
    std::cout << "Iterations of switching and staying: ";
    std::cin >> iterations;

    int stay_wins = 0;
    for (int i = 0; i < iterations; i++) {
        bool won = play(false);
        if (won) stay_wins++;
    }
    float percent_stay = stay_wins / float(iterations) * 100;


    int switch_wins = 0;
    for (int i = 0; i < iterations; i++) {
        bool won = play(true);
        if (won) switch_wins++;
    }
    float percent_switch = switch_wins / float(iterations) * 100;

    std::cout << "If you stay, you win " << percent_stay << " % of plays" << std::endl;
    std::cout << "If you switch, you win " << percent_switch << " % of plays" << std::endl;

    return 0;
}

bool play(bool should_switch) {
    int winning_door = rand() % 3;
    int my_choice = rand() % 3;

    int revealed_door;
    if (winning_door == my_choice) {
        do {
            revealed_door = rand() % 3;
        } while (revealed_door == winning_door);
    } else {
        revealed_door = 3 - winning_door - my_choice;
    }
    // *reveal*

    if (should_switch) {
        my_choice = 3 - revealed_door - my_choice;
    }
    return (my_choice == winning_door);
}
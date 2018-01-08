#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>

bool collides(int);

int main() {
    std::srand(time(0));

    int iterations, num_people;
    std::cout << "Iterations (N): ";
    std::cin >> iterations;
    std::cout << "Number of people: ";
    std::cin >> num_people;

    int num_collisions = 0;
    for (int i = 0; i < iterations; i++) {
        if (collides(num_people)) {
            num_collisions++;
        }
    }
    float p = num_collisions / float(iterations) * 100;

    std::cout << "Chance of birthday collision: " << p << "%" << std::endl;
    return 0;
}

bool collides(int num) {
    // survey num people. return true if you get a birthday collision
    std::set<int> birthdays;
    bool found = false;
    for (int i = 0; i < num; i++) {
        int birthday = rand() % 365;
        std::set<int>::iterator it = birthdays.find(birthday);
        if (it == birthdays.end()) {
            birthdays.insert(birthday);
        } else {
            return true;
        }
    }
    return false;
} 
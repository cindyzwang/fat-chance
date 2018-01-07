#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>

int survey_room();

int main() {
    std::srand(time(0));

    int iterations;
    std::cout << "Iterations (N): ";
    std::cin >> iterations;

    int sum = 0;
    for (int i = 0; i < iterations; i++) {
        sum += survey_room();
    }
    int average = sum / iterations;
    std::cout << "Surveyed an average of " << average << " people to find a shared birthday" << std::endl;
    return 0;
}

int survey_room() {
    // survey a room full of people, return how many people surveyed before
    // you find 2 people who share a birthday

    std::set<int> birthdays;
    bool found = false;
    int count = 0;
    while (!found) {
        int birthday = rand() % 365;
        std::set<int>::iterator it = birthdays.find(birthday);
        if (it == birthdays.end()) {
            birthdays.insert(birthday);
            count++;
        } else {
            found = true;
        }
    }
    return count;
}
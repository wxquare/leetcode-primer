#include <iostream>
#include <random>

int generateRandomNumber(int lower, int upper) {
    // random_device is a uniformly-distributed integer random number generator
    std::random_device rd;

    // Use the random_device to seed a random number generator
    std::mt19937 gen(rd());

    // Define the range
    std::uniform_int_distribution<> dis(lower, upper);

    // Generate the random number
    return dis(gen);
}

int main() {
    int lower = 1;
    int upper = 418;

    // Generate a random number in the range [lower, upper]
    int random_number = generateRandomNumber(lower, upper);
    std::cout << "Random number between " << lower << " and " << upper << ": " << random_number << std::endl;

    return 0;
}
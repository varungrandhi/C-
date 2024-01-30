/*
    C++ Program: Dice Roll Simulation

    Description:
    This program simulates the rolling of two six-sided dice a specified number of times.
    It generates random numbers for each dice, calculates the sum of the two dice, 
    and records the occurrences of each sum in an array. The program then displays
    the results, showing the number of times each possible sum (2 to 12) was rolled.

    Structure:
    - The program includes necessary libraries for input/output and random number generation.
    - The `dice_roll` function simulates a single dice roll, generating random values for two dice.
    - In the `main` function, the user is prompted to input the number of dice roll simulations.
    - The program then performs the specified number of simulations, records the results in an array,
      and counts occurrences for each possible sum.
    - Finally, the program displays the simulation results, showing the occurrences for each sum.

    Note: The array `simulations_array` is used to store simulation results, and its size is set to 100.
          The program assumes non-negative integers for dice outcomes.

    Author: [Varun Grandhi]
    Project Name: Dice Roll Simulation
*/
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int dice_roll() {
    // Function to simulate a single dice roll and calculate the sum
    int dice1 = (int)(1 + (rand() % 6));
    int dice2 = (int)(1 + (rand() % 6));
    int diceSum = dice1 + dice2;
    return diceSum;
}

int main() {
    // Main function where the program execution begins

    int simulations; // Variable to store the number of dice roll simulations
    cout << "How many rolls? " << endl;
    cin >> simulations;

    cout << "Simulating " << simulations << " rolls" << endl;
    cout << "Result: " << endl;

    int simulations_array[100] = {}; // Array to store the results of simulations

    for(int i = 0; i <= simulations; i++) {
        // Loop to perform the specified number of simulations and store the results
        simulations_array[i] = dice_roll();
    }

    for(int j = 2; j <= 12; j++) {
        // Loop to iterate through possible sums (2 to 12) and count occurrences
        int count = 0;

        for(int k = 0; k <= simulations; k++) {
            // Loop to count occurrences of the current sum in the simulations array
            if (simulations_array[k] == j) {
                count = count + 1;
            }
        }

        cout << j << " was rolled " << count << " times " << endl;
    }

    return 0; // Return 0 to indicate successful program execution
}

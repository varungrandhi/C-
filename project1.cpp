//-------------------------------
// Name: Varun Grandhi, Project Name: Simulating dice rolls.
/* Project Description: Utilising the C++ random function, a random number is generated for every roll or toss.
The values are then assigned to the dice, and the total value of the dice is determined by summing them all.
An array is used to hold the number of same sum of dice generated in 'n' rolls, and then the count is updated using a
pointer. Finally, simulation results are printed, showing the number of rolls requested and the number of same sum of
 dice generated or rolled.*/
//-------------------------------

#include <iostream> // Header file library to carry out input and output streams. Brings all the C++ pre-processor code here.
#include <cstdlib> // This library is used as it contains functions(random) that are required for pseudo-random number generation.
#include <ctime>// This header provides us functionality of date and time, as we use time in seeding to generate diff sequence of random numbers.

using namespace std; // using namespace called std(standard) will allow us to use all things in std like cout for example.

// Declaring Functions: generateRandomNumber(), this functions used to generate the random numbers for each dice when its tossed/rolled.
// Variables in these functions are described under function definition section below.
int generateRandomNumber();

// Main Function that carries out the main block of code.
// srand((unsgined) time(NULL)) - Seeding srand with current time for diff sequence of numbers in each run.
// Variables:
// totalRollsRequested (int) - Variable that asks user for how many rolls.
// sumOccurencesArray[13] (int) - Array to store the sum of dices generated in each roll. Created 13 elements array by initializing all to zero values.
// *sumOccurencePtr(int) - Pointer defined and pointed to array_track as we use this to increment the values in array using index to count same sums.
// diceValue1 (int) - Value of the dice1 in each roll.
// diceValue2 (int) - Value of the dice2 in each roll.
// currentSum (int) - Addition of dice1 and dice2 value which gives sum of both dices in each roll.
// rollsCounter (int) - used in 'do-while' loop to keep track on the number of rolls performed.

int main(){
    srand((unsigned) time(NULL));
    
    // Variables for roll simulation and result tracking
    int totalRollsRequested; // Variable to store the user input for the number of rolls
    int sumOccurrencesArray[13] = {0}; // Array to track occurrences of each sum
    int* sumOccurrencesPtr = sumOccurrencesArray; // Pointer to the array
    int dieValue1, dieValue2, currentSum; // Variables to store values of dice and their sum
    int rollsCounter = 0; // Counter to track the number of rolls
    
    cout << "How many rolls? ";//Prints on screen and asks user for how many rolls?
    cin >> totalRollsRequested;//Input to be kept for how many rolls needed on the screen.

    // Simulate dice rolls and track occurrences using a do-while loop
    do
    {
        dieValue1 = generateRandomNumber(); // Generate a random number for the first die
        dieValue2 = generateRandomNumber(); // Generate a random number for the second die
        currentSum = dieValue1 + dieValue2; // Calculate the sum of two dice rolls
        sumOccurrencesPtr[currentSum] = sumOccurrencesPtr[currentSum] + 1; // Update the count for the current sum
        rollsCounter++;// Incrementing the counter until false
    } while (rollsCounter < totalRollsRequested);//Checks the condition until false, if true loop runs

    // Display simulation information
    cout << "Simulating " << totalRollsRequested << " rolls..." << endl;// Prints: "Simulating 100 rolls..."
    cout << "Results:" << endl;// Prints "Results:" on display

    // Display the occurrences of each sum using a do-while loop
    int sumIndex = 2;//the possible sums of two six-sided dice range from 2 to 12
    do
    {
        cout << sumIndex << " was rolled " << sumOccurrencesArray[sumIndex] << " times." << endl;/*used to print the
                                                            current sumIndex, the corresponding count of
                                                            occurrences stored in sumOccurrencesArray[sumIndex], and a message
                                                            indicating the number of times that sum was rolled.*/
        sumIndex++;//incrementing until 12
    } while (sumIndex <= 12);//terminates when sumIndex>12
    
    return 0;//return saying that there is no return value or program executed correctly
}
// Functions Definitions:
/*generateRandomNumber() - used to generate one random number each time its called in for loop and assigned to dice1 & dice2 as return values */
//rand() - Function generates the random integer.
// dieValue (int)- stores the random number generated using random function.
// returns : dieValue (integer)
// Function to generate a random number between 1 and 6 (simulate a six-sided die)
int generateRandomNumber(){
 int dieValue = (rand() % 6) + 1; // Generate a random number between 1 and 6// we used modulo operator 6 as we need only values between 0 to 5 and added 1 so it changes from 1 to 6.
 return dieValue;
};

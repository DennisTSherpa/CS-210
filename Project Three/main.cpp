// Developer: Dennis T Sherpa

#include "CornerGrocer.h"  // Includes the definition of the class CornerGrocer.
#include <iostream>  // Included to perform input and output stream operations.

int main() {
    CornerGrocer items;  // Creates an instance of the CornerGrocer class.
    
    items.StoreFile(); // Reads and stores data from the input file.

    items.SortItems(); // Sorts the list of items.

    items.FindItemFrequency(); // Finds the number of times an item was purchased.

    items.CreateDataFile(); // Creates a data file with item frequencies.

    items.DisplayMenu(); // Displays the main menu and interacts with the user.

    std::cout << "ありがとう! In other words, thank you!\n" << std::endl; // Displays a thank you message in Japanese for user's enjoyment.

    return 0;  // Indicates successful program execution.
}


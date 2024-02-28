// Developer: Dennis T Sherpa

// Header guards are included to ensure that the contents of this header file are not copied more than once into any 
// single file to prevent duplicate definitions.
#ifndef CORNER_GROCER_H
#define CORNER_GROCER_H

#include <string> // Included to perform string type vairable declarations.
#include <vector> // Included to perform vector declarations

// Definition of a class named CornerGrocer.
class CornerGrocer {
    // CornerGrocer's public section.
    public:
    // Declaration of public member functions:        
        void StoreFile(); // Stores all the information in the input file into a vector.
        void SortItems(); // Sorts through all the item names to create a vector with no repeated item names.
        void FindItemFrequency(); // Finds the number of times an item was purchased.
        void CreateDataFile(); // Creates a data file named "frequency.dat", that contains every item only once followed by the
        // number of times it was purchased.
        void DisplayMenu(); // Displays the menu.
        void OptionOne(); // Prompts user to input an item name and returns the number of times that item was purchased.
        void OptionTwo(); // Prints the list with numbers that represent the frequency of all items purchased.
        void OptionThree(); // Prints the same frequency information for all the items in the form of a histogram.

    // CornerGrocer's private section.
    private:
    // Declaration of private member variables:
        std::string itemName; // Stores an item's name.
        int itemFrequency; // Stores the number of times an item was purchased.
        std::vector<std::string> originalList; // Stores all the item names from the input file.
        std::vector<std::string> sortedList; // Stores every item's name only once.
        std::vector<int> itemOccurences; // Stores the number of times an item was purchased as an element of itemOccurences at the
        // same index of the item's frequency respective item's name index in sortedList. Example: If an item named “Spinach” is in 
        // the vector sortedList located at index 1, then the number of times “Spinach” was purchased can be found in the vector 
        // itemOccurences, also at the index 1.
};

#endif 

// Developer: Dennis T Sherpa

#include "CornerGrocer.h" // Includes the definition of the class CornerGrocer.
#include <iostream> // Included to perform input and output stream operations.
#include <fstream> // Included to work with files.
#include <vector> // Included to work with vectors.
#include <cctype> // Included to transform characters.
#include <stdexcept> // Included to handle exceptions.

using namespace std; // Included to utilize the names of objects and functions in the standard library without having
// to prefix them with std::.

unsigned int i; // Declared as a global variable to reduce variable declarations. Before usage, it will always be intialized to a
// particular value for appropriate utilization.

// Definition of StoreFile().
void CornerGrocer::StoreFile() {
    // Opens the input file as OriginalFile.
    ifstream OriginalFile("CS210_Project_Three_Input_File.txt");

    // If file was successfully opened this will prove true.
    if (OriginalFile.is_open()) {
        // Until a string is not successfully stored into itemName; this will loop will continue to iterate.
        while (getline(OriginalFile, itemName)) {
            // Appends itemName to the end of originalList as its new element.
            originalList.push_back(itemName);
        }
        // Closes the input file.
        OriginalFile.close();
    }
    // If file was not opened, then this will execute.
    else {
        cout << "Error opening file." << endl;
    }
} 

// Definition of SortItems().
void CornerGrocer::SortItems() {
    // Intialize itemFrequency to 0.
    itemFrequency = 0;
    // Declare an unsigned int j.
    unsigned int j;

    // Loop through the originalList.
    for (i = 0; i < originalList.size(); ++i) {
        // Nested loop to compare with sortedList.
        for (j = 0; j < sortedList.size(); ++j) {
            // If the item from originalList is found in sortedList, increase the frequency.
            if (originalList.at(i) == sortedList.at(j)) {
                itemFrequency += 1;
            }
        }
        // If the itemFrequency is 0, add the item to the sortedList.
        if (itemFrequency == 0) {
            sortedList.push_back(originalList.at(i));
        }
        // Reset itemFrequency to 0 for the next iteration.
        itemFrequency = 0;
    }
}

// Definition of FindItemFrequency().
void CornerGrocer::FindItemFrequency() {
    // Initialize itemFrequency to 0.
    itemFrequency = 0;
    // Declare an unsigned int j.
    unsigned int j;

    // Loop through the sortedList.
    for (i = 0; i < sortedList.size(); ++i) {
        // Nested loop to compare with originalList.
        for (j = 0; j < originalList.size(); ++j) {
            // If the item from sortedList is found in originalList, increase the frequency.
            if (sortedList.at(i) == originalList.at(j)) {
                itemFrequency += 1;
            }
        }
        // Add the final itemFrequency to the itemOccurences vector.
        itemOccurences.push_back(itemFrequency); // Doing this will build the relation between sortedList and itemOccurences, where
        // each item name in sortedList can be matched with its accurate number of appearances located in itemOccurences by index.
        // In other words, an item name in sortedList and that item's number of appearances in itemOccurences are located at the same 
        // index in their respective vectors.

        // Reset itemFrequency to 0 for the next iteration.
        itemFrequency = 0;
    }
}

// Definition of CreateDataFile().
void CornerGrocer::CreateDataFile() {
    // Create and open a data file named "frequency.dat".
    ofstream MyFile("frequency.dat"); 

    // Write every item name paired with the number of times that item appears in the input file onto the data file.
    for (i = 0; i < itemOccurences.size(); ++i) {
        MyFile << sortedList.at(i) << " " << itemOccurences.at(i) << endl;
    }

    // Close the file.
    MyFile.close();
}

// Definition of DisplayMenu().
void CornerGrocer::DisplayMenu() {
    // Initialize i to 1.
    i = 1;

    // Continue displaying the menu until the user inputs 4 to exit.
    while (i != 4) {
        // Display the menu options.
        cout << "\nMenu (Options are only integers from 1 to 4):" << endl;
        cout << "1. Display an item's frequency." << endl;
        cout << "2. Display list of items and its respective frequency." << endl;
        cout << "3. Display a histogram of items and its respective frequency." << endl;
        cout << "4. Exit program.\n" << endl;
        cout << "Your input: ";

        // Try block: Attempt to execute the code within this block.
        try
        {   
            // Store user's input into i.
            cin >> i;
            cout << endl; // For proper output appearance.
            // Check if input was successful.
            if (cin.fail()) {
                // Throw an exception of type invalid_argument with a message.
                throw invalid_argument("\nInvalid input! ");
            }
        }
        // Catch block: If an exception of type invalid_argument is thrown, catch it and handle it here.
        catch(const invalid_argument& excpt)
        {   
            // Clear cin's failbit.
            cin.clear();
            // Ignore the incorrect input.
            cin.ignore();
            // Print an error message to alert user of their invalid input.
            cout << excpt.what() << "Please try again.\n" << endl;
            // End the current iteration and continue with the next iteration.
            continue;
        }

        // Check the value of i to determine the user's choice.
        if (i == 1) {
            OptionOne(); // Call OptionOne() if user input is 1.
        }
        else if (i == 2) {
            OptionTwo(); // Call OptionTwo() if user input is 2.
        }
        else if (i == 3) {
            OptionThree(); // Call OptionThree() if user input is 3.
        }
        else if (i == 4) {
            continue; // Continue the loop to exit the program if user input is 4.
        }
        else {
            cout << "Error! Valid input are only integers from 1 to 4." << endl; 
            // Print an error message for invalid input choices.
        }
    }
}

// Definition of OptionOne().
void CornerGrocer::OptionOne() {
    // Declare a boolean value to check if an item was purchased.
    bool validItem = false;
    // Prompt user for input.
    cout << "Enter the name of the item you wish to look for: ";

    // Store input into itemName.
    cin >> itemName;
    cout << endl; // For proper output appearance.

    // Convert the first letter to uppercase.
    itemName[0] = static_cast<char>(toupper(static_cast<unsigned char>(itemName[0])));

    // Convert the rest of the letters to lowercase.
    for (i = 1; i < itemName.size(); ++i) {
        itemName[i] = static_cast<char>(tolower(static_cast<unsigned char>(itemName[i])));
    }

    // For loop to find the number of purchases of the item.
    for (i = 0; i < sortedList.size(); ++i) {
        // If the user's input matches an item name in the vector sortedList, then this will execute.
        if (itemName == sortedList.at(i)) {
            // Print the result for the user.
            cout << itemName << " was purchased " << itemOccurences.at(i) << " times." << endl;
            validItem = true;
            break;
        }
    }

    // If item was never purchased then this will execute.
    if (!validItem) {
        cout << itemName << " was not purchased at all." << endl;
    }
}

// Definition of OptionTwo().
void CornerGrocer::OptionTwo() {
    cout << endl; // For proper output appearance.

    // Display all items and their respective frequencies.
    for (i = 0; i < itemOccurences.size(); ++i) {
        cout << sortedList.at(i) << " " << itemOccurences.at(i) << endl; 
    }
}

// Definition of OptionThree().
void CornerGrocer::OptionThree() {
    cout << endl; // For proper output appearance.

    // Display a histogram of items and their respective frequencies.
    for (i = 0; i < itemOccurences.size(); ++i) {
        cout << sortedList.at(i) << " ";
        // Inner loop to print a dollar sign for each occurrence.
        for (int j = 0; j < itemOccurences.at(i); ++j) {
            cout << "$";
        }
        cout << endl;
    }
}


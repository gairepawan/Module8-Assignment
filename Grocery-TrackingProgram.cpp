// Name: Pawan Gaire
// Date: 04/18/2024
#include <iostream>
#include <fstream>
#include <map>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency; // Map to store item frequencies

public:
    // Function to read input file and populate itemFrequency map
    void readInputFile(const std::string& filename) {
        std::ifstream inputFile(filename); // Open input file stream
        if (!inputFile) { // Check if file opening failed
            std::cerr << "Error: Unable to open input file.\n"; // Print error message
            exit(1); // Exit program with error code
        }

        std::string item;
        while (inputFile >> item) { // Read items from file until end of file
            itemFrequency[item]++; // Increment frequency count for each item
        }
        inputFile.close(); // Close input file stream
    }

    // Function to get frequency of a specific item
    int getItemFrequency(const std::string& item) {
        return itemFrequency[item]; // Return frequency of specified item
    }

    // Function to print all items with their frequencies
    void printAllItemsFrequency() {
        for (const auto& pair : itemFrequency) { // Iterate over items and frequencies in map
            std::cout << pair.first << " " << pair.second << "\n"; // Print item and frequency
        }
    }

    // Function to print histogram representation of item frequencies
    void printHistogram() {
        for (const auto& pair : itemFrequency) { // Iterate over items and frequencies in map
            std::cout << pair.first << " "; // Print item name
            for (int i = 0; i < pair.second; ++i) { // Print asterisks representing frequency
                std::cout << "*";
            }
            std::cout << "\n"; // Move to next line after printing asterisks
        }
    }

    // Function to backup item frequencies to a file
    void backupDataToFile() {
        std::ofstream backupFile("frequency.dat"); // Open output file stream
        if (!backupFile) { // Check if file opening failed
            std::cerr << "Error: Unable to create backup file.\n"; // Print error message
            return; // Return without writing to file
        }

        for (const auto& pair : itemFrequency) { // Iterate over items and frequencies in map
            backupFile << pair.first << " " << pair.second << "\n"; // Write item and frequency to file
        }
        backupFile.close(); // Close output file stream
    }
};

int main() {
    GroceryTracker tracker; // Create an instance of GroceryTracker class
    tracker.readInputFile("CS210_Project_Three_Input_File.txt"); // Read input file and populate item frequencies

    int choice;
    do {
        // Display menu options
        std::cout << "Menu Options:\n";
        std::cout << "1. Lookup item frequency\n";
        std::cout << "2. Print all items with frequency\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Read user choice from console

        // Perform operations based on user choice
        switch (choice) {
        case 1: {
            std::string item;
            std::cout << "Enter item to lookup: ";
            std::cin >> item;
            std::cout << "Frequency of " << item << ": " << tracker.getItemFrequency(item) << "\n";
            break;
        }
        case 2:
            tracker.printAllItemsFrequency();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            tracker.backupDataToFile();
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4); // Continue loop until user chooses to exit

    return 0; // Exit program with success code
}

/////////////////////////////////////////////////////////////////////
// Name: Kristin Suarez
// Date: November 4, 2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: This program creates a dictionary for a
// spell checker. It initializes an array, loads words from a file,
// counts the words, and uses a debugging flag to display the
// dictionary and measure how long each function takes.
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const bool debug = false; // Set to true to enable debug output

void initalizeArray(string words[], int size);
bool loadDictionary(string words[], int size);
int countWords(string words[], int size);
void printArray(string words[], int size);

int main() {

    cout << "*****************************" << endl;
    cout << "Welcome to the Magic Spell Checker!" << endl;
    cout << "*****************************" << endl;

    const int MAX_WORDS = 1000;
    string dictionary[MAX_WORDS];
    
    auto start = high_resolution_clock::now();
    
    initalizeArray(dictionary, MAX_WORDS);

    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<microseconds>(end - start);

    
    cout << "Dictionary initialized successfully!" << endl;
    
    if(debug){
     cout << "Initialization time: " << elapsed.count() << " microseconds" << endl;
    }

    auto loadStart = high_resolution_clock::now();
    bool loaded = loadDictionary(dictionary, MAX_WORDS);
    auto loadEnd = high_resolution_clock::now();
    auto loadElapsed = duration_cast<microseconds>(loadEnd - loadStart);

    if(debug){
     cout << "Dictionary loading time: " << loadElapsed.count() << " microseconds" << endl;
    }

    if (loaded) {
     cout << "Dictionary loaded successfully!" << endl;
    } else {
     cout << "Dictionary could not be loaded." << endl;
    }

    auto countStart = high_resolution_clock::now();

    int totalWords = countWords(dictionary, MAX_WORDS);

    auto countEnd = high_resolution_clock::now();
    auto countElapsed = duration_cast<microseconds>(countEnd - countStart);

    if(debug){
     cout << "Word counting time: " << countElapsed.count() << " microseconds" << endl;
    }

    cout << "Loaded " << totalWords << " words from dictionary." << endl;
    
    if (debug) {
     auto printStart = high_resolution_clock::now();
     
     printArray(dictionary, totalWords);

     auto printEnd = high_resolution_clock::now();
        auto printElapsed = duration_cast<microseconds>(printEnd - printStart);
        cout << "Printing time: " << printElapsed.count() << " microseconds" << endl;
    }

    return 0;
}

void initalizeArray(string words[], int size){
   
    for(int i = 0; i < size; i++){
        words[i] = "";
    }
}

bool loadDictionary(string words[], int size){

    ifstream file;
    file.open("dictionary_small.txt");

    if(!file){
        cout << "Error: could not open dictionary file!" << endl;
        return false;
    }

    int count = 0;
    while(count < size && file >> words[count]){
        count++;
    }
    
    file.close();

    return true;
}

int countWords(string words[], int size){
    int count = 0;

    for(int i = 0; i < size; i++){
        if(words[i] != ""){
            count++;
        }
    }
    return count;
}

void printArray(string words[], int size) {

    for (int i = 0; i < size; i++){
     cout << i + 1 << ". " << words[i] << endl;
    }
}   
// COMSC-210 | Lab 23 | Ibrahim Bello
// I understand that this commit won't be graded, but I want
// to complete the assignment so the set assignment is easier.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <ctime>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // Create list
    list<Goat> trip;  

    // Main menu logic
    int choice;
    do {
        choice = main_menu();

        switch (choice) {
            case 1:
                add_goat(trip, names, colors);
                cout << "Goat added." << endl;
                break;
            case 2:
                delete_goat(trip);
                cout << "Goat deleted." << endl;
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                cout << "Goodbye!" << endl;;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}

int select_goat(list<Goat> trip) {
    int choice;
    cout << "Choose a goat:" << endl;
    display_trip(trip);
    cout << endl;
    cin >> choice;
    return choice;
}

void delete_goat(list<Goat> &trip) {
    cout << "Deleting a goat..." << endl;
    int choice = select_goat(trip);
    int i = 0;
    for (auto it = trip.begin(); it != trip.end(); ++it, ++i) {
        if (i == choice - 1) {
            trip.erase(it);
            return;
        }
    }
}

void add_goat(list<Goat> &trip, string nms[], string clrs[]) {
    trip.emplace_back(nms[rand() % SZ_NAMES], rand() % MAX_AGE + 1,
     clrs[rand() % SZ_COLORS]);
}


void display_trip(list<Goat> trip) {
    int count = 1;
    for (Goat goat : trip) {
        cout << "[" << count << "] " << goat.get_name() << " (" <<
        goat.get_age() << ", " << goat.get_color() << ")" << endl;
        count++; 
    }
}

int main_menu() {
    int choice;
    cout << "**** GOAT MANAGER 3001 ****" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;
    return choice; 
}
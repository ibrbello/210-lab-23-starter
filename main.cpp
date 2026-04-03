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
    bool again;

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

    //int test = main_menu();
    //cout << test;
    list<Goat> trip;   // a herd of goats is called a "trip" <-- fun fact
    // create 3 Goat objects and insert them into the list & print
    for (int i = 0; i < 3; i++) {
        Goat tmp(names[rand() % SZ_NAMES], rand() % 20 + 1);
        trip.push_back(tmp);
    }
    display_trip(trip);

    return 0;
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

int select_goat(list<Goat> trip) {
    return 0;
}

void display_trip(list<Goat> trip) {
    int count = 1;
    for (Goat goat : trip) {
        cout << "[" << count << "] " << goat.get_name() << " (" <<
        goat.get_age() << ", " << goat.get_color() << ")" << endl;
        count++; 
    }
}

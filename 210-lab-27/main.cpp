#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int CHOICES = 7;

void add_villager(map<string, tuple<int, string, string>>&);
void delete_villager(map<string, tuple<int, string, string>>&);
void increase_friendship(map<string, tuple<int, string, string>>&);
void decrease_friendship(map<string, tuple<int, string, string>>&);
void search_villager(map<string, tuple<int, string, string>>);
void display_map(map<string, tuple<int, string, string>>);
int main_menu();

int main() {
    map<string, tuple<int, string, string>> villagers;    // Map container to store all the villagers
    
    int choice = main_menu();
    while (choice != CHOICES) {
        switch(choice) {    // switch cases for each of the choices intputted by the user, while the have not selected to end the main menu
            case 1:
                add_villager(villagers);
                break;
            case 2:
                if (villagers.empty())
                    cout << "List is empty" << endl;
                else
                    delete_villager(villagers);
                    break;
            case 3:
                if (villagers.empty())
                    cout << "List is empty" << endl;
                else
                    increase_friendship(villagers);
                    break;
            case 4:
                if (villagers.empty())
                    cout << "List is empty" << endl;
                else
                    decrease_friendship(villagers);
                    break;
            case 5:
                if (villagers.empty())
                    cout << "List is empty" << endl;
                else
                    search_villager(villagers);
                    break;
            case 6:
                if (villagers.empty())
                    cout << "List is empty" << endl;
                else
                    display_map(villagers);
                    break;
            default:
                cout << "Invalid";
                break;
        }
        choice = main_menu();
    }
    villagers.clear();
    if (villagers.empty())
        cout << "List cleared" << endl;
    
    cout << "Thanks for using the VILLAGER MANAGER 3001" << endl;
    cout << "----------------------------" << endl;
    return 0;
}

int main_menu() {
        cout << "----------------------------" << endl;    // Main menu displaying allt h eoptions for the user
        cout << "*** VILLAGER MANAGER 3001 ***" << endl;
        cout << "[1] Add a villager" << endl;
        cout << "[2] Delete a villager" << endl;
        cout << "[3] Increase Friendship" << endl;
        cout << "[4] Decrease Friendship" << endl;
        cout << "[5] Search a villager" << endl;
        cout << "[6] Display villagers" << endl;
        cout << "[7] Exit" << endl;
        cout << "Choice --> ";
        int choice;
        cin >> choice;
    while (choice < 1 || choice > CHOICES) {    // validation loop to ensure user anters within range
        cout << "Invalid, try again --> ";
        cin >> choice;
    }
        cout << "----------------------------" << endl;
    
    return choice;
}

void add_villager(map<string, tuple<int, string, string>> &villagers) {    // add villager funnction
    string name;
    int friendship;
    string spec;
    string phrase;
    
    cout << "Name: ";    // User prtomted to enter the name, friend level, species, and catchphrase of each villager
    cin >> name;
    cout << "Friendship level: ";
    cin >> friendship;
    while (friendship > 10 || friendship < 0) {    // validation loop to ensure user enters friendhsip leel in range
        cout << "Enter a level between 0-10\n" << "Friendship level: ";
        cin >> friendship;
    }
    cout << "Species: ";
    cin >> spec;
    cout << "Catchphrase: ";
    cin.ignore();
    getline(cin, phrase);
    
    tuple<int, string, string> vilData = {friendship, spec, phrase};    // tuple to stores the information of the newly created villager
    villagers.insert({name, vilData});
    cout << "----------------------------" << endl;
    cout << "[" << name << "] added" << endl;
}

void delete_villager(map<string, tuple<int, string, string>> &villagers) {    // delete villager funnction
    string name;
    
    cout << "Enter name of villager you wish to delete: ";    // User enters name of villager they wish to delete
    cin >> name;
    
    villagers.erase(name);    // Villager erased from the map
    cout << "----------------------------" << endl;
    cout << "[" << name << "] deleted" << endl;
}

void increase_friendship(map<string, tuple<int, string, string>> &villagers) {    // increase friendhsip of villager funnction
    string name;
    int friendship;
    
    cout << "Enter name of villager you wish to increase friendship: ";    // User enters name of villager they wish to change
    cin >> name;
    
    string searchKey = name;
    auto it = villagers.find(searchKey);    // iterator find the location based off the searchkey
    
    if (it != villagers.end()) {    // if the iterator has no reach the end of the map
        cout << "Enter new friendship level: ";
        cin >> friendship;
        
        while (friendship < get<0>(it->second)) {    // validation loop to esnure user enters a level that is an increase
            cout << "Enter new friendship that is greater: ";
            cin >> friendship;
        }
        get<0>(it->second) = friendship;
    }
    else    // if searchKey is not found
        cout << endl << searchKey << " not found." << endl;
}

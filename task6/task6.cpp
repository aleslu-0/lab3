#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

bool initialize(vector<string> *names) {
    string rm;
    cout << "Are you sure? (y/n)" << endl;
    cin >> rm;
    if (rm == "y") {
        names->clear();
        cout << "Cleared." << endl;
        return true;
    }
    else if (rm == "n") {
        cout << "Returning to menu." << endl;
        return true;
    }
    else {
        cout << "Invalid output" << endl;
        return false;
    }
}

bool insert(vector<string> *names) {
    while (true) {
        string s;
        cout << "Name to insert: (q or Q to exit)" << endl;
        cin >> s;
        if (s == "q" || s == "Q") {
            return true;
        }
        names->insert(names->end(), s);
    }
    return false;
}

void search(const vector<string>* names) {
    string str;
    cout << "Name to search: ";
    cin >> str;
    int len = str.length();
    int size = names->size();
    //Using substring, check if substring is in each element
    for (int k = 0; k < size; k++) {
        string sstr = names->at(k);
        string substr = sstr.substr(0, len);
        if (substr == str) {
            cout << names->at(k) << endl;
        }
    }
}

bool delete_nam(vector<string>* names) {
    while (true) {
        string str;
        cout << "Name to delete: (q or Q to exit)" << endl;
        cin >> str;
        if (str == "q" || str == "Q") {
            return true;
        }
        for (int k = 0; k < names->size(); k++) {
            if (names->at(k) == str) {
                cout << names->at(k) << " was deleted" << endl;
                names->erase(names->begin());
            }
        }
    }   
    return false;
}

string print(const vector<string>* names) {
    if (names->size() == 0) {
        return "Database is empty.";
    }
    else {
        for (int k = 0; k < names->size(); k++) {
            cout << names->at(k) << endl;
        }
        return "\nDatabase finished printing.";
    }
}

void save(const vector<string>* names) {
    ofstream outfile;
    string filename;
    cout << "Name of file (e.g. filename.txt)" << endl;
    cin >> filename;
    outfile.open(filename);
    //Save names to file
    for (int k = 0; k < names->size(); k++) {
        outfile << names->at(k) << endl;
    }    
    cout << "Data saved in: " << filename << endl;
    outfile.close(); 
    cout << endl;

}

int load(vector<string>* names) {
    names->clear();
    ifstream infile;
    string filename;
    cout << "Name of file to load (.txt will be added.)" << endl;
    cin >> filename;  
    filename += ".txt";
    infile.open(filename);
    string data;
    getline(infile, data);
    //Check if first row in file is empty
    if (data == "") {
        cout << "No data found." << endl;
        return 0;
    }
    cout << "Loading " << filename << endl;
    //Clear getline
    infile.clear();
    infile.seekg(0);
    //Read file
    while (getline(infile, data)) {
        names->insert(names->end(), data);
    }
    cout << "Data loaded." << endl;
    infile.close();
    cout << endl;
    return 0;
}

int main()
{
    vector<string>name;   
    while (true) {
        vector<string>* database = &name;
        int inp = 0;
        cout << "1. Initialise database" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Search" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Print" << endl;
        cout << "6. Save" << endl;
        cout << "7. Load" << endl;
        cout << "8. Quit" << endl;
        cin >> inp;

        if (inp == 1) {
            initialize(database);
        }
        else if (inp == 2) {
            insert(database);
        }
        else if (inp == 3) {
            search(database);
        }
        else if (inp == 4) {
            delete_nam(database);
        }
        else if (inp == 5) {
            cout << print(database) << endl;
        }
        else if (inp == 6) {
            save(database);
        }
        else if (inp == 7) {
            load(database);
        }
        else if (inp == 8) {
            return 0;
        }
        else {
            cout << "Invalid input.";
        }

    }
    return 0;
}

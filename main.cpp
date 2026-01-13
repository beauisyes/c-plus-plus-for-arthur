#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
   
   /* Overall flow of the program:
   Get some input for the title
   Get some input for column header #1
   Get some input for column header #2
   
   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces
   
   Print out data in table format
   
   Print out data in chart format
   */
// WRITE YOUR CODE HERE

    string title;
    cout << "Enter a title for the data:";
    getline(cin, title);
    cout << endl;
    cout << "You entered: " << title << endl;

    string header_one;
    string header_two;

    cout << "Enter the column 1 header:";
    getline(cin,header_one);
    cout << endl;
    cout << "You entered: " << header_one << endl;
    
    cout << "Enter the column 2 header:";
    getline(cin,header_two);
    cout << endl;
    cout << "You entered: " << header_two << endl;

    
    vector<string> strings;
    vector<int> integers;
    while (true) {
        cout << "Enter a data point (-1 to stop input):" << endl;
        string data;
        getline(cin, data);

        if (data == "-1") {
            break;
        }
        int split_point = data.find(",");
        if (split_point == string::npos) {
            cout << "Error: No comma in string." << endl;
            continue;
        }
        int more_comma_check = data.substr(split_point+1).find(",");
        if (more_comma_check != string::npos) {
            cout << "Error: Too many commas in input." << endl;
            continue;
        }

        int integer;
        string str = data.substr(0,split_point);
        try {
            integer = stoi(data.substr(split_point+2));
        } catch (const invalid_argument& e) {
            cout << "Error: Comma not followed by an integer." << endl;
            continue;
        }

        strings.push_back(str);
        integers.push_back(integer);

        cout << "Data string: " << str << endl;
        cout << "Data integer: " << integer << endl;

    }
    cout << endl;
    cout << setw(33) << right << title << endl;
    cout << setw(20) << left << header_one;
    cout << "|";
    cout << setw(23) << right << header_two << endl;
    for (int i = 0; i < 44; i++) cout << "-";
    cout << endl;
    for (int i = 0; i < strings.size(); i++) {
        cout << setw(20) << left << strings[i];
        cout << "|";
        cout << setw(23) << right << integers[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < strings.size(); i++) {
        cout << setw(20) << right << strings[i] << " ";
        for (int j = 0; j < integers[i]; j++) cout << "*";
        cout << endl;
    }
}


#include <iostream>
#include <list>
#include <vector>

using namespace std;

using Row = vector<int>;
using Spreadsheet = list<Row>;

void displaySpreadsheet(const Spreadsheet& spreadsheet) {
    cout << "---------------------------------------------------" << endl;
    for (const auto& row : spreadsheet) {
        for (int cell : row) {
            cout << "| " << cell << "\t";
        }
        cout << "|" << endl;
    }
    cout << "---------------------------------------------------" << endl;
}

void addRow(Spreadsheet& spreadsheet) {
    Row newRow;
    int cellValue;
    cout << "Enter values for the new row (enter 0 to stop): ";
    while (cin >> cellValue && cellValue != 0) {
        newRow.push_back(cellValue);
    }
    spreadsheet.push_back(newRow);
    cout << "New row added successfully!" << endl;
}

void deleteRow(Spreadsheet& spreadsheet, int rowNum) {
    if (rowNum < 1 || rowNum > spreadsheet.size()) {
        cout << "Invalid row number! Please try again." << endl;
        return;
    }
    auto it = spreadsheet.begin();
    advance(it, rowNum - 1);
    spreadsheet.erase(it);
    cout << "Row " << rowNum << " deleted successfully!" << endl;
}

int main() {
    Spreadsheet spreadsheet;

    spreadsheet.push_back({1, 2, 3});
    spreadsheet.push_back({4, 5, 6});
    spreadsheet.push_back({7, 8, 9});

    int choice;
    do {
        cout << "\nSpreadsheet Menu:\n";
        cout << "1. Display Spreadsheet\n";
        cout << "2. Add Row\n";
        cout << "3. Delete Row\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nCurrent Spreadsheet:\n";
                displaySpreadsheet(spreadsheet);
                break;
            case 2:
                addRow(spreadsheet);
                break;
            case 3:
                int rowToDelete;
                cout << "Enter the row number to delete: ";
                cin >> rowToDelete;
                deleteRow(spreadsheet, rowToDelete);
                break;
            case 4:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}


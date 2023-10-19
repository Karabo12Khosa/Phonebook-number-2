#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Contact_Book {
    string name;
    string number;
};

void printArray(Contact_Book arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << ": " << arr[i].number << endl;
    }
    cout << endl;
}

void selectionSort(Contact_Book arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].name < arr[minIndex].name) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

bool binarySearch(Contact_Book arr[], int l, int r, string x, string &result) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid].name == x) {
            result = arr[mid].number;
            return true;
        }
        if (arr[mid].name < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return false;
}

int main() {
    Contact_Book contacts[] = {{"Zulu", "082 6432 867"},{"Wiseman", "071 56378 679"}, {"Kgothatso", "060 6421 756"},
        {"Musa", "083 6534 978"},{"Lungile", "075 3564 872"},{"Faith", "078 6534 975"}, {"Katlego", "089 6534 1539"},
        {"Thato", "069 6532 657"}, {"Simphiwe", "078 6534 142"},{"Katlego", "067 8643 881"} };

    int n = sizeof(contacts) / sizeof(contacts[0]);

    cout << "Unsorted List of Names and Contact Numbers:" << endl;
    printArray(contacts, n);

    selectionSort(contacts, n);

    cout << "Sorted List of Names and Contact Numbers:" << endl;
    printArray(contacts, n);

    string search_name;
    string contact_number;
    while (true) {
        cout << "\n Enter a name to search (or 'quit' to exit): ";
        cin >> search_name;
        if (search_name == "quit") {
            break;
        }
        if (binarySearch(contacts, 0, n - 1, search_name, contact_number))
        {
            cout<< search_name << " is in the list" << endl;
            cout << " Name: " << search_name << "\n\ Contact Number: " << contact_number << endl;
        } else {
            cout << search_name << " is not in the list. " << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <list>

using namespace std;

void printList(const list<int>& lst) {
    for (const auto& element : lst) {
        cout << element << " ";
    }
    cout << endl;
}

void customSort(list<int>& lst) {
    lst.sort();
}

list<int> mergeLists(const list<int>& list1, const list<int>& list2) {
    list<int> mergedList;
    auto it1 = list1.begin();
    auto it2 = list2.begin();

    while (it1 != list1.end() && it2 != list2.end()) {
        if (*it1 < *it2) {
            mergedList.push_back(*it1);
            ++it1;
        } else {
            mergedList.push_back(*it2);
            ++it2;
        }
    }

    while (it1 != list1.end()) {
        mergedList.push_back(*it1);
        ++it1;
    }

    while (it2 != list2.end()) {
        mergedList.push_back(*it2);
        ++it2;
    }

    return mergedList;
}

int main() {
    list<int> myList;

    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    cout << "Enter " << n << " elements for the list: \n";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        myList.push_back(value);
    }

    cout << "\nOriginal list: ";
    printList(myList);

    // Sorting the list
    customSort(myList);

    cout << "\nSorted list: ";
    printList(myList);
    cout << "\n----------------------------------------\n";

    // Merging two lists
    list<int> list1, list2;
    int m;
    cout << "\nEnter the number of elements in the first list: ";
    cin >> m;
    cout << "Enter " << m << " elements for the first list: \n";
    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        list1.push_back(value);
    }

    int k;
    cout << "\nEnter the number of elements in the second list: ";
    cin >> k;
    cout << "Enter " << k << " elements for the second list: \n";
    for (int i = 0; i < k; ++i) {
        int value;
        cin >> value;
        list2.push_back(value);
    }

    list<int> mergedList = mergeLists(list1, list2);

    cout << "\nMerged list: ";
    printList(mergedList);

    return 0;
}


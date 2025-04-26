#include <iostream>
#include <vector>
using namespace std;

void showStorageOptions() {
    vector<pair<string, int>> storage = {
        {"Chennai", 500},
        {"Delhi", 700},
        {"Hyderabad", 600}
    };

    cout << "\nAvailable Storage Facilities:\n";
    for (auto &s : storage) {
        cout << s.first << " - " << s.second << " tonnes vacant\n";
    }
}

int main() {
    showStorageOptions();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

void collectFarmerData() {
    string name, crop, region;
    double acres, production;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter crop you are growing: ";
    cin >> crop;

    cout << "Enter number of acres: ";
    cin >> acres;

    cout << "Enter production in tonnes: ";
    cin >> production;

    cout << "Enter your region (Tamil Nadu/Andhra Pradesh/Punjab/West Bengal): ";
    cin >> region;

    cout << "\nData Saved Successfully!\n";
    cout << "Name: " << name << "\nCrop: " << crop << "\nAcres: " << acres << "\nProduction: " << production << " tonnes\nRegion: " << region << endl;
}

int main() {
    collectFarmerData();
    return 0;
}

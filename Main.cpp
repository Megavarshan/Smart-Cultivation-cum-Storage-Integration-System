#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct FarmerData {
    string name;
    string crop;
    double acres;
    double production;
    string region;
    string language;
};

struct WeatherInfo {
    string region;
    string season;
    string advisory;
};

struct DiseaseInfo {
    string infection;
    string chemical;
    string instructions;
    string reason;
};

map<string, WeatherInfo> weatherPatterns = {
    {"Tamil Nadu", {"Sep-Dec", "Rice season. Expect heavy rains, prepare for pest attacks."}},
    {"Andhra Pradesh", {"Jun-Sep", "Ideal for maize and pulses. Watch humidity levels."}},
    {"Punjab", {"Nov-Apr", "Wheat season. Irrigation advised after monsoon."}},
    {"West Bengal", {"Sep-Feb", "Pulses and maize season. Moisture may cause fungal infections."}}
};

map<string, DiseaseInfo> diseaseDatabase = {
    {"Rust", {"Propiconazole", "Spray during cool, moist weather.", "Rust thrives in humidity."}},
    {"Blast", {"Tricyclazole", "Apply 10-15 days post-planting.", "Affects leaves, reduces rice yield."}}
};

vector<pair<string, int>> storageFacilities = {
    {"Chennai", 500},
    {"Delhi", 700},
    {"Hyderabad", 600},
    {"Kolkata", 550}
};

void displayStorageOptions() {
    cout << "\nAvailable Storage Facilities:\n";
    for (auto &facility : storageFacilities) {
        cout << "- " << facility.first << " : " << facility.second << " tonnes available\n";
    }
}

void displayGovernmentSchemes(const string &language) {
    cout << "\n🌾 Government Schemes Recommended 🌾\n";
    cout << "1. PM-Kisan (Income support to farmers) 🌟\n";
    cout << "2. eNAM (National Agriculture Market) 🛒\n";
    cout << "3. PMFBY (Crop Insurance Scheme) 🛡️\n";
}

void diagnoseDisease(const string &language) {
    cout << "\nDo you notice any infection on your crops? (yes/no): ";
    string response;
    cin >> response;

    if (response == "yes") {
        cout << "Enter infection name (Rust/Blast): ";
        string infection;
        cin >> infection;

        if (diseaseDatabase.find(infection) != diseaseDatabase.end()) {
            DiseaseInfo info = diseaseDatabase[infection];
            cout << "\nDiagnosis Report:\n";
            cout << "Chemical: " << info.chemical << "\n";
            cout << "Instructions: " << info.instructions << "\n";
            cout << "Reason: " << info.reason << "\n";
        } else {
            cout << "No matching disease found.\n";
        }
    } else {
        cout << "✅ No infections detected. Keep monitoring your crops.\n";
    }
}

void collectFarmerData(const string &language) {
    FarmerData farmer;
    cout << "\nPlease enter your details:\n";

    cout << "Name: ";
    cin >> farmer.name;

    cout << "Crop grown: ";
    cin >> farmer.crop;

    cout << "Acres of land: ";
    cin >> farmer.acres;

    cout << "Production (in tonnes): ";
    cin >> farmer.production;

    cout << "Region (Tamil Nadu/Andhra Pradesh/Punjab/West Bengal): ";
    cin >> farmer.region;

    if (weatherPatterns.find(farmer.region) != weatherPatterns.end()) {
        cout << "\n🌦️ Weather Advisory:\n";
        cout << weatherPatterns[farmer.region].advisory << endl;
    } else {
        cout << "No weather information available for your region.\n";
    }

    displayStorageOptions();
    diagnoseDisease(language);
    displayGovernmentSchemes(language);
}

int main() {
    cout << "🌱 Smart Agriculture Management System 🌱\n";
    cout << "Select your language:\n1. English\n2. Tamil\n3. Telugu\nChoice: ";
    int langChoice;
    cin >> langChoice;

    string language = (langChoice == 2) ? "Tamil" : (langChoice == 3) ? "Telugu" : "English";

    collectFarmerData(language);

    cout << "\nThank you for using the Smart Agriculture System! 🙏\n";
    return 0;
}
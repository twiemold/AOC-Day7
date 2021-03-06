#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    fstream inputFile;
    vector<string> inputs;
    string input;
    vector<int> crabs;
    vector<vector<unsigned int>> fuelCosts;
    inputFile.open("../input.txt");
    if (inputFile.is_open()) {
        while (inputFile >> input) {
            inputs.push_back(input);
        }
    }
    inputFile.close();

    stringstream myStream(inputs[0].substr());
    while (myStream.good()) {
        string substr;
        getline(myStream, substr, ',');
        int val = stoi(substr);
        crabs.push_back(val);
    }

    int max = *std::max_element(crabs.begin(), crabs.end());

    for (int j = 0; j < max; ++j) {
        vector<unsigned int> tempFuelCosts;
        vector<unsigned int> finalValues;
        int locationVal = j;
        unsigned int fuelSum = 0;
        for (int crab : crabs) {
            unsigned int fuelCost = 0;
            int distance = abs(crab - j);
            for(int i = 1; i <= distance; ++i) {
                fuelCost += i;
            }
            tempFuelCosts.push_back(fuelCost);
        }
        for (unsigned int tempFuelCost : tempFuelCosts) {
            fuelSum += tempFuelCost;
        }
        finalValues.push_back(fuelSum);
        finalValues.push_back(locationVal);
        fuelCosts.push_back(finalValues);
    }

    unsigned int minFuel = fuelCosts[0][0];
    unsigned int minLocation = -1;
    for (auto & fuelCost : fuelCosts) {
        if (fuelCost[0] < minFuel) {
            minFuel = fuelCost[0];
            minLocation = fuelCost[1];
        }
    }

    cout << "The minimum amount of fuel is " + to_string(minFuel)
         + " at location " + to_string(minLocation);

    return 0;
}

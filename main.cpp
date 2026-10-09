/*
Developer: Jayden Veloz
File Name: Ch4Ex3.cpp
Date: 10 / 9 / 26
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    //Variables
    const double planA = 39.99;
    const double planAGBs = 2;

    const double planB = 59.99;
    const double planBGBs = 8;

    const double planC = 79.99;

    string customer, month;
    double usedGBs, costA, costB, AsavedCostB, AsavedCostC, BsavedCostC;
    char planType;

    // Inputs
    cout << "Please enter your name: ";
    cin >> customer;

    cout << "What month is this for? ";
    cin >> month;

    cout << "How much data did you use this month? ";
    cin >> usedGBs;

    cout << "What plan are you on? ";
    cin >> planType;

    // Checks for cost using Plan A
    if (usedGBs > planAGBs) {
        costA = (usedGBs - planAGBs) * 8 + planA;
    } else {
        costA = planA;
    }

    // Checks for cost using Plan B
    if (usedGBs > planBGBs) {
        costB = (usedGBs - planBGBs) * 8 + planB;
    } else {
        costB = planB;
    }

    // Calculates saved costs
    AsavedCostB = costA - costB;
    AsavedCostC = costA - planC;
    BsavedCostC = costB - planC;

    switch (planType) {
        // Plan A
        case 'A': cout << "\nHello " << customer << "! \nYour Plan " << planType << " bill for the month of "
            << month << " is $" << costA << endl;

            // Outputs other plans if cheaper than initial plan
            if (costA > costB && costA > planC) {
                cout << "\nBy switching to Plan B, you can save up to $" << fixed << setprecision(2) << AsavedCostB << "!" << endl;
                cout << "By switching to Plan C, you can save even more! Up to $" << fixed << setprecision(2) << AsavedCostC << "!" << endl;
            } else if (costA > costB) {
                cout << "By switching to Plan B, you can save up to $" << fixed << setprecision(2) << AsavedCostB << "!" << endl;
            }

            break;
        // PLan B
        case 'B': cout << "\nHello " << customer << "! \nYour Plan " << planType << " bill for the month of "
            << month << " is $" << costB << endl;

            // Outputs other plans if cheaper than initial plan
            if (costB > planC) {
                cout << "\nBy switching to Plan C, you can save up to $" << fixed << setprecision(2) << BsavedCostC << "!" << endl;
            }

            break;
        // Plan C
        case 'C': cout << "\nHello " << customer << "! \nYour Plan " << planType << " bill for the month of "
            << month << " is $" << planC << endl;

            break;
        // Invalid input
        default: cout << "Please enter a valid plan" << endl;
            break;

    }

    return 0;
}
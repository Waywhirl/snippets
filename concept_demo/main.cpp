#include <iostream>
#include <string>
#include <chrono>
#include <thread> //this is for being able to sleep the program

using namespace std;


string binToHex(string bin) {
    string hex = "";
    for(int i = 0; i < bin.size(); i += 4) {
        string nibble = bin.substr(i, 4);
        if(nibble == "0000") hex += "0";
        else if(nibble == "0001") hex += "1";
        else if(nibble == "0010") hex += "2";
        else if(nibble == "0011") hex += "3";
        else if(nibble == "0100") hex += "4";
        else if(nibble == "0101") hex += "5";
        else if(nibble == "0110") hex += "6";
        else if(nibble == "0111") hex += "7";
        else if(nibble == "1000") hex += "8";
        else if(nibble == "1001") hex += "9";
        else if(nibble == "1010") hex += "A";
        else if(nibble == "1011") hex += "B";
        else if(nibble == "1100") hex += "C";
        else if(nibble == "1101") hex += "D";
        else if(nibble == "1110") hex += "E";
        else if(nibble == "1111") hex += "F";
    }
    return hex;
}


int main() {
    string userInput;
    getline(cin, userInput);

    if(userInput == "OT toyprotocol start") {
        cout << "initializing toyprotocol..." << endl;
        cout << "Building dynaKey..." << endl;

        int numBits = 16;  // Total number of bits to generate
        string dynaKey = "";  // Start with an empty dynaKey
        string hexKey = "";

        // Generate dynaKey bits every 5 seconds
        for(int i = 0; i < numBits; i++) {
            // Wait for 5 seconds
            for(int j = 5; j > 0; j--) {
                cout << j << " " << flush;
                this_thread::sleep_for(chrono::seconds(1));
            }

            // Generate a random bit (0 or 1)
            int bit = rand() % 2;
            dynaKey += to_string(bit);  // Append the bit to the dynaKey

            if((i+1) % 4 == 0 || i+1 == numBits){
                string hex = binToHex(dynaKey.substr(dynaKey.size() - 4));
                hexKey.append(hex);
                cout << "Bit #" << i+1 << " of " << numBits << ": " << bit << " (" << dynaKey << ")" << endl;
                cout << "Hex: " << hex << endl; //print the current state of dynaKey
            } else{
                cout << "Bit #" << i+1 << " of " << numBits << ": " << bit << " (";
                cout << dynaKey << ")" << endl;  // Print the current state of the dynaKey
            }
        }

        cout << "dynaKey build complete" << endl;
        cout << "Total bits generated: " << numBits << endl;
        cout << "current binary dynaKey: " << dynaKey << endl;
        cout << "current hex dynaKey: " << hexKey << endl;
    } else {
        cout << userInput << " is not a recognized command." << endl;
    }

    return 0;
}


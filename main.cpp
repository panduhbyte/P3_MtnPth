#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
 * P3 Charles Valdez Mountain Path
 */
void in_dat();
int maxVal, minVal;
int *arrData;

int main() {
    in_dat();
    return 0;
}

void in_dat(){
    // ### Takes in file as string vector then convert to integer. ###
    ifstream infile;
    infile.open("colorado1.dat");
    vector<string> numStr;
    vector<int> numVec;

    string value;
    while(infile >> value){
        numStr.push_back(value);
    }

    infile.close();
    infile.clear();

    int numSize = numStr.size();
    for(int a=0; a < numSize; a++){
        int n = atoi(numStr.at(a).c_str());
        numVec.push_back(n);
    }

    // ### Vector data converted to integer array then find max. ###
    int * numInt = &numVec[0];

    int high = numInt[0];
    int low = numInt[0];

    for (int i = 0; i < numSize; i++) {
        if (numInt[i] > high) {high = numInt[i];}
        else if(numInt[i] < low) {low = numInt[i];}
    }
    maxVal = high;
    minVal = low;
    arrData = numInt;
}
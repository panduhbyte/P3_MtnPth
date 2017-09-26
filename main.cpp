#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
 * P3 Charles Valdez Mountain Path using
 */

// Prototype functions.
void in_dat();

// Global variables.
int *arrData, maxVal, minVal, width, height, numSize;

int main(){
    in_dat();

    // Allocate 2D array.
    int** row = new int*[height];
    for(int k=0;k<width;k++){
        row[k] = new int[width];
    }

    // Fill the 2D array.
    int data = 2;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            row[i][j] = arrData[data];
            data++;
        }
    }

    // Print 2D array.
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<row[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //##### Greedy algorithm and ppm creation.
    ofstream img;
    img.open("pic1.ppm");
    img << "P3\n" << width << " " << height << endl;
    img <<  maxVal << endl;
    int  up1, up2, up3, mid1, mid2, mid3, dn1, dn2, dn3, now1, now2, now3;


    img.close();
    img.clear();
    // Deallocate 2D Array
    for(int i=0;i<height;i++){
        delete [] row[i];
    }
    delete [] row;

    return 0;
}

void in_dat(){
    // ### Takes in file as string vector then convert to integer. ###
    ifstream infile;
    infile.open("test2.dat");
    vector<string> numStr;
    vector<int> numVec;

    string value;
    while(infile >> value){
        numStr.push_back(value);
    }

    infile.close();
    infile.clear();

    numSize = numStr.size();
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
    width = arrData[0];
    height = arrData[1];
    delete [] numInt;
}
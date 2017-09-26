#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
/*
 * P2 Charles Valdez Mountain Path
 */

int main() {
    // ### Takes in file as string vector then convert to integer. ###
    ifstream infile;
    infile.open("colorado1.dat");
    vector<string> numStr;
    vector<int> numVec;

    if(infile.fail()){
        cout<<"Oops\n";
        return 0;
    }
    else{
        string value;
        while(infile >> value){
            numStr.push_back(value);
        }
    }
    infile.close();
    infile.clear();

    int numSize = numStr.size();
    for(int a=0; a < numSize; a++){
        int n = atoi(numStr.at(a).c_str());
        numVec.push_back(n);
    }

    // ### Vector integer converted to integer array then find max. ###
    int* numInt = &numVec[0];

    int max = numInt[0];
    int min = numInt[0];

    for (int i = 0; i < numSize; i++) {
        if (numInt[i] > max) {max = numInt[i];}
        else if(numInt[i] < min) {min = numInt[i];}
    }

    // ### Making ppm file. ###
    int w = numInt[0];
    int h = numInt[1];

    ofstream img;
    img.open("pic.ppm");
    img << "P3" << endl;
    img << w << " " << h << endl;
    img <<  max << endl;

    for(int b = 2; b < numSize; b += w){
        for(int c = b; c < w + b && c < numSize; c++){
            img << numInt[c]  <<" "<< numInt[c]  <<" "<< numInt[c]  << "\t";
        }
        img << endl;
    }
    img.close();
    img.clear();

    // ### Greedy algorithm. ###
    int now, up, mid, dn;
    cout << "Insert left most position: \n";
    cin >> now;
    now = ((now * w) + 2);
    for(int d = 1; d < w; d++){
        up = now - w + 1;
        mid = now + 1;
        dn = now + w + 1;

        if(now > 0 && numInt[up] <= numInt[mid] && numInt[up] <= numInt[dn]){
            now = up;
        }
        else if(now < numSize && numInt[dn] <= numInt[mid] && numInt[dn] <= numInt[up]){
            now = dn;
        }
        else{now = mid;}
        numInt[now] = max;
    }

    // ### Making outlined ppm. ###
    img.open("pic1.ppm");
    img << "P3" << endl;
    img << w << " " << h << endl;
    img <<  max << endl;

    for(int b = 2; b < numSize; b += w){
        for(int c = b; c < w + b && c < numSize; c++){
            if(numInt[c] == max ){
                img << max  <<" "<< 0 <<" "<< 0 << "\t";
            }
            else
                img << numInt[c]  <<" "<< numInt[c]  <<" "<< numInt[c]  << "\t";
        }
        img << endl;
    }
    img.close();
    img.clear();

    return 0;
}
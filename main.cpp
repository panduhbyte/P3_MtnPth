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
    int temp1;
    temp1 = row[4][0];
    cout<<temp1<<endl;


    /*
    //##### Greedy algorithm
    int  up1, up2, up3, mid1, mid2, mid3, dn1, dn2, dn3;
    int now1, now2, now3, in1, in2, in3;
    cout<<"Enter starting point 1.\n";
    cin>>in1;
    cout<<"Enter starting point 2.\n";
    cin>>in2;
    cout<<"Enter starting point 3.\n";
    cin>>in3;

    for(int nowCol=0; nowCol<width; nowCol++){
        up1 = row[in1-1][nowCol+1];
        up2 = row[in2-1][nowCol+1];
        up3 = row[in3-1][nowCol+1];

        mid1 = row[in1][nowCol+1];
        mid2 = row[in2][nowCol+1];
        mid3 = row[in3][nowCol+1];

        dn1 = row[in1+1][nowCol+1];
        dn2 = row[in2+1][nowCol+1];
        dn3 = row[in3+1][nowCol+1];

        if(in1>0 && up1<=mid1 && up1<=dn1){in1=up1;}
        else if(in1<height && dn1<=mid1 && dn1<=up1){in1=dn1;}
        else{in1=mid1;}
        row[in1][nowCol]=maxVal;

        if(in2>0 && up2<=mid2 && up2<=dn1){in2=up2;}
        else if(in2<height && dn2<=mid2 && dn2<=up2){in2=dn2;}
        else{in2=mid2;}
        row[in2][nowCol]=maxVal;

        if(in3>0 && up3<=mid3 && up3<=dn3){in3=up3;}
        else if(in3<height && dn3<=mid3 && dn3<=up3){in3=dn3;}
        else{in3=mid3;}
        row[in3][nowCol]=maxVal;

    }




    // ppm creation.
    ofstream img;
    img.open("pic1.ppm");
    img << "P3\n" << width << " " << height << endl;
    img <<  maxVal << endl;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(row[i][j] == maxVal){img<<maxVal<<" 0 0\t";}
            else{img<<row[i][j]<<" "<<row[i][j]<<" "<<row[i][j]<<"\t";}
        }
        img<<"\n";
    }
    img.close();
    img.clear();
*/
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
    infile.open("test1.dat");
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
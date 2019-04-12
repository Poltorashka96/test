#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "SortingTest.h"
using namespace std;

void SortingTest(string fileName)
{
    extern int INPUT_FILE_SIZE;
    unsigned int tmp1, tmp2;

    cout<< "Test...\n";

    ifstream outputFileIn(fileName, ios::binary);
    outputFileIn.read((char*)&tmp1, sizeof(int));

    while(outputFileIn)
    {
        outputFileIn.read((char*)&tmp2, sizeof(int));
        if(tmp2 >= tmp1){
            tmp1 = tmp2;
        }
        else {
            cout<<"file is not sorted\n";
            break;
        }
    }
    if(outputFileIn.eof()) {
        cout<<"file is sorted\n";
    }

    outputFileIn.close();
}

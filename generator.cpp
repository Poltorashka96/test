#include "generator.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <thread>
using namespace std;

extern unsigned int INPUT_FILE_SIZE = 1024 * 1024 * 1024;//количество int переменных, которые помест€тс€ в 4√б

void generator()
{
    unsigned int tmp;
    cout<<"Loading...\n";

    mt19937 gen;
    gen.seed(time(0));

    ofstream inputFileStrmOut("inputfile.bin", ios::binary);
    if(inputFileStrmOut.is_open()){
        cout<< "Input file is open for writing\n";
    }
    else {
            cout<< "Input file is not open for writing\n";
    }

    for(int i = 0; i < INPUT_FILE_SIZE; i++)
    {
        tmp = gen();
        inputFileStrmOut.write((char*)&tmp, sizeof(int));
    }

    inputFileStrmOut.close();
}







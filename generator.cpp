#include "generator.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

extern int sizebigfile;

void generator()
{
    unsigned int a;

    mt19937 gen;
    gen.seed(time(0));
    ofstream fileStrmOut("file.bin",ios::binary);
    for(int i=0;i<sizebigfile;i++)
    {
        a=gen();
        fileStrmOut.write((char*)&a,sizeof(int));
    }
    fileStrmOut.close();
}


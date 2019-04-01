#include "generator.h"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

extern unsigned int sizebigfile=1073741824;

void generator()
{
    unsigned int a;
    //cout<<"enter the size of input file (Gb)\n";
    //cin>>sizebigfile;
    //sizebigfile=(sizebigfile*1073741824)/4;
    cout<<"Loading...\n";

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


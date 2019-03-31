#include <iostream>
#include <fstream>
#include <string>
#include "testsort.h"
using namespace std;

void testsort(string namefile){
    extern int sizebigfile;
    unsigned int tmp1,tmp2;
    int count=0;
    ifstream in(namefile,ios::binary);
    in.read((char*)&tmp1,sizeof(int));
    while(in){
        in.read((char*)&tmp2,sizeof(int));
        if(tmp2>=tmp1)
            tmp1=tmp2;
        else {
                cout<<"fail is not ordered\n";
                break;
        }
        count++;
    }
    if(in.eof()) cout<<"fail is ordered\n";
    if(count-1==sizebigfile) cout<<"sizes of files are equal\n";
    else cout<<"sizes of files are not equal\n";
    in.close();
}

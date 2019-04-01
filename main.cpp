#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include "generator.h"
#include "testsort.h"

using namespace std;
extern unsigned int sizebigfile;
void Sort(string namefile1,string namefile2,string nameoutfile);

int main()
{
    int sizefile=134217728;
    vector<unsigned int>v;
    unsigned int b;
    int j=1;

    generator();

    ifstream fileStrmIn("file.bin",ios::binary);
    while(fileStrmIn){
            if(j>sizebigfile/sizefile) break;
        for(int i=0;i<sizefile;i++){
             fileStrmIn.read((char*)&b,sizeof(int));
             v.push_back(b);
        }
        sort(v.begin(),v.end());
        ofstream out("file"+to_string(j)+".bin",ios::binary);
        for(int k=0;k<sizefile;k++){
            out.write((char*)&v[k],sizeof(int));
        }
        out.close();
        v.clear();
        j++;
    }
    fileStrmIn.close();

    int k=j;
    int lasti=k+j-3;
        for(int i=1;i<lasti;i+=2){
                Sort("file"+to_string(i)+".bin","file"+to_string(i+1)+".bin","file"+to_string(k)+".bin");
                k++;
        }

        ifstream filein("file"+to_string(k-1)+".bin",ios::binary);
        ofstream fileout("fileout.bin",ios::binary);
        while(filein){
              filein.read((char*)&b,sizeof(int));
              fileout.write((char*)&b,sizeof(int));
        }
    filein.close();
    fileout.close();

    testsort("fileout.bin");

    return 0;
}

void Sort(string namefile1,string namefile2,string nameoutfile)
{
    ifstream in1(namefile1,ios::binary);
    ifstream in2(namefile2,ios::binary);
    ofstream out1(nameoutfile,ios::binary);
    unsigned int tmp1,tmp2;
    in1.read((char*)&tmp1,sizeof(int));
    in2.read((char*)&tmp2,sizeof(int));
    while(in2){
        while(in1){
            if(tmp2>=tmp1){
                out1.write((char*)&tmp1,sizeof(int));
                in1.read((char*)&tmp1,sizeof(int));
            }
            else{
                out1.write((char*)&tmp2,sizeof(int));
                break;
            }
        }
        if(in1.eof())out1.write((char*)&tmp2,sizeof(int));
        in2.read((char*)&tmp2,sizeof(int));
    }
    if(!in1.eof())
    {
        while(!in1.eof()){
            out1.write((char*)&tmp1,sizeof(int));
            in1.read((char*)&tmp1,sizeof(int));
        }
    }
    in1.close();
    in2.close();
    out1.close();

}


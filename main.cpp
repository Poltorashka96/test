#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>>

using namespace std;

unsigned int a;
void generator();
void Sort(int m[],int n);

int main()
{
    int sizefile=4;
    vector<unsigned int>v;

    generator();

    ifstream fileStrmIn("file.bin",ios::binary);
    if(!fileStrmIn) cout<<"fail is not open\n";

    cout<<"fail is open\n";

    unsigned int b;
    int j=1;
    while(fileStrmIn){
        for(int i=0;i<sizefile;i++){
             fileStrmIn.read((char*)&b,sizeof(int));
             v.push_back(b);
        }
        sort(v.begin(),v.end());
        ofstream out("file"+to_string(j)+".bin",ios::binary);
        cout<<"file "<<j<<" is open\n";
        for(int k=0;k<sizefile;k++){
            out.write((char*)&v[k],sizeof(int));
        }
        out.close();
        v.clear();
        j++;
    }
    fileStrmIn.close();

    return 0;
}

void generator()
{
    mt19937 gen;
    gen.seed(time(0));

    int sizebigfile=16;
    ofstream fileStrmOut("file.bin",ios::binary);
    for(int i=0;i<sizebigfile;i++)
    {
        a=gen();
        fileStrmOut.write((char*)&a,sizeof(int));
    }
    fileStrmOut.close();

}

void Sort(int m[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>0;j--)
            if(m[j]<m[j-1]) swap(m[j],m[j-1]);
    }
}


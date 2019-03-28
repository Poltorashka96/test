#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

unsigned int a;
void generator();
void Sort(int m[],int n);

int main()
{
    generator();

    ifstream fileStrmIn("file.bin",ios::binary);
    if(!fileStrmIn) cout<<"fail is not open\n";

    cout<<"fail is open\n";

    unsigned int b;
    int j=1;
    while(fileStrmIn){
        ofstream out("file"+to_string(j)+".bin",ios::binary);
        cout<<"file "<<j<<"is open\n";
        for(int i=0;i<134217728;i++){
             fileStrmIn.read((char*)&b,sizeof(int));
             out.write((char*)&b,sizeof(int));
        }
        out.close();
        j++;
    }
    fileStrmIn.close();


    return 0;
}

void generator()
{
    mt19937 gen;
    gen.seed(time(0));


    ofstream fileStrmOut("file.bin",ios::binary);
    for(int i=0;i<1073741824;i++)
    {
        a=gen();
        fileStrmOut.write((char*)&a,sizeof(int));
    }
    fileStrmOut.close();

    /*ifstream in2("file.bin",ios::binary);
    while(in2.read((char*)&a,sizeof(int)))
    cout<<a<<" ";
    in2.close();
*/
}

void Sort(int m[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>0;j--)
            if(m[j]<m[j-1]) swap(m[j],m[j-1]);
    }
}


#include <iostream>
#include <fstream>
#include<vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <utility>

using namespace std;

unsigned int a;
void generator();
void Sort(int m[],int n);

int main()
{
    generator();
    /*unsigned int buffsize=1024*1024;

    int buffer[buffsize];
    int i=1;
    FILE* ptrfile=fopen("file.bin","rb");
    while(!feof(ptrfile))
    {
    fread(buffer,sizeof(int),buffsize,ptrfile);
    Sort(buffer,buffsize);
    ofstream out("file"+to_string(i)+".bin",ios::binary);
    for(int k=0;k<buffsize;k++)
    out.write((char*)&buffer[k],sizeof(int));
    i++;
    }
    fclose(ptrfile);*/

    ifstream in("file.bin",ios::binary);
    unsigned int buffsize=1024;
    uint32_t buff[buffsize];
    int i=1;
    unsigned int j=0;
    in.seekg(0, in.end);
    unsigned int lenght = in.tellg();
    in.seekg(0,in.beg);
    unsigned int cnt = lenght/buffsize;
    while (in && j<cnt)
    {
        //in.seekg(0, in.end);
        //int lenght = in.tellg();
        //in.seekg(0,in.beg);
        //cout<<lenght;
    //in.read(buff, buffsize);
    in.read(reinterpret_cast<char *>(buff), buffsize);
    ofstream out("file"+to_string(i)+".bin",ios::binary);
    for(unsigned int k=0;k<buffsize;k++){out.write((char*)&buff[k],sizeof(uint32_t)); cout<<&buff[k]<<endl;}
    out.close();
    i++; j++;
    }
    in.close();
    /*unsigned int b;
    for(int j=1;j<=i;j++)
    {
    cout<<"file "<<j<<":\n";
    ifstream in1("file"+to_string(j)+".bin",ios::binary);
    while(in1.read((char*)&b,sizeof(int)))
    cout<<b<<" ";
    in1.close();
    cout<<endl;
    }*/

    return 0;
}

void generator()
{
    mt19937 gen;
    gen.seed(time(0));


    ofstream fileStrmOut("file.bin",ios::binary);
    for(int i=0;i<1024;i++)
    {
        a=gen();
        fileStrmOut.write((char*)&a,sizeof(int));
    }
    fileStrmOut.close();

    /*ifstream in2("file.bin",ios::binary);
    while(in2.read((char*)&a,sizeof(int)))
    cout<<a<<" ";
    in2.close();*/

}

void Sort(int m[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>0;j--)
            if(m[j]<m[j-1]) swap(m[j],m[j-1]);
    }
}


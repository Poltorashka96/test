#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstring>
#include <thread>
#include <chrono>
#include "generator.h"
#include "SortingTest.h"

using namespace std;
extern unsigned int INPUT_FILE_SIZE;
int j = 1;
const int BUFFER_SIZE = (1024 * 1024 * 1024) / 8;//количество int переменных, которые помест€тс€ в 512 ћбайт


void MergeSortFile(string fileName_1, string fileName_2, string outputFileName);
void DivideAndSort();
bool FileExist(string fileName);
void Choice (string fileName);

int main()
{
    generator();
    DivideAndSort();

    thread thread_1(MergeSortFile, "tmpfile1.bin", "tmpfile2.bin", "tmpfile9.bin");
    thread thread_2(MergeSortFile, "tmpfile3.bin", "tmpfile4.bin", "tmpfile10.bin");
    thread thread_3(MergeSortFile, "tmpfile5.bin", "tmpfile6.bin", "tmpfile11.bin");
    thread thread_4(MergeSortFile, "tmpfile7.bin", "tmpfile8.bin", "tmpfile12.bin");
    thread_1.join();
    thread_2.join();
    thread_3.join();
    thread_4.join();

    thread thread_5(MergeSortFile, "tmpfile9.bin", "tmpfile10.bin", "tmpfile13.bin");
    thread thread_6(MergeSortFile, "tmpfile11.bin", "tmpfile12.bin", "tmpfile14.bin");
    thread_5.join();
    thread_6.join();

    thread thread_7(MergeSortFile, "tmpfile13.bin", "tmpfile14.bin", "outputfile.bin");
    thread_7.join();

    SortingTest("outputfile.bin");

    return 0;
}

void MergeSortFile(string fileName_1, string fileName_2, string outputFileName)
{
        cout<< "\nMerge Sort...\n";

         if (FileExist(outputFileName)){
            Choice(outputFileName) ;
        }

        ifstream file_1_StrmIn(fileName_1, ios::binary);
        if(!file_1_StrmIn.is_open()){
            cout<< fileName_1 << " is not open\n";
            exit(1);
        }
        cout<< fileName_1 << " is open\n";

        ifstream file_2_StrmIn(fileName_2, ios::binary);
        if(!file_2_StrmIn.is_open()){
            cout<< fileName_2 << " is not open\n";
            exit(1);
        }
        cout<< fileName_2 << " is open\n";

        ofstream outFileStrmOut(outputFileName, ios::binary);
        if(!outFileStrmOut.is_open()){
            cout<< outputFileName << " is not open\n";
            exit(1);
        }
            cout<< outputFileName << " is open\n\n";

        unsigned int tmp1,tmp2;

        file_1_StrmIn.read((char*)&tmp1, sizeof(int));
        file_2_StrmIn.read((char*)&tmp2, sizeof(int));

        while(file_2_StrmIn)
        {
            while(file_1_StrmIn)
            {
                if(tmp2>=tmp1)
                {
                    outFileStrmOut.write((char*)&tmp1, sizeof(int));
                    file_1_StrmIn.read((char*)&tmp1, sizeof(int));
                }
                else
                {
                    outFileStrmOut.write((char*)&tmp2, sizeof(int));
                    break;
                }
            }
            if(file_1_StrmIn.eof()){
                outFileStrmOut.write((char*)&tmp2, sizeof(int));
            }
            file_2_StrmIn.read((char*)&tmp2, sizeof(int));
        }
        if(!file_1_StrmIn.eof())
        {
            while(!file_1_StrmIn.eof())
            {
                outFileStrmOut.write((char*)&tmp1, sizeof(int));
                file_1_StrmIn.read((char*)&tmp1, sizeof(int));
            }
        }

        file_1_StrmIn.close();
        file_2_StrmIn.close();
        outFileStrmOut.close();

        j++;
        numberOutFile++;
    }

void DivideAndSort()
{
    unsigned int tmp;

    vector<unsigned int>buffer;
    ifstream inputFileStrmIn("inputfile.bin", ios::binary);
    if(!inputFileStrmIn.is_open()){
        cout<<"Input file is not open for reading\n\n";
        exit(1);
    }
        cout<<"Input file is open for reading\n\n";

    while(inputFileStrmIn)
    {
        cout<<"poixali\n";
        if(j > INPUT_FILE_SIZE / BUFFER_SIZE) {
            break;
        }
        for(int i = 0; i < BUFFER_SIZE; i++)
        {
            inputFileStrmIn.read((char*)&tmp, sizeof(int));
            buffer.push_back(tmp);
        }
        sort(buffer.begin(),buffer.end());

        string inputFileName = "tmpfile" + to_string(j) + ".bin";
        if (FileExist(inputFileName)){
        Choice(inputFileName) ;
        }
        ofstream tmpFileOut(inputFileName, ios::binary);
        if(!tmpFileOut.is_open()){
            cout<< "tmp file" << j << "is not open";
            exit(1);
        }
            cout<< "tmp file " << j << " is open\n";

        for(int k = 0; k < BUFFER_SIZE; k++)
        {
            tmpFileOut.write((char*)&buffer[k], sizeof(int));
        }
        tmpFileOut.close();
        buffer.clear();
        j++;
    }

    inputFileStrmIn.close();
}

bool FileExist(string fileName)
{
    ifstream file(fileName, ios::binary);
    if(file.is_open())
    {
        return true;
        file.close();
    }
    else return false;
}

void Choice (string fileName)
    {
        cout<< fileName << " is already exist\n";
        cout<< "Do you want to (o)verwrite it\n?";
        char choice;
        while(1)
        {
            cin>>choice;
            if(choice == 'y'){
                break;
            }
            else if(choice == 'n'){
                exit(1);
            }
            else{
                cout<< "Incorrect, try again";
            }
        }
    }


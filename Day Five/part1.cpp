#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

int getSeatID(string binarySpace, int currentMinRow,int currentMaxRow,int currentMinColumn,int currentMaxColumn){
    if(binarySpace[0]=='F'){
        return getSeatID(binarySpace,currentMinRow,floor(currentMaxRow/2)+currentMinRow,currentMinColumn,currentMaxColumn);    
    }
    if(binarySpace[0]=='F'){
        return getSeatID(binarySpace,currentMinRow,floor(currentMaxRow/2),currentMinColumn,currentMaxColumn);    
    }
}
// main() is where program execution begins.
int main()
{
    int valid = 0;
    fstream inputFile;
    // Reading a file from https://www.tutorialspoint.com/read-data-from-a-text-file-using-cplusplus#:~:text=Read%20Data%20from%20a%20Text%20File%20using%20C%2B%2B,operation%20using%20object%20newfile.%204%20Example%205%20Output
    inputFile.open("input.txt", ios::in); //open a file to perform read operation using file object
    int maxID=0;
    if (inputFile.is_open())
    { //checking whether the file is open
        string tp;
        while (getline(inputFile, tp))
        {
            //read data from file object and put it into string.
            cout << tp << "\n";
            int seatID = getSeatID(tp,0,127);
    }
    return 0;
}
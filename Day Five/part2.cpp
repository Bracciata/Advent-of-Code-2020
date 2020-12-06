#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <cmath>
#include <algorithm>
#include <vector>       // std::vector

using namespace std;

//https://www.programiz.com/cpp-programming/examples/binary-decimal-convert
int convertBinaryToDecimal(long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n != 0)
    {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

// main() is where program execution begins.
int main()
{
    int seatIDs[813];
    int currentSeats = 0;
    int valid = 0;
    fstream inputFile;
    // Reading a file from https://www.tutorialspoint.com/read-data-from-a-text-file-using-cplusplus#:~:text=Read%20Data%20from%20a%20Text%20File%20using%20C%2B%2B,operation%20using%20object%20newfile.%204%20Example%205%20Output
    inputFile.open("input.txt", ios::in); //open a file to perform read operation using file object
    if (inputFile.is_open())
    { //checking whether the file is open
        std::string tp;
        while (getline(inputFile, tp))
        {
            //read data from file object and put it into string.
            cout << tp << "\n";
            size_t pos = 0;
            while ((pos = tp.find('F', pos)) != std::string::npos)
            {
                tp.replace(pos, 1, "0");
                pos += 1;
            }
            pos = 0;
            while ((pos = tp.find('B', pos)) != std::string::npos)
            {
                tp.replace(pos, 1, "1");
                pos += 1;
            }
            cout << tp << "\n";
            std::string rowBinary = tp.substr(0, 7);
            cout << rowBinary << '\n';
            int row = convertBinaryToDecimal(std::stol(rowBinary));
            std::string colStr = tp.substr(7, 3);
            cout << colStr << '\n';
            pos = 0;
            while ((pos = colStr.find('L', pos)) != std::string::npos)
            {
                colStr.replace(pos, 1, "0");
                pos += 1;
            }
            pos = 0;
            while ((pos = colStr.find('R', pos)) != std::string::npos)
            {
                colStr.replace(pos, 1, "1");
                pos += 1;
            }
            int col = convertBinaryToDecimal(std::stol(colStr));
            seatIDs[currentSeats] = (row * 8) + col;
            currentSeats++;
        }
        std::vector<int> vectorIDs (seatIDs, seatIDs+currentSeats);   
        sort(vectorIDs.begin(), vectorIDs.end());
        for (int i = 1; i < currentSeats; i++)
        {
            if (vectorIDs[i] == vectorIDs[i - 1] + 2)
            {
                cout << "Your seat is: " << vectorIDs[i]- 1 << '\n';
                return 0;
            }
        }
        return 0;
    }
}
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// main() is where program execution begins.
int main()
{
    int numberOfLines = 0;
    fstream inputFile;
    // Reading a file from https://www.tutorialspoint.com/read-data-from-a-text-file-using-cplusplus#:~:text=Read%20Data%20from%20a%20Text%20File%20using%20C%2B%2B,operation%20using%20object%20newfile.%204%20Example%205%20Output
    inputFile.open("input.txt", ios::in); //open a file to perform read operation using file object

    if (inputFile.is_open())
    { //checking whether the file is open
        string tp;
        while (getline(inputFile, tp))
        { //read data from file object and put it into string.
            numberOfLines++;
        }
        inputFile.close(); //close the file object.
    }
    const int arrayLength = numberOfLines;
    cout << numberOfLines;
    int input[numberOfLines];
    int index = 0;
    inputFile.open("input.txt", ios::in); //open a file to perform read operation using file object

    if (inputFile.is_open())
    { //checking whether the file is open
        string tp;
        while (getline(inputFile, tp))
        { //read data from file object and put it into string.
            cout << tp;
            cout << '\n';
            input[index] = std::stoi(tp);
            index++;
        }
        inputFile.close(); //close the file object.
    }
    for (int i = 0; i < numberOfLines; ++i)
    {
        for (int j = i; j < numberOfLines; ++j)
        {
            if (input[j] + input[i] == 2020)
            {
                cout << input[j];
                cout << '\n';
                cout << input[j] * input[i];
                cout << '\n';
            }
        }
    }
    return 0;
}
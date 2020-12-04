#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getTrees(int x, int y)
{
    fstream inputFile;
    // Reading a file from https://www.tutorialspoint.com/read-data-from-a-text-file-using-cplusplus#:~:text=Read%20Data%20from%20a%20Text%20File%20using%20C%2B%2B,operation%20using%20object%20newfile.%204%20Example%205%20Output
    inputFile.open("input.txt", ios::in); //open a file to perform read operation using file object
    int trees = 0;
    if (inputFile.is_open())
    { //checking whether the file is open
        string tp;
        int lineNumber = 0;
        while (getline(inputFile, tp))
        {
            //read data from file object and put it into string.
            if (lineNumber > 0 && lineNumber % y == 0)
            {
                int spotToCheck = (x * lineNumber) % (tp.length() - 1);

                if (tp[spotToCheck] == '#')
                {
                    trees++;
                }
            }
            lineNumber++;
        }
        inputFile.close(); //close the file object.
        cout << "Total Trees: " << trees << "\n";
    }
    return trees;
}

// main() is where program execution begins.
int main()
{

    long product = 1;
    product = product * getTrees(1, 1);
    product = product * getTrees(3, 1);
    product = product * getTrees(5, 1);
    product = product * getTrees(7, 1);
    product = product * getTrees(1, 2);
    cout << "Product of the Trees: " << product << endl;
    return 0;
}
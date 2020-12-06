#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream inputFile;
    inputFile.open("input.txt", ios::in);

    if (inputFile.is_open())
    {
        string tp;
        int lineNumber = 0;
        int trees = 0;
        while (getline(inputFile, tp))
{            if (lineNumber > 0)
            {   

                int spotToCheck = (3 * lineNumber) % (tp.length() - 1);

                
                if (tp[spotToCheck] == '#')
                {
                    trees++;
                }
            }
            lineNumber++;
        }
        int spotToCheck = ((3 *(lineNumber-1)) % (tp.length()));

        if (tp[spotToCheck] == '#')
        {
            trees++;
        }

        inputFile.close();
        cout << "Total Trees: " << trees << "\n";
    }
    return 0;
}
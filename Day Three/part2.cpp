#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getTrees(int x, int y)
{
    fstream inputFile;
    inputFile.open("input.txt", ios::in);
    int trees = 0;
    if (inputFile.is_open())
    {
        string tp;
        int lineNumber = 0;
        while (getline(inputFile, tp))
        {

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
        int spotToCheck = ((x * (lineNumber - 1)) % (tp.length()));

        if (tp[spotToCheck] == '#')
        {
            trees++;
            cout << lineNumber << endl;
        }
        inputFile.close();
        cout << "Total Trees: " << trees << "\n";
    }
    return trees;
}

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
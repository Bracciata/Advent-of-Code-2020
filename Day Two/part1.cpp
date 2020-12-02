#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// main() is where program execution begins.
int main()
{
    int valid = 0;
    fstream inputFile;
    // Reading a file from https://www.tutorialspoint.com/read-data-from-a-text-file-using-cplusplus#:~:text=Read%20Data%20from%20a%20Text%20File%20using%20C%2B%2B,operation%20using%20object%20newfile.%204%20Example%205%20Output
    inputFile.open("input.txt", ios::in); //open a file to perform read operation using file object

    if (inputFile.is_open())
    { //checking whether the file is open
        string tp;
        while (getline(inputFile, tp))
        {
            //read data from file object and put it into string.
            cout << tp << "\n";
            int portionOfString = 0;
            int posOfDash;
            int lowerBound = 0;
            int upperBound = 0;
            char theLetterInPass;
            int occurrences = -1;
            for (int i = 0; i < tp.length(); ++i)
            {
                if (portionOfString == 0 && tp[i] == '-')
                {
                    ++portionOfString;
                    posOfDash = i;
                    lowerBound = std::stoi(tp.substr(0, i));
                    cout << lowerBound << '\n';
                }
                else if (portionOfString == 1 && tp[i] == ' ')
                {
                    ++portionOfString;
                    upperBound = std::stoi(tp.substr(posOfDash + 1, i));
                    cout << upperBound << '\n';
                    theLetterInPass = tp[i + 1];
                }
                else
                {
                    //cout << tp[i];
                    if (tp[i] == theLetterInPass)
                    {
                        ++occurrences;
                    }
                }
            }
            if (lowerBound <= occurrences && upperBound >= occurrences)
            {
                ++valid;
                cout << "Valid\n";
            }
        }
        inputFile.close(); //close the file object.
        cout << "Total Valid: " << valid << "\n";
    }
    return 0;
}
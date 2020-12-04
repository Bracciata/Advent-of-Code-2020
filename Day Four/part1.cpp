#include <iostream>
#include <fstream>
#include <string>
#include <array>

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
        std::array<bool, 7> requiredFields;
        for (int i = 0; i < requiredFields.size(); i++)
        {
            requiredFields[i] = false;
        }
        while (getline(inputFile, tp))
        {
            //read data from file object and put it into string.
            cout << tp << "\n";
            if (tp.length() == 1)
            {
                bool isValid = true;
                for (int i = 0; i < requiredFields.size(); i++)
                {
                    if (requiredFields[i] == false)
                    {
                        isValid = false;
                    }
                }
                if (isValid)
                {
                    valid++;
                }
                for (int i = 0; i < requiredFields.size(); i++)
                {
                    requiredFields[i] = false;
                }
            }
            else
            {
                if (tp.find("byr:") != std::string::npos)
                {
                    requiredFields[0] = true;
                }
                if (tp.find("iyr:") != std::string::npos)
                {
                    requiredFields[1] = true;
                }
                if (tp.find("eyr:") != std::string::npos)
                {
                    requiredFields[2] = true;
                }
                if (tp.find("hgt:") != std::string::npos)
                {
                    requiredFields[3] = true;
                }
                if (tp.find("hcl:") != std::string::npos)
                {
                    requiredFields[4] = true;
                }
                if (tp.find("ecl:") != std::string::npos)
                {
                    requiredFields[5] = true;
                }
                if (tp.find("pid:") != std::string::npos)
                {
                    requiredFields[6] = true;
                }
            }
        }
        bool isValid = true;
        for (int i = 0; i < requiredFields.size(); i++)
        {
            if (requiredFields[i] == false)
            {
                isValid = false;
            }
        }
        if (isValid)
        {
            valid++;
        }
        for (int i = 0; i < requiredFields.size(); i++)
        {
            requiredFields[i] = false;
        }
        inputFile.close(); //close the file object.
        cout << "Total Valid: " << valid << "\n";
    }
    return 0;
}
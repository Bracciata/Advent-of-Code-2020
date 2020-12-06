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
        int totalSum = 0;
        bool currentGroupAnswers[26];
        for (int i = 0; i < 26; i++)
        {
            currentGroupAnswers[i] = false;
        }
        while (getline(inputFile, tp))
        {
            if (tp.length() == 1)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (currentGroupAnswers[i])
                    {
                        totalSum++;
                    }
                    currentGroupAnswers[i] = false;
                }
            }
            else
            {
                for (int i = 0; i < tp.length(); i++)
                {
                    int val = tp[i];
                    currentGroupAnswers[val-97]=true;
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (currentGroupAnswers[i])
            {
                totalSum++;
            }
            currentGroupAnswers[i] = false;
        }
        inputFile.close();
        cout << "Total Yes: " << totalSum << "\n";
    }
    return 0;
}
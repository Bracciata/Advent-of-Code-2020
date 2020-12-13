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
        int accumValue=0;
        while (getline(inputFile, tp))
        {
           if(tp.substr(0,3)=="acc"){
               int accum =  std::stoi(    tp.substr(4));
               accumValue+=accum;
               cout << accumValue << '\n';
               cout << tp <<'\n';
           }
           else if(tp.substr(0,3)=="nop"){

               
           }else{
               //jmp
                           int jump =  std::stoi(    tp.substr(4));
            if(jump<0){
                break;
            }
           }
        }
        
        inputFile.close();
        cout << "Total Yes: " << accumValue << "\n";
    }
    return 0;
}
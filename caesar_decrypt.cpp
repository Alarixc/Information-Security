#include <iostream>
#include<string>
#include<fstream>
using namespace std;

string encrypt(string str, int n){
    string en = "";
    for(int i=0;i<str.length();i++){
        en += int(str[i]) - n;
        
    }
    return en;
}
int main() {
    string line;
    string something;
    ifstream file("text_encrypted.txt");
    ofstream myfile;
    myfile.open("text_decrypted.txt");
    int shift = 3;
    while(getline(file,line)){
        myfile << encrypt(line,shift);
    }
    file.close();
    myfile.close();
    return 0;
}

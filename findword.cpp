#include <iostream>
#include <fstream>
#include <vector>
int main(){
    std::ifstream inputFile("kata.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Terjadi eror saat membuka teks!" << std::endl;
        return 1;
    }
    std::vector<std::vector<char>> katakata;
    std::string kata;
    while(std::getline(inputFile,kata)){
        katakata.push_back(std::vector<char>());
        for(char &c :kata)if(c!=' '){katakata.back().push_back(toupper(c));std::cout<<(char)toupper(c);}
        std::cout<<'\n';
    }

    inputFile.close();

    return 0;
}

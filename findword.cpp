#include <iostream>
#include <fstream>
#include <vector>
int main(){
    std::ifstream inputFile("kata.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Terjadi eror saat membuka teks!" << std::endl;
        return 1;
    }
    //cek input file
    std::string kata;
    while(getline(inputFile,kata))std::cout<<kata;
    return 0;
}
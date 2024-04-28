#include <iostream>
#include <fstream>
#include <vector>
class cariKata{
    std::vector<std::vector<char>> text;
    std::vector<char> word,drow;
    int panjangKata;
    public:
    cariKata(std::vector<std::vector<char>> text, std::vector<char> word) {
        this->text = text;
        this->word = word;
        panjangKata = word.size();
    }
    bool cekKata(){
        for (int i = 0; i < text.size(); ++i) {
            for (int j = 0; j < text[i].size(); j++) {
                std::vector<char> tersedia;
                for(int k = 0; k<panjangKata;k++)tersedia.push_back(text[i][j]);
                if(tersedia==drow||tersedia==word)return 1;
            }
        }
        return 0;
    }
};

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
        for(char &c :kata)if(c!=' ')katakata.back().push_back(toupper(c));
    }
    inputFile.close();
    std::cout<<"#input :\n";
int n;
std::cin>>n;  
for(int i = 0; i < n; i++){
    std::vector<char> words;
    std::cin>>kata;
    for(char &c : kata)words.push_back(toupper(c));
    cariKata obj1(katakata,words);
    std::cout<<obj1.cekKata()<<'\n';
}
    return 0;
}
#include <iostream>  
#include <fstream> 
#include <vector> 
#include <algorithm> //untuk std::reverse

class cariKata{
    std::vector<std::vector<char>> text;
    std::vector<char> word,drow;
    int panjangKata,i,j;
    public:
    cariKata(std::vector<std::vector<char>> text, std::vector<char> word) {
        this->text = text;
        this->word = word;
        drow = word;
        std::reverse(drow.begin(), drow.end());
        panjangKata = word.size();
    }
    bool cekKata(bool bar, int kol){
        for ( i = 0; i < text.size()-bar*panjangKata+bar; ++i) {
            for ((kol!=-1)? j = 0: j = text[i].size(); (kol!=-1)?(j < text[i].size()-kol*panjangKata+kol):(j > kol*panjangKata); (kol<0)?j--:j++) {
                std::vector<char> tersedia;
                for(int k = 0; k<panjangKata;k++)tersedia.push_back(text[i+k*bar][j+k*kol]);
                if(tersedia==drow||tersedia==word)return 1;
            }
        }
        return 0;
    }
    std::string cek(){
        return adaTidak(cekKata(1,0)||cekKata(0,1)||cekKata(1,1)||cekKata(1,-1));
    }
    std::string adaTidak(bool ada) {
        if (ada) return "Ada\n";
        return "Tidak ada\n";
    }
};

int main() {
std::ifstream inputFile("kata.txt");
if (!inputFile.is_open()) {
    std::cerr << "Terjadi eror saat membuka teks!" << std::endl;
    return 1;
}
std::vector<std::vector<char>> katakata;
std::string kata;
std::vector<std::string> hasil;
while (std::getline(inputFile, kata)) {
    katakata.push_back(std::vector<char>());
    for (char& c : kata)if(c!=' ')katakata.back().push_back(toupper(c)); 
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
    hasil.push_back(obj1.cek());
}
std::cout<<"\n#Output:\n";
for(int i = 0; i<hasil.size();i++)std::cout<<hasil[i];
return 0;
}

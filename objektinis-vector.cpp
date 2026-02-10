#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>

struct Studentas{
    std::vector<std::string> vardpav;
    std::vector<std::vector<double>> paz;
    std::vector<int> m; //studento pazymiu skaicius
    std::vector<double> egz; //studento egzamino rezultatas
    
};

int n=0; //studentu sk.

int main(){
    Studentas stud;
    std::cout << "Koks yra studento vardas ir pavarde? Norint uzbaigti cikla irasykite 'baigta'" << std::endl;
    while(true){
        std::string a;
        double b;
        int p=0;
        double e;
        std::getline(std::cin, a);
        if(a == "baigta") break;
        if(a.empty()) continue;
        stud.vardpav.push_back(a);
        n++;
        stud.paz.push_back(std::vector<double>());
        std::cout<< "Kokie yra studento pazymiai? Baige parasykit 0" << std::endl;
        while(true){
            std::cin >> b;
            if(b == 0) break;
            stud.paz.back().push_back(b);
            p++;
        }
        stud.m.push_back(p);
        std::cout << "Koks yra egzamino rezultatas? ";
        std::cin >> e;
        stud.egz.push_back(e);
        std::cout << "Sekantis studentas: " << std::endl;
    }
    std::cout << std::endl;
    for(int i=0; i<n; i++){
        std::cout << stud.vardpav[i] << std::endl;
        for(int j=0; j<stud.m[i]; j++){
            std::cout << stud.paz[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
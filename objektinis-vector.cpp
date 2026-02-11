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
    std::vector<double> vid;
    std::vector<double> med;
    
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

    for(int i=0; i<n; i++){
        double sum=0;
        for(int j=0; j<stud.m[i]; j++){
            sum+=stud.paz[i][j];
        }
        double vid = (sum / stud.m[i] * 1.0) * 0.4 + 0.6 * stud.egz[i];
        stud.vid.push_back(vid);
    }

    for(int i=0; i<n; i++){
        std::sort(stud.paz[i].begin(), stud.paz[i].end());
        double med;
        if(stud.m[i] % 2 == 0){
            med = (stud.paz[i][stud.m[i]/2 - 1] + stud.paz[i][stud.m[i]/2]) / 2.0;
            stud.med.push_back(med);
        }
        else{
            med = stud.paz[i][stud.m[i]/2];
            stud.med.push_back(med);
        }
    }

    std::cout << std::endl;

    /*for(int i=0; i<n; i++){
        std::cout << stud.vardpav[i] << std::endl;
        for(int j=0; j<stud.m[i]; j++){
            std::cout << stud.paz[i][j] << " ";
        }
        std::cout<< " egz - " << stud.egz[i];
        std::cout << std::endl;
    }*/

    std::cout << std::fixed << "Vardas" << std::setw(10) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    for(int i=0; i<n; i++){
        std::cout << std::fixed << std::setprecision(2) << stud.vardpav[i] << std::setw(9) << stud.med[i] << std::endl;
    }
    return 0;
}
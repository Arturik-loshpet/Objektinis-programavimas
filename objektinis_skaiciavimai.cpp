#include "objektinis.h"

#include <algorithm>
#include <cctype>
#include <random>
#include <stdexcept>

void mediana(std::vector<Studentas>& stud){
    for(int i=0; i<stud.size(); i++){
        std::sort(stud[i].paz.begin(), stud[i].paz.end());
        int m = stud[i].paz.size();
        if(stud[i].paz.size() % 2 == 0){
            stud[i].med = (stud[i].paz[(m / 2) - 1] + stud[i].paz[m / 2]) / 2.0;
        }
        else{
            stud[i].med = stud[i].paz[m / 2];
        }
    }
}

void vidurkis(std::vector<Studentas>& stud){
    for(int i=0; i<stud.size(); i++){
        double sum=0;
        for(int j=0; j<stud[i].paz.size(); j++){
            sum += stud[i].paz[j];
        }
        stud[i].vid = (sum / double(stud[i].paz.size())) * 0.4 + stud[i].egz * 0.6;
    }
}

int validation(std::string a){
    int b;
    try {
        b = stoi(a);
        return b;
    }
    catch (std::invalid_argument&){
        return 0;
    }
}

void paz_ivestis_random(Studentas& temp, int m){
    std::random_device rd;                 
    std::mt19937 gen(rd());  //mt - varyklis, rd - seed;
    std::uniform_int_distribution<> dist(1, 10);
    for(int i = 0; i<m; i++){
        int r = dist(gen); //run engine, throug hdistribution
        temp.paz.push_back(r);
    }
}

void egz_ivestis_random(Studentas& temp){
    std::random_device rd;                 
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dist(1, 10);
    int r = dist(gen);
    temp.egz = r;
}

bool valid_name(const std::string& s) {
    if (s.empty()) return false;

    for (unsigned char c : s) {
        if (!std::isalpha(c) && c != '-') 
            return false;
    }
    return true;
}

void vardu_ivedimas_random(Studentas& temp){
    std::vector<std::string> vard = {"Artur", "Simas", "Romas", "Patrikas", "Rokas", "Ignas", "Tomas", "Rugile", "Aiste", "Martynas"};
    std::vector<std::string> pav = {"Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"};
    std::random_device rd;                 
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dist(0, 9);
    int r = dist(gen);
    temp.vardas = vard[r];
    temp.pavarde = pav[r];
}


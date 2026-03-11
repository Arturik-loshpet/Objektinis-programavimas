#include "objektinis.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <filesystem>
#include <random>

bool nuskaite;

void failu_kurimas(std::string name, int zmones, int m, double& laikas){
    std::string input;
    std::random_device rd;                 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    auto pradzia = std::chrono::high_resolution_clock::now();

    std::ofstream failas(name);
    failas << "vardas pavarde ";
    for(int i=0; i<m; i++){
        failas << " ND" << i+1;
    }
    failas << " egz" << std::endl;
    for(int i=0; i<zmones; i++){
        failas << "vardas" << i+1 << " pavarde" << i+1;
        for(int j=0; j<m; j++){
            int r = dist(gen);
            failas << " " << r;
        }
        failas << " " << dist(gen) << std::endl;
    }

    auto pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
    std::cout << zmones << " Rasymas uztruko " << trukme.count() << " ms" << std::endl;
    laikas += trukme.count();
    failas.close();
}

void isvestis_failas(std::vector<Studentas>& stud){
    std::string input;
    while(true){
        std::cout << "Duomenis rasyti: 1 - i konsole, 2 - i atskira faila: ";
        std::cin >> input;
        if(validation(input) == 1){
                std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)"  << std::setw(10) << "Galutinis (Med.)" << std::endl;
                std::cout << "-----------------------------------------------------------------------------------" << std::endl;
                for(int i=0; i<stud.size(); i++){
                std::cout << std::fixed << std::left << std::setw(15) << stud[i].vardas << std::setw(15) << stud[i].pavarde << std::setw(9) << std::setprecision(2) << stud[i].vid <<  std::setw(9) << stud[i].med << std::endl;
                }
                break;
        }
        if(validation(input) == 2){
            std::ofstream rezfailas("rezultatai.txt");
                rezfailas << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)"  << std::setw(10) << "Galutinis (Med.)" << std::endl;
                rezfailas << "-----------------------------------------------------------------------------------" << std::endl;
                for(int i=0; i<stud.size(); i++){
                rezfailas << std::fixed << std::left << std::setw(15) << stud[i].vardas << std::setw(15) << stud[i].pavarde << std::setw(9) << std::setprecision(2) << stud[i].vid <<  std::setw(9) << stud[i].med << std::endl;
                }
                rezfailas.close();
                break;
        }
        break;
    }
}

void skaitymas(Studentas& temp, std::vector<Studentas>& stud, bool& nuskaite, std::string input, double& laikas){
    std::string line;
    int paz;
    nuskaite = true;
    auto pradzia = std::chrono::high_resolution_clock::now();
    std::ifstream duomfailas(input);
    if (!duomfailas.is_open()) {
        std::cout << "Nepavyko atidaryti failo! " << std::endl;
        nuskaite = false;
        return;
    }

    if (duomfailas.peek() == std::ifstream::traits_type::eof()) {
    std::cout << "Failas tuscias!" << std::endl;
    nuskaite = false;
    return;
    }

    std::stringstream buffer;
    buffer << duomfailas.rdbuf(); 

    std::getline(buffer, line);
    while(std::getline(buffer, line)){
        Studentas temp;
        std::istringstream laik(line);
        laik >> temp.vardas >> temp.pavarde;
        while(laik >> paz){
            temp.paz.push_back(paz);
        }
        temp.egz = temp.paz.back();
        temp.paz.pop_back();
        stud.push_back(temp);
    }
    duomfailas.close();
    auto pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
    std::cout << "Skaitymas failo " << input <<" uztruko " << trukme.count() << " ms" << std::endl;
    laikas += trukme.count();
}
void skirstymas(std::vector<Studentas>& stud, std::vector<Studentas>& maladiec, std::vector<Studentas>& lopai, double& laikas){
    auto pradzia = std::chrono::high_resolution_clock::now();
    for(int i=0; i<stud.size(); i++){
        Studentas temp;
        temp = stud[i];
        if(temp.vid < 5){
            lopai.push_back(temp);
        }
        else{
            maladiec.push_back(temp);
        }
    }
    stud.clear();
    auto pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
    std::cout << "Skirstymas i 2 masyvus truko " << trukme.count() << " ms" << std::endl;
    laikas += trukme.count();
}

void rasymas(std::vector<Studentas> a, std::string name, double& laikas){
    auto pradzia = std::chrono::high_resolution_clock::now();

    std::ofstream rezfailas(name);
    rezfailas << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)"  << std::setw(10) << "Galutinis (Med.)" << std::endl;
    rezfailas << "-----------------------------------------------------------------------------------" << std::endl;
    for(int i=0; i<a.size(); i++){
        rezfailas << std::fixed << std::left << std::setw(15) << a[i].vardas << std::setw(15) << a[i].pavarde << std::setw(9) << std::setprecision(2) << a[i].vid <<  std::setw(9) << a[i].med << std::endl;               
    }
    rezfailas.close();
    auto pabaiga = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
    std::cout << name << " Rasymas truko " << trukme.count() << " ms" << std::endl;
    laikas += trukme.count();
}
void uzd_4(std::vector<Studentas>& stud, std::vector<Studentas>& maladiec, std::vector<Studentas>& lopai, double& laikas){
    vidurkis(stud);
    mediana(stud);
    rusiavimas(stud, laikas);
    skirstymas(stud, maladiec, lopai, laikas);
    rasymas(maladiec, "maladiec.txt", laikas);
    rasymas(lopai, "lopai.txt", laikas);
    std::cout << "Darbas su failu uztruko " << laikas << " ms" <<std::endl;
    std::cout << std::endl;
}
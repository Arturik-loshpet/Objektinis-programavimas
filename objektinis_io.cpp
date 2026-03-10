#include "objektinis.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <filesystem>

bool nuskaite;

void paz_sk(Studentas& temp, int& m){
    std::string input;
    while(true){
            std::cout << "Kiek pazymiu turi " << temp.vardas << " " <<temp.pavarde << "? ";
            std::cin >> input;
            m = validation(input);
            if(m == 0) std::cout << "Ne skaicius!" << std::endl;
            else if(m < 1) std::cout << "iveskite tinkama sk." <<std::endl;
            else break;
        }
}

void paz_ivestis_ranka(Studentas& temp, int m){
    std::string input;
    for(int j=0; j<m; j++){
            int pazymis;
            std::cout << "Iveskite " << j+1 << " pazymi: ";
            std::cin >> input;
            pazymis = validation(input);
            if(pazymis == 0){
                std::cout << "Ne skaicius!" << std::endl;
                j--;
                continue;
            }
            else if(pazymis > 10 || pazymis < 1){
                std::cout << "Netinkamas sk. Bandykite dar karta" << std::endl;
                j--;
                continue;
            }
            else temp.paz.push_back(pazymis);
        }
}

void egz_ivestis_ranka(Studentas& temp){
    std::string input;
    while(true){
            std::cout << "Koks yra " << temp.vardas << " " <<temp.pavarde << " egzamino rezultatas? ";
            int egz;
            std::cin >> input;
            egz = validation(input);
            if(egz == 0){
                std::cout << "Ne skaicius!" << std::endl;
                continue;
            }
            else if(egz > 10 || egz < 1){
                std::cout << "Netinkamas sk. Bandykite dar karta" << std::endl;
                continue;
            }
            else{
                temp.egz = egz;
                break;
            }
        }
}

void isvestis(std::vector<Studentas>& stud){
    std::string input;
    while(true){
        std::cout << "Ka noretumet pamatyt? Mediana - 1, arba Vidurki - 2 ";
        std::cin >> input;
        if(validation(input) == 0) std::cout << "Iveskite sk! " <<std::endl;
        else if(validation(input) != 1 && validation(input) != 2) std::cout << "Iveskite tinkama sk!"<<std::endl;
        else break;
    }
    if(validation(input) == 1){
        std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        for(int i=0; i<stud.size(); i++){
        std::cout << std::fixed << std::left << std::setw(15) << stud[i].vardas << std::setw(15) << stud[i].pavarde << std::setw(9) << std::setprecision(2) << stud[i].med << std::endl;
        }
    }
    else if(validation(input) == 2){
        std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        for(int i=0; i<stud.size(); i++){
        std::cout << std::fixed << std::left << std::setw(15) << stud[i].vardas << std::setw(15) << stud[i].pavarde << std::setw(9) << std::setprecision(2) << stud[i].vid << std::endl;
        }
    }
}

void vardu_ivedimas_ranka(Studentas& temp, std::vector<Studentas>& stud){
    while(true){
        std::string vardas, pavarde;
        std::cout << "Koks yra " << stud.size() + 1 << " studento vardas ir pavarde? ";
        std::cin >> vardas >> pavarde;
        if(valid_name(vardas) == true && valid_name(pavarde) == true){
            temp.vardas = vardas;
            temp.pavarde = pavarde;
            break;
        }
        else std::cout << "Iveskite tinkama varda ir pavarde\n";
    }
}

void skaitymas(Studentas& temp, std::vector<Studentas>& stud, bool& nuskaite){
    std::string input;
    std::string line;
    int paz;
    nuskaite = true;

    for (const auto& entry : std::filesystem::directory_iterator(".")) {
        auto name = entry.path().filename().string();
        if (entry.is_regular_file() && entry.path().extension() == ".txt" && name != "rezultatai.txt") {
            std::cout << entry.path().filename() << std::endl;
        }

    }

    std::cout << "Koki faila noretumete nuskaityti? " << std::endl;
    std::cin >> input;
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
    std::cout << "Skaitymas uztruko " << trukme.count() << " ms" << std::endl;
}

void rusiavimas(std::vector<Studentas>& stud){
    std::string input;
    while(true){
        std::cout << "Rusiuokite studentus pagal: 1 - varda, 2 - pavarde, 3 - vidurki, 4 - mediana ";
        std::cin >> input;
        if(validation(input) == 1){
            std::sort(stud.begin(), stud.end(), [](const Studentas& a, const Studentas& b) {
            return a.vardas < b.vardas;
            });
            break;
        }
        else if(validation(input) == 2){
            std::sort(stud.begin(), stud.end(), [](const Studentas& a, const Studentas& b) {
            return a.pavarde < b.pavarde;
            });
            break;
        }
        else if(validation(input) == 3){
            std::sort(stud.begin(), stud.end(), [](const Studentas& a, const Studentas& b) {
            return a.vid < b.vid;
            });
            break;
        }
        else if(validation(input) == 4){
            std::sort(stud.begin(), stud.end(), [](const Studentas& a, const Studentas& b) {
            return a.med < b.med;
            });
            break;
        }
        else std::cout << "Ivesktie tinkama sk!";  
    }
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

#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <string>
#include <stdexcept>
#include <random>
#include <cctype>
#include <fstream>
#include <sstream>
#include <chrono>
#include <filesystem>
#include "objektinis.h"



int main() {

    std::vector<Studentas> stud;
    std::string input;
    bool nuskaite=true;
    double b=0;
    double laikas=0;
    std::vector<Studentas> maladiec, lopai;
    std::cout << "Studentu Vardu ir pazymiu ivedimu sistema, skirta medianos bei vidurkio apskaiciavimui" << std::endl;
    while(true){
        Studentas temp;
        int last;
        int m;
          while(true){
            std::cout << "1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - skaityti duomenis is failo, 5 - generuoti failus, 6 - baigti darbą: ";
            std::cin >> input;
            if (validation(input) == 1){
                vardu_ivedimas_ranka(temp, stud);
                if (temp.vardas.empty() || temp.pavarde.empty()) break;
                paz_sk(temp,m);
                if (m < 1) break;
                paz_ivestis_ranka(temp, m);
                if (temp.paz.size() != static_cast<size_t>(m)) break;
                egz_ivestis_ranka(temp);
                if (temp.egz == 0) break;
                stud.push_back(temp);
            }
            else if(validation(input) == 2){
                vardu_ivedimas_ranka(temp, stud);
                if (temp.vardas.empty() || temp.pavarde.empty()) break;
                paz_sk(temp, m);
                if (m < 1) break;
                paz_ivestis_random(temp, m);
                egz_ivestis_random(temp);
                stud.push_back(temp);
            }
            else if(validation(input) == 3){
                vardu_ivedimas_random(temp);
                paz_sk(temp, m);
                paz_ivestis_random(temp, m);
                egz_ivestis_random(temp);
                stud.push_back(temp);

            }
            else if(validation(input) == 4){
                int n=0;
                for (const auto & entry : std::filesystem::directory_iterator(".")) {
                    auto name = entry.path().filename().string();
                    if (entry.is_regular_file() && entry.path().extension() == ".txt" && name != "rezultatai.txt" && name != "lopai.txt" && name != "maladiec.txt") {
                        std::cout << entry.path().filename() << std::endl;
                        n++;
                    }
                }
                if(n == 0){
                    std::cout << "Nera tinkamu failu! " << std::endl;
                    break;
                }
                else{
                    std::cout << "Koki faila noretumete nuskaityti? " << std::endl;
                    std::cin >> input;
                    skaitymas(temp, stud, nuskaite, input, laikas);
                    if(nuskaite == true){
                        testavimas(stud, maladiec, lopai, laikas);
                        break;
                    }
                    else std::cout << "Parinkite kita faila arba veskite duomenis" << std::endl;
                }
            }
            else if(validation(input) == 5){
                m = paz_sk();
                failu_kurimas("studentai1000.txt", 1000, m, b);
                failu_kurimas("studentai10000.txt", 10000, m, b);
                failu_kurimas("studentai100000.txt", 100000, m, b);
                failu_kurimas("studentai1000000.txt", 1000000, m, b);
                failu_kurimas("studentai10000000.txt", 10000000, m, b);
                std::cout << std::endl;
                tyrimai_5(stud, maladiec, lopai, laikas);
                break;
            }
            else if(validation(input) == 6){
                std::cout << "Sekmingai baigete studentu duomenu ivedima! " <<std::endl;
                break;
            }
            else std::cout << "Iveskite tinkama sk! " << std::endl;
        }
        break;
    }
    if(stud.size() == 0){
        return 0;
    }
    else{
        vidurkis(stud);
        mediana(stud);
        if (stud.size() > 1) rusiavimas(stud, b);
        isvestis_failas(stud);
    }
}

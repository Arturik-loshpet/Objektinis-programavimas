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
#include "objektinis.h"

int main() {

    std::vector<Studentas> stud;
    std::string input;
    bool nuskaite;
    std::cout << "Studentu Vardu ir pazymiu ivedimu sistema, skirta medianos bei vidurkio apskaiciavimui" << std::endl;
    while(true){
        Studentas temp;
        int last;
        int m;
          while(true){
            std::cout << "1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - skaityti duomenis is failo, 5 - baigti darbą: ";
            std::cin >> input;
            if (validation(input) == 1){
                vardu_ivedimas_ranka(temp, stud);
                paz_sk(temp,m);
                paz_ivestis_ranka(temp, m);
                egz_ivestis_ranka(temp);
                stud.push_back(temp);
            }
            else if(validation(input) == 2){
                vardu_ivedimas_ranka(temp, stud);
                paz_sk(temp, m);
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
                skaitymas(temp, stud, nuskaite);
                if(nuskaite == true) break;
                else std::cout << "Parinkite kita faila arba veskite duomenis" << std::endl;
            }
            else if(validation(input) == 5){
                std::cout << "Sekmingai baigete studentu duomenu ivedima! " <<std::endl;
                break;
            }
            else std::cout << "Iveskite tinkama sk! " << std::endl;
        }
        break;
    }
    vidurkis(stud);
    mediana(stud);
    if(validation(input) == 4){
        rusiavimas(stud);
        isvestis_failas(stud);
    }
    else isvestis(stud);
}

#include "objektinis.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

std::string input;

void paz_sk(Studentas& temp, int& m){
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

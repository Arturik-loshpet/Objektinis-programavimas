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

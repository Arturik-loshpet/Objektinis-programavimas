#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <string>
#include <stdexcept>
#include <random>
#include <cctype>

std::string input;

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz;
    int egz;
    double vid;
    double med;
};

bool valid_name(const std::string& s);
int validation(std::string a);
void paz_sk(Studentas& temp, int& m);
void paz_ivestis_ranka(Studentas& temp, int m);
void egz_ivestis_ranka(Studentas& temp);
void paz_ivestis_random(Studentas& temp, int m);
void egz_ivestis_random(Studentas& temp);
void vidurkis(std::vector<Studentas>& stud);
void mediana(std::vector<Studentas>& stud);
void isvestis(std::vector<Studentas>& stud);


int main() {

    std::vector<Studentas> stud;
    std::cout << "Studentu Vardu ir pazymiu ivedimu sistema, skirta medianos bei vidurkio apskaiciavimui" << std::endl;
    while(true){
        Studentas temp;
        int last;
        int m;
          while(true){
            std::string vardas, pavarde;
            std::cout << "Ar studentu vardus ir pavardes norite vesti: ranka - 1, ar sugeneruoti - 2? ";
            std::cin >> input;
            if (validation(input) == 1){
                while(true){
                    std::cout << "Koks yra " << stud.size() + 1 << " studento vardas ir pavarde? ";
                    std::cin >> vardas >> pavarde;
                    if(valid_name(vardas) == true && valid_name(pavarde) == true){
                        temp.vardas = vardas;
                        temp.pavarde = pavarde;
                        break;
                    }
                    else std::cout << "Iveskite tinkama varda ir pavarde\n";
                }
                break;
            }
            else if(validation(input) == 2){ 
                break;
            }
            else std::cout << "Iveskite tinkama sk! ";
        } 
        while(true){
            std::cout << "Ar studento pazymius norite vesti: ranka - 1, ar sugeneruoti - 2? ";
            std::cin >> input;
            if (validation(input) == 1){
                paz_sk(temp, m);
                paz_ivestis_ranka(temp, m);
                egz_ivestis_ranka(temp);
                break;
            }
            else if(validation(input) == 2){ 
                paz_sk(temp, m);
                paz_ivestis_random(temp, m);
                egz_ivestis_random(temp);
                break;
            }
            else std::cout << "Iveskite tinkama sk! ";
        } 
        stud.push_back(temp);
        
        while(true){
            std::cout << "Ar norite ivesti dar vieno studento duomenis? 1 - taip. 2 - ne: ";
            std::cin >> input;
            last = validation(input);
            if (last != 1 && last != 2) std::cout << "Iveskite tinkama sk! " << std::endl;
            else if(last == 2 || last == 1) break;
        }
        if(last == 2) break;
        else if (last == 1) continue;
    }

    vidurkis(stud);
    mediana(stud);
    isvestis(stud);
}
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
void isvestis(std::vector<Studentas>& stud){
    while(true){
        std::cout << "Ka noretumet pamatyt? Mediana - 1, arba Vidurki - 2 ";
        std::cin >> input;
        if(validation(input) == 0) std::cout << "Iveskite sk! ";
        else if(validation(input) != 1 && validation(input) != 2) std::cout << "Iveskite tinkama sk!";
        else break;
    }
    if(validation(input) == 1){
        std::cout << std::fixed << "Vardas" << std::setw(10) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        for(int i=0; i<stud.size(); i++){
        std::cout << std::fixed << std::setprecision(2) << stud[i].vardas << std::setw(10) << stud[i].pavarde << std::setw(9) << stud[i].med << std::endl;
        }
    }
    else if(validation(input) == 2){
        std::cout << std::fixed << "Vardas" << std::setw(10) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        for(int i=0; i<stud.size(); i++){
        std::cout << std::fixed << std::setprecision(2) << stud[i].vardas << std::setw(10) << stud[i].pavarde << std::setw(9) << stud[i].vid << std::endl;
        }
    }
}
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
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dist(1, 10);
    for(int i = 0; i<m; i++){
        int r = dist(gen);
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
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

std::string input;

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz;
    int egz;
    double vid;
    double med;
};

int n=0;

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
void vardu_ivedimas_random(Studentas& temp);
void vardu_ivedimas_ranka(Studentas& temp, std::vector<Studentas>& stud);
void skaitymas(Studentas& temp, std::vector<Studentas>& stud);
void rusiavimas(std::vector<Studentas>& stud);
void isvestis_failas(std::vector<Studentas>& stud);


int main() {

    std::vector<Studentas> stud;
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
                skaitymas(temp, stud);
                break;
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
void skaitymas(Studentas& temp, std::vector<Studentas>& stud){
    std::string line;
    int paz;
    std::ifstream duomfailas("studentai10000.txt");
    if (!duomfailas.is_open()) {
        std::cout << "Nepavyko atidaryti failo! " << std::endl;
        return;
    }
    std::getline(duomfailas, line);
    while(!duomfailas.eof()){
        Studentas temp;
        std::getline(duomfailas, line);
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
}
void rusiavimas(std::vector<Studentas>& stud){
    while(true){
        std::cout << "Rusiuokite studentus pagal: 1 - varda, 2 - pavarde, 3 - vidurki, 4 - mediana";
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
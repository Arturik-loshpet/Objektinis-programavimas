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
int n = 0;

struct Studentas {
    std::string vardas;
    std::string pavarde;
    int paz_sk = 0;
    int* paz = nullptr;
    int egz;
    double vid;
    double med;
};

int validation(std::string a);
void vardu_ivedimas_ranka(Studentas& temp);
bool valid_name(const std::string& s);
void vardu_ivedimas_random(Studentas& temp);
void paz_sk(Studentas& temp, int& m);
void paz_ivestis_ranka(Studentas& temp);
void egz_ivestis_ranka(Studentas& temp);
void paz_ivestis_random(Studentas& temp);
void egz_ivestis_random(Studentas& temp);
void mediana(Studentas stud[], int n);
void vidurkis(Studentas stud[], int n);
void isvestis(Studentas stud[], int n);

int main(){
    Studentas* stud = nullptr;
    std::cout << "Studentu Vardu ir pazymiu ivedimu sistema, skirta medianos bei vidurkio apskaiciavimui" << std::endl;
    bool baigti = false;
    while(true){
        Studentas temp;
        int m;
        while(true){
            std::cout << "1 - ranką, 2 - generuoti tik pažymius, 3 - generuoti studentų vardus, pavardės ir pažymius, 4 - baigti darbą: ";
            std::cin >> input;
            if (validation(input) == 1){
                vardu_ivedimas_ranka(temp);
                paz_sk(temp,m);
                temp.paz_sk = m;
                temp.paz = new int[m];
                paz_ivestis_ranka(temp);
                egz_ivestis_ranka(temp);
                break;
            }
            else if(validation(input) == 2){
                vardu_ivedimas_ranka(temp);
                paz_sk(temp, m);
                temp.paz_sk = m;
                temp.paz = new int[m];
                paz_ivestis_random(temp);
                egz_ivestis_random(temp);
                break;
            }
            else if(validation(input) == 3){
                vardu_ivedimas_random(temp);
                paz_sk(temp, m);
                temp.paz_sk = m;
                temp.paz = new int[m];
                paz_ivestis_random(temp);
                egz_ivestis_random(temp);
                break;

            }
            else if(validation(input) == 4){
                std::cout << "Sekmingai baigete studentu duomenu ivedima! " <<std::endl;
                baigti = true;
                break;
            }
            else std::cout << "Iveskite tinkama sk! " << std::endl;
        }
        if (baigti) break;

        Studentas* naujas_stud = new Studentas[n + 1];
        for (int i = 0; i < n; i++) {
            naujas_stud[i] = stud[i];
        }
        naujas_stud[n] = temp;
        delete[] stud;
        stud = naujas_stud;
        n++;
    }

    if (n > 0) {
        vidurkis(stud, n);
        mediana(stud, n);
        isvestis(stud, n);
    } else {
        std::cout << "Studentu duomenu nera." << std::endl;
    }

    for (int i = 0; i < n; i++) delete[] stud[i].paz;
    delete[] stud;
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
    catch (std::out_of_range&){
        return 0;
    }
}

void vardu_ivedimas_ranka(Studentas& temp){
    while(true){
        std::string vardas, pavarde;
        std::cout << "Koks yra " << n+1 << " studento vardas ir pavarde? ";
        std::cin >> vardas >> pavarde;
        if(valid_name(vardas) == true && valid_name(pavarde) == true){
            temp.vardas = vardas;
            temp.pavarde = pavarde;
            break;
        }
        else std::cout << "Iveskite tinkama varda ir pavarde" << std::endl;
    }
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
    std::string vard[10] = {"Artur", "Simas", "Romas", "Patrikas", "Rokas", "Ignas", "Tomas", "Rugile", "Aiste", "Martynas"};
    std::string pav[10] = {"Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"};
    std::random_device rd;                 
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dist(0, 9);
    int r = dist(gen);
    temp.vardas = vard[r];
    temp.pavarde = pav[r];
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
void paz_ivestis_ranka(Studentas& temp){
    for(int j=0; j<temp.paz_sk; j++){
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
        else temp.paz[j] = pazymis;
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
void paz_ivestis_random(Studentas& temp){
    std::random_device rd;                 
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dist(1, 10);
    for(int i = 0; i<temp.paz_sk; i++){
        int r = dist(gen);
        temp.paz[i] = r;
    }
}
void egz_ivestis_random(Studentas& temp){
    std::random_device rd;                 
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dist(1, 10);
    int r = dist(gen);
    temp.egz = r;
}
void mediana(Studentas stud[], int n) {
    for (int i = 0; i < n; i++) {
        std::sort(stud[i].paz, stud[i].paz + stud[i].paz_sk);
        int m = stud[i].paz_sk;
        if (m % 2 == 0) stud[i].med = (stud[i].paz[m/2 - 1] + stud[i].paz[m/2]) / 2.0; 
        else  stud[i].med = stud[i].paz[m/2];
    }
}
void vidurkis(Studentas stud[], int n) {
    for (int i = 0; i < n; i++) {

        double sum = 0.0;

        for (int j = 0; j < stud[i].paz_sk; j++) {
            sum += stud[i].paz[j];
        }

        if (stud[i].paz_sk > 0) {
            stud[i].vid = (sum / stud[i].paz_sk) * 0.4
                        + stud[i].egz * 0.6;
        } else {
            stud[i].vid = 0;
        }
    }
}
void isvestis(Studentas stud[], int n){
    while(true){
        std::cout << "Ka noretumet pamatyt? Mediana - 1, arba Vidurki - 2 ";
        std::cin >> input;
        if(validation(input) == 0) std::cout << "Iveskite sk! " << std::endl;
        else if(validation(input) != 1 && validation(input) != 2) std::cout << "Iveskite tinkama sk!" << std::endl;
        else break;
    }
    if(validation(input) == 1){
        std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        for(int i=0; i<n; i++){
        std::cout << std::fixed << std::left << std::setw(15) << stud[i].vardas << std::setw(15) << stud[i].pavarde << std::setw(9) << std::setprecision(2) << stud[i].med << std::endl;
        }
    }
    else if(validation(input) == 2){
        std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        for(int i=0; i<n; i++){
        std::cout << std::fixed << std::left << std::setw(15) << stud[i].vardas << std::setw(15) << stud[i].pavarde << std::setw(9) << std::setprecision(2) << stud[i].vid << std::endl;
        }
    }
}

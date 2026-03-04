#ifndef STUDENTAS_H
#define STUDENTAS_H
#include <string>
#include <vector>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> paz;
    int egz;
    double vid;
    double med;
};

//patikrinimai
bool valid_name(const std::string& s);
int validation(std::string a);

//rankinis ivedimas
void paz_sk(Studentas& temp, int& m);
void paz_ivestis_ranka(Studentas& temp, int m);
void egz_ivestis_ranka(Studentas& temp);
void vardu_ivedimas_ranka(Studentas& temp, std::vector<Studentas>& stud);

//randominis generavimas
void paz_ivestis_random(Studentas& temp, int m);
void egz_ivestis_random(Studentas& temp);
void vardu_ivedimas_random(Studentas& temp);

//skaiciavimas / isvestis i koncolse
void vidurkis(std::vector<Studentas>& stud);
void mediana(std::vector<Studentas>& stud);
void isvestis(std::vector<Studentas>& stud);

//darbas zu failais
void skaitymas(Studentas& temp, std::vector<Studentas>& stud);
void rusiavimas(std::vector<Studentas>& stud);
void isvestis_failas(std::vector<Studentas>& stud);

#endif
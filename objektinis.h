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
bool read_input(std::string& input);

//rankinis ivedimas
void paz_sk(Studentas& temp, int& m);
void paz_ivestis_ranka(Studentas& temp, int m);
void egz_ivestis_ranka(Studentas& temp);
void vardu_ivedimas_ranka(Studentas& temp, std::vector<Studentas>& stud);
int paz_sk();

//randominis generavimas
void paz_ivestis_random(Studentas& temp, int m);
void egz_ivestis_random(Studentas& temp);
void vardu_ivedimas_random(Studentas& temp);

//skaiciavimas / isvestis i koncolse
void vidurkis(std::vector<Studentas>& stud);
void mediana(std::vector<Studentas>& stud);
void isvestis(std::vector<Studentas>& stud);

//darbas zu failais
void skaitymas(Studentas& temp, std::vector<Studentas>& stud, bool& nuskaite, std::string input, double& laikas);
void rusiavimas(std::vector<Studentas>& stud, double& laikas);
void isvestis_failas(std::vector<Studentas>& stud);
void failu_kurimas(std::string name, int zmones, int m, double& laikas);
void rasymas(std::vector<Studentas> a, std::string name, double& laikas);
void skirstymas(std::vector<Studentas>& stud, std::vector<Studentas>& maladiec, std::vector<Studentas>& lopai, double& laikas);
void testavimas(std::vector<Studentas>& stud, std::vector<Studentas>& maladiec, std::vector<Studentas>& lopai, double& laikas);
void tyrimai_5(std::vector<Studentas>& stud, std::vector<Studentas>& maladiec, std::vector<Studentas>& lopai, double& laikas);

#endif
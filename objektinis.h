#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <deque>
#include <algorithm>
#include <list>
#include <string>
#include <vector>

template <typename GradeContainer>
struct Studentas {
    std::string vardas;
    std::string pavarde;
    GradeContainer paz;
    int egz = 0;
    double vid = 0.0;
    double med = 0.0;
};

using VectorStudent = Studentas<std::vector<int>>;
using ListStudent = Studentas<std::list<int>>;
using DequeStudent = Studentas<std::deque<int>>;

using VectorContainer = std::vector<VectorStudent>;
using ListContainer = std::list<ListStudent>;
using DequeContainer = std::deque<DequeStudent>;

bool valid_name(const std::string& s);
int validation(const std::string& a);
bool read_input(std::string& input);
int paz_sk();

template <typename T, typename Allocator, typename Compare>
void sort_container(std::list<T, Allocator>& container, Compare comp) {
    container.sort(comp);
}

template <typename Container, typename Compare>
void sort_container(Container& container, Compare comp) {
    std::sort(container.begin(), container.end(), comp);
}

template <typename GradeContainer>
double skaiciuoti_mediana(GradeContainer& paz);

template <typename Student>
void paz_sk(Student& temp, int& m);

template <typename Student>
void paz_ivestis_ranka(Student& temp, int m);

template <typename Student>
void egz_ivestis_ranka(Student& temp);

template <typename Student>
void vardu_ivedimas_ranka(Student& temp, std::size_t current_count);

template <typename Student>
void paz_ivestis_random(Student& temp, int m);

template <typename Student>
void egz_ivestis_random(Student& temp);

template <typename Student>
void vardu_ivedimas_random(Student& temp);

template <typename StudentContainer>
void vidurkis(StudentContainer& stud);

template <typename StudentContainer>
void mediana(StudentContainer& stud);

template <typename StudentContainer>
void isvestis(StudentContainer& stud);

template <typename StudentContainer>
void rusiavimas(StudentContainer& stud, double& laikas);

void failu_kurimas(const std::string& name, int zmones, int m, double& laikas);

template <typename StudentContainer>
void isvestis_failas(StudentContainer& stud);

template <typename StudentContainer>
void skaitymas(StudentContainer& stud, bool& nuskaite, const std::string& input, double& laikas);

template <typename StudentContainer>
void skirstymas(StudentContainer& stud, StudentContainer& maladiec, StudentContainer& lopai, double& laikas);

template <typename StudentContainer>
void rasymas(const StudentContainer& a, const std::string& name, double& laikas);

template <typename StudentContainer>
void testavimas(StudentContainer& stud, StudentContainer& maladiec, StudentContainer& lopai, double& laikas);

template <typename StudentContainer>
void tyrimai_5(StudentContainer& stud, StudentContainer& maladiec, StudentContainer& lopai, double& laikas);

template <typename StudentContainer>
int run_program(const std::string& konteinerio_pavadinimas);

extern template void paz_sk<VectorStudent>(VectorStudent& temp, int& m);
extern template void paz_sk<ListStudent>(ListStudent& temp, int& m);
extern template void paz_sk<DequeStudent>(DequeStudent& temp, int& m);
extern template void paz_ivestis_ranka<VectorStudent>(VectorStudent& temp, int m);
extern template void paz_ivestis_ranka<ListStudent>(ListStudent& temp, int m);
extern template void paz_ivestis_ranka<DequeStudent>(DequeStudent& temp, int m);
extern template void egz_ivestis_ranka<VectorStudent>(VectorStudent& temp);
extern template void egz_ivestis_ranka<ListStudent>(ListStudent& temp);
extern template void egz_ivestis_ranka<DequeStudent>(DequeStudent& temp);
extern template void vardu_ivedimas_ranka<VectorStudent>(VectorStudent& temp, std::size_t current_count);
extern template void vardu_ivedimas_ranka<ListStudent>(ListStudent& temp, std::size_t current_count);
extern template void vardu_ivedimas_ranka<DequeStudent>(DequeStudent& temp, std::size_t current_count);

extern template void paz_ivestis_random<VectorStudent>(VectorStudent& temp, int m);
extern template void paz_ivestis_random<ListStudent>(ListStudent& temp, int m);
extern template void paz_ivestis_random<DequeStudent>(DequeStudent& temp, int m);
extern template void egz_ivestis_random<VectorStudent>(VectorStudent& temp);
extern template void egz_ivestis_random<ListStudent>(ListStudent& temp);
extern template void egz_ivestis_random<DequeStudent>(DequeStudent& temp);
extern template void vardu_ivedimas_random<VectorStudent>(VectorStudent& temp);
extern template void vardu_ivedimas_random<ListStudent>(ListStudent& temp);
extern template void vardu_ivedimas_random<DequeStudent>(DequeStudent& temp);

extern template void vidurkis<VectorContainer>(VectorContainer& stud);
extern template void vidurkis<ListContainer>(ListContainer& stud);
extern template void vidurkis<DequeContainer>(DequeContainer& stud);
extern template void mediana<VectorContainer>(VectorContainer& stud);
extern template void mediana<ListContainer>(ListContainer& stud);
extern template void mediana<DequeContainer>(DequeContainer& stud);

extern template void isvestis<VectorContainer>(VectorContainer& stud);
extern template void isvestis<ListContainer>(ListContainer& stud);
extern template void isvestis<DequeContainer>(DequeContainer& stud);
extern template void rusiavimas<VectorContainer>(VectorContainer& stud, double& laikas);
extern template void rusiavimas<ListContainer>(ListContainer& stud, double& laikas);
extern template void rusiavimas<DequeContainer>(DequeContainer& stud, double& laikas);

extern template void isvestis_failas<VectorContainer>(VectorContainer& stud);
extern template void isvestis_failas<ListContainer>(ListContainer& stud);
extern template void isvestis_failas<DequeContainer>(DequeContainer& stud);
extern template void skaitymas<VectorContainer>(VectorContainer& stud, bool& nuskaite, const std::string& input, double& laikas);
extern template void skaitymas<ListContainer>(ListContainer& stud, bool& nuskaite, const std::string& input, double& laikas);
extern template void skaitymas<DequeContainer>(DequeContainer& stud, bool& nuskaite, const std::string& input, double& laikas);
extern template void skirstymas<VectorContainer>(VectorContainer& stud, VectorContainer& maladiec, VectorContainer& lopai, double& laikas);
extern template void skirstymas<ListContainer>(ListContainer& stud, ListContainer& maladiec, ListContainer& lopai, double& laikas);
extern template void skirstymas<DequeContainer>(DequeContainer& stud, DequeContainer& maladiec, DequeContainer& lopai, double& laikas);
extern template void rasymas<VectorContainer>(const VectorContainer& a, const std::string& name, double& laikas);
extern template void rasymas<ListContainer>(const ListContainer& a, const std::string& name, double& laikas);
extern template void rasymas<DequeContainer>(const DequeContainer& a, const std::string& name, double& laikas);
extern template void testavimas<VectorContainer>(VectorContainer& stud, VectorContainer& maladiec, VectorContainer& lopai, double& laikas);
extern template void testavimas<ListContainer>(ListContainer& stud, ListContainer& maladiec, ListContainer& lopai, double& laikas);
extern template void testavimas<DequeContainer>(DequeContainer& stud, DequeContainer& maladiec, DequeContainer& lopai, double& laikas);
extern template void tyrimai_5<VectorContainer>(VectorContainer& stud, VectorContainer& maladiec, VectorContainer& lopai, double& laikas);
extern template void tyrimai_5<ListContainer>(ListContainer& stud, ListContainer& maladiec, ListContainer& lopai, double& laikas);
extern template void tyrimai_5<DequeContainer>(DequeContainer& stud, DequeContainer& maladiec, DequeContainer& lopai, double& laikas);
extern template int run_program<VectorContainer>(const std::string& konteinerio_pavadinimas);
extern template int run_program<ListContainer>(const std::string& konteinerio_pavadinimas);
extern template int run_program<DequeContainer>(const std::string& konteinerio_pavadinimas);

#endif

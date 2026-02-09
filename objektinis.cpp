#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>

struct Studentas
{
    std::string Var="A", Pav="B";
    double rez;
    double median, vid;
    std::vector<int> paz;
};

void median(Studentas& A, double n){
    std::sort(A.paz.begin(), A.paz.end());
    if(int(n) % 2 == 0){
        A.median = (A.paz[n/2 - 1] + A.paz[n/2])/2.0;
    }
    else{
        A.median = A.paz[int(n/2)];
    }
}
void vidurkis(Studentas& A, double n){
    double sum=0;
    for(int i=0; i<n; i++){
        int temp;
        std::cout << "Ivesk " << i+1 << " is " << n << std::endl;
        std::cin >> temp;
        A.paz.push_back(temp);
        sum += temp;
    }
        std::cout << "Koks yra studento egzamino rezultatas? ";
        std::cin >> A.rez;
        A.vid = (sum / n) * 0.4 + 0.6 * A.rez;
}

int main(){
    Studentas A;
    double n;
    std::cout << "Iveskite varda ir pavarde: ";
    std::cin >> A.Var >> A.Pav;
    std::cout << "Kiek pazymiu turi studentas? ";
    std::cin >> n;
    vidurkis(A, n);
    median(A, n);
    std::cout << "Ka noretumet pamatyt? Mediana - 1, arba Vidurki - 2 ";
    int a;
    std::cin >> a;
    if(a == 1){
        std::cout << std::fixed << "Vardas" << std::setw(10) << "Pavarde" << std::setw(20) << "Galutinis (Med.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        std::cout << std::fixed << std::setprecision(2) << A.Var << std::setw(10) << A.Pav << std::setw(9) << A.median << std::endl;
    }
    else{
        std::cout << std::fixed << "Vardas" << std::setw(10) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        std::cout << std::fixed << std::setprecision(2) << A.Var << std::setw(10) << A.Pav << std::setw(9) << A.vid << std::endl;
    }
}
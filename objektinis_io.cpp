#include "objektinis.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>

bool read_input(std::string& input) {
    if (std::cin >> input) {
        return true;
    }

    if (std::cin.eof()) {
        std::cout << "Ivestis nutraukta." << std::endl;
        return false;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Netinkama ivestis. Bandykite dar karta." << std::endl;
    return false;
}

template <typename Student>
void paz_sk(Student& temp, int& m) {
    std::string input;
    while (true) {
        std::cout << "Kiek pazymiu turi " << temp.vardas << " " << temp.pavarde << "? ";
        if (!read_input(input)) {
            return;
        }
        m = validation(input);
        if (m == 0) {
            std::cout << "Ne skaicius!" << std::endl;
        } else if (m < 1) {
            std::cout << "iveskite tinkama sk." << std::endl;
        } else {
            break;
        }
    }
}

template <typename Student>
void paz_ivestis_ranka(Student& temp, int m) {
    std::string input;
    for (int j = 0; j < m; ++j) {
        std::cout << "Iveskite " << j + 1 << " pazymi: ";
        if (!read_input(input)) {
            return;
        }
        const int pazymis = validation(input);
        if (pazymis > 10 || pazymis < 1) {
            std::cout << "Netinkamas sk. Bandykite dar karta" << std::endl;
            --j;
            continue;
        }
        temp.paz.push_back(pazymis);
    }
}

template <typename Student>
void egz_ivestis_ranka(Student& temp) {
    std::string input;
    while (true) {
        std::cout << "Koks yra " << temp.vardas << " " << temp.pavarde << " egzamino rezultatas? ";
        if (!read_input(input)) {
            return;
        }
        const int egz = validation(input);
        if (egz > 10 || egz < 1) {
            std::cout << "Netinkamas sk. Bandykite dar karta" << std::endl;
            continue;
        }
        temp.egz = egz;
        break;
    }
}

template <typename Student>
void vardu_ivedimas_ranka(Student& temp, std::size_t current_count) {
    while (true) {
        std::string vardas;
        std::string pavarde;
        std::cout << "Koks yra " << current_count + 1 << " studento vardas ir pavarde? ";
        if (!(std::cin >> vardas >> pavarde)) {
            if (std::cin.eof()) {
                std::cout << "Ivestis nutraukta." << std::endl;
                return;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Netinkama ivestis. Bandykite dar karta." << std::endl;
            continue;
        }
        if (valid_name(vardas) && valid_name(pavarde)) {
            temp.vardas = vardas;
            temp.pavarde = pavarde;
            break;
        }
        std::cout << "Iveskite tinkama varda ir pavarde" << std::endl;
    }
}

template <typename StudentContainer>
void isvestis(StudentContainer& stud) {
    std::string input;
    while (true) {
        std::cout << "Ka noretumet pamatyt? Mediana - 1, arba Vidurki - 2 ";
        if (!read_input(input)) {
            return;
        }

        const int choice = validation(input);
        if (choice != 1 && choice != 2) {
            std::cout << "Iveskite tinkama sk!" << std::endl;
            continue;
        }

        if (choice == 1) {
            std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde"
                      << std::setw(20) << "Galutinis (Med.)" << std::endl;
        } else {
            std::cout << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde"
                      << std::setw(20) << "Galutinis (Vid.)" << std::endl;
        }
        std::cout << "-----------------------------------------------------------------------------------" << std::endl;
        for (const auto& studentas : stud) {
            std::cout << std::fixed << std::left << std::setw(15) << studentas.vardas
                      << std::setw(15) << studentas.pavarde << std::setw(9) << std::setprecision(2)
                      << (choice == 1 ? studentas.med : studentas.vid) << std::endl;
        }
        return;
    }
}

template <typename StudentContainer>
void rusiavimas(StudentContainer& stud, double& laikas) {
    std::string input;
    while (true) {
        std::cout << "Rusiuokite studentus pagal: 1 - varda, 2 - pavarde, 3 - vidurki, 4 - mediana ";
        if (!read_input(input)) {
            return;
        }

        const auto pradzia = std::chrono::high_resolution_clock::now();
        const int choice = validation(input);
        if (choice == 1) {
            sort_container(stud, [](const auto& a, const auto& b) { return a.vardas < b.vardas; });
        } else if (choice == 2) {
            sort_container(stud, [](const auto& a, const auto& b) { return a.pavarde < b.pavarde; });
        } else if (choice == 3) {
            sort_container(stud, [](const auto& a, const auto& b) { return a.vid < b.vid; });
        } else if (choice == 4) {
            sort_container(stud, [](const auto& a, const auto& b) { return a.med < b.med; });
        } else {
            std::cout << "Iveskite tinkama sk!" << std::endl;
            continue;
        }

        const auto pabaiga = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
        laikas += trukme.count();
        return;
    }
}

int paz_sk() {
    std::string input;
    int pazsk = 0;
    while (true) {
        std::cout << "Kiek pazymiu tures studentai sarase? ";
        std::cin >> input;
        pazsk = validation(input);
        if (pazsk > 0) {
            return pazsk;
        }
        std::cout << "iveskite tinkama sk! " << std::endl;
    }
}

template void paz_sk<VectorStudent>(VectorStudent& temp, int& m);
template void paz_sk<ListStudent>(ListStudent& temp, int& m);
template void paz_sk<DequeStudent>(DequeStudent& temp, int& m);
template void paz_ivestis_ranka<VectorStudent>(VectorStudent& temp, int m);
template void paz_ivestis_ranka<ListStudent>(ListStudent& temp, int m);
template void paz_ivestis_ranka<DequeStudent>(DequeStudent& temp, int m);
template void egz_ivestis_ranka<VectorStudent>(VectorStudent& temp);
template void egz_ivestis_ranka<ListStudent>(ListStudent& temp);
template void egz_ivestis_ranka<DequeStudent>(DequeStudent& temp);
template void vardu_ivedimas_ranka<VectorStudent>(VectorStudent& temp, std::size_t current_count);
template void vardu_ivedimas_ranka<ListStudent>(ListStudent& temp, std::size_t current_count);
template void vardu_ivedimas_ranka<DequeStudent>(DequeStudent& temp, std::size_t current_count);
template void isvestis<VectorContainer>(VectorContainer& stud);
template void isvestis<ListContainer>(ListContainer& stud);
template void isvestis<DequeContainer>(DequeContainer& stud);
template void rusiavimas<VectorContainer>(VectorContainer& stud, double& laikas);
template void rusiavimas<ListContainer>(ListContainer& stud, double& laikas);
template void rusiavimas<DequeContainer>(DequeContainer& stud, double& laikas);

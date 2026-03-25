#include "objektinis.h"

#include <algorithm>
#include <cctype>
#include <functional>
#include <iterator>
#include <random>
#include <stdexcept>

bool valid_name(const std::string& s) {
    if (s.empty()) {
        return false;
    }

    for (unsigned char c : s) {
        if (!std::isalpha(c) && c != '-') {
            return false;
        }
    }
    return true;
}

int validation(const std::string& a) {
    try {
        return std::stoi(a);
    } catch (const std::exception&) {
        return 0;
    }
}

template <typename GradeContainer>
double skaiciuoti_mediana(GradeContainer& paz) {
    if (paz.empty()) {
        return 0.0;
    }

    sort_container(paz, std::less<int>{});

    const std::size_t dydis = paz.size();
    auto mid = paz.begin();
    std::advance(mid, static_cast<long>(dydis / 2));
    if (dydis % 2 == 0) {
        auto left = mid;
        --left;
        return (*left + *mid) / 2.0;
    }
    return static_cast<double>(*mid);
}

template <typename StudentContainer>
void mediana(StudentContainer& stud) {
    for (auto& studentas : stud) {
        studentas.med = skaiciuoti_mediana(studentas.paz);
    }
}

template <typename StudentContainer>
void vidurkis(StudentContainer& stud) {
    for (auto& studentas : stud) {
        double sum = 0.0;
        for (int pazymis : studentas.paz) {
            sum += pazymis;
        }
        studentas.vid = (sum / static_cast<double>(studentas.paz.size())) * 0.4 + studentas.egz * 0.6;
    }
}

template <typename Student>
void paz_ivestis_random(Student& temp, int m) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);
    for (int i = 0; i < m; ++i) {
        temp.paz.push_back(dist(gen));
    }
}

template <typename Student>
void egz_ivestis_random(Student& temp) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);
    temp.egz = dist(gen);
}

template <typename Student>
void vardu_ivedimas_random(Student& temp) {
    static const std::vector<std::string> vard = {
        "Artur", "Simas", "Romas", "Patrikas", "Rokas",
        "Ignas", "Tomas", "Rugile", "Aiste", "Martynas"
    };
    static const std::vector<std::string> pav = {
        "Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5",
        "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 9);
    const int r = dist(gen);
    temp.vardas = vard[r];
    temp.pavarde = pav[r];
}

template double skaiciuoti_mediana<std::vector<int>>(std::vector<int>& paz);
template double skaiciuoti_mediana<std::list<int>>(std::list<int>& paz);
template double skaiciuoti_mediana<std::deque<int>>(std::deque<int>& paz);

template void vidurkis<VectorContainer>(VectorContainer& stud);
template void vidurkis<ListContainer>(ListContainer& stud);
template void vidurkis<DequeContainer>(DequeContainer& stud);
template void mediana<VectorContainer>(VectorContainer& stud);
template void mediana<ListContainer>(ListContainer& stud);
template void mediana<DequeContainer>(DequeContainer& stud);

template void paz_ivestis_random<VectorStudent>(VectorStudent& temp, int m);
template void paz_ivestis_random<ListStudent>(ListStudent& temp, int m);
template void paz_ivestis_random<DequeStudent>(DequeStudent& temp, int m);
template void egz_ivestis_random<VectorStudent>(VectorStudent& temp);
template void egz_ivestis_random<ListStudent>(ListStudent& temp);
template void egz_ivestis_random<DequeStudent>(DequeStudent& temp);
template void vardu_ivedimas_random<VectorStudent>(VectorStudent& temp);
template void vardu_ivedimas_random<ListStudent>(ListStudent& temp);
template void vardu_ivedimas_random<DequeStudent>(DequeStudent& temp);

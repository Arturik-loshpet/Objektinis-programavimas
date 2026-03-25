#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "library.h"

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

inline bool valid_name(const std::string& s) {
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

inline int validation(const std::string& a) {
    try {
        return std::stoi(a);
    } catch (const std::exception&) {
        return 0;
    }
}

inline bool read_input(std::string& input) {
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

inline int paz_sk() {
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

template <typename T, typename Allocator, typename Compare>
void sort_container(std::list<T, Allocator>& container, Compare comp) {
    container.sort(comp);
}

template <typename Container, typename Compare>
void sort_container(Container& container, Compare comp) {
    std::sort(container.begin(), container.end(), comp);
}

template <typename GradeContainer>
double skaiciuoti_mediana(GradeContainer& paz) {
    if (paz.empty()) {
        return 0.0;
    }

    if constexpr (std::is_same_v<GradeContainer, std::list<int>>) {
        paz.sort(std::less<int>{});
    } else {
        std::sort(paz.begin(), paz.end(), std::less<int>{});
    }

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

template <typename StudentContainer>
void mediana(StudentContainer& stud) {
    for (auto& studentas : stud) {
        studentas.med = skaiciuoti_mediana(studentas.paz);
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

inline void failu_kurimas(const std::string& name, int zmones, int m, double& laikas) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 10);

    const auto pradzia = std::chrono::high_resolution_clock::now();

    std::ofstream failas(name);
    failas << "vardas pavarde ";
    for (int i = 0; i < m; ++i) {
        failas << " ND" << i + 1;
    }
    failas << " egz" << std::endl;
    for (int i = 0; i < zmones; ++i) {
        failas << "vardas" << i + 1 << " pavarde" << i + 1;
        for (int j = 0; j < m; ++j) {
            failas << " " << dist(gen);
        }
        failas << " " << dist(gen) << std::endl;
    }

    const auto pabaiga = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
    std::cout << zmones << " Rasymas uztruko " << trukme.count() << " ms" << std::endl;
    laikas += trukme.count();
}

template <typename StudentContainer>
void isvestis_failas(StudentContainer& stud) {
    std::string input;
    while (true) {
        std::cout << "Duomenis rasyti: 1 - i konsole, 2 - i atskira faila: ";
        if (!read_input(input)) {
            return;
        }

        const int choice = validation(input);
        if (choice != 1 && choice != 2) {
            std::cout << "Iveskite tinkama sk!" << std::endl;
            continue;
        }

        std::ostream* out = &std::cout;
        std::ofstream rezfailas;
        if (choice == 2) {
            rezfailas.open("rezultatai.txt");
            out = &rezfailas;
        }

        *out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde"
             << std::setw(20) << "Galutinis (Vid.)" << std::setw(10) << "Galutinis (Med.)" << std::endl;
        *out << "-----------------------------------------------------------------------------------" << std::endl;
        for (const auto& studentas : stud) {
            *out << std::fixed << std::left << std::setw(15) << studentas.vardas
                 << std::setw(15) << studentas.pavarde << std::setw(9) << std::setprecision(2)
                 << studentas.vid << std::setw(9) << studentas.med << std::endl;
        }
        return;
    }
}

template <typename StudentContainer>
void skaitymas(StudentContainer& stud, bool& nuskaite, const std::string& input, double& laikas) {
    using Student = typename StudentContainer::value_type;

    std::string line;
    int pazymis = 0;
    nuskaite = false;

    try {
        const std::filesystem::path failo_kelias = input;
        if (!std::filesystem::exists(failo_kelias)) {
            throw std::runtime_error("Toks failas nurodytame aplanke nerastas!");
        }
        if (!std::filesystem::is_regular_file(failo_kelias)) {
            throw std::runtime_error("Nurodytas kelias nera failas!");
        }

        const auto pradzia = std::chrono::high_resolution_clock::now();
        std::ifstream duomfailas(input);
        if (!duomfailas.is_open()) {
            throw std::runtime_error("Nepavyko atidaryti failo!");
        }
        if (duomfailas.peek() == std::ifstream::traits_type::eof()) {
            throw std::runtime_error("Failas tuscias!");
        }

        std::stringstream buffer;
        buffer << duomfailas.rdbuf();

        std::getline(buffer, line);
        while (std::getline(buffer, line)) {
            if (line.empty()) {
                continue;
            }

            Student temp;
            std::istringstream laik(line);
            if (!(laik >> temp.vardas >> temp.pavarde)) {
                throw std::runtime_error("Netinkamas failo formatas.");
            }

            while (laik >> pazymis) {
                if (pazymis < 1 || pazymis > 10) {
                    throw std::runtime_error("Pazymiai faile turi buti nuo 1 iki 10.");
                }
                temp.paz.push_back(pazymis);
            }

            if (laik.fail() && !laik.eof()) {
                throw std::runtime_error("Netinkamas pazymio formatas faile.");
            }
            if (temp.paz.empty()) {
                throw std::runtime_error("Studentas neturi nei vieno pazymio.");
            }

            temp.egz = temp.paz.back();
            temp.paz.pop_back();
            if (temp.paz.empty()) {
                throw std::runtime_error("Truksta namu darbu pazymiu.");
            }

            stud.push_back(temp);
        }

        const auto pabaiga = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
        std::cout << "Skaitymas uztruko " << trukme.count() << " ms" << std::endl;
        laikas += trukme.count();
        nuskaite = true;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cout << "Failu sistemos klaida: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

template <typename StudentContainer>
void skirstymas(StudentContainer& stud, StudentContainer& maladiec, StudentContainer& lopai, double& laikas) {
    const auto pradzia = std::chrono::high_resolution_clock::now();
    for (const auto& studentas : stud) {
        if (studentas.vid < 5) {
            lopai.push_back(studentas);
        } else {
            maladiec.push_back(studentas);
        }
    }
    stud.clear();

    const auto pabaiga = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
    std::cout << "Skirstymas i 2 konteinerius truko " << trukme.count() << " ms" << std::endl;
    laikas += trukme.count();
}

template <typename StudentContainer>
void rasymas(const StudentContainer& a, const std::string& name, double& laikas) {
    const auto pradzia = std::chrono::high_resolution_clock::now();

    std::ofstream rezfailas(name);
    rezfailas << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde"
              << std::setw(20) << "Galutinis (Vid.)" << std::setw(10) << "Galutinis (Med.)" << std::endl;
    rezfailas << "-----------------------------------------------------------------------------------" << std::endl;
    for (const auto& studentas : a) {
        rezfailas << std::fixed << std::left << std::setw(15) << studentas.vardas
                  << std::setw(15) << studentas.pavarde << std::setw(9) << std::setprecision(2)
                  << studentas.vid << std::setw(9) << studentas.med << std::endl;
    }

    const auto pabaiga = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
    std::cout << name << " Rasymas truko " << trukme.count() << " ms" << std::endl;
    laikas += trukme.count();
}

template <typename StudentContainer>
void testavimas(StudentContainer& stud, StudentContainer& maladiec, StudentContainer& lopai, double& laikas) {
    vidurkis(stud);
    mediana(stud);
    rusiavimas(stud, laikas);
    skirstymas(stud, maladiec, lopai, laikas);
    rasymas(maladiec, "maladiec.txt", laikas);
    rasymas(lopai, "lopai.txt", laikas);
    std::cout << "Darbas su failu uztruko " << laikas << " ms" << std::endl;
    std::cout << std::endl;
}

template <typename StudentContainer>
void tyrimai_5(StudentContainer& stud, StudentContainer& maladiec, StudentContainer& lopai, double& laikas) {
    while (true) {
        std::string ivestis;
        std::cout << "Kuri faila norite skaityti? 1 - studentai1000.txt, 2 - studentai10000.txt, 3 - studentai100000.txt, 4 - studentai1000000.txt, 5 - studentai10000000.txt, 6 - baigti ";
        if (!read_input(ivestis)) {
            return;
        }

        const int p = validation(ivestis);
        if (p == 6) {
            break;
        }

        std::string failo_vardas;
        if (p == 1) {
            failo_vardas = "studentai1000.txt";
        } else if (p == 2) {
            failo_vardas = "studentai10000.txt";
        } else if (p == 3) {
            failo_vardas = "studentai100000.txt";
        } else if (p == 4) {
            failo_vardas = "studentai1000000.txt";
        } else if (p == 5) {
            failo_vardas = "studentai10000000.txt";
        } else {
            std::cout << "Iveskite tinkama sk. " << std::endl;
            continue;
        }

        bool nuskaite = false;
        stud.clear();
        maladiec.clear();
        lopai.clear();
        laikas = 0;

        skaitymas(stud, nuskaite, failo_vardas, laikas);
        if (nuskaite) {
            testavimas(stud, maladiec, lopai, laikas);
        }
    }
}

template <typename StudentContainer>
int run_program(const std::string& konteinerio_pavadinimas) {
    using Student = typename StudentContainer::value_type;

    StudentContainer stud;
    StudentContainer maladiec;
    StudentContainer lopai;
    std::string input;
    bool nuskaite = true;
    double b = 0.0;
    double laikas = 0.0;

    std::cout << "Naudojamas konteineris: " << konteinerio_pavadinimas << std::endl;
    std::cout << "Studentu Vardu ir pazymiu ivedimu sistema, skirta medianos bei vidurkio apskaiciavimui" << std::endl;
    while (true) {
        Student temp;
        int m = 0;
        while (true) {
            std::cout << "1 - ranka, 2 - generuoti tik pazymius, 3 - generuoti studentu vardus, pavardes ir pazymius, 4 - skaityti duomenis is failo, 5 - generuoti failus, 6 - baigti darba: ";
            if (!read_input(input)) {
                return 0;
            }

            const int choice = validation(input);
            if (choice == 1) {
                vardu_ivedimas_ranka(temp, stud.size());
                if (temp.vardas.empty() || temp.pavarde.empty()) {
                    break;
                }
                paz_sk(temp, m);
                if (m < 1) {
                    break;
                }
                paz_ivestis_ranka(temp, m);
                if (temp.paz.size() != static_cast<std::size_t>(m)) {
                    break;
                }
                egz_ivestis_ranka(temp);
                if (temp.egz == 0) {
                    break;
                }
                stud.push_back(temp);
            } else if (choice == 2) {
                vardu_ivedimas_ranka(temp, stud.size());
                if (temp.vardas.empty() || temp.pavarde.empty()) {
                    break;
                }
                paz_sk(temp, m);
                if (m < 1) {
                    break;
                }
                paz_ivestis_random(temp, m);
                egz_ivestis_random(temp);
                stud.push_back(temp);
            } else if (choice == 3) {
                vardu_ivedimas_random(temp);
                paz_sk(temp, m);
                if (m < 1) {
                    break;
                }
                paz_ivestis_random(temp, m);
                egz_ivestis_random(temp);
                stud.push_back(temp);
            } else if (choice == 4) {
                int n = 0;
                for (const auto& entry : std::filesystem::directory_iterator(".")) {
                    const auto name = entry.path().filename().string();
                    if (entry.is_regular_file() && entry.path().extension() == ".txt" &&
                        name != "rezultatai.txt" && name != "lopai.txt" && name != "maladiec.txt") {
                        std::cout << entry.path().filename() << std::endl;
                        ++n;
                    }
                }
                if (n == 0) {
                    std::cout << "Nera tinkamu failu! " << std::endl;
                    break;
                }

                std::cout << "Koki faila noretumete nuskaityti? " << std::endl;
                if (!read_input(input)) {
                    return 0;
                }
                skaitymas(stud, nuskaite, input, laikas);
                if (nuskaite) {
                    testavimas(stud, maladiec, lopai, laikas);
                    break;
                }
                std::cout << "Parinkite kita faila arba veskite duomenis" << std::endl;
            } else if (choice == 5) {
                m = paz_sk();
                failu_kurimas("studentai1000.txt", 1000, m, b);
                failu_kurimas("studentai10000.txt", 10000, m, b);
                failu_kurimas("studentai100000.txt", 100000, m, b);
                failu_kurimas("studentai1000000.txt", 1000000, m, b);
                failu_kurimas("studentai10000000.txt", 10000000, m, b);
                std::cout << std::endl;
                tyrimai_5(stud, maladiec, lopai, laikas);
                break;
            } else if (choice == 6) {
                std::cout << "Sekmingai baigete studentu duomenu ivedima!" << std::endl;
                break;
            } else {
                std::cout << "Iveskite tinkama sk!" << std::endl;
            }
        }
        break;
    }

    if (stud.empty()) {
        return 0;
    }

    vidurkis(stud);
    mediana(stud);
    if (stud.size() > 1) {
        rusiavimas(stud, b);
    }
    isvestis_failas(stud);
    return 0;
}

#endif

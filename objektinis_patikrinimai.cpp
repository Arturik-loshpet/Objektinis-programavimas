
#include "library.h"
#include "patikrinimai.h"

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

bool read_input(std::string& input) {
    try {
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
    }
    catch (const std::exception&) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Klaida skaitant ivesti. Bandykite dar karta." << std::endl;
    }

    return false;
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
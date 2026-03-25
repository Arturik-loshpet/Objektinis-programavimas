#include "funkcijos.h"
#include "library.h"
int main() {
    std::string input;

    while (true) {
        std::cout << "Pasirinkite konteineri: 1 - vector, 2 - list, 3 - deque: ";
        if (!read_input(input)) {
            return 0;
        }

        const int choice = validation(input);
        if (choice == 1) {
            return run_program<VectorContainer>("vector");
        }
        if (choice == 2) {
            return run_program<ListContainer>("list");
        }
        if (choice == 3) {
            return run_program<DequeContainer>("deque");
        }

        std::cout << "Iveskite tinkama sk!" << std::endl;
    }
}

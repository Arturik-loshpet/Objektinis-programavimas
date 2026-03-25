#include <algorithm>
#include <chrono>
#include <cctype>
#include <cstddef>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

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
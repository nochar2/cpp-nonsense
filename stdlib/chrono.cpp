#include <iostream>
#include <chrono>
#include <ctime>
using namespace std::chrono;
int main(void) {
    const auto start = high_resolution_clock::now();

    // -- This works in C++20:
    std::cout << "chrono << : " << start << std::endl;

    // -- Before C++20, you would use the C api.
    // (ctime, asctime already add a newline)
    // -- absolute time (C format)
    std::time_t start_tt = high_resolution_clock::to_time_t(start);
    std::cout << "ctime     : " << std::ctime(&start_tt);

    // -- calendar date/time (same result)
    std::tm *start_tm = std::localtime(&start_tt);
    std::cout << "asctime   : " << std::asctime(start_tm);

    // -- strftime
    char c[50];
    strftime(c, 50, "%d.%m.%Y %H:%M:%S", start_tm);
    std::cout << "strftime  : " << c << std::endl;
}

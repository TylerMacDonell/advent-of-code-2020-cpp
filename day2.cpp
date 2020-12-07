#include <vector>
#include <fstream>
#include <string>
#include <cstdio>

int main(int argc, char const *argv[]) {
    std::ifstream file("day2.txt");
    
    int min, max;
    char c, q;
    std::string password;

    int valid_1 = 0;
    int valid_2 = 0;

    while (file >> min >> c >> max >> c >> q >> password) {
        size_t n = std::count(password.begin(), password.end(), c);

        if (n >= min && n <= max) {
            valid_1++;
        }

        if ((password[min-1] == c) != (password[max-1] == c)) {
            valid_2++;
        }
    }

    printf("part 1 answer: %d\n", valid_1);
    printf("part 2 answer: %d\n", valid_2);

    return 0;
}

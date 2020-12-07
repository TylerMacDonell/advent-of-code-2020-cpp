#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>
#include <map>
#include <unordered_set>
#include <algorithm>

int present_fields = 0;
int valid_fields = 0;

int valid_passports_1 = 0;
int valid_passports_2 = 0;

std::unordered_set<std::string> valid_ecl = {
    "amb", "blu", "brn", "gry", "grn", "hzl", "oth"
};

void validate_passport() {
    if (present_fields == 7) {
        valid_passports_1++;
    }

    if (valid_fields == 7) {
        valid_passports_2++;
    }

    present_fields = 0;
    valid_fields = 0;
}

void validate_field(const std::string &f, const std::string &v) {
    if (f != "cid") {
        present_fields++;
    }

    if (f == "byr") {
        int y = std::stoi(v);
        if (y >= 1920 && y <= 2002) {
            valid_fields++;
        }
    } else if (f == "iyr") {
        int y = std::stoi(v);
        if (y >= 2010 && y <= 2020) {
            valid_fields++;
        }
    } else if (f == "eyr") {
        int y = std::stoi(v);
        if (y >= 2020 && y <= 2030) {
            valid_fields++;
        }
    } else if (f == "hgt") {
        size_t pos = v.find("in");
        if (pos != std::string::npos) {
            int h = std::stoi(v.substr(0, pos));
            if (h >= 59 && h <= 76) {
                valid_fields++;
            }
        } else {
            pos = v.find("cm");
            if (pos != std::string::npos) {
                int h = std::stoi(v.substr(0, pos));
                if (h >= 150 && h <= 193) {
                    valid_fields++;
                }
            }
        }
    } else if (f == "hcl") {
        if (v.length() == 7 && v[0] == '#'
            && v.find_first_not_of("0123456789abcdef", 1) == std::string::npos) {
            valid_fields++;
        }
        
    } else if (f == "ecl") {
        if (valid_ecl.find(v) != valid_ecl.end()) {
            valid_fields++;
        }
    } else if (f == "pid") {
        if (v.length() == 9 && std::all_of(v.begin(), v.end(), ::isdigit)) {
            valid_fields++;
        }
    } 
}

int main(int argc, char const *argv[]) {
    std::ifstream file("day4.txt");
    std::string line;
    
    while (std::getline(file, line)) {
        if (line.empty()) {
            validate_passport();
        } else {
            std::istringstream token(line);
            while (token >> line) {
                std::string field = line.substr(0, 3);
                std::string value = line.substr(4, line.length());
                validate_field(field, value);
            }
        }
    }
    validate_passport();

    printf("part 1 answer: %d\n", valid_passports_1);
    printf("part 2 answer: %d\n", valid_passports_2);

    return 0;
}

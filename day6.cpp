#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <limits>
#include <map>

std::map<char, bool> seen;
std::map<char, int> seen_counts;
int people = 0;
int seen_count = 0;

int total_1 = 0;
int total_2 = 0;

void sum_questions() {
    total_1 += seen_count;

    for (const auto &[key, value] : seen_counts) {
        if (value == people) total_2++;
    }

    people = 0;
    seen_count = 0;
    seen.clear();
    seen_counts.clear();
}

int main(int argc, char const *argv[]) {
    std::ifstream file("day6.txt");
    
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) {
            sum_questions();
        } else {
            people++;
            for (auto &c : line) {
                if (!seen[c]) {
                    seen[c] = true;
                    seen_count++;
                }

                seen_counts[c] = seen_counts[c] + 1;
            }
        }
    }

    sum_questions();

    printf("part 1 answer: %d\n", total_1);
    printf("part 2 answer: %d\n", total_2);

    return 0;
}

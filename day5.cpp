#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <limits>
#include <array>


int binary(const std::string &pass, char low, int i, int min, int max) {
    if (min == max) {
        return min;
    } else if (pass[i] == low) {
        return binary(pass, low, i+1, min, min + (max - min) / 2);
    } else {
        return binary(pass, low, i+1, min + 1 + (max - min) / 2, max);
    }
}

int seat_id(const std::string &pass) {
    int row = binary(pass, 'F', 0, 0, 127);
    int column = binary(pass, 'L', 7, 0, 7);
    return row * 8 + column;
}

int main(int argc, char const *argv[]) {
    std::ifstream file("day5.txt");
    
    std::string line;
    int max_id = 0;
    int min_id = INT_MAX;

    std::array<bool, 1024> seen;

    while (std::getline(file, line)) {
        int id = seat_id(line);
        seen[id] = true;
        max_id = std::max(max_id, id);
        min_id = std::min(min_id, id);
    }

    int mine = 0;

    for (int i = min_id + 1; i < max_id; ++i) {
        if (!seen[i]) {
            mine = i;
            break;
        }
    }

    printf("part 1 answer: %d\n", max_id);
    printf("part 2 answer: %d\n", mine);

    return 0;
}

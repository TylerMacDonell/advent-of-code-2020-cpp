#include <vector>
#include <fstream>
#include <string>
#include <cstdio>

struct Slope {
    Slope(int w, int h) : w(w), h(h) {}
    int w;
    int h;
    int x = 0;
    int hits = 0;
};

std::vector<Slope> slopes = {
    Slope(1, 1),
    Slope(3, 1),
    Slope(5, 1),
    Slope(7, 1),
    Slope(1, 2)
};

int main(int argc, char const *argv[]) {
    std::ifstream file("day3.txt");
    
    std::string line;
    int y = 0;

    while (std::getline(file, line)) {
        for (auto &slope : slopes) {
            if (y % slope.h != 0) continue;
            if (line[slope.x] == '#') slope.hits++;
            slope.x = (slope.x + slope.w) % line.size();
        }
        y++;
    }

    printf("part 1 answer: %d\n", slopes[1].hits);

    int answer = 1;
    for (auto &slope : slopes) {
        answer *= slope.hits;
    }

    printf("part 2 answer: %d\n", answer);

    return 0;
}

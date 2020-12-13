#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <limits>
#include <map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

int main(int argc, char const *argv[]) {
    ifstream file("day8.txt");
    
    vector<pair<string, int>> program;
    string t1, t2;

    while (file >> t1 >> t2) {
        program.push_back(pair(t1, stoi(t2)));
    }

    map<int, bool> seen;
    int acc = 0;
    int ins = 0;

    while (!seen[ins]) {
        auto [instruction, value] = program[ins];
        seen[ins] = true;

        if (instruction == "nop") {
            ins++;
        } else if (instruction == "acc") {
            acc += value;
            ins++;
        } else if (instruction == "jmp") {
            ins += value;
        }
    }

    printf("part 1 answer: %d\n", acc);

    return 0;
}

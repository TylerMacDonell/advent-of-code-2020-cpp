#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

int main(int argc, char const *argv[]) {
    std::ifstream file("day1.txt");
    
    std::string line;
    std::vector<int> nums;

    while (std::getline(file, line)) {
        nums.push_back(std::stoi(line));
    }

    std::map<int, bool> seen;

    // part 1 runtime O(n)
    for (auto &num : nums) {
        int compliment = 2020 - num;

        if (seen[compliment]) {
            printf("part 1 answer: %d\n", num * compliment);
            break;
        }

        seen[num] = true;
    }

    // part 2 runtime O(n^2)
    for (int i = 0; i < nums.size(); ++i) {        
        for (int j = i+1; j < nums.size(); ++j) {
            int sum = nums[i] + nums[j];
            int compliment = 2020 - sum;

            if (seen[compliment]) {
                printf("part 2 answer: %d\n", nums[i] * nums[j] * compliment);
                return 0;
            }

            seen[nums[j]] = true;
        }

        seen[nums[i]] = true;
    }

    return 0;
}

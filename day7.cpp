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
    ifstream file("day7.txt");
    
    map<string, vector<pair<string, int>>> child_map;
    map<string, vector<string>> parent_map;
    string t1;
    string t2;
    int num;

    while (file >> t1 >> t2) {
        string container = t1 + t2;

        // read x of "bags contain x"
        file >> t1 >> t1 >> t1;

        if (t1 == "no") {
            // discard "other bags"
            file >> t1 >> t1;
            continue;
        }

        num = stoi(t1);

        while (file >> t1 >> t2) {
            string containee = t1 + t2;
            parent_map[containee].push_back(container);
            child_map[container].push_back(pair(containee, num));
            
            // read "bags"
            file >> t1;
            if (t1.back() == '.') {
                // line finished
                break;
            } else  {
                file >> t1;
                num = stoi(t1);
            }
        }
    }

    queue<string> queue;
    unordered_set<string> answer_set;

    for (auto &item : parent_map["shinygold"]) {
        queue.push(item);
    }

    while (!queue.empty()) {
        auto item = queue.front();
        queue.pop();
        answer_set.insert(item);
        for (auto &parent : parent_map[item]) {
            queue.push(parent);
        }
    }

    printf("part 1 answer: %lu\n", answer_set.size());

    int answer2 = 0;

    for (auto &item : child_map["shinygold"]) {
        for (int i = 0; i < item.second; ++i) { 
            queue.push(item.first);
        }
    }

    while (!queue.empty()) {
        auto item = queue.front();
        queue.pop();

        answer2++;

        for (auto &child : child_map[item]) {
            for (int i = 0; i < child.second; ++i) { 
                queue.push(child.first);
            }
        }
    }

    printf("part 2 answer: %d\n", answer2);

    return 0;
}

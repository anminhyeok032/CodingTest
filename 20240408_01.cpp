#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    // 옷 종류, 옷 이름
    unordered_map <string, int> types;
    for (auto i : clothes)
    {
        string clotheType = i[1];
        types[clotheType]++;
    }


    answer = 1;
    for (auto i : types)
    {
        answer *= i.second + 1;
    }

    // 아무것도 안입었을 때 - 1
    return answer - 1;
}

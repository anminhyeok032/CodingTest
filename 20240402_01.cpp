#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
void dfs(vector<int>, int, int, int);

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, 0, 0);

    return answer;
}

void dfs(vector<int> numbers, int target, int index, int sum)
{
    if (index == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }
    dfs(numbers, target, index + 1, sum + numbers[index]);
    dfs(numbers, target, index + 1, sum - numbers[index]);
}

int main()
{
    // [문제 설명]
    // n개의 음이 아닌 정수들이 있습니다. 
    // 이 정수들을 순서를 바꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 
    // 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

    vector<int> numbers { 4, 1, 2, 1 };
    int target = 4;
    solution(numbers, target);

    cout << "Answer : " << answer << endl;
}
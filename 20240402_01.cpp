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
    // [���� ����]
    // n���� ���� �ƴ� �������� �ֽ��ϴ�. 
    // �� �������� ������ �ٲ��� �ʰ� ������ ���ϰų� ���� Ÿ�� �ѹ��� ������� �մϴ�. 
    // ���� ��� [1, 1, 1, 1, 1]�� ���� 3�� ������� ���� �ټ� ����� �� �� �ֽ��ϴ�.

    vector<int> numbers { 4, 1, 2, 1 };
    int target = 4;
    solution(numbers, target);

    cout << "Answer : " << answer << endl;
}
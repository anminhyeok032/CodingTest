// TODO : 시간 초과의 문제가 해결하기.
// 순서대로 연속된 수에 접근하여, k보다 합산이 커지면 다음 수로 넘어가 다음 루프를 돌며, 
// k와 합산이 같은 수에 대해 vector에 저장한뒤, 해당 값들의 차를 이용해 비교하는 방식

// 투포인터 방식을 사용하여 시간 복잡도를 줄여보자.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    
    for (int i = 0; i < sequence.size(); ++i)
    {
        int j = i;
        int sum = 0;
        for (int j = i; j < sequence.size(); ++j)
        {
            sum += sequence[j];
            if (sum == k) {
                answer.emplace_back(i);
                answer.emplace_back(j);
            }
            else if (sum > k)
                break;
        }
    }

    int answerMin = 9999;
    vector<int> a;
    int i = 0;
    while ( i < answer.size() - 1 ) {
        int tmp = answer[i + 1] - answer[i];
        if (tmp < answerMin) {
            answerMin = tmp;
            a.clear();
            a.emplace_back(answer[i]);
            a.emplace_back(answer[i + 1]);
        }
        i += 2;
    }
    return a;
}


int main() {
    vector<int> seq{1, 1, 1, 2, 3, 4, 5};
    auto answer = solution(seq, 5);
    for (auto& i : answer)
        cout << i << endl;
}
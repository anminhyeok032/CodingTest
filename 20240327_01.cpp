// TODO : �ð� �ʰ��� ������ �ذ��ϱ�.
// ������� ���ӵ� ���� �����Ͽ�, k���� �ջ��� Ŀ���� ���� ���� �Ѿ ���� ������ ����, 
// k�� �ջ��� ���� ���� ���� vector�� �����ѵ�, �ش� ������ ���� �̿��� ���ϴ� ���

// �������� ����� ����Ͽ� �ð� ���⵵�� �ٿ�����.

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
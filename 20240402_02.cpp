#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    int i = 0;
    
    while(i < s.size())
    {
        if (s[i] == s[i + 1]) {
            s.erase(i, 2);
            if (i != 0)
                i--;
        }
        else
            i++;
    }

    if (s.size() == 0)
        answer = 1;
    else
        answer = 0;

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "S : " << s << endl;

    return answer;
}

int Resolution(string s)
{
    int answer = -1;

    stack<char> str;
    str.push('0');
    for (auto i : s)
    {
        if (str.top() == i)
            str.pop();
        else
            str.push(i);
    }
    
    if (str.size() == 1)
        answer = 1;
    else
        answer = 0;

    return answer;
}

int main()
{
    // ¦���� �����ϱ�
    // ��� ���ŵǸ� 1, ���������� 0
    int res = Resolution("11223344");
    cout << "result : " << res << endl;
}
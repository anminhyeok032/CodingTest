#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<pair<int, int>> MinMax;
vector<int> condition;
int n, k, d;

bool isHigh(int mid)
{
	long long count = 0;
	for (int i = 0; i < k; i++)
	{
		if (MinMax[i].first > mid)	continue;
		count += ((min(MinMax[i].second, mid)) - MinMax[i].first) / condition[i] + 1;
	}
	return count >= d;
}

int solution()
{
	int low = 0;
	int hi = 1'000'000;
	while (hi >= low) {
		long long mid = (low + hi) / 2;
		if (isHigh(mid)) hi = mid - 1;
		else low = mid + 1;
	}
	return low;
}


int solution(int low, int high)
{
	if (high <= low) return low;
	int mid = (low + high) / 2;
	long long count = 0;
	for (int i = 0; i < k; i++)
	{	
		// 최소 범위가 현재 중간값보다 큰 조건은 몫에 들어가지 않으므로 스킵 
		if (mid < MinMax[i].first)	continue;
		// 중간값과 범위 Min 값 비교 후 작은 값으로 몫 + 1 값 계산
		count += (min(MinMax[i].second, mid) - MinMax[i].first) / condition[i] + 1;
	}
	if (count >= d) return solution(low, mid - 1);
	else return solution(mid + 1, high);
	
}


int main()
{

	cin >> n >> k >> d;
	int max = 0;
	int a, b, c;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b >> c;
		MinMax.emplace_back(a, b);
		condition.emplace_back(c);
		
	}
	int result = solution(0, 999999);
	std::cout << result << std::endl;
}
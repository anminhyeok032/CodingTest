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
	int result = solution();
	std::cout << result << std::endl;
}
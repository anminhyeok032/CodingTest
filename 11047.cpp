// 백준 11047 그리디
// 동전의 최소값

#include <iostream>
#include <vector>


int main()
{
	int n, k;
	std::cin >> n >> k;

	std::vector<int> coins;

	for (int i = 0; i < n; i++)
	{
		int coin;
		std::cin >> coin;
		coins.push_back(coin);
	}
	int answer = 0, changes = k;
	for (auto i = coins.rbegin(); i < coins.rend(); ++i)
	{
		int tmp = changes / *i;
		if (tmp != 0) {
			answer += tmp;
			changes = changes % *i;
		}
	}

	std::cout << answer << std::endl;
	
	return 0;
}
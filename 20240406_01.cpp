#include <iostream>
#include <unordered_map>

int n, m;
std::unordered_map <int, int> cards;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int card;
		std::cin >> card;
		/*auto search = cards.find(card);
		if (search != cards.end())
			cards[card] += 1;
		else
		{
			cards[card] = 1;
		}*/
		cards[card]++;
	}
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		int check;
		std::cin >> check;
		/*auto search = cards.find(check);
		if (search != cards.end())
			std::cout << search->second << " ";
		else
			std::cout << "0 ";*/
		std::cout << cards[check] << " ";
		
	}
}
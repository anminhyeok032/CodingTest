#include <iostream>
#include <vector>


std::vector <long long> length;
int k, n;

// 랜선 자르기 문제
// 이분탐색을 이용하여 필요한 값을 찾음
// 값이 2^31 까지 받을 수 있다는 점에서 순차 탐색을 하면 너무 시간 복잡도가 올라감
int solution(long long low, long long high)
{
	if (high < low)	return high;

	long long sum = 0;
	long long mid = (low + high) / 2;

	for (long long i : length)
	{
		sum += i / mid;
	}

	if (sum >= n)	return solution(mid + 1, high);
	else	return solution(low, mid - 1);
}

int main()
{

	std::cin >> k;
	std::cin >> n;
	
	long long max = 0;

	for (int i = 0; i < k; ++i)
	{
		long long len;
		std::cin >> len;
		length.push_back(len);
		if (max < length[i]) max = length[i];
	}

	int res = solution(1, max);

	std::cout << res << std::endl;

	// 내가 처음에 다가간 방식
	// 순차 탐색으로 총합에 대해 접근하여 적절한 값을 얻어냄
	// O(n^2)으로 시간 초과, -> 이분 탐색을 이용해야함.
	/*int k, n;
	std::cin >> k;
	std::cin >> n;
	std::vector <int> length;
	int sum = 0;

	for (int i = 0; i < k; ++i)
	{
		int len;
		std::cin >> len;
		length.push_back(len);
		sum += length[i];
	}
	int result = sum / n;
	int isN = 0;
	int i = 0;
	while (i < k)
	{
		int code = length[i++] / result;
		isN += code;

		
		if (i == k)
		{
			if (isN < n)
			{
				result--;
				i = isN = 0;
			}
			else
			{
				break;
			}
		}
		
	}
	std::cout << result << std::endl;*/
}
#include <iostream>
#include <vector>


std::vector <long long> length;
int k, n;

// ���� �ڸ��� ����
// �̺�Ž���� �̿��Ͽ� �ʿ��� ���� ã��
// ���� 2^31 ���� ���� �� �ִٴ� ������ ���� Ž���� �ϸ� �ʹ� �ð� ���⵵�� �ö�
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

	// ���� ó���� �ٰ��� ���
	// ���� Ž������ ���տ� ���� �����Ͽ� ������ ���� ��
	// O(n^2)���� �ð� �ʰ�, -> �̺� Ž���� �̿��ؾ���.
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
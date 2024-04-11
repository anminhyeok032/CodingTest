#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	// 회의의 수
	int n;
	std::cin >> n;
	
	// 회의 끝나는 시간과, 시작 시간을 받는 vector
	std::vector<std::pair<int, int>> meetingTime;

	for (int i = 0; i < n; i++)
	{
		int startTime, endTime;
		std::cin >> startTime >> endTime;

		meetingTime.emplace_back(std::make_pair(endTime, startTime));
	}
	sort(meetingTime.begin(), meetingTime.end());
	

	int currentTime = meetingTime[0].first;
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (currentTime <= meetingTime[i].second)
		{
			currentTime = meetingTime[i].first;
			count++;
		}
	}

	std::cout << count << std::endl;
}

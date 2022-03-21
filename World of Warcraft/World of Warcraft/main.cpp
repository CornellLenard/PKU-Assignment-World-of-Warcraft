#include "world_of_warcraft.h"


int main()
{
	int round = 0, M = 0, N = 0, R = 0, K = 0, T = 0;
	int data[10] = { 0 };
	std::cin >> round;

	for (int i = 0; i < round; i++)
	{
		std::cout << "Case " << i + 1 << ":\n";
		std::cin >> M >> N >> R >> K >> T;

		for (int i = 0; i < 10; i++)
			std::cin >> data[i];

		WorldOfWarcraft wow(M, N, R, K, T, data);
		wow.Run();
	}

	return 0;
}



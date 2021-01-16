#include <iostream>

using namespace std;

short value[15];
short weight[15];
short tests, n, capacity, result;

short inline max(short n1, short n2)
{
	return n1 > n2 ? n1 : n2;
}

short package(short localWeight, short index = 0)
{
	if (localWeight == 0 || index == n)  return 0;

	if (weight[index] > localWeight) return package(localWeight, index + 1);

	short rightMax = (weight[index] <= 100 ? value[index] : value[index] - 5) + package(localWeight - weight[index], index + 1);
	short leftMax = package(localWeight, index + 1);

	return max(leftMax, rightMax);
}

int main()
{
	scanf("%hi", &tests);

	while (tests--) {

		scanf("%hi", &n);
		for (int i = 0; i < n; i++) {
			scanf("%hi", &value[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%hi", &weight[i]);
		}
		scanf("%hi", &capacity);

		result = package(capacity) - 20;

		printf("%i\n", result > 0 ? result : 0);
	}
	return 0;
}
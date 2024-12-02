#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ARR_LENGTH 1024

void insert(int arr[], int value)
{
	int i;
	for (i = 0; i < ARR_LENGTH; i++) {
		if (value < arr[i]) {
			break;
		}
	}

	for (int j = ARR_LENGTH - 1; j > i; j--) {
		arr[j] = arr[j - 1];
	}

	arr[i] = value;
}

int main()
{
	int a, b;
	int left[ARR_LENGTH];
	int right[ARR_LENGTH];

	for (int i = 0; i < ARR_LENGTH; i++) {
		left[i] = INT_MAX;
		right[i] = INT_MAX;
	}

	while (scanf("%d %d", &a, &b) == 2) {
		insert(left, a);
		insert(right, b);
	}

	int distance = 0;
	int similarity = 0;

	for (int i = 0; i < ARR_LENGTH; i++) {
		int l = left[i];
		int r = right[i];

		if (l == INT_MAX || r == INT_MAX) break;

		int temp = l - r;
		distance += temp < 0 ? -temp : temp;

		int count = 0;
		for (int i = 0; i < ARR_LENGTH; i++) {
			int r = right[i];
			if (r == l) count++;
		}
		similarity += l * count;
	}

	printf("Part 1: %d\n", distance);
	printf("Part 2: %d\n", similarity);

	return 0;
}

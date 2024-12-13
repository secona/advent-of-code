#include <stdio.h>

int main() {
	int a;
	int b;
	int temp;
	int direction = 0;
	int safecount = 0;

	while ((temp = getchar()) != EOF) {
		if (temp >= '0' && temp <= '9') {
			b *= 10;
			b += temp - '0';
			continue;
		}

		if (temp == ' ' || temp == '\n') {
			if (a != 0) {
				int unsafe = 0;
				int diff = b - a;

				if (direction == 0) {
					direction = diff;
				}

				if ((diff < 1 || diff > 3) && (diff > -1 || diff < -3)) {
					unsafe = 1;
				} else {
					unsafe = -(diff * direction);
				}

				if (unsafe > 0) {
					safecount--;
					while ((temp = getchar()) != '\n');
				}
			}

			a = b;
			b = 0;
		}

		if (temp == '\n') {
			safecount++;
			a = 0;
			b = 0;
			direction = 0;
		}
	}

	printf("%d\n", safecount);

	return 0;
}

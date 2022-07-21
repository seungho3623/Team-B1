#include <stdio.h>

int total_period = 0, room = 0; 
int checkIn = 0, checkOut = 0;
char temp[101][31];

int check(int index) {
	int maxCount = 0;

	for (int i = 0; i < room; i++) {
		int count = 0;
		for (int j = index; j < checkOut - 1; j++) {
			if (temp[j][i] == 'O') { count++; }
			else { break; }
		}
		if (maxCount < count) {
			maxCount = count;
		}
	}
	return maxCount;
}

int main() {
	
	scanf("%d %d", &total_period, &room);

	for (int i = 0; i < total_period; i++) {
		for (int j = 0; j < room; j++) {
			scanf("%d", &temp[i][j]);
		}
	}

    scanf("%d %d", &checkIn, &checkOut);

	int change = -1;

	for (int i = checkIn - 1; i < checkOut - 1;) {
		change++;

		if (check(i) == 0) {
			change = -1;
			break;
		}
		i += check(i);
	}

    printf("%d", change);
}

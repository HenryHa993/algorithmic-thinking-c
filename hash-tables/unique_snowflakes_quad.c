#include <stdio.h>

#define SIZE 100000

// This should traverse right from a given index to determine if it is identical
int identical_right(int snowflake1[], int snowflake2[], int start) {
	int offset;
	// We can hard-code details such as array size
	for (offset = 0; offset < 6; offset++) {
		if (snowflake1[offset] != snowflake2[(start + offset) % 6]) {
			return 0;
		}
	}
	return 1;
}

int identical_left(int snowflake1[], int snowflake2[], int start) {
	int offset;
	int snowflake2_index;
	for(offset = 0; offset < 6; offset++) {
		snowflake2_index = start - offset;
		if(snowflake2_index < 0) {
			snowflake2_index += 6;
		}
		if(snowflake1[offset] != snowflake2[snowflake2_index]) {
			return 0;
		}
	}
	return 1;
}

int are_identical(int snowflake1[], int snowflake2[]) {
	int start;
	for (start = 0; start < 6; start++) {
		if (identical_right(snowflake1, snowflake2, start)) {
			return 1;
		}
		if (identical_left(snowflake1, snowflake2, start)) {
			return 1;
		}
	}
	return 0;
}

void identify_identical(int snowflakes[][6], int n){
	int i;
	int j;
	// Traverse through the two-dimensional array
	for (i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if (are_identical(snowflakes[i], snowflakes[j])) {
				printf("Twin snowflakes found.\n");
				return;
			}
		}
	}
	printf("No two snowflakes are alike.\n");
}

int main() {
	static int snowflakes[SIZE][6];
	int n;
	int i;
	int j;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 6; j++) {
			scanf("%d", &snowflakes[i][j]);
		}
	}
	identify_identical(snowflakes, n);
	return 0;
}
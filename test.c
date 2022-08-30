#include <stdio.h>

#include <stdio.h>

#define YELLOW_1 "\x1b[48;5;226m"
#define YELLOW_2
#define RESET "\x1b[0m"

int main(void) {

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            printf("\x1b[48;5;%dm %03d \x1b[0m", i * 16 + j, i * 16 + j);
			if (j % 5 == 0)
        printf("\n");
        }
    }

	int i, j, k;
	int color[7]= {231, 230, 229, 228, 227, 226, 220};
	i = 0;
	k = 0;
	while (i < 30)
	{
		j = 0;
		while (j < i)
		{
            printf("\x1b[48;5;%dm  %s", color[k], RESET);
			j++;
		}
		printf("\n");
		i++;
		if (i % 5 == 0)
			k++;
	}

}

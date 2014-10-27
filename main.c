#include <stdio.h>

char	table[3][3]={ {0,0},{0,0},{0,0} };

int	init_table() {
	int i,j;

	for (i=0;i<3;i++)
		for (j=0;j<3;j++)
			table[i][j] = 0;
		
	return 0;

}

int	print_table() {
	int	i,j;

	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			int c = table[i][j];
			printf("%c", c==0?'.':c);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

int	main(void) {
	print_table();
	table[0][0] = 'x';
	print_table();
	table[1][1] = 'o';
	print_table();
	table[2][2] = 'z';
	print_table();
	return 0;
}

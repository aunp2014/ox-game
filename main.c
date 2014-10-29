#include <stdio.h>
#include <strings.h>

char	table[3][3]={ {0,0},{0,0},{0,0} };
int	x,y;

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

int	test_table_1() {
	print_table();
	table[0][0] = 'x';
	print_table();
	table[1][1] = 'o';
	print_table();
	table[2][2] = 'z';
	print_table();
	return 0;
}

void	read_pos() {
	int	n = 0;
	char	buf[80], *s;

	do {
		printf("please select position x,y: ");
		fgets(buf, sizeof(buf)-1, stdin);
		/* get rid of '\n' */
		s = index(buf, '\n');
		if (s != NULL)
			*s = '\0';
		n = sscanf(buf, "%d,%d", &x, &y);
		if (n!=2) {
			printf("invalid input '%s'\n", buf);
		}
	} while (n<2);
}

int	main(void) {
	int	count=3;
	char	c = 'x';

	while (count > 0) {
		read_pos();
		printf("[x,y] = %d,%d\n", x,y);

		if (x < 3 && y < 3) {
			if (table[x][y] != 0) {
				printf("position (%d,%d) has been used by '%c'\n", 
					x, y, table[x][y]);
				continue;
			}
			table[x][y] = c;
			if (c == 'x') {
				c = 'o';
			} else {
				c = 'x';
			}
			print_table();       
		} else {
			printf("[%d, %d] is invalid position\n", x, y);
		}
		count--;
	}
	
	return 0;
}

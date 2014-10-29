#include <stdio.h>
#include <stdlib.h>
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
	FILE *f = fopen("output-board", "w");

	if (f == (FILE *)NULL) {
		fprintf(stderr, "Can't create output file\n");
		exit(-1);
	}

	for (i=0;i<3;i++) {
		for (j=0;j<3;j++) {
			int c = table[i][j];
			fprintf(f, "%c", c==0?'.':c);
		}
		fprintf(f, "\n");
	}
	fprintf(f, "\n");
	fclose(f);

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

void	read_pos(char turn) {
	int	n = 0;
	char	buf[80], *s;

	do {
		printf("please select position x,y for %c: ", turn);
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

int	check_win() {
	int	win = 0;

	if (
		(table[0][0]=='x' && table[0][1]=='x' && table[0][2]=='x') ||
		(table[1][0]=='x' && table[1][1]=='x' && table[1][2]=='x') ||
		(table[2][0]=='x' && table[2][1]=='x' && table[2][2]=='x') ||

		(table[0][0]=='x' && table[1][0]=='x' && table[2][0]=='x') ||
		(table[0][1]=='x' && table[1][1]=='x' && table[2][1]=='x') ||
		(table[0][2]=='x' && table[1][2]=='x' && table[2][2]=='x') ||

		(table[0][0]=='x' && table[1][1]=='x' && table[2][2]=='x') ||
		(table[0][2]=='x' && table[1][1]=='x' && table[2][0]=='x') 
	)	{
		win = 'x';
	} else if	(
		(table[0][0]=='o' && table[0][1]=='o' && table[0][2]=='o') ||
		(table[1][0]=='o' && table[1][1]=='o' && table[1][2]=='o') ||
		(table[2][0]=='o' && table[2][1]=='o' && table[2][2]=='o') ||

		(table[0][0]=='o' && table[1][0]=='o' && table[2][0]=='o') ||
		(table[0][1]=='o' && table[1][1]=='o' && table[2][1]=='o') ||
		(table[0][2]=='o' && table[1][2]=='o' && table[2][2]=='o') ||

		(table[0][0]=='o' && table[1][1]=='o' && table[2][2]=='o') ||
		(table[0][2]=='o' && table[1][1]=='o' && table[2][0]=='o') 
	)	{
		win = 'o';
	}
	return win;
}

int	main(void) {
	int	count=9;
	char	c = 'x';
	char	r;

	while (count > 0) {
		read_pos(c);
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
		r = check_win();
		if (r) {
			printf("%c is winning\n", r);
			exit(0);
		}
		count--;
	}
	printf("no-one win\n");
	
	return 0;
}

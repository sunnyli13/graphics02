#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

	struct matrix *m1 = new_matrix(4, 4);
	struct matrix *m2 = new_matrix(4, 2);

	// add_edge
	printf("Testing add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =\n");
	add_edge(m2, 1, 2, 3, 4, 5, 6);
	print_matrix(m2);
	printf("\n");

	// ident.
	printf("Testing ident. m1 =\n");
	ident(m1);
	print_matrix(m1);
	printf("\n");

	// mult.
	printf("Testing Matrix mult. m1 * m2 =\n");
	matrix_mult(m1, m2);
	print_matrix(m2);
	printf("\n");

	free_matrix(m1);
	m1 = new_matrix(4, 4);
	add_edge(m1, 1, 2, 3, 4, 5, 6);
	add_edge(m1, 7, 8, 9, 10, 11, 12);

	printf("Testing Matrix mult. m1 =\n");
	print_matrix(m1);
	printf("\n");

	printf("Testing Matrix mult. m1 * m2 =\n");
	matrix_mult(m1, m2);
	print_matrix(m2);
	printf("\n");

	free_matrix(m1);
	free_matrix(m2);

	// create gallery image
	screen s;
	clear_screen(s);
	color c;

	struct matrix *mat = new_matrix(4, 6);

	c.red = 26;
	c.green = 148;
	c.blue = 49;

	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 50; j++) {
			plot(s, c, i, j);
		}
	}

	c.red = 185;
	c.green = 235;
	c.blue = 255;

	for (int i = 0; i < 500; i++) {
		for (int j = 50; j < 500; j++) {
			plot(s, c, i, j);
		}
	}

	c.red = 101;
	c.green = 67;
	c.blue = 33;

	add_edge(mat, 350, 25, 0, 400, 0, 0);
	add_edge(mat, 320, 80, 0, 350, 25, 0);
	add_edge(mat, 300, 300, 0, 320, 80, 0);
	add_edge(mat, 150, 25, 0, 100, 0, 0);
	add_edge(mat, 180, 80, 0, 150, 25, 0);
	add_edge(mat, 200, 300, 0, 180, 80, 0);

	draw_lines(mat, s, c);

	c.red = 97;
	c.green = 138;
	c.blue = 61;

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		int xr = rand() % 300;
		int yr = rand() % 300;
		draw_line(250, 250, 250 + xr, 250 + yr, s, c);
		draw_line(250, 250, 250 - xr, 240 + yr, s, c);
	}

	for (int i = 0; i < 200; i++) {
		draw_line(rand() % 501, 250 + rand() % 250, rand() % 501, 250 + rand() % 250, s, c);
	}

	//display(s);
	save_extension(s, "pic.png");

}
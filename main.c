/*

MAZE GENERATOR

Copyright 2019 Brian Puthuff

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


#define FLOOR 32
#define WALL  63


enum
{
	UP    = 0,
	RIGHT = 1,
	DOWN  = 2,
	LEFT  = 3 
};


struct maze
{
	uint8_t *cells;
	uint8_t w;
	uint8_t h;
};


struct maze *
create_maze(uint8_t w, uint8_t h);


void
destroy_maze(struct maze *m);


void
build_selection(int8_t *s);


uint8_t
get_cell(struct maze *m, uint16_t x, uint16_t y);


void
set_cell(struct maze *m, uint8_t d, uint16_t x, uint16_t y);


void
build_maze(struct maze *m, int16_t r, int16_t c);


void
print_maze(struct maze *m);


int main(int argc, char **argv)
{
	uint8_t w = 0;
	uint8_t h = 0;
	uint8_t r = 0;
	uint8_t c = 0;
	struct maze *m = NULL;


	/* random seed */
	srand(time(NULL));
	
	/* parse command line arguments */
	if (argc > 2) {
		w = (uint8_t)strtod(argv[1], NULL);
		h = (uint8_t)strtod(argv[2], NULL);
	} else if (argc > 1) {
		w = (uint8_t)strtod(argv[1], NULL);
		h = (uint8_t)strtod(argv[1], NULL);
	} else {
		w = 9;
		h = 9;
	}

	/* create maze structure */
	m = create_maze(w, h);

	if (m == NULL) {
		return 1;
	}
	
	/* choose an odd start row */
	do {
		r = rand() % m->h;
	} while ((r % 2) != 1);
		
	/* chose an odd start column */
	do {
		c = rand() % m->w;
	} while ((c % 2) != 1);
	
	build_maze(m, r, c);
	print_maze(m);
	destroy_maze(m);

	return 0;
}


struct maze *
create_maze(uint8_t w, uint8_t h)
{
	struct maze *m = NULL;
	uint8_t *d = NULL;
	uint16_t a = 0;
	uint16_t i = 0;

	/* correct bad dimensional input */
	if (w < 3)
		w = 3;

	if (h < 3)
		h = 3;

	if ((w % 2) == 0 )
		w -= 1;

	if ((h % 2) == 0 )
		h -= 1;

	a = (uint16_t)w * (uint16_t)h;

	d = malloc(sizeof(*d) * a);
	if (d == NULL) {
		printf("The cell data could not be allocated.\n");
		return NULL;
	}

	for (i = 0; i < a; i += 1)
		d[i] = WALL;

	m = malloc(sizeof(*m));
	if (m == NULL) {
		printf("The maze structure could not be allocated.\n");
		free(d);
		return NULL;
	}

	m->w = w;
	m->h = h;
	m->cells = d;

	return m;
}


void
destroy_maze(struct maze *m)
{
	if (m == NULL)
		return;

	if (m->cells != NULL)
		free(m->cells);
	
	free(m);
}


void
build_selection(int8_t *s)
{
	uint8_t d = 0;
	uint8_t i = 0;
	uint8_t f = 0;
	uint8_t p = 0;


	do {
		f = 0;
		d = (uint8_t)rand() % 4;
		for (i = 0; i < (p + 1); i += 1) {
			if (s[i] == d)
				f = 1;
		}
		if (f == 0) {
			s[p] = d;
			p += 1;
		}
	} while (p < 4);
}


uint8_t
get_cell(struct maze *m, uint16_t x, uint16_t y)
{
	if (m == NULL)
		return 0;

	if ((x >= m->w) || (y >= m->h))
		return 0;
	
	return m->cells[((y * m->w) + x)];
}


void
set_cell(struct maze *m, uint8_t d, uint16_t x, uint16_t y)
{
	if (m == NULL)
		return;

	if ((d != FLOOR) && (d != WALL))
		return;

	if ((x >= m->w) || (y >= m->h))
		return;
	
	m->cells[((y * m->w) + x)] = d;
}


void
build_maze(struct maze *m, int16_t r, int16_t c)
{	
	uint8_t d = 0;
	int8_t s[4] = { -1, -1, -1, -1 };


	build_selection(s);
	set_cell(m, FLOOR, c, r);
	for (d = 0; d < 4; d += 1) { 
		switch (s[d]) {
		case UP:
			if ((r - 2) > 0) {
				if (get_cell(m, c, (r - 2)) == WALL) {
					set_cell(m, FLOOR, c, (r - 1));
					build_maze(m, (r - 2), c);
				}
			}
			break;
		case RIGHT:
			if ((c + 2) < (m->w - 1)) {
				if (get_cell(m, (c + 2), r) == WALL) {
					set_cell(m, FLOOR, (c + 1), r);
					build_maze(m, r, (c + 2));
				}
			}
			break;
		case DOWN:
			if ((r + 2) < (m->h - 1)) {
				if (get_cell(m, c, (r + 2)) == WALL) {
					set_cell(m, FLOOR, c, (r + 1));
					build_maze( m, (r + 2), c );
				}
			}
			break;
		case LEFT:
			if ((c - 2) > 0) {
				if (get_cell(m, (c - 2), r) == WALL) {
					set_cell(m, FLOOR, (c - 1), r);
					build_maze(m, r, (c - 2));
				}
			}
			break;
		default:
			break;

		}
	}
}


void
print_maze(struct maze *m)
{
	uint8_t r;
	uint8_t c;
	uint8_t d;


	printf("\n\n\n");
	for (r = 0; r < m->h; r += 1) {
		for (c = 0; c < m->w; c += 1) {
			d = (unsigned char)get_cell(m, c, r);
			printf("%c%c", d, d);
		}
		printf("\n");
	}
	printf ( "\n\n\n" );
}


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
#include <time.h>



enum {
	UP    = 0,
	RIGHT = 1,
	DOWN  = 2,
	LEFT  = 3 
};



struct Maze {
	int *cells;
	int w;
	int h;
};



struct Maze *createMaze ( int width, int height );
void destroyMaze ( struct Maze *m );
void drill ( struct Maze *m, int r, int c );
void printMaze ( struct Maze *m );



int main ( int argc, char **argv ) {

	int w, h;
	int r, c;
	struct Maze *maze;



	/* random seed */
	srand ( time ( NULL ) ) ;
	
	/* parse command line arguments */
	if (argc > 2) {
		w = ( int ) ( strtod ( argv[1], NULL ) );
		h = ( int ) ( strtod ( argv[2], NULL ) );
	}
	else if (argc > 1) {
		w = ( int ) ( strtod ( argv[1], NULL ) );
		h = ( int ) ( strtod ( argv[1], NULL ) );
	}
	else {
		w = 9;
		h = 9;
	}

	/* create maze structure */
	maze = createMaze ( w, h );

	if ( maze != NULL ) {
		/* choose a start row */
		do {
			r = rand ( ) % maze->h;
		} while ( r % 2 != 1 );
		
		/* chose a start column */
		do {
			c = rand ( ) % maze->w;
		} while ( c % 2 != 1 );
	
		/* build maze */
		drill ( maze, r, c );

		/* display maze */
		printMaze ( maze );

		/* destroy maze structure */
		destroyMaze ( maze );
	}

	return 0;
}



struct Maze *createMaze ( int width, int height ) {

	int i;
	struct Maze *m = NULL;
	int *cd = NULL;



	/* correct bad dimensional input */
	if ( width < 3 ) {
		width = 3;
	}
	if ( height < 3 ) {
		height = 3;
	}
	if ( width % 2 == 0 ) {
		width -= 1;
	}
	if ( height % 2 == 0 ) {
		height -= 1;
	}

	/* allocate memory for cell data */
	cd = malloc ( sizeof ( int ) * ( width * height ) );
	if ( cd != NULL ) {
		/* set all cell data to 1 (wall) */
		for ( i = 0; i < ( width * height ); i++ ) {
			cd[i] = 1;
		}

		/* allocate memory for maze structure */
		m = malloc ( sizeof ( struct Maze ) );
		if ( m != NULL ) {
			m->w = width;
			m->h = height;
			m->cells = cd;

		}
		else {
			free (cd );
			printf ( "Maze structure could not be created.\n" );
		}
	}
	else {
		printf ( "Cell data buffer could not be created.\n" );
	}

	return m;
}



void destroyMaze ( struct Maze *m ) {

	if ( m != NULL ) {
		if ( m->cells != NULL ) {
			free ( m->cells );
		}
		free ( m );
	}
}



void drill ( struct Maze *m, int r, int c ) {
	
	int i, p;
	int direction;
	int bull;
	int selection[4] = { -1, -1, -1, -1 };



	/* build a randomized selection set */
	p = 0;
	do {
		bull = 0;
		direction = rand ( ) % 4;
		for (i = 0; i < p + 1; i++) {
			if ( selection[i] == direction ) {
				bull = 1;
			}
		}
		if ( bull == 0 ) {
			selection[p] = direction;
			p++;
		}
	}
	while ( p < 4 );



	/* build a path workshop */
	m->cells[r * m->w + c] = 0;
	
	for ( i = 0; i < 4; i++ ) { 
		direction = selection[i];
		switch ( direction ) {
		case UP:
			if ( r - 2 > 0 ) {
				if ( m->cells[( r - 2 ) * m->w + c] == 1) {
					m->cells[( r - 1 ) * m->w + c] = 0;
					drill ( m, r - 2, c );
				}
			}
			break;

		case RIGHT:
			if ( c + 2 < m->w - 1 ) {
				if ( m->cells[r * m->w + ( c + 2 )] == 1) {
					m->cells[r * m->w + ( c + 1 )] = 0;
					drill ( m , r, c + 2 );
				}
			}
			break;

		case DOWN:
			if ( r + 2 < m->h - 1 ) {
				if ( m->cells[( r + 2 ) * m->w + c] == 1) {
					m->cells[( r + 1 ) * m->w + c] = 0;
					drill ( m, r + 2, c ); 
				}
			}
			break;

		case LEFT:
			if ( c - 2 > 0 ) {
				if ( m->cells[r * m->w + ( c - 2 )] == 1) {
					m->cells[r * m->w + ( c - 1 )] = 0;
					drill ( m, r, c - 2 );
				}
			}
			break;
		default:
			break;

		}
	}
}



void printMaze ( struct Maze *m ) {
	
	int r, c;



	printf ( "\n\n\n" );
	for ( r = 0; r < m->h; r++ ) {
		for ( c = 0; c < m->w; c++ ) {
			if ( m->cells[r * m->w + c] == 0 ) {
				printf ( " " );
			}
			else {
				printf ( "#" );
			}
		}
		printf ( "\n" );
	}
	printf ( "\n\n\n" );
}


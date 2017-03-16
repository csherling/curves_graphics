#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {

  screen s;
  struct matrix * edges;
  struct matrix * transform;

  color color;
  color.red = MAX_COLOR;
  color.green = MAX_COLOR;
  color.blue = MAX_COLOR;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  /* print_matrix(make_rotX(M_PI/4)); */
  /* printf("\n"); */
  /* print_matrix(make_rotY(M_PI/4)); */
  /* printf("\n"); */
  /* print_matrix(make_rotZ(M_PI/4)); */
  /* printf("\n"); */

  /* if ( argc == 2 ) */
  /*   parse_file( argv[1], transform, edges, s ); */
  /* else */
  /*   parse_file( "stdin", transform, edges, s ); */

  clear_screen(s);
  add_circle(edges, 100,100,0,50,100);
  draw_lines(edges, s, color);
  display(s);
  
  free_matrix( edges );
  free_matrix( transform );
}  

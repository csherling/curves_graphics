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
  color.green = 0;
  color.blue = 0;
  
  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  /* print_matrix(make_rotX(M_PI/4)); */
  /* printf("\n"); */
  /* print_matrix(make_rotY(M_PI/4)); */
  /* printf("\n"); */
  /* print_matrix(make_rotZ(M_PI/4)); */
  /* printf("\n"); */

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "script", transform, edges, s );



  
  clear_screen(s);
  edges = new_matrix(4,4);
  /* add_circle(edges, 100,100,0,50,10); */

  /* print_matrix(edges); */


  add_edge(edges,150,50,0,350,50,0); //b
  add_edge(edges,150,249,0,350,249,0); //t
  add_edge(edges,100,100,0,100,200,0); //l
  add_edge(edges,399,100,0,399,200,0); //r

  add_edge(edges,150,75,0,350,75,0); //b
  add_edge(edges,150,224,0,350,224,0); //t
  add_edge(edges,125,100,0,125,200,0); //l
  add_edge(edges,374,100,0,374,200,0); //r

  add_edge(edges,162.5,249,0,162.5,299,0); //1
  add_edge(edges,187.5,249,0,187.5,299,0); //2
  add_edge(edges,312.5,249,0,312.5,299,0); //3
  add_edge(edges,337.5,249,0,337.5,299,0); //4

  add_circle(edges,175,324,0,28,100); //l
  add_circle(edges,325,324,0,28,100); //r

  add_edge(edges,202,327,0,217,327,0); //tl
  add_edge(edges,202,321,0,217,321,0); //bl

  add_edge(edges,283,327,0,297,327,0); //tr
  add_edge(edges,283,321,0,297,321,0); //br

  add_edge(edges,217,327,0,222.5,342,0); //bl
  add_edge(edges,217,321,0,222.5,336,0); //bl

  add_edge(edges,222.5,342,0,233.5,312,0); //bl
  add_edge(edges,222.5,336,0,233.5,306,0); //bl

  add_edge(edges,233.5,312,0,244.5,342,0); //bl
  add_edge(edges,233.5,306,0,244.5,336,0); //bl

  add_edge(edges,244.5,342,0,255.5,312,0); //bl
  add_edge(edges,244.5,336,0,255.5,306,0); //bl

  add_edge(edges,255.5,312,0,266.5,342,0); //bl
  add_edge(edges,255.5,306,0,266.5,336,0); //bl

  add_edge(edges,266.5,342,0,277.5,312,0); //bl
  add_edge(edges,266.5,336,0,277.5,306,0); //bl

  add_edge(edges,277.5,312,0,283,327,0); //bl
  add_edge(edges,277.5,306,0,283,321,0); //bl
  
  add_curve(edges,100,100,150,50,0,-100,100,0,100,0); //bl
  add_curve(edges,100,200,150,250,0,100,100,0,100,0); //tl
  add_curve(edges,350,50,400,100,100,0,0,100,100,0); //br
  add_curve(edges,350,250,400,200,100,0,0,-100,100,0); //tr

  add_curve(edges,125,100,150,75,0,-50,50,0,100,0); //bl
  add_curve(edges,125,200,150,225,0,50,50,0,100,0); //tl
  add_curve(edges,350,75,375,100,50,0,0,50,100,0); //br
  add_curve(edges,350,225,375,200,50,0,0,-50,100,0); //tr
  
  /* add_curve(edges,0,0,100,100,200,100,300,0,100,1); */
  draw_lines(edges, s, color);
  display(s);

  save_extension(s, "battery.png");
  
  free_matrix( edges );
  free_matrix( transform );
}  

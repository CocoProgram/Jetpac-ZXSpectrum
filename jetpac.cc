#include <esat/window.h>
#include <esat/draw.h>
#include <esat/sprite.h>
#include <esat/input.h>
#include <esat/time.h>

#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <time.h>

const int ventanaX=800;
const int ventanaY=800;

int esat::main(int argc, char **argv) {

  double current_time,last_time;
  unsigned char fps=30;

  esat::WindowInit(ventanaX,ventanaY);
  WindowSetMouseVisibility(true);

  srand(time(NULL)); // Por si se hacen randoms

  // Cosas que se tengan que inicializar antes del bucle de juego (Menú, por ejemplo)

  while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {
    esat::DrawBegin();
    last_time = esat::Time();
    esat::DrawClear(0,0,0);

	  // Dibujar();

    esat::DrawEnd();
    do{
    current_time = esat::Time();
    }while((current_time-last_time)<=1000.0/fps);

    esat::WindowFrame();
  }

 // Liberar celdas
  esat::WindowDestroy();
  return 0;
}

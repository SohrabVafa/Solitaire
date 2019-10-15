/*
 * Practice projects for summer
 */

/* 
 * File:   main.cpp
 * Author: sohrabvafa
 *
 * Created on August 25, 2019, 8:32 PM
 */

#include <cstdlib>
#include "Utilidades.h"
#include "Game.h"
using namespace std;
using namespace miniwin;

/*
 * 
 */
int main() {
   vredimensiona(1240, 950);
   
   Game g;
   
   g.Show();
   
 //  while(true);
   while(tecla()!=ESCAPE){
       g.Play();
       g.Show();
       espera(1000);
   }
   vcierra();
   return 0;
}


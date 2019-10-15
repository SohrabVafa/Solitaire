/*
 * Practice projects for summer
 */

#include "Utilidades.h"
using namespace miniwin;

void drawTable(){
    color(VERDE);
    rectangulo_lleno(0,0,1240,950);
    color(AMARILLO);
    rectangulo(50,20,170,220);
    rectangulo(220,20,340,220);
    rectangulo(390,20,510,220);
    rectangulo(560,20,680,220);
    rectangulo(800,20,920,220);
    rectangulo(970,20,1090,220);
    
    rectangulo(50,270,170,470);
    rectangulo(220,270,340,470);
    rectangulo(390,270,510,470);
    rectangulo(560,270,680,470);
    rectangulo(730,270,850,470);
    rectangulo(900,270,1020,470);
    rectangulo(1070,270,1190,470);
}

void drawClubs(int x, int y){
    circulo(x-9,y,8);
    circulo(x+9,y,8);
    circulo(x,y-9,8);
    
    linea(x,y-5,x-5,y+12);
    linea(x,y-5,x+5,y+12);
    linea(x-5,y+12,x+5,y+12);
}

void drawSpades(int x, int y){
    
    linea(x-17,y,x+17,y);
    linea(x-17,y,x,y-17);
    linea(x+17,y,x,y-17);
    
    linea(x,y-5,x-5,y+12);
    linea(x,y-5,x+5,y+12);
    linea(x-5,y+12,x+5,y+12);
}

void drawHearts(int x, int y){
    linea(x-12,y,x,y+17);
    linea(x,y+17,x+12,y);
    linea(x-12,y,x-6,y-6);
    linea(x-6,y-6, x, y);
    linea(x,y, x+6, y-6);
    linea(x+6,y-6,x+12,y);
//    circulo(x-6,y,6);
//    circulo(x+6,y,6);
}

void drawDiamonds(int x, int y){
    
    linea(x-10,y,x,y+15);
    linea(x,y+15,x+10,y);   
    linea(x-10,y,x,y-15);
    linea(x,y-15,x+10,y);
}

void drawCard(Card c, int x, int y){
    if(c.face_up){
    color(BLANCO);
    rectangulo_lleno(x,y,x+120,y+200);
    color_rgb(217,217,217);
    rectangulo(x,y,x+120,y+200);
        if(c.Col() == Colors::Red)
            color(ROJO);
        else
            color(NEGRO);
        
        std::string rank[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
        
        
        texto(x+10,y+25,rank[c.rank]);
        switch (c.suit){
            case Suits::Clubs: 
                drawClubs(x+40,y+20);
                break;
            case Suits::Diamonds:
                drawDiamonds(x+40,y+20);
                break;
            case Suits::Hearts:
                drawHearts(x+40,y+10);
                break;
            case Suits::Spades:
                drawSpades(x+40,y+20);
                break;
            
        }
                
    }else{
        color_rgb(204, 0, 0);
        rectangulo_lleno(x,y,x+120,y+200);
        color_rgb(255, 26, 26);
        rectangulo(x,y,x+120,y+200);
        color_rgb(255, 26, 26);
        linea(x+20,y+20,x+60,y+180);
        linea(x+60,y+180,x+100,y+20);
        linea(x+20,y+180,x+60,y+20);
        linea(x+60,y+20,x+100,y+180);
        linea(x+10,y+100,x+110,y+100);
    }
}

void drawPile(CardPile p, int x, int y){
    for(int i=0; i<p.getUtil(); i++){
        drawCard(p.getCard(i),x,y+(i*40));
    }
}

void drawSelection(int num, int x, int y){
    color_rgb(50, 0, 200);
    rectangulo_lleno(x-2,y-2,x+123,y+163+(num*40));
}
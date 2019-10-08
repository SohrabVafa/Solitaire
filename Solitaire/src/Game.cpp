/*
 * Practice projects for summer
 */

/* 
 * File:   Game.cpp
 * Author: sohrabvafa
 * 
 * Created on August 25, 2019, 6:46 PM
 */

#include "Game.h"
using namespace miniwin;

Game::Game() {
    for(int i=0; i<4; i++)
        piles[i] = new SuitPile;
    piles[4] = new DiscardPile;
    piles[5] = new DeckPile;
    for(int i=6; i<13; i++)
        piles [i] = new TablePile;
    
    piles[5]->Mix();
    
    for(int i=1; i<8; i++){
        for(int j=0; j<i; j++){
            piles[i+5]->AddCard(piles[5]->Pop());
        }
        piles[i+5]->setFaceUp();
    }
    
    int aux = 0;
    for(int i=0; i<6; i++){
        if(i==4)
            aux = 70;
        piles[i]->x = 50+(170*i) + aux;
        piles[i]->y = 20;
    }
    for(int i=0; i<7; i++){
        piles[i+6]->x = 50+(170*i);
        piles[i+6]->y = 270;
    }
    
}

Game::Game(const Game& orig) {
}

Game::~Game() {
    for(int i=0; i<13; i++){
        delete piles[i];
    }
}

void Game::Show(){
    borra();
    drawTable();
    for(int i=0; i<13; i++){
        piles[i]->Draw();
    }
    refresca();
}

void Game::Play(){
    float r_x,r_y;
    bool selected = false;
    CardPile *pile1, *pile2;
    while(!selected && tecla()!=ESCAPE){
        
        if(raton_boton_izq() && raton(r_x,r_y)){
            
           
           
           std::cout<<r_x<<"  "<<r_y<<"\n";
           
           for(int i=0; i<13 && !selected; i++){
               
               selected = piles[i]->isSelected(r_x, r_y);
               
               if(selected){
                   if(piles[i]->getUtil()!=0){
                       pile1 = piles[i];
                       pile1->DrawSelected();
                       refresca();
                    }else{
                       selected = false;
                    }
               }
            }
        }
    }
    if(pile1!=piles[5]){
        selected = false;
        espera(1000);
        while(!selected && tecla()!=ESCAPE){
        
            if(raton_boton_izq() && raton(r_x,r_y)){
           
                std::cout<<r_x<<"  "<<r_y<<"\n";
           
                for(int i=0; i<13 && !selected; i++){
               
                    selected = piles[i]->isSelected(r_x, r_y);
               
                    if(selected){
                        if(piles[i]!=pile1){
                            pile2 = piles[i];
                            pile2->DrawSelected();
                            refresca();
                        }else{
                            selected = false;
                        }
                    }    
                }
            }
        }
        
        int pos = pile1->getUtil();
        if(pile1==piles[4] || pile2==piles[0] || pile2==piles[1] || pile2==piles[2] || pile2==piles[3]){
            pos--;
        }else{
            while(pile1->getCard(pos-1).face_up){
                pos--;
            }
        }
      
        if(pile2->CanTake(pile1->getCard(pos))){
            for(int i=pos; i<pile1->getUtil(); i++){
                pile2->AddCard(pile1->getCard(i));
            }
            pile1->setUtil(pos);
            pile1->setFaceUp();
        }
        
        
    }else{
        piles[4]->AddCard(pile1->Pop());
        piles[4]->getCard(piles[4]->getUtil()-1).face_up = true;
        
        
        
        
    }
    
    
       
    
}
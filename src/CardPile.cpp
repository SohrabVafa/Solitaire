/*
 * Practice projects for summer
 */

/* 
 * File:   CardPile.cpp
 * Author: sohrabvafa
 * 
 * Created on August 25, 2019, 12:01 PM
 */

#include "CardPile.h"
#include "Utilidades.h"
CardPile::CardPile(const CardPile& orig) {
    
    size = util = orig.util;
    pile = new Card[size];  
    for(int i=0; i<util; i++)
        pile[i] = orig.pile[i];
}

void CardPile::AddCard(Card c){
    if(size <= util){
        size++;
        Card *aux = new Card[size];
        for(int i=0; i<util; i++)
            aux[i] = pile[i];
        delete[] pile;
        pile = aux;
        aux = nullptr;
    }
    pile[util] = c;
    util++;
}

void CardPile::Mix(){
    srand (time(NULL));
    int pos;
    Card aux;
    for(int i=0; i<util; i++){
        pos = rand() % util;
        aux = pile[i];
        pile[i] = pile[pos];
        pile[pos] = aux;
    }
}

void CardPile::Draw(){
    if(util>0)
        drawCard(pile[util-1],x,y);
}

void CardPile::DrawSelected(){
    drawSelection(1,x,y);
    Draw();
}

Card CardPile::Pop(){
    if(util>0)
        util--;
    return pile[util];
    
}

bool CardPile::isSelected(int i, int j){
    return ((i>=x && i<=x+width) && (j>=y && j<=y+height));
}
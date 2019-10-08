/*
 * Practice projects for summer
 */

/* 
 * File:   SpecialCardPiles.cpp
 * Author: sohrabvafa
 * 
 * Created on August 25, 2019, 6:22 PM
 */

#include "SpecialCardPiles.h"

    DeckPile::DeckPile(): CardPile(52){
        for(int i=0; i<13; i++){
            AddCard(Card(i, Suits::Clubs,false));
            AddCard(Card(i, Suits::Diamonds,false));
            AddCard(Card(i, Suits::Hearts,false));
            AddCard(Card(i, Suits::Spades,false)); 
        }
    }
    
    void TablePile::Draw(){
        drawPile(*this, x, y);
    }
    
    void TablePile::DrawSelected(){     
        drawSelection(this->util,x,y);
        Draw();
    }
    
    bool TablePile::isSelected(int i, int j){
        
        return ((i>=x && i<=x+120) && (j>=y && j<=(y+200+(this->getSize()*40))));
    }
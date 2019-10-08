/*
 * Practice projects for summer
 */

/* 
 * File:   SpecialCardPiles.h
 * Author: sohrabvafa
 *
 * Created on August 25, 2019, 6:22 PM
 */

#ifndef SPECIALCARDPILES_H
#define SPECIALCARDPILES_H
#include "Utilidades.h"
#include "CardPile.h"

class SuitPile : public CardPile{
    public:
    bool CanTake(Card c) override{
        bool aux = false;
        if(util>0){
            aux = (pile[util-1].suit == c.suit && (pile[util-1].rank + 1) == c.rank);
        }
        return ((util == 0 && c.rank == 0) || aux);
    }
    
};

class DeckPile : public CardPile{
public:
    //creates the complete deck pile
    DeckPile();

    
};

class DiscardPile : public CardPile{
    
};

class TablePile : public CardPile{
public:
    
    bool CanTake(Card c) override{
        bool aux = false;
        if(util>0){
            aux = (pile[util-1].Col() != c.Col() && (pile[util-1].rank - 1) == c.rank);
        }
        return ((util == 0 && c.rank == 12) || aux);
    }
    
    void Draw() override;
    void DrawSelected() override;
    bool isSelected(int i, int j) override;
};
#endif /* SPECIALCARDPILES_H */


/*
 * Practice projects for summer
 */

/* 
 * File:   CardPile.h
 * Author: sohrabvafa
 *
 * Created on August 25, 2019, 12:01 PM
 */

#ifndef CARDPILE_H
#define CARDPILE_H
#include <iostream>
#include "Cards.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
class CardPile {
protected:
    Card *pile;
    int size;
    int util;
    int width=120, height=200;
//    bool selected = false;
public:
    
    int x, y;
    
    CardPile(){
        pile = nullptr;
        util = size = x = y = 0;
    }
    
    CardPile(int n){
        pile = new Card[n];
        util = 0;
        size = n;
    }
    
    CardPile(const CardPile& orig);
    
    virtual ~CardPile(){
        delete[] pile;
    }
    
    //Get
    
    
    const Card & getCard(int i) const {
        return pile[i];
    }
    
    Card & getCard(int i){
        return pile[i];
    }
    
    int getUtil(){
        return util;
    }
    
    int getSize(){
        return size;
    }
        
    Card Pop();
    //Set
    
    void setUtil(int n){
        if(n<=size){
            util=n;
        }
    }
    
    void setCard(Card c, int pos){
        if (pos<util)
            pile[pos] = c;
    }
    
    void AddCard(Card c);
    
    void Mix();
    
    void setFaceUp(){
        pile[util-1].face_up = true;
    }
    
    //To be redefined
    
    virtual bool CanTake(Card c){
        return false;
    }
    
/*    virtual Card Select() {
        selected = true;
        return Card(0, Suits::Clubs, false);
    }
*/    
    virtual void Draw();
    
    virtual void DrawSelected();
    
    
    virtual bool isSelected(int i, int j);
};

#endif /* CARDPILE_H */


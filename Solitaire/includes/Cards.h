/*
 * Practice projects for summer
 */

/* 
 * File:   Cards.h
 * Author: sohrabvafa
 *
 * Created on August 25, 2019, 12:07 PM
 */

#ifndef CARDS_H
#define CARDS_H

enum class Suits{Spades, Hearts, Diamonds, Clubs};

enum class Colors{Black, Red};

struct Card{
    short rank;
    Suits suit;
    bool face_up;
    
    Card(){
        rank = 1;
        suit = Suits::Clubs;
        face_up = false;
    }
    
    Card(short r, Suits s, bool f){
        rank =r;
        suit = s;
        face_up = f;
    }
    
    Colors Col(){
        if(suit == Suits::Diamonds || suit == Suits::Hearts)
            return Colors::Red;
        return Colors::Black;
    }
};

#endif /* CARDS_H */


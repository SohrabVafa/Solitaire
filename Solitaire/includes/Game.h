/*
 * Practice projects for summer
 */

/* 
 * File:   Game.h
 * Author: sohrabvafa
 *
 * Created on August 25, 2019, 6:46 PM
 */

#ifndef GAME_H
#define GAME_H

#include "SpecialCardPiles.h"

class Game {
private:
    // 0-3 Suits 4 discard 5 deck 6-12 table
    CardPile *piles[13];
public:
    //creates a complete pile of cards and puts each pile with the number of cards that it needs
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    //shows the table and the piles
    void Show();
    
    void Play();

};

#endif /* GAME_H */


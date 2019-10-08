/*
 * Practice projects for summer
 */

/* 
 * File:   Utilidades.h
 * Author: sohrabvafa
 *
 * Created on August 25, 2019, 8:42 PM
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "miniwin.h"
#include "CardPile.h"
#include <sstream>
void drawTable();

void drawClubs(int x, int y);

void drawSpades(int x, int y);

void drawHearts(int x, int y);

void drawDiamonds(int x, int y);

void drawCard(Card c, int x, int y);

void drawPile(CardPile p, int x, int y);

void drawSelection(int num, int x, int y);

#endif /* UTILIDADES_H */


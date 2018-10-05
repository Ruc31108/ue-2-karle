/*
 * File: HelloKarel.c
 * --------------------------------
 * The HelloKarel program is a simple
 * program to demonstrate a minimal working
 * Karel example.
 * 
 */

#include "karel.h"
/*
 * Truns Karel 90 degress to the Right
 */
void turnRight(){
    for (int turnRightCounter = 0; turnRightCounter < 3; ++turnRightCounter) {
        turnLeft();
    }
}

void setup() {
    loadWorld("damagedPillar1");
}

void bigStep(){
    for (int moveCounter = 0; moveCounter < 4; ++moveCounter) {
        move();
    }
}

void checkForBeep() {
    // Kein # vorhanden
    if (noBeepersPresent()){
        // Hinlegen
        putBeeper();
    }
}

void build(){
    // Test fuer push
    checkForBeep();
    if(!frontIsBlocked()) {
        bigStep();
    } else {
        if (facingEast()) {
            turnLeft();
            move();
            turnLeft();
        } else if (facingWest()) {
            turnRight();
            move();
            turnRight();
        }
    }
}

void run() {
    while(!((frontIsBlocked() && leftIsBlocked() && facingEast()) || (frontIsBlocked() && rightIsBlocked() && facingWest()))) {
        build();
    }
}


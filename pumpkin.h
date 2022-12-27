//
// Created by Karla Castello on 4/16/22.
//

#ifndef PROJECT_2_PUMPKIN_H
#define PROJECT_2_PUMPKIN_H

#include <iostream>
#include <iomanip>

using namespace std;

#include "crop.h"

class Pumpkin : public Crop {
    public:
        Pumpkin(){
            health = 100;
            waterLevel = 0;
            fertilizer = 0;
            maturation = 13;
        }
        void nextDay() override{
            maturation--;
                if (health <= 100 && health > 0) {
                    if (waterLevel < 8) {
                        decreaseHealth(10);
                    }
                    if (fertilizer < 6) {
                        decreaseHealth(5);
                    }
                    if (waterLevel >= 8) {
                        increaseHealth(7);
                    }
                    if (fertilizer >= 6) {
                        increaseHealth(5);
                    }
                weather();
                printBadChance();
                if (waterLevel < 0){
                    waterLevel = 0;
                }
                if (waterLevel > 10){
                    waterLevel = 10;
                }
                if (fertilizer < 0){
                    fertilizer = 0;
                }
                if (fertilizer > 10){
                    fertilizer = 10;
                }
                if (health < 0){
                    health = 0;
                }
                if (health > 100){
                    health = 100;
                }
                cout << sep << endl;
                cout << "                                               Water level is at " << waterLevel << endl;
                cout << "                                               Fertilizer level is at " << fertilizer << endl;
                cout << "                                               The health of your "<< cropName <<" are at " << health << endl;
                cout << "                                               Days until mature: " << maturation << endl;
                cout << sep << endl;
            }

        }
        string getName()override {return cropName;}
        //save game
        void saveGame(string outPutFile) override{
            ofstream outGame(outPutFile);
            outGame << health << endl;
            outGame << waterLevel << endl;
            outGame << fertilizer << endl;
            outGame << maturation << endl;
            outGame << cropType << endl;
            outGame.close();
        }

        void printBadChance() override{
           srand(time(0));
           int i = rand()%100 + 1;
           if (i % 12 == 0){
               cout << "                                               Oh no! A fungal disease has grown on your pumpkins and their leaves!" << endl;
               cout << "                                                    The health of your pumpkins has decreased! :(" << endl;
               health -= 30;
           }
        }
    private:
        string cropName = "pumpkins";
        int cropType = 1;

};

#endif //PROJECT_2_PUMPKIN_H



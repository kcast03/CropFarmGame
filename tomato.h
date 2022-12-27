//
// Created by Karla Castello on 4/16/22.
//

#ifndef PROJECT_2_TOMATO_H
#define PROJECT_2_TOMATO_H

#include "crop.h"

class Tomato : public Crop {
public:
    Tomato(){
        health = 100;
        waterLevel = 0;
        fertilizer = 0;
        maturation = 11;
    }
    void nextDay() override {
        maturation--;
        if (health <= 100 && health > 0) {
            if (waterLevel < 7) {
                decreaseHealth(10);
            } else {
                increaseHealth(7);
            }
        }
        weather();
        printBadChance();
        if (waterLevel < 0) {
            waterLevel = 0;
        }
        if (waterLevel > 10) {
            waterLevel = 10;
        }
        if (fertilizer < 0) {
            fertilizer = 0;
        }
        if (fertilizer > 10) {
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
        cout << "                                               The health of your " << cropName << " are at " << health << endl;
        cout << "                                               Days until mature: " << maturation << endl;
        cout << sep << endl;
    }

    string getName() override {return cropName;}
    //save game
    void saveGame(string outPutFile) override{
        ofstream outGame(outPutFile);
        outGame << health;
        outGame << waterLevel << endl;
        outGame << fertilizer << endl;
        outGame << maturation << endl;
        outGame << cropType << endl;
        outGame.close();
    }
    void printBadChance() override{
        srand(time(0));
        int i = rand()% 100 + 1;
        if (i % 11 == 0){
            cout << "                                               Oh no! It seems like some extreme weather has ruined some of your tomatoes!" << endl;
            cout << "                                                       The health of your tomatoes has decreased! :(" << endl;
            health -= 40;
        }
    }

private:
    string cropName = "tomatoes";
    int cropType = 3;
};

#endif //PROJECT_2_TOMATO_H

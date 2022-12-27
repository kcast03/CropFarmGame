//
// Created by Karla Castello on 4/16/22.
//

#ifndef PROJECT_2_POTATO_H
#define PROJECT_2_POTATO_H

#include "crop.h"

class Potato : public Crop{
public:
    Potato(){
        health = 100;
        waterLevel = 0;
        fertilizer = 0;
        maturation = 6;
    }
    void nextDay() override{
        maturation--;
            if (health <= 100 && health > 0) {
                if (waterLevel < 5 || waterLevel > 7) {
                    decreaseHealth(4);
                } else {
                    increaseHealth(6);
                }
                if (fertilizer < 7) {
                    decreaseHealth(5);
                }

                if (fertilizer >= 7) {
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
            cout << "                                               The health of your "<<cropName << " are at " << health << endl;
            cout << "                                               Days until mature: " << maturation << endl;
            cout << sep << endl;
        }
    }
    string getName() override {return cropName;}
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
        int i = rand()% 100 + 1;
        if (i % 9 == 0){
            cout << "                                               Oh no! You potatoes are beginning to show signs of potato wilt!" << endl;
            cout << "                                                       The health of your potatoes has decreased! :(" << endl;
            health -= 20;
        }
    }

private:
    string cropName = "potatoes";
    int cropType = 2;
};

#endif //PROJECT_2_POTATO_H




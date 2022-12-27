//
// Created by Karla Castello on 4/19/22.
//

#ifndef PROJECT_2_CROP_H
#define PROJECT_2_CROP_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Crop {
public:
    Crop();
    void Gameplay();
    virtual void nextDay() = 0;
    virtual string getName() = 0;
    int getHealth() ;
    void setHealth(int);
    void setWaterLevel(int);
    void setFertilizer(int);
    void setMaturation(int);
    void decreaseHealth(int h);
    void increaseHealth(int h);
    void increaseWaterLevel(int water);
    int getWaterLevel() ;
    void increaseFertilizerLevel(int fer);
    int getMaturation() const;
    virtual void printBadChance() = 0;
    void static printMenu();
    void Replant();
    bool winOrLose() const;
    virtual void saveGame(string) = 0;
    void weather();
    string sep = "===============================================================================================================================================================";

protected:
    int health = 100;
    int maturation = 1;
    int waterLevel = 0;  //0-10
    int fertilizer = 0;//0-10
};


#endif //PROJECT_2_CROP_H

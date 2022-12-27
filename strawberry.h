#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "crop.h"

class Strawberry : public Crop {
	public:
        //default constructor
        Strawberry(){
            health = 100;
            waterLevel = 0;
            fertilizer = 0;
            maturation = 8;
        }
        //outputs the data variables of the crop object depending on water level, fertilizer, weather and bad chance
        void nextDay() override{
            maturation --;
                //decrease or increases crop health depending on the water and fertilizer levels
                if (health <= 100 && health > 0) {
                    if (waterLevel < 7 ) {
                        decreaseHealth(10);
                    } else {
                        increaseHealth(7);
                    }
                    if (fertilizer < 8) {
                        decreaseHealth(5);
                    }

                    if (fertilizer >= 8) {
                        increaseHealth(5);
                    }
                weather(); //outputs the random weather
                printBadChance(); //outputs the bad chance randomly and decreases health accordingly
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
                cout << "                                               The health of your "<< cropName << " at " << health << endl;
                cout << "                                               Days until mature: " << maturation << endl;
                cout << sep << endl;
            }
        }
        //outputs the name of crop
        string getName()override {return cropName;}
        //saves variables of crop object into a file
    void saveGame(string outPutFile) override{
        ofstream outGame(outPutFile);
        outGame << health << endl;
        outGame << waterLevel << endl;
        outGame << fertilizer << endl;
        outGame << maturation << endl;
        outGame << cropType << endl;
        outGame.close();
    }
    //function that decreases health randomly
    void printBadChance() override{
        srand(time(0));
        int i = rand()%100 + 1;
        if (i % 13 == 0){
            cout << "                                               Oh no! Some pesky critters have invaded your strawberries!" << endl;
            cout << "                                                       The health of your strawberries has decreased! :(" << endl;
            health -= 45;
        }
    }
	private:
        string cropName = "strawberries";
        int cropType = 4;
};

#endif
#include "crop.h"

//all major functions are in this file

//default constructor
Crop::Crop(){
    health = 100;
    waterLevel = 0;
    fertilizer = 0;
    maturation = 0;
}
//functions used to manipulate health based on other variables and user input
int Crop::getHealth() {
    if (health > 100){
        health = 100;
    }
    return health;
}

void Crop::increaseHealth(int h) {
    if (health < 100) {
        health += h;
    }
}

void Crop::decreaseHealth(int h) {
    if (health > 0) {
        health -= h;
    }
}
//functions to manipulate water level based on user input and other variables
void Crop::increaseWaterLevel(int water){
    if (water > 10){
        cout << "||||  Max water level is 10. Please select level 1 -10." << endl;
    }
    if (waterLevel == 10){
        cout << "||||  You have reached the max water level!" << endl;
    }
    else {
        waterLevel += water;
    }
}
int Crop::getWaterLevel() {
    if (waterLevel > 10){
        waterLevel = 10;
    }
    return waterLevel;
}

//increase fertilizer based on user input
void Crop::increaseFertilizerLevel(int fer) {
    if (fertilizer == 10) {
        cout << "||||  You have reached the max fertilizer level!" << endl;
    } else {
        fertilizer += fer;
    }
}
int Crop::getMaturation() const {
    return maturation;
}
//setters for the main crop variables for saving and loading game
void Crop::setHealth(int h){
    health = h;
}
void Crop::setFertilizer(int f){
    fertilizer = f;
}
void Crop::setMaturation(int m){
    maturation = m;
}
void Crop::setWaterLevel(int w) {
    waterLevel= w;
}

//function that replants your crop and randomly sets the health, and sets the water and fertilizer back to 0
void Crop::Replant() {
    srand(time(0));
    health = rand() % 100 + 1;
    waterLevel = 0;
    fertilizer = 0;
}

//print choices for user manipulation
void Crop::printMenu(){
    cout << "||||  What would you like to do today?" << endl;
    cout << "||||    1 - Water my crop"<< endl;
    cout << "||||    2 - Add fertilizer" << endl;
    cout << "||||    3 - Check crop's health" << endl;
    cout << "||||    4 - Check water level" << endl;
    cout << "||||    5 - Replant" << endl;
    cout << "||||    6 - Quit Game" << endl;
    cout << "||||    7- Sleep/Next Day" << endl;
}
//needed to determine winner/loser and exit user input loop
bool Crop::winOrLose() const{
    if (maturation == 0){
        if (health > 0) {
            return true;
        }
    }
    else if (health <= 0){
        return true;
    }
    return false;
}

//random weather functions that decrease and increase water level
void Crop::weather(){
    srand(time(0));
    int i = rand() % 2 + 1;
    if (i == 1){
        cout << "                                               The weather today is rainy and cloudy." << endl;
        waterLevel += 3;
        fertilizer -= 3;
    }
    else if(i == 2){
        cout << "                                               The weather today is sunny and dry. Make sure your crop has enough water!" << endl;
        waterLevel -= 2;

    }
}
//all the options the user has to manipulate a crop objects
void Crop::Gameplay(){
    cout << endl;
    Crop::printMenu();
    int option;
    cin >> option;
    while (!winOrLose()) {
        switch (option) {
            case 1: //add water and how much
                cout << "||||    How much would you like to add? (1-10)" << endl;
                int water;
                cin >> water;
                increaseWaterLevel(water); //
                break;
            case 2: //add fertilizer and how much
                cout << "||||    How much would you like to add? (1-10)" << endl;
                int fer;
                cin >> fer;
                increaseFertilizerLevel(fer); //
                break;
            case 3: //check crop health
                cout << "||||  Your " << getName() << " are at " << getHealth() << " health." << endl;
                break;
            case 4: //check water level
                cout << "||||  Your "<< getName() <<"' water level is at " << getWaterLevel() << endl;
                break;
            case 5: //replant crop
                cout << "||||  You are about to replant your " << getName() <<". The health will either decrease or increase." << endl;
                cout << "||||    Are you sure you would like to replant?" << endl;
                cout << "||||      1 - Yes!      2 - Not today. " << endl;
                int replant;
                cin >> replant;
                if (replant == 1){
                    Replant();
                }
                else {
                    break;
                }
                break;
            case 6: //save and quit game
                cout << "||||  Are you sure you would like to end the game here?" << endl;
                cout << "||||    0- Save and Quit    1- Keep Playing" << endl;
                int play;
                cin >> play;
                if (play == 1){
                    break;
                }
                else if (play == 0){
                    cout << "                                               See you next time!" << endl;
                    cout << sep << endl;
                    cout << "||||  Please enter name for unfinished game: ";
                    string NewGame;
                    cin >> NewGame;
                    saveGame(NewGame);
                    goto endLoop;
                }
                break;
            case 7: //output nextDay() function
                nextDay();
                break;
            default:
                cout << "||||  Invalid Option!" << endl;
                cout << sep << endl;
        }
        if (getHealth() <= 0){
            cout << "                   Your crops have died. Game Over."<< endl;
            goto endLoop;
        }
        else if (getMaturation() == 0 && getHealth() > 0){
            cout <<"                    WINNER: You have successfully grown your crops to their mature age!"<<endl;
            goto endLoop;
        }
        cout << endl;
        cout << "||||  Press 'enter' to continue"<< endl;
        system("read");
        Crop::printMenu();
        cin >> option;

    }
    endLoop: ;

}










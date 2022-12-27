#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "crop.h"
#include "pumpkin.h"
#include "potato.h"
#include "tomato.h"
#include "strawberry.h"


using namespace std;
string sep = "===============================================================================================================================================================";

//This function prints the starting screen title and options. It is only used once.
void printStartScreen() {
    cout << "                       ||||||||||   |||||||||    |||||||||||  ||||||||||   ||||    ||||    ||||      |||     |||     |||||||||  ||||     ||||" << endl;
    cout << "                       |||          |||   |||    |||     |||  |||    |||    |||    |||    ||  ||     |||     |||     |||         |||     |||" << endl;
    cout << "                       |||          |||||||||    |||     |||  ||||||||||     ||    ||    ||||||||    |||     |||     |||||||||    |||||||||" << endl;
    cout << "                       |||          |||    |||   |||     |||  |||             ||  ||    ||      ||   |||     |||     |||             |||" << endl;
    cout << "                       ||||||||||   |||     |||  |||||||||||  |||              ||||    ||        ||  ||||||| ||||||  |||||||||       |||" << endl;
    cout << endl;
    cout << "                                               Press 's' to load saved game or 'n' to start a new game and press enter" << endl;
}
//This function prints the basic instructions for the user. It is only used once.
void printInstructions(){
    cout <<"                                               The purpose of this game is to get your crop to its mature age without it dying."<< endl;
    cout <<"                                                                    Press enter after any input."<< endl;
    cout <<"                                               Health is measured from 1 - 100. If the health is at 0, you lose the game."<< endl;
    cout <<"                                                                            Good Luck!"<< endl;
    cout <<"                                                                    (Press 'enter' to continue)"<<endl;

}
//This function shows the different options you have when selecting the type of crop. It is shown whenever a new game is made.
void printCropMenu() {
    cout << "                                               Please choose your starting crop: " << endl;
    cout << "                                                       1 - Pumpkin" << endl;
    cout << "                                                       2 - Potato" << endl;
    cout << "                                                       3 - Tomato" << endl;
    cout << "                                                       4 - Strawberry" << endl;
}
//loads data from variables into their respective object variables
void loadGame(string inPutFile) {
    ifstream inGame(inPutFile);
    if (!inGame.is_open()) {
        cout << "                                                       File not found!";

    } else {
        int h;
        int w;
        int f;
        int m;
        int type;
        inGame >> h;
        inGame >> w;
        inGame >> f;
        inGame >> m;
        inGame >> type;
        inGame.close();


        if (type == 1) {
            Pumpkin crop;
            crop.setHealth(h);
            crop.setWaterLevel(w);
            crop.setFertilizer(f);
            crop.setMaturation(m);
            crop.Gameplay();

        } else if (type == 2) {
            Potato crop;
            crop.setHealth(h);
            crop.setWaterLevel(w);
            crop.setFertilizer(f);
            crop.setMaturation(m);
            crop.Gameplay();

        } else if (type == 3) {
            Tomato crop;
            crop.setHealth(h);
            crop.setWaterLevel(w);
            crop.setFertilizer(f);
            crop.setMaturation(m);
            crop.Gameplay();
        } else if (type == 4) {
            Strawberry crop;
            crop.setHealth(h);
            crop.setWaterLevel(w);
            crop.setFertilizer(f);
            crop.setMaturation(m);
            crop.Gameplay();

        }

    }
}

int main() {
    cout << sep << endl;
    printStartScreen(); //prints the start screen
    cout << sep << endl;
    string game;
    cin >> game;
    while (true){     //while loop to choose to load saved game or make new game
        if (game == "n" || game == "s"){
            break;
        }
        else{
            cout << "                                                     Invalid Input! Please Try Again." << endl;
            cout << endl;
            cin >> game;
        }
    }

    if (game == "n") { //new game
        system("clear");
        cout << sep << endl;
        printInstructions();  //instructions to game
        cout << sep << endl;
        system("read");
        system("clear");
        cout << sep << endl;
        printCropMenu();  //menu to choose crop
        cout << sep << endl;
        int crop;
        cin >> crop;
        //starts the gameplay depending on the object/crop the user has chosen
        if (crop == 1) {
            Pumpkin start;
            system("clear");
            cout << sep << endl << sep << endl;
            cout << "||||  You have chosen: Pumpkin" << endl;
            start.Gameplay();

        } else if (crop == 2) {
            Potato start;
            system("clear");
            cout << sep << endl << sep << endl;
            cout <<"||||  You have chosen: Potato" << endl;
            start.Gameplay();
        } else if (crop == 3) {
            Tomato start;
            system("clear");
            cout << sep << endl << sep << endl;
            cout << "||||  You have chosen: Tomato" << endl;
            start.Gameplay();
        } else if (crop == 4) {
            Strawberry start;
            system("clear");
            cout << sep << endl << sep << endl;
            cout << "||||  You have chosen: Strawberry" << endl;
            start.Gameplay();
        }
    }
    //option to load saved game;
    else if (game == "s"){
        system("clear");
        cout << sep << endl;
        string inputFileName;
        cout << "||||  Please enter the name of your saved game: ";
        cin >> inputFileName;
        cout << endl;
        loadGame(inputFileName);
    }


    return 0;
}

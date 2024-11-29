// #include "Food.h"
// #include "MacUILib.h"
// #include "GameMechs.h"

// Food::Food(){

// }

// Food::~Food(){

// }

// void Food::generateFood(GameMechs* gameMechsPtr, objPos blockOff){
//     int goalIndices[2];  // Stores indices of chosen characters from goalstring
//     int goalstringLength = my_strlen(goalstring);
//     int i, j;

//     for (i = 0; i < 2; i++){
//         int index;
//         int unique = 0;

//         while (!unique) {
//             unique = 1;
//             index = rand() % goalstringLength;
            

//             for (j = 0; j < i; j++) {
//                 if (goalIndices[j] == index) {
//                     unique = 0;
//                     break;
//                 }
//             }
//         }

//         goalIndices[i] = index;
//         list[i].symbol = goalstring[index];
//     }

//     //three unique random characters from ASCII range 33–126
//     for (i = 2; i < listSize; i++) {
//         int unique = 0;
        
//         while (!unique) {
//             unique = 1;
//             list[i].symbol = (char)(rand() % (126 - 33 + 1) + 33);  //random ASCII character

//             if (list[i].symbol == playerPos->symbol || list[i].symbol == '|' || list[i].symbol == '=' || list[i].symbol == ' ') {
//                 unique = 0;
//             }

//             //check for duplicates with previously chosen symbols
//             for (j = 0; j < i; j++) {
//                 if (list[j].symbol == list[i].symbol) {
//                     unique = 0;
//                     break;
//                 }
//             }
//         }
//     }

//     //assign random positions to each item and removing overlap
//     for (i = 0; i < listSize; i++) {
//         int valid = 0;
        
//         while (!valid) {
//             valid = 1;
//             list[i].x = rand() % xRange + 1;
//             list[i].y = rand() % yRange + 1;

//             //Break if there's overlap with other items or the player
//             for (j = 0; j < i; j++) {
//                 if ((list[i].x == list[j].x && list[i].y == list[j].y) || 
//                     (list[i].x == playerPos->x && list[i].y == playerPos->y)) {
//                     valid = 0;
//                     break;
//                 }
//             }
//         }
//     }
// }

// void Food::getFoodPos(objPos &foodpos){

// }
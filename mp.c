/****************************************************************************** 
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts learned. I have constructed
the functions and their respective algorithms and corresponding code by
myself. The program was run, tested, and debugged by my own efforts. I
further certify that I have not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
Keisha Leigh DM. Villanueva - 12210021 - S19B
******************************************************************************/

/*
    Description: This program's shooting game features a tile-based approach and 
                places restrictions on both the player's and the enemy's movement within specific areas.
    Programmed by: Keisha Leigh DM. Villanueva S19B
    Last modified: December 4, 2022
    Version: 1.9
*/

#include <stdio.h>

/* This function draws the grid of the game and where player and enemies are located
  Precondition: The player has not won or lose yet
  @param nPlayerx is where player is positioned
  @param nEnemyx1 represents the x coordinate of enemy 1 
  @param nEnemyy1 represents the y coordinate of enemy 1
  @param nEnemyx2 represents the x coordinate of enemy 2 
  @param nEnemyy2 represents the y coordinate of enemy 2
  @param nEnemyx3 represents the x coordinate of enemy 3 
  @param nEnemyy3 represents the y coordinate of enemy 3
  @returns nothing
*/
void drawGrid(int nPlayerx, int nEnemyx1, int nEnemyy1, int nEnemyx2, 
                int nEnemyy2, int nEnemyx3, int nEnemyy3){
    int i; // variable for row
    int j; // variable for column
    
    for(i = 0; i < 9; i++){
        if(i == 0){
            printf("┌-------┐");
        }
        else if(i == 6){
            printf("|-------|");
        }
        else if(i == 7){
            for(j = 1; j <= 9; j++){
                if(j%2 == 1){ // check if column's position is odd and prints the column's grid
                    printf("|");
                }
                if(j%2 == 0){ // check if column's position is even and prints where the player is positioned
                    if(j == nPlayerx){
                    printf("P"); 
                    }
                    else{ // prints a blank space
                    printf(" ");  
                    }
                }
            }  
        }
        else if(i == 8){
            printf("└-------┘");
        }
        else{
            for(j = 1; j <= 9; j++){
                if(j%2 == 1){ // check if columns' position is odd and prints the column's grid
                    printf("|");
                }
                if(j%2 == 0){ // check if column's position is even and prints where the enemies is positioned
                    if((j == nEnemyx1 && i == nEnemyy1) || (j == nEnemyx2 && i == nEnemyy2) 
                        || (j == nEnemyx3 && i == nEnemyy3)){
                    printf("X"); 
                    }
                    else{ // prints a blank space
                    printf(" ");  
                    }
                }
            }  
        }
        printf("\n");
    } // end for loop
}

/* This function shows the score of the player
    Precondition: The game is not yet over 
    @param nScore consists of player's current score
    @returns nothing
*/
void showScore(int nScore){
    printf("Score: %d\n", nScore);  
}

/* This function prints actions to choose from and ask for player input action  
    Precondition: Player does not lose yet
    @returns nInput
*/
int askPlayerInput(){
	int nInput;
	printf("Actions:\n");
	printf(" 1 - move left\n");
	printf(" 2 - move right\n");
	printf(" 3 - fire laser\n");
    
    do{                                
        printf("Input action: ");
        scanf("%d", &nInput);
        printf("\n");
    }while(nInput > 4 || nInput < 0);  // continually seeks an input of 1, 2, or 3 in order to advance the game
    
	return nInput;
}

/* This function shows the player move
    Precondition: The player chooses 1 or 2 as player input action
    @param nInput consists player input action
    @param *nPlayerx stores the position of player
    @returns nothing
*/
void showPlayermove(int nInput, int *nPlayerx){
    if(nInput > 0 && nInput <=2){ // if nInput is not between 1 or 2, the enemies will not move
        if(nInput == 1){ // player moves left
            if(*nPlayerx > 2){
                *nPlayerx-=2;
            }      
        }
        if(nInput == 2){ // player moves right
            if(*nPlayerx < 8){
                *nPlayerx+=2;
            }   
        }
    }
}

/* This function shows the enemy move
    Precondition: The game is not yet over
    @param *nEnemyx1 stores current x coordinate of enemy 1 
    @param *nEnemyy1 stores current y coordinate of enemy 2
    @param *nEnemyx2 stores current x coordinate of enemy 2
    @param *nEnemyy2 stores current y coordinate of enemy 2
    @param *nEnemyx3 stores current x coordinate of enemy 3
    @param *nEnemyy3 stores current y coordinate of enemy 1
    @param *nEnemyMove1 stores the move of enemy 1
    @param *nEnemyMove2 stores the move of enemy 2
    @param *nEnemyMove3 stores the move of enemy 1
    @returns nothing
*/
void showEnemymove(int nInput, int *nEnemyx1, int *nEnemyy1, int *nEnemyx2, int *nEnemyy2, int *nEnemyx3, 
                    int *nEnemyy3, int *nEnemyMove1, int *nEnemyMove2, int *nEnemyMove3){
    
    if(nInput > 0 && nInput <=3){ // if nInput is not between 1, 2, or 3, the enemies will not move
        if(*nEnemyMove1 > 0){
            if(*nEnemyMove1 == 1){
                *nEnemyx1 +=2; 
            } // enemy 1 goes to the right for the initial move
            if(*nEnemyMove1 == 2){
                *nEnemyy1 +=1;
            } // enemy 1 makes a second move and goes down
            if(*nEnemyMove1 == 3){
                *nEnemyx1 -=2;
            } // enemy 1 makes a third move, moving to the left
            if(*nEnemyMove1 == 4){
                *nEnemyy1 +=1; 
            } // enemy 1 moves down for their fourth move
        }
        
        if(*nEnemyMove2 > 0){
            if(*nEnemyMove2 == 1){
                *nEnemyx2 +=2; 
            } // enemy 2 goes to the right for the initial move
            if(*nEnemyMove2 == 2){
                *nEnemyy2 +=1;
            } // enemy 2 makes a second move and goes down
            if(*nEnemyMove2 == 3){
                *nEnemyx2 -=2;
            } // enemy 2 makes a third move, moving to the left
            if(*nEnemyMove2 == 4){
                *nEnemyy2 +=1; 
            } // enemy 2 moves down for their fourth move
        }

        if(*nEnemyMove3 > 0){
            if(*nEnemyMove3 == 1){
                *nEnemyx3 +=2; 
            } // enemy 3 goes to the right for the initial move
            if(*nEnemyMove3 == 2){
                *nEnemyy3 +=1;
            } // enemy 3 makes a second move and goes down
            if(*nEnemyMove3 == 3){
                *nEnemyx3 -=2;
            } // enemy 3 makes a third move, moving to the left
            if(*nEnemyMove3 == 4){
                *nEnemyy3 +=1; 
            } // enemy 3 moves down for their fourth move
        }
       
        *nEnemyMove1 = *nEnemyMove1 % 4 + 1; // recursively returns to cases at the switch statement for *nEnemyMove1
        *nEnemyMove2 = *nEnemyMove2 % 4 + 1; // recursively returns to cases at the switch statement for *nEnemyMove2
        *nEnemyMove3 = *nEnemyMove3 % 4 + 1; // recursively returns to cases at the switch statement for *nEnemyMove3
    }
}

/* This function shows when player selects to shoot and enemies are respawn
    Precondition: The player chooses 3 as player input action
    @param nPlayerx consists where player is positioned
    @param *nEnemyx1 stores current x coordinate of enemy 1 
    @param *nEnemyy1 stores current y coordinate of enemy 2
    @param *nEnemyx2 stores current x coordinate of enemy 2
    @param *nEnemyy2 stores current y coordinate of enemy 2
    @param *nEnemyx3 stores current x coordinate of enemy 3
    @param *nEnemyy3 stores current y coordinate of enemy 1
    @param *nEnemyMove1 stores enemy 1 move
    @param *nEnemyMove2 stores enemy 2 move
    @param *nEnemyMove3 stores enemy 3 move
    @param *nScore stores player's current score when player shoots enemy
    @returns nothing
*/
void showFirelaser(int nPlayerx, int *nEnemyx1, int *nEnemyy1, int *nEnemyx2, 
                    int *nEnemyy2, int *nEnemyx3, int *nEnemyy3, 
                    int *nEnemyMove1, int *nEnemyMove2, int *nEnemyMove3, int *nScore){
    int i; // variable for row
    int nRespawn = 0; // variable for enemy that has respawned 

    for(i = 5; i > 0 && nRespawn < 1; i--){ // check enemy from the bottom row and at least one enemy has respawned
        if((nPlayerx == *nEnemyx1 && i == *nEnemyy1) || (nPlayerx == *nEnemyx2 && i == *nEnemyy2) || (nPlayerx == *nEnemyx3 && i == *nEnemyy3)){ 
        // checks if there are enemies in the same column where player is positioned
            
            *nScore += 10; // adds score when player shoots an enemy
            
            // enemy 1 
            if(nPlayerx == *nEnemyx1 && i == *nEnemyy1){ // checks if enemy 1 is in the same column where player is positioned
                *nEnemyx1 = 2;
                *nEnemyy1 = 1;
                *nEnemyMove1 = 1;
                nRespawn += 1; 
            } // respawns enemy 1 at top left corner when player shoots enemy 1
            
            // enemy 2
            if(nPlayerx == *nEnemyx2 && i == *nEnemyy2){ // checks if enemy 2 is in the same column where player is positioned
                if(nRespawn == 1){ // checks one enemy will be in the same location where it will be respawned
                    *nEnemyx2 = 4;
                    *nEnemyy2 = 1;
                    *nEnemyMove2 = 1;
                    nRespawn += 1;
                } // respawns enemy 2 beside the enemy that has respawned
                else{
                    *nEnemyx2 = 2;
                    *nEnemyy2 = 1;
                    *nEnemyMove2 = 1;
                    nRespawn += 1;
                } // alternatively, respawns enemy 2 at top left corner when player shoots enemy 2
            } 
            
            // enemy 3
            if(nPlayerx == *nEnemyx3 && i == *nEnemyy3){ // checks if enemy 3 is in the same column where player is positioned
                if(nRespawn == 2){ // checks two enemyies will be in the same location where it will be respawned
                    *nEnemyx3 = 6;
                    *nEnemyy3 = 1;
                    *nEnemyMove3 = 1;
                    nRespawn += 1; 
                } // if all three enemies will respawn, they will respawn beside each other 
                else if(nRespawn == 1){ // checks one enemy will be in the same location where it will be respawned
                    *nEnemyx3 = 4;
                    *nEnemyy3 = 1;
                    *nEnemyMove3 = 1;
                    nRespawn += 1; 
                } // respawns enemy 3 beside the enemy that has respawned
                else{
                    *nEnemyx3 = 2;
                    *nEnemyy3 = 1;
                    *nEnemyMove3 = 1;
                    nRespawn += 1; 
                } // alternatively, respawns enemy 3 at top left corner when player shoots enemy 3
            } 
        } 
    } // end for loop
}

/* This function prints VICTORY! when player defeats the enemy
    Precondition: Player wins the game
    @returns nothing
*/
void printVictory(){
    printf("VICTORY!\n\n");
}

/* This function prints DEFEATED! when enemy defeats the player
    Precondition: Player loses the game
    @returns nothing
*/
void printDefeated(){
    printf("DEFEATED!\n\n"); 
}

int main(){
    // variable declaration 
    int nInput = 0;
    int nPlayerx = 2;
    int nEnemyx1 = 2, nEnemyx2 = 4, nEnemyx3 = 6;
    int nEnemyy1 = 1, nEnemyy2 = 1, nEnemyy3 = 1;
    int nEnemyMove1 = 1, nEnemyMove2 = 1, nEnemyMove3 = 1;
    int nScore = 0;

    drawGrid(nPlayerx, nEnemyx1, nEnemyy1, nEnemyx2, nEnemyy2, nEnemyx3, nEnemyy3);
    showScore(nScore);
    
    do{
        nInput = askPlayerInput();
        showPlayermove(nInput, &nPlayerx);
        if (nInput == 3){ // if player chooses 3 as player input action
            showFirelaser(nPlayerx, &nEnemyx1, &nEnemyy1, &nEnemyx2, &nEnemyy2, &nEnemyx3, 
                &nEnemyy3, &nEnemyMove1, &nEnemyMove2, &nEnemyMove3, &nScore);
        }
        showEnemymove(nInput, &nEnemyx1, &nEnemyy1, &nEnemyx2, &nEnemyy2, &nEnemyx3, 
                &nEnemyy3, &nEnemyMove1, &nEnemyMove2, &nEnemyMove3); 
        drawGrid(nPlayerx, nEnemyx1, nEnemyy1, nEnemyx2, nEnemyy2, nEnemyx3, nEnemyy3);
        showScore(nScore);
    }while(nScore < 100 && nEnemyy1 <= 5 
            && nEnemyy2 <= 5 && nEnemyy3 <= 5); // if the score has not reached 100 and all enemies reached its last row
    
    if (nScore >= 100){
        printVictory(); // if score reaches 100, prints VICTORY!
    }
    else{
        printDefeated(); // alternatively, prints DEFEATED!
    }
    
    return 0;
}
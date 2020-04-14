/*
 * pa2.cpp
 *
 *  Created on: Nov 7, 2018
 *      Author: SBMUN
 */

#include "definition.h"

/* ATTENTION:
 * 1. PLEASE Read the introduction before each function carefully!
 * 2. You can ONLY add your code where you find a comment:
 *   // complete your code here
 * 3. DO NOT modify other things!!
 */

/************* Functions Requires You to Complete. *************/

/* ================================================================
 * Randomly place mines and flowers on the  play board.
 * mine and flower should not exist in the same cell.
 * ----------------------------------------------------------------
 * Input:
 * - cell[MAXSIZE][MAXSIZE]: the play board;
 * - num_mines: number of mines;
 * - num_flowers: number of flowers;
 * - height: height of the play board, which is the number of rows;
 * - width: width of the play board, which is the number of columns;
 * ----------------------------------------------------------------
 */
void generateMineAndFlower(Cell cell[MAXSIZE][MAXSIZE], int num_mines,
      int num_flowers, int height, int width) {

   cout << "\nPlacing mines and flowers ......" << endl;
   srand (time(NULL));int
   row = rand() % height;
   int col = rand() % width;

   for (int i = 0; i < num_mines; i++) {
      if (cell[row][col].content == MINE) {
         row = rand() % height;
         col = rand() % width;

         --i;
      } else {
         cell[row][col].content = MINE;
      }
   }
   for (int j = 0; j < num_flowers; j++) {
      if (cell[row][col].content == MINE
            || cell[row][col].content == FLOWER) {
         row = rand() % height;
         col = rand() % width;
         --j;
      } else {
         cell[row][col].content = FLOWER;
      }

   }

}

/* ================================================================
 * Count the number of surrounding mines of all cells on the game board.
 * You should compute this number not just for empty cells,
 * but also the mine cells and flower cells.
 * ----------------------------------------------------------------
 * Input:
 * - cell[MAXSIZE][MAXSIZE]: the play board;
 * - height: height of the play board, which is the number of rows;
 * - width: width of the play board, which is the number of columns;
 * ----------------------------------------------------------------
 */

void generateMinecountMap(Cell cell[MAXSIZE][MAXSIZE], int height, int width) {
   cout << "/n generate real maps ......" << endl;
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {

//For the 3X3 combinations
         for (int a = i - 1; a < i + 2; a++) {
            for (int b = j - 1; b < j + 2; b++) {
               if (isOnBoard(a, b, height, width)
                     && cell[a][b].content == MINE) {
                  cell[i][j].count += 1;
               }
            }
         }
      }
   }
}

/* ================================================================
 * Sweep the empty cell recursively.
 * You are REQUIRED to implement this function using recursion.
 * You will receive NO mark if your implementation is not an recursion.
 * ----------------------------------------------------------------
 * Input:
 * - cell[MAXSIZE][MAXSIZE]: the play board;
 * - height: height of the play board, which is the number of rows;
 * - width: width of the play board, which is the number of columns;
 * - row: index of current row;
 * - col: index of current column;
 * Output:
 * - additional_life: how many additional lives are obtained
 * ----------------------------------------------------------------
 */
int recursiveSweep(Cell cell[MAXSIZE][MAXSIZE], int height, int width, int row,
      int col) {

	int life = 0;
   if (cell[row][col].marked == false || cell[row][col].swept == false || isOnBoard(row, col, height, width)) {
//Now the square is swept
      cell[row][col].swept = true;
      //content = mine
      if (cell[row][col].content == MINE) {
         return -1;
      }
      //when flower
      else if (cell[row][col].content == FLOWER) {
         if (cell[row][col].count == 0) {
             for (int a = row - 1; a < row + 2; a++) {
                for (int b = col - 1; b < col + 2; b++) {
                   life+= recursiveSweep(cell,height,width, a,b);}}
         }
         else return 1;
      }
      //count =0 w/o flower or mine
      //neither flower nor mine
      else if (cell[row][col].count == 0) {
         for (int a = row - 1; a < row + 2; a++) {
            for (int b = col - 1; b < col + 2; b++) {
               return recursiveSweep(cell,height,width, a,b);;}}
      }
      else return 0;
   }
   else return 0;
}
/* ================================================================
 * Run the game according to the operation chosen
 * ATTENTION:
 * 1. you will use recursiveSweep() in this function.
 * 2. you will use isOnBoard() to help validate the input.
 * ----------------------------------------------------------------
 * Input:
 * - cell[MAXSIZE][MAXSIZE]: the play board;
 * - height: height of the play board, which is the number of rows;
 * - width: width of the play board, which is the number of columns;
 * - row: index of current row;
 * - col: index of current column;
 * - life: record number of lives remaining;
 * - num_mines: number of mines;
 * - num_marked_mines: number of mines marked as mine by player;
 * - op: operation taken. { 0: sweep; 1: mark; 2: unmark}
 * ----------------------------------------------------------------
 */
void operation(Cell cell[MAXSIZE][MAXSIZE], int height, int width, int row,
      int col, int& life, int num_mines, int& num_marked_mines, int op) {
   /* choose to sweep */
   if (op == 0) {
         while(!isOnBoard(row, col, height, width) || cell[row][col].marked == true || cell[row][col].swept == true){
               cout << "Invalid" << endl;
               cout << "row [0-"<<height-1<<"]: "; cin >> row;
               cout << "col [0-"<<width-1<<"]: "; cin >> col;}
         if(cell[row][col].content == MINE){
            life--;
            cell[row][col].swept = true;}
         if(cell[row][col].content ==  FLOWER){
            if(cell[row][col].count == 0){
               life += recursiveSweep(cell, height, width, row, col);
            }
            else{
               cell[row][col].swept = true;
               life++;
            }
         }
         else life += recursiveSweep(cell, height, width, row, col);

   }

   /* choose to mark */
   if (op == 1) {

      while(!isOnBoard(row, col, height, width) || cell[row][col].marked == true || cell[row][col].swept == true){
         cout << "Invalid" << endl;
         cout << "Please input again, from 0-" <<height-1<< "]: "; cin >> row;
         cout << "col [0-"<<width-1<<"]: "; cin >> col;
      }

      if (cell[row][col].marked == false && cell[row][col].swept == false
            && isOnBoard(row, col, height, width)) {

         if (cell[row][col].content == FLOWER) {
            cell[row][col].swept = true;
            cout << "This Place is flower" << endl;

         }

         if (num_marked_mines < num_mines) {
            cell[row][col].marked = true;
            num_marked_mines += 1;
         }
      }
   }

   /* choose to unmark */
   if (op == 2) {
       while(cell[row][col].marked == false || !isOnBoard(row, col, height, width)){
          cout << "Invalid" << endl;
          cout << "row [0-"<<height-1<<"]: "; cin >> row;
          cout << "col [0-"<<width-1<<"]: "; cin >> col;
   }

      if (cell[row][col].marked == true && cell[row][col].swept == false
            && isOnBoard(row, col, height, width)) {
         cell[row][col].marked = false;
         num_marked_mines -= 1;
      }


   }


}


/* ================================================================
 * Check game state: win/lose/continue
 * ----------------------------------------------------------------
 * Input:
 * - cell[MAXSIZE][MAXSIZE]: the play board;
 * - num_mines: number of mines;
 * - height: height of the play board, which is the number of rows;
 * - width: width of the play board, which is the number of columns;
 * - life: record number of lives remaining;
 * Output:
 * - {return -1: lose; return 0: continue; return 1: win}
 * ----------------------------------------------------------------
 */
int checkWin(const Cell cell[MAXSIZE][MAXSIZE], int num_mines, int height,
      int width, int life) {
//The PlayerWIN
   int success = 0;
   for (int a = 0; a < height; a++) {
      for (int b = 0; b < width; b++) {
         if (cell[a][b].marked == MINE) {
            success++;
         }
      }
   }
   if (success == num_mines) {
      return 1;
   } else if (life == 0) {
      return -1;
   } else {
      return 0;
   }

}

//============================================================================
// Name        : pa2.cpp
// Author      : 
// Version     :
// Copyright   : YU,KIJUN (20319196)
// Description : PA2 (minesweeper)
//============================================================================
//  pa2.cpp
//	minesweeper

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


	for (int i = 0; i < num_mines; i++){
		int a = (rand() % height);
		int b = (rand() % width);
		if (cell[a][b].content == MINE){
			i--;
		}
		else {
			cell[a][b].content = MINE; //gen mine
		}
	}

	for (int i = 0; i < num_flowers; i++){
		int a = (rand() % height);
		int b = (rand() % width);
		if (cell[a][b].content == MINE || cell[a][b].content == FLOWER){
			i--;
		}
		else {
			cell[a][b].content = FLOWER; //gen flower
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
void generateMinecountMap(Cell cell[MAXSIZE][MAXSIZE], int height,
	                      int width) {

	cout << "\ngenerate real maps ......" << endl;

	for (int i = 0 ; i < height; i++){
		for (int j = 0; j < width ; j++ ){
			if (cell[i][j].content == MINE){
				for (int a = -1; a < 2; a++){
					for (int b = -1 ;b < 2 ; b++){
						if (isOnBoard(a+i,b+j,height,width)){
							cell[a+i][b+j].count++;
						}
					}
				}
			}
		}
	} // PRINT COUNT FOR EMPTY CELLS
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


int recursiveSweep(Cell cell[MAXSIZE][MAXSIZE], int height, int width,
	               int row, int col) {

	// complete your code here
	if (cell[row][col].marked == true) return 0;
	cell[row][col].swept = true;

	if (cell [row][col].count == 0 && isOnBoard(row,col,height,width)){
		for (int i = -1; i < 2; i++){
			for (int j = -1; j < 2; j++){
				if (isEmpty(cell, row + i, col + j) && cell[row + i][col + j].swept == false)
					recursiveSweep(cell, height, width, row + i, col + j);
				if (cell[row + i][col + j].content == FLOWER && cell[row + i][col + j].swept == false && isOnBoard(row + i,col + j,height,width)){
					 cell[row + i][col + j].swept = true;
					 cell[row + i][col + j].count = 1;
					cout << "found flower life +1"<<endl;

				}
			}
		}
	}
	return 0;
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
void operation(Cell cell[MAXSIZE][MAXSIZE], int height, int width,
	           int row , int col, int& life, int num_mines,
	           int& num_marked_mines, int op) {

	/* choose to sweep */
	if (op == 0) {
		if (cell[row][col].marked == true || cell[row][col].swept == true)
			cout << " the cell should be neither swept nor marked!"<< endl;

		else switch (cell[row][col].content){
				case MINE:
					cout << "mine swept life -1"<< endl;
					life--;
					cell[row][col].swept = true;
					cell[row][col].marked = true;
					num_marked_mines++;
					break;
				case FLOWER:
					life++;
					cout << "found flower life +1"<<endl;
					if (cell[row][col].count > 0){
						cell[row][col].swept = true;
						cell[row][col].count = 0;
						break;}
					else
					recursiveSweep(cell, height, width, row, col);
					cell[row][col].count = 0;
					break;

				case EMPTY:
					recursiveSweep(cell, height, width, row, col);
					if(cell[row][col].count == 0)
					for (int i = 0 ; i < height; i++){
						for (int j = 0; j < width ; j++){
							if (cell[i][j].content == FLOWER && cell[i][j].swept == true && cell[i][j].count == 1){
								cell[i][j].count = 0;
								life++;
							}
						}
					}
					break;
				default:
					break;
		}
	}

	/* choose to mark */
	if (op == 1) {
		if (num_marked_mines == num_mines)
			cout << "already marked "<< num_mines <<" mines"<<endl;
		else if (!cell[row][col].marked && !cell[row][col].swept){
			if (cell[row][col].content == FLOWER){
				cout<< "you marked flower, chance for additional life lost."<< endl;
				cell[row][col].swept = true;
				cell[row][col].count = 0;
			}
			else{
				num_marked_mines++;
				cell[row][col].marked = true;
			}

		}
		else
			cout << "You should mark either non-marked or non-swept cell"<< endl;
	}


	/* choose to unmark */
	if (op == 2) {
		if (num_marked_mines < 1)
			cout << "No cells are marked as mine"<<endl;

		else if (cell[row][col].marked && !cell[row][col].swept){
			cell[row][col].marked = false;
			num_marked_mines--;
		}

		else
			cout << "you can unmark marked cells only!" << endl;
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
int checkWin(const Cell cell[MAXSIZE][MAXSIZE], int num_mines,
             int height, int width, int life) {
	if (life == 0)
		return -1;
	if (life > 0){
		int found_mine = 0;
		int unswept = 0;

		for (int i = 0 ; i < height; i++){
			for (int j = 0; j < width ; j++ ){
				if (cell[i][j].content == MINE && cell[i][j].marked == true)
					found_mine++;
				if (cell[i][j].swept == false)
					unswept++;
			}
		}
		if ((found_mine + unswept) == num_mines)
			return 1;
	}
	return 0;
}

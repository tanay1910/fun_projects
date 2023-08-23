//nqueen problem
#include<stdio.h>
#include <stdbool.h>

// void createBoard(int r, int c)
// {
// 	int i,j, board[r][c];
// 	for(i=0;i<r;i++)
// 	{
// 		for(j=0;j<c;j++)
// 		{
// 			board[i][j]='.';
// 		}
// 	}
// }

void showBoard(int board[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

void putQueen(int board[4][4],int i, int j)
{
	board[i][j]='Q';
}

bool rowCheck(int board[4][4], int row)
{
	int i=row,j;
	for(j=0;j<4;j++)
	{
		if (board[i][j]=='Q')
			return true;
	}
	return false;

}

bool colCheck(int board[4][4], int col)
{
	int i,j=col;
	for(i=0;i<4;i++)
	{
		if (board[i][j]=='Q')
			return true;
	}
	return false;

}

bool lowerRightDiagCheck(int board[4][4], int row,int col)
{
	int i,j;
	for(i=row,j=col;i<4,j<4;i++,j++)
	{
		if(board[i][j]=='Q')
		{
			return true;
		}
	}
	return false;
}

bool upperRightDiagCheck(int board[4][4], int row,int col)
{
	int i,j;
	for(i=row,j=col;i>0,j<4;i--,j++)
	{
		if(board[i][j]=='Q')
		{
			return true;
		}
	}
	return false;
}

bool lowerLeftDiagCheck(int board[4][4], int row,int col)
{
	int i,j;
	for(i=row,j=col;i<4,j>0;i++,j--)
	{
		if(board[i][j]=='Q')
		{
			return true;
		}
	}
	return false;
}

bool upperLeftDiagCheck(int board[4][4], int row,int col)
{
	int i,j;
	for(i=row,j=col;i>=0,j>=0;i--,j--)
	{
		if(board[i][j]=='Q')
		{
			return true;
		}
	}
	return false;
}

bool conditionSatisfied(int board[4][4], int row, int col)
{
	int i,j;
	if(rowCheck(board,row)==false && colCheck(board,col)==false && upperLeftDiagCheck(board,row,col)==false && lowerLeftDiagCheck(board,row,col)==false && upperRightDiagCheck(board,row,col)==false && lowerRightDiagCheck(board,row,col)==false)
	{
		return true;
	}
	return false;
}

void main()
{
	int board[4][4],i,j,qCount=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			board[i][j]='.';
		}
	}

	// showBoard(board);
	// putQueen(board,0,1);
	// for(i=0;i<4;i++)
	// {
	// 	for(j=0;j<4;j++)
	// 	{
	// 		if(conditionSatisfied(board,i,j)==true)
	// 		{
	// 			putQueen(board,i,j);
	// 		}
	// 	}
	// }

	for(i=0,j=0;j<4;j++)
	{
		qCount=0;
		putQueen(board,i,j);
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(conditionSatisfied(board,i,j)==true)
				{
					putQueen(board,i,j);
					qCount++;
				}
			}
		}
		if(qCount==4)
		{
			showBoard(board);
		}



	}

	// putQueen(board,1,1);
	// showBoard(board);
	// if(upperLeftDiagCheck(board,2,3)==true)
	// {
	// 	printf("alr pres!");
	// }

	// createBoard(4,4);

}
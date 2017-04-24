//Input sudoku board - where empty put 0

#include <stdio.h>

int sudoku_check(int check_number, int sudoku_table[9][9], int column, int row)
{
    int sector_column = column/3;
    int sector_row = row/3;

    /*SPRAWDZANIE SEKTOROW*/
    int r, c;
    for(r=(sector_row*3); r<((sector_row+1)*3); r++)
	{
		for(c=(sector_column*3); c<((sector_column+1)*3); c++)
		{
			if(sudoku_table[c][r] == check_number)
				return 0;
		}
	}

	/*SPRAWDZANIE LINI*/
	for(r=0; r<9; r++)
	{
		if(sudoku_table[column][r] == check_number)
			return 0;
		if(sudoku_table[r][row] == check_number)
			return 0;
	}

    return 1;
}

int sudoku_solver(int sudoku_table[9][9], int column, int row)
{
	/*MIEJSCE WYPELNIONE NA STARCIE*/
	if(sudoku_table[column][row])
	{
		if((column==8)&&(row==8))
		{
			return 1;
		}
		else if (column==8)
		{
			if(sudoku_solver(sudoku_table, 0, row+1))
			return 1;
		}
		else
		{
			if(sudoku_solver(sudoku_table, column+1, row))
			return 1;
		}
	}
	else
	{
		/*WYPELNIANIE*/
		int k = 1;
		for(k; k<=9; k++)
		{
			if(sudoku_check(k, sudoku_table, column, row))
			{
				sudoku_table[column][row] = k;

				if((column==8)&&(row==8))
				{
					return 1;
				}
				else if (column==8)
				{
					if(sudoku_solver(sudoku_table, 0, row+1))
						return 1;
				}
				else
				{
					if(sudoku_solver(sudoku_table, column+1, row))
						return 1;
				}

				sudoku_table[column][row] = 0;
			}
		}
	}

	return 0;
}

int main()
{
	/*INPUT*/
	int sudoku_table[9][9];
	int row, column;

	for(row=0; row<9; row++)
	{
		for(column=0; column<9; column++)
		{
			scanf("%i", &(sudoku_table[column][row]));
		}
	}

	sudoku_solver(sudoku_table, 0, 0);

	//OUTPUT
	for(row=0; row<9; row++)
	{
		for(column=0; column<9; column++)
		{
			printf("%i ", sudoku_table[column][row]);
		}
		printf("\n");
	}

	return 0;
}

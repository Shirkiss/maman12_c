#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
 * Progrem: magic
 * ----------------------------
 *   The user enter a list of numbers in one line, starting with the magic square size side, and the program 
 *   Return 1 if it is a magic square and 0 otherwise
 */

/*
 * Function: get_numbers_array
 * ----------------------------
 *   Get the magic square size side and a pointer to an array and put inside of the array numbers given by the user
 *   @param magic_number - magic square size side
 *   @param *array - a pointer to an array to put the magic numbers inside
 *   @return 0 if there was an error with one of the numbers 1 otherwise
 */
int get_numbers_array(int magic_number, int *array);

/*
 * Function: is_magic_square
 * ----------------------------
 *   Get the magic square size side and a pointer to an array and put inside of the array numbers given by the user
 *   @param magic_number - magic square size side
 *   @param *array - a pointer to an array to put the magic numbers inside
 *   @return 0 if there was an error with one of the numbers 1 otherwise
 */
int is_magic_square(int *array, int magic_number);

/*
 * Function: get_magic_number
 * ----------------------------
 *   Get the max size of the magic square size side and return the magic number given by the user or 0 if there
 *   was an error in the number
 *   @param max_size - magic square size side max value
 *   @return 0 if there was an error with one of the numbers, and the magic square size side otherwise
 */
int get_magic_number(int max_size);

/*
 * Function: print_magic_square
 * ----------------------------
 *   Get the magic square size side and a pointer to an array and print the array as a square
 *   @param magic_number - magic square size side
 *   @param *array - a pointer to an array to print
 */
void print_magic_square(int magic_number, int *array);

int main(void)
{
	static int const max_size = 8;
	int magic_number;
	int *array_of;


	printf ("\nWelcome to magic program!\n");


	/* get the magic number (N) */
	magic_number = get_magic_number(max_size);
	/* check if there were any errors */
	if (magic_number == 0)
		return 0;

	/* create array based on the given magic number */
	array_of = (int *) malloc(magic_number*magic_number);

	/* put all the other numbers in the array */
	if (get_numbers_array(magic_number, array_of) == 0)
		return 0;
	print_magic_square(magic_number, array_of);

	/* check if the array is a magic square */
	return is_magic_square(array_of,magic_number);
}

int get_numbers_array(int magic_number, int *array)
{
	int c,c_number,index,i;
	index = 0;
	

	while ((c = getchar()) != EOF)
	{
		while (c == ' ' || c == '\t')
		{
			c = getchar();
		}
		if (c == '\n')
		{
			printf("\nPlease enter all the numbers in one line\n");
			return 0;
		}
		if (!isdigit(c))
		{
			printf ("\nPlease enter only numbers\n");

			return 0;
		}

		c_number = 0;
		while (isdigit(c))
		{
	   		c_number = (c_number * 10) + (c - '0');
	   		c = getchar();
		}
		array[index] = c_number;
		/* Check if the input value already exists in the array */
		for (i = 0; i < index; ++i ) { 
			if (array[i] == array[index])
			{
				printf ("\nYou entered the number %d more than one time\n",array[i]);
				return 0;
			}		
		}
		index++;
	}
	if (index > magic_number*magic_number)
	{
		printf ("\nYou entered too many variants for %d*%d magic square\n",magic_number, magic_number);
		return 0;
	}
	if (index < magic_number*magic_number)
	{
		printf ("\nYou didn't enter enougth variants variants for %d*%d magic square\n",magic_number, magic_number);
		return 0;
	}
	return 1;

}

int is_magic_square(int *array, int magic_number)
{	int row;
	int column;
	int sum = magic_number*(magic_number*magic_number+1)/2;
	int sum_row;
	int sum_column;
	int sum_diagonal = 0;
	for (row = 0; row < magic_number; ++row ) {
		sum_row = 0;
		sum_column = 0;
		for (column = 0; column < magic_number; ++column )  {
			/* check if array elements between 1-N^2 */
			if ((array[column+(magic_number*row)] > magic_number*magic_number) || (array[column+(magic_number*row)] < 1))
			{
				printf ("\nThe number %d is not in the right range\n", array[column+(magic_number*row)]);
				printf ("\nPlease enter only numbers between 1-%d\n", magic_number*magic_number);
				return 0;
			}
			sum_row = sum_row + array[column+(magic_number*row)];
			sum_column = sum_column + array[row+(magic_number*column)];
			if (row == column)
            			sum_diagonal = sum_diagonal + array[column+(magic_number*row)];
		}
		if (sum != sum_row || sum != sum_column)
		{
			printf("\nSorry, the numbers that you entered are not creating magic square\n");
			return 0;
		}
	}
	if (sum != sum_diagonal)
	{
		printf("\nSorry, the numbers that you entered are not creating magic square\n");
		return 0;
	}
printf("\nWell done! you entered a magic square\n");	
return 1;
}

int get_magic_number(int max_size)
{
	int c,c_number;
	c = getchar();
	c_number = 0;
	while (isdigit(c))
	{
   		c_number = (c_number * 10) + (c - '0');
   		c = getchar();
	}

	if (c_number < 3 || c_number > max_size)
	{		
		printf ("\nThe magic square size side you entered is not in the correct range or type\n");
		return 0;
	}
	return c_number;
}

void print_magic_square(int magic_number, int *array)

{	int row;
	int column;

	printf ("\nHere are the numbers that you entered:\n");

	for (row = 0; row < magic_number; ++row ) {
		for (column = 0; column < magic_number; ++column )  {
			printf("%d\t",array[column+(magic_number*row)]);
		}
		printf("\n");			
	}


}

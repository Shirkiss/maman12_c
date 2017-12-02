#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
/*
 * Progrem: --------
 * ----------------------------
 *   Asking the user to chose a progrem between my_strchr, my_strcmp, my_strncmp and applying those function on params given by the user and print it to the screen.
 */


int get_numbers_array(int magic_number, int *array_of_numbers);
int is_magic_box(int *array, int size);
int get_magic_box_size_side(int max_size);

int main(void)
{
	static int const max_size = 8;
	int magic_box_size_side;
	int *array_of;


	printf ("\nWelcome to magic program!\n");


	// get the size side number (N)
	magic_box_size_side = get_magic_box_size_side(max_size);
	if (magic_box_size_side == 0)
		return 0;
	array_of = (int *) malloc(magic_box_size_side*magic_box_size_side);


	if (get_numbers_array(magic_box_size_side, array_of) == 0)
		return 0;

	is_magic_box(array_of,magic_box_size_side);
	return 1;
}

int get_numbers_array(int magic_size, int *array_of_numbers)
{
	int b,b_number,index;
	index = 0;
	

	while ((b = getchar()) != EOF)
	{
		while (b == ' ' || b == '\t')
		{
			b = getchar();
		}
		if (b == '\n')
		{
			printf( "\nPlease enter all the numbers in one line\n");
			return 0;
		}
		if (!isdigit(b))
		{
			printf ("\nPlease enter only numbers\n");

			return 0;
		}

		b_number = 0;
		while (isdigit(b))
		{
	   		b_number = (b_number * 10) + (b - '0');
	   		b = getchar();
		}
		array_of_numbers[index] = b_number;
		index++;
	}
	if (index > magic_size*magic_size)
	{
		printf ("\nYou entered too many variants for %d*%d magic box\n",magic_size, magic_size);
		return 0;
	}
	if (index < magic_size*magic_size)
	{
		printf ("\nYou didn't enter enougth variants variants for %d*%d magic box\n",magic_size, magic_size);
		return 0;
	}
	return 1;
	

}

int is_magic_box(int *array, int magic_box_size_side)
{	int row;
	int column;
	int sum = magic_box_size_side*(magic_box_size_side*magic_box_size_side+1)/2;
	int sum_row;
	int sum_column = 0;
	int sum_diagonal = 0;
	for (row = 0; row < magic_box_size_side; ++row ) {
		sum_row = 0;
		sum_column = 0;
		for (column = 0; column < magic_box_size_side; ++column )  {
			/* check if array elements between 1-N^2 */
			if ((array[column+(magic_box_size_side*row)] > magic_box_size_side*magic_box_size_side) || (array[column+(magic_box_size_side*row)] < 1))
			{
				printf ("\nThe number %d is not in the right range\n", array[column+(magic_box_size_side*row)]);
				printf ("\nPlease enter only numbers between 1-%.0f\n", pow(magic_box_size_side,2));
				return 0;
			}
			sum_row = sum_row + array[column+(magic_box_size_side*row)];
			sum_column = sum_column + array[row+(magic_box_size_side*column)];
			if (row == column)
            			sum_diagonal = sum_diagonal + array[column+(magic_box_size_side*row)];
		}
		if (sum != sum_row || sum != sum_column)
		{
			printf("\nNo Magic square\n");
			return 0;
		}
	}
	if (sum != sum_diagonal)
	{
		printf("\nNo Magic square\n");
		return 0;
	}
printf("\nMagic square\n");	
return 1;
}

int get_magic_box_size_side(int max_size)
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
		printf ("\nThe magic box size side you entered is not in the correct range or type\n");
		return 0;
	}
	return c_number;
}

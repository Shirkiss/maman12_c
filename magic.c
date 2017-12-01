#include <string.h>
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

int main(void)
{
	printf ("\nWelcome to magic program!\n");
	printf ("\nPlease enter magic box numbers\n");


	int c,c_number,i;
	static int const max_size = 8;
	c = getchar();
	c_number = 0;
	while (isdigit(c))
	{
   		c_number = (c_number * 10) + (c - '0');
   		c = getchar();
	}

	if (c_number < 3 || c_number > max_size)
	{		
		printf ("\nThe first number you entered is not in the correct range or type\n");
		return 0;
	}
	int array_size = c_number*c_number;
	int array_of[array_size];


	int status = get_numbers_array(array_size, array_of);
	if (status == 0)
		return 0;


	for (i = 0; i < array_size; i++ ) {

		if ((array_of[i] > c_number*c_number) || (array_of[i] < 0))
		{
			printf ("array_of[%d] = %d", i, array_of[i]);
			printf ("\nError - please enter only numbers between 0-%.0f\n", pow(c_number,2));

			return 0;
		}
		
		
   	}
	is_magic_box(array_of,array_size);
	return 1;
}

int get_numbers_array(int size, int *array_of_numbers)
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
			printf( "\nError - please enter all the numbers in one line\n");
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
	if (index > size)
	{
		printf ("\nToo many variants\n");
		return 0;
	}
	if (index < size)
	{
		printf ("\nNot enougth variants\n");
		return 0;
	}
	return 1;
	

}

int is_magic_box(int *array, int size)
{	int i;
	for (i = 0; i < 5; i++ ) {
			printf( "\narray[%d] = %d\n", i, array[i]);
}
return 0;
}

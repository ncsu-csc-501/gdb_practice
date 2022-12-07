#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

__attribute__((optimize("O0")))
int func1(int *ptr_x, int *ptr_y) {
	int val_x = 0;
	int val_y = 0;

	val_x = *ptr_x;
	val_y = *ptr_y;

	
	kprintf("in func1: %d+%d\n", val_x, val_y);

	return val_x + val_y;	
}

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int main()
{
	int x = 382;
	int y = 119;
	int sum = func1(&x, &y);

	kprintf("\n\nHello CSC %d\n\n", sum);
	return 0;
}


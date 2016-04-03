#include <stdio.h>
#include <stdlib.h>
#include "fuzzy.h"
int main()
{
	fuzzy* machine1;
	machine1=(fuzzy*)malloc(sizeof(fuzzy));
	machine1=new_fuzzy(4.0,-4.0);
	
	//posative
	equ *pos_arg;
	pos_arg=(equ*)malloc(sizeof(equ));
	pos_arg->a=(1.0/8.0);
	pos_arg->b=(0.5);
	//negative
	equ *neg_arg;
	neg_arg=(equ*)malloc(sizeof(equ));
        neg_arg->a=(-1.0/8.0);
        neg_arg->b=(0.5);
	//
	
	//scale
	float scale[4]={4,0,0,-4};
	
	//parameter
	float e[7]={-6.0,-4.0,-2.0,0,2.0,4.0,6.0};
	float ce[7]={-6.0,-4.0,-2.0,0,2.0,4.0,6.0};
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			printf("%e",machine1->InferEng_ptr(machine1,pos_arg,neg_arg,e[i],ce[j],scale,4));
		}

		printf("\n");
	}
	return 0;
}

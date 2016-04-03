#include "fuzzy.h"
fuzzy *new_fuzzy(float upper1,float lowwer1)
{
	fuzzy* obj=NULL;
	obj=(fuzzy*)malloc(sizeof(fuzzy));	
	if(obj==NULL)
	{
		perror("memory leak");
		exit(EXIT_FAILURE);
	}
	obj->upper=upper1;
	obj->lowwer=lowwer1;
	obj->pos_ptr=posative_func;
	obj->neg_ptr=negative_func;
	obj->InferEng_ptr=Inference_Engineer;
	return obj;

}
//posative Slope
float posative_func(fuzzy *argu,equ *equ_arg,float parameter)
{
	if(argu==NULL || equ_arg==NULL)
	{
		perror("fuzzy or equ is pointer to NULL");
		exit(EXIT_FAILURE);		
	}
	if(parameter>(argu->upper))return 1.0; 	
	else if (parameter<(argu->lowwer))return 0;
	else return (equ_arg->a)*parameter+(equ_arg->b);
}

//negative Slope
float negative_func(fuzzy *argu,equ *equ_arg,float parameter)
{
 	if(argu==NULL || equ_arg==NULL)
        {
                perror("fuzzy or equ is pointer to NULL");
                exit(EXIT_FAILURE);
        }
	if(parameter>(argu->upper))return 0;
        else if (parameter<(argu->lowwer))return 1.0;
        else return (equ_arg->a)*parameter+(equ_arg->b);
}

//Inference_Engineer
float Inference_Engineer(fuzzy* mac1,equ* pos_arg,equ *neg_arg,float e,float ce,float *scale,int scale_len)
{
	if(scale_len<4)
	{
		perror("The scale number is too few");
		exit(EXIT_FAILURE);
	}
	float u[8]={
			mac1->pos_ptr(mac1,pos_arg,e),
			mac1->pos_ptr(mac1,pos_arg,ce),
			mac1->pos_ptr(mac1,pos_arg,e),
			mac1->neg_ptr(mac1,neg_arg,ce),
			mac1->neg_ptr(mac1,neg_arg,e),
                        mac1->pos_ptr(mac1,pos_arg,ce),
			mac1->neg_ptr(mac1,neg_arg,e),
                        mac1->neg_ptr(mac1,neg_arg,ce),
			};

	//min save number before subscripting(ex: A[0],A[1];A[0] is before subscripting)
	for(int i=0;i<8;i+=2)
	{
		if(u[i]>u[i+1])u[i]=u[i+1];
	}
	//
	return (u[0]*scale[0]+u[2]*scale[1]+u[4]*scale[2]+u[6]*scale[3])/(u[0]+u[2]+u[4]+u[6]);	
}


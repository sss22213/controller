#ifndef _fuzzy_H_
#define _fuzzy_H_

//include header
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//define method 0 is small,1 is mult  
#define method 0
//
typedef struct _fuzzy fuzzy;
typedef struct _equ equ;

//
typedef float(*negative)(fuzzy*,equ*,float);
typedef float(*posative)(fuzzy*,equ*,float);
typedef float(*Infer_Eng)(fuzzy*,equ*,equ*,float,float,float*,int);

typedef struct _fuzzy
{
        //parameter
        float upper;
        float lowwer;
        negative neg_ptr;
        posative pos_ptr;
	Infer_Eng InferEng_ptr;		
}
fuzzy;

typedef struct _equ
{
        //y=ax+b
        float a;
        float b;
}equ;


//Constructor
fuzzy *new_fuzzy(float,float);
float posative_func(fuzzy*,equ*,float);
float negative_func(fuzzy*,equ*,float);
float Inference_Engineer(fuzzy*,equ*,equ*,float,float,float*,int);


#endif

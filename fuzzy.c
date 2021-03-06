
#include <stdio.h>
#include <stdlib.h>
float min(float a,float b)
{
	if(a>b)
		return b;
	else
		return a;

}
float InferenceEngine(float e,float ce)
{
	//P,P
	float M1=(1.0/8.0)*(e-4.0)+1.0;
        float M2=(1.0/8.0)*(ce-4.0)+1.0;
	if(e>=4)M1=1;
	if(e<=-4)M1=0;
	if(ce>=4)M2=1;
	if(ce<=-4)M2=0;
	//P,N
	float M3=(1.0/8.0)*(e-4.0)+1.0;
        float M4=(-1.0/8.0)*(ce+4.0)+1.0;
	if(e>=4)M3=1;
        if(e<=-4)M3=0;
        if(ce>=4)M4=0;
        if(ce<=-4)M4=1;

	//N,P
	float M5=(-1.0/8.0)*(e+4.0)+1.0;
        float M6=(1.0/8.0)*(ce-4.0)+1.0;
	if(e>=4)M5=0;
        if(e<=-4)M5=1;
        if(ce>=4)M6=1;
        if(ce<=-4)M6=0;

	//N,N
	float M7=(-1.0/8.0)*(e+4.0)+1.0;
        float M8=(-1.0/8.0)*(ce+4.0)+1.0;
	if(e>=4)M7=0;
        if(e<=-4)M7=1;
        if(ce>=4)M8=0;
        if(ce<=-4)M8=1;

	//Min 4 parameter	
	float R1=min(M1,M2);
	float R2=min(M3,M4);
	float R3=min(M5,M6);
	float R4=min(M7,M8);
	//calue
	float u=(R1*4.0+R2*0+R3*0+R4*-4.0)/(R1+R2+R3+R4);
	return u;
}

int main()
{
	float e[7]={-6.0,-4.0,-2.0,0,2.0,4.0,6.0};
	float ce[7]={-6.0,-4.0,-2.0,0,2.0,4.0,6.0};
	//claue 
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<7;j++)
		{
			printf(" %d ",(int)InferenceEngine(e[i],ce[j]));
		}
		printf(" \n ");
	}
	return 0;
}

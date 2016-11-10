#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define L 100
#define T 40.0
#define p 10.0

float main(void){
  float *x;
  float *u_init;
  float *u_fut;
  float *u_p;
  float *u_past;
  int i;
  
  x=malloc(L*sizeof(float));
  u_init=malloc(L*sizeof(float));
  u_fut=malloc(L*sizeof(float));
  u_p=malloc(L*sizeof(float));
  u_past=malloc(L*sizeof(float));
  
  for(i=0;i<L;i++){
    x[i]=i;
    if(x[i]<=80){
      u_init[i]=(0.0125)*x[i];
    }else{
      u_init[i]=5-0.05*x[i];
    }
    u_fut[i]=0.0;
    u_p[i]=0.0;
    u_past[i]=0.0;
  }
  u_init[0]=0;
  u_init[L-1]=0;
  //futuro(x,u_init,u_fut,u_p,u_past);
  
  //return 0;
  //}
  //void futuro(float *x,float *u_init,float *u_fut, float *u_p,float *u_past){
  float dx=x[0]-x[1];
  float dt=0.035;
  float c=(float) T/p;
  float r=c*(dt/dx);
  int a;
  for(a=1;a<L-1;a++){
    u_fut[a]= u_init[a] + pow(r,2)*0.5*(u_init[a+1]-2*u_init[a]+u_init[a-1]);
    u_past[a]=u_init[a];
    u_p[a]=u_fut[a];
  }
  int t;
  for(t=0;t<200;t++){
    int j;
    printf("%f\n",u_p[0]);
    for(j=1;j<L-1;j++){
      u_fut[j]=(2*(1-pow(r,2)))*u_p[j] - u_past[j] + pow(r,2)*(u_p[j+1]+u_p[j-1]);
      u_past[j]=u_p[j];
      u_p[j]=u_fut[j];
      printf("%f \n",u_p[j]);
    }
    printf("%f\n",u_p[L-1]);
  }
  return 0;
}


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float main(){
  float *V;
  float *Ex;
  float *Ey;
  float L=5;
  float l=2;
  float d=1;
  float h=0.02;
  float V0=100;
  float N = pow(L/h,2);
  int n=(int) L/h;
  V=malloc(N*sizeof(float));
  Ex=malloc(N*sizeof(float));
  Ey=malloc(N*sizeof(float));
  int i;
  int j;
  int V1=(int) (L/h)/2-(d/h)/2;
  int V2=(int) (L/h)/2-(l/h)/2;
  int V3=(int) (L/h)/2+(d/h)/2;
  int V4=(int) (L/h)/2+(l/h)/2;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      V[j + n*i]=0;
      Ex[j + n*i]=0;
      Ey[j + n*i]=0;
    }
  }
  
  int s;
  int u;
  for(u=V1-1;u<V3;u++){
    for(s=V2-1;s<V4;s++){
      if(u==V1-1){
	V[s+n*u]=50;
      }else if(u==V3-1){
	V[s+n*u]=-50;
      }else{
	V[s+n*u]=V0;
	V[s+n*u]=V0;
      }
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%f\n",V[j + n*i]);
    }
  }
  int r;
  for(r=0;r<2*N;r++){
    int x;
    for(x=1;x<n-1;x++){
      int y;
      for(y=1;y<n-1;y++){
	V[y+n*x]=0.25*(V[(y+1)+n*x]+V[y +n*(x+1)]+V[(y-1)+n*x]+V[y+n*(x-1)]);
      }
    }
  }
  
  int a;
  int e;
  for(a=0;a<n-1;a++){
    for(e=0;e<n-1;e++){
      Ex[e+n*a]=(V[(e+1)+n*a]-V[e+n*a])/h; 
      Ey[e+n*a]=(V[e+n*(a+1)]-V[e+n*a])/h;
    }
  }
  int t;
  int o;
  for(t=0;t<n;t++){
    for(o=0;o<n;o++){
      printf("%f %f %f\n", Ex[o + n*t], Ey[o + n*t], V[o + n*t]);
    }
  }
  return 0;
} 

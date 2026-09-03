#include <stdio.h> 

int main (void)
{
  int wheel;
  double weight;
  double wheelr;
  double to;
  double rg;
  double c;
  double w;
  double elm;
  double Fmin;
  double Fmotor;
  const double safty = 2.0;
  const double DM = 1.5;
  
 

  printf("구동바퀴 수(ea):");
  scanf("%d",&wheel);
  printf("총하중(kg):");
  scanf("%lf",&weight);
  printf("바퀴 반지름(m):");
  scanf("%lf",&wheelr);
  printf("토크(Nm):");
  scanf("%lf",&to);
  printf("감속비(G):");
  scanf("%lf",&rg);
  printf("구름저항계수(c):");
  scanf("%lf",&c);
  printf("모터 정격토크(Nm):");
  scanf("%lf",&elm);
  
  
  w = 9.8 * weight;

  printf("중량(N):%.1lf\n",w);

  Fmin = c * w * safty * DM;
  Fmotor =((to * rg)/wheelr)*wheel;

  printf("총하중(kg):%.2lf\n",weight);
  printf("구동바퀴 수(ea):%d\n",wheel);
  printf("모터 정격 토크(Nm):%.2lf\n",elm);
  printf("감속비:%.2lf\n",rg);
  printf("바퀴반지름:%.4lf\n\n",wheelr);

  printf("필요한 최소 견인력:%.2lfN\n",Fmin);
  printf("모터가 낼수있는 견인력:%.2lfN\n",Fmotor);

  
  if(Fmin <= Fmotor){printf("판정:만족\n");}else{printf("판정:불만족\n");}
  
    
  return 0;
}
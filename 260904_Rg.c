#include <stdio.h> 
#include <math.h>

int main (void)
{ 
  double r, W, eL_P, eR_P, L ;

  printf("바퀴 반지름[m] : ");        if(scanf("%lf",&r)!=1) return 1;
  printf("트랙폭[m] : ");            if(scanf("%lf",&W)!=1) return 1;
  printf("왼쪽 바퀴 오차율[%%] : ");   if(scanf("%lf",&eL_P)!=1) return 1;
  printf("오른쪽 바퀴 오차율[%%] : ");  if(scanf("%lf",&eR_P)!=1) return 1;
  printf("목표 주행 거리[m] : ");      if(scanf("%lf",&L)!=1) return 1;
  if( r<=0 || W<=0 || eL_P<0 || eR_P<0 || L<=0 )
  {printf("잘못된 값 추가\n");
  return 1;
 }
 // 퍼센트 비율로 변경
 double eL = eL_P/100 ;
 double eR = eR_P/100 ;

 // 바퀴반경
 const double rL = r * (1+eL);
 const double rR = r * (1+eR);
 // 바퀴회전수 
 const double N =(L/(2*r*M_PI));

 // 좌우 바퀴의 유효 이동거리
 double dL = 2*M_PI*rL*N ;
 double dR = 2*M_PI*rR*N ;
 // 곡률 반경
 double Rc = (W/2.0) * (dL+dR)/(dR-dL);
 // 편류각
 double rA = L/Rc ;
 double rA_d = rA*180.0/M_PI;
 // 편류 거리 
 double Ddrift = Rc*(1-cos(rA));

  printf("좌/우 유효 반지름[m] : %.5lf m / %.5lf m\n",rL,rR);
  printf("곡률반경[m] : %.3lf m\n",Rc);
  printf("편류각[deg] : %.3lf deg\n",rA_d);
  printf("최종 편류거리[m] : %.5lf m\n",Ddrift);
  printf("바퀴 회전수: %.2lf\n",N);
  printf("좌/우 유효 이동거리[m] : %.5lf m / %.5lf m\n",dL,dR);
  
 
  return 0;
}
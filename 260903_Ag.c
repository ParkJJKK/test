#include <stdio.h> 
#include <math.h>

int main (void)
{ 
  double Kg, Tm, G, n, r, c, SF;
  int Nm;

 //변수 입력
  printf("총질량[kg] : "); scanf("%lf",&Kg);
  printf("모터 정격토크[Nm] : "); scanf("%lf",&Tm);
  printf("구동 모터 수[개] : "); scanf("%d",&Nm);
  printf("감속비 : "); scanf("%lf",&G);
  printf("구동효율 [0~1] : "); scanf("%lf",&n);
  printf("바퀴 반지름 [m] : "); scanf("%lf",&r);
  printf("구름계수 [0.015~0.03]: "); scanf("%lf",&c);
  printf("안전계수 [>=1] : "); scanf("%lf",&SF);

  // 입력값 검증
  // 수식
  const double Ttot = Nm * Tm * G * n; //총 구동 토크
  const double Favail = Ttot / r; // 가용 견인력
  const double mg = Kg*9.8;
  
  double sin_the = (Favail/SF-c*mg)/mg;
  if (sin_the < 0.0) sin_the = 0.0;
  if (sin_the > 1.0) sin_the = 1.0;

  double the_R = asin(sin_the);
  double the_D = the_R * 180.0/M_PI;
  double the_G = tan(the_R) * 100.0;

  //결과 출력
  printf("\n[결과]\n");
  printf("총 구동 토크 T_tot : %.2f Nm\n",Ttot);
  printf("가용 견인력 F_avail : %.2f N\n",Favail);
  printf("등판 가능 최대각 : %.2f deg\n",the_D);
  printf("등판율(grade) : %.1f %%\n",the_G);
  printf("(가정: 마찰한계 무시, 구름저항 c포함, 안전계수 SF 적용)\n");

  return 0;
}
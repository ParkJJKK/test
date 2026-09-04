#include <stdio.h> 
#include <math.h>

int main (void)
{ 
  double Kg, Tm, G, n, r, c, SF;
  int Nm;

 //변수 입력
  printf("총질량[kg] : ");         if(scanf("%lf",&Kg)!=1) return 1;
  printf("모터 정격토크[Nm] : ");    if(scanf("%lf",&Tm)!=1) return 1;
  printf("구동 모터 수[개] : ");     if(scanf("%d",&Nm)!=1) return 1;
  printf("감속비 : ");              if(scanf("%lf",&G)!=1) return 1; 
  printf("구동효율 [0~1] : ");       if(scanf("%lf",&n)!=1) return 1;
  printf("바퀴 반지름 [m] : ");       if(scanf("%lf",&r)!=1) return 1;
  printf("구름계수 [0.015~0.03]: "); if(scanf("%lf",&c)!=1) return 1;
  printf("안전계수 [>=1] : ");       if(scanf("%lf",&SF)!=1) return 1;

  // 입력값 검증
  if (Kg<=0 || Tm<=0 || G<=0 || n<=0 || n>1 || r<=0 || c<0 || SF<1)
  {printf("입력값 범위를 확인하세요.\n");
  return 1;
  }

  // 계산
  const double Ttot = Nm * Tm * G * n; //총 구동 토크
  const double Favail = Ttot / r; // 가용 견인력
  const double mg = Kg*9.8; //중량
  
  //최대 등판각 안전계수 포함 
  double sin_the = (Favail/SF-c*mg)/mg;
  if (sin_the < 0.0) sin_the = 0.0;
  if (sin_the > 1.0) sin_the = 1.0;

  double the_R = asin(sin_the); //sin_the 라디안 값으로 변경 
  double the_D = the_R * 180.0/M_PI; //라디안값을 다시 60분법(Degree)으로 변환 (각도로 볼수있게)
  double the_G = tan(the_R) * 100.0; //라디안 값에 

  //결과 출력
  printf("\n[결과]\n");
  printf("총 구동 토크 T_tot : %.2f Nm\n",Ttot);
  printf("가용 견인력 F_avail : %.2f N\n",Favail);
  printf("등판 가능 최대각 : %.2f deg\n",the_D);
  printf("등판율(grade) : %.1f %%\n",the_G);
  printf("(가정: 마찰한계 무시, 구름저항 c포함, 안전계수 SF 적용)\n");

  return 0;
}
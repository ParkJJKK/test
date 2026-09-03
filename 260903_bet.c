#include <stdio.h> 

int main (void)
{
  double load;
  double vel;
  double R;
  double V;
  double C;
  double ETA;
 
  
  //배터리 사양 및 환경 정보 입력
 
  printf("평균 전류 I_load [A](부하측): "); if (scanf("%lf",&load)!=1) return 1;
  printf("평균속도 vel [km/h]:");         if(scanf("%lf",&vel)!=1) return 1;
  printf("예비율 R [20% = 0.2]:");       if(scanf("%lf",&R)!=1)return 1;
  
  printf("공칭전압 V [V]:");             if(scanf("%lf",&V)!=1)return 1;
  printf("용량 C [Ah]:");               if(scanf("%lf",&C)!=1)return 1;
  printf("시스템효율 eta [90% = 0.9]:");             if(scanf("%lf",&ETA)!=1)return 1;
  
  //입력범위 검증
  if(V<=0 || C<=0 || load<=0 || vel<0 || R<0 || R>=1 || ETA<=0 || ETA>100)
 {printf("입력값 볌위를 확인하세요\n");
  
  return 1;
  }
  //소비전력
  const double P = (V * load) / ETA;

  //사용 가능 에너지 
  const double E_usable = V * C * ETA * (1.0-R);

  //런타임 게산 
  const double t_h = E_usable / P;
  const double t_min = t_h * 60.0;

  //주행거리 계산
  const double d_km = vel * t_h;

  //출력결과
  printf("사용 가능 에너지 E_usable : %.2f Wh\n", E_usable);
  printf("런 타임 t               : %.2f h(%.1f min)\n", t_h, t_min);
  printf("주행거리 d              : %.2f km\n", d_km);

  return 0;
}
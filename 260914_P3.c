#include <stdio.h> 
#include <string.h>

typedef struct{
    char ip[150];
    int count;
}IPcount;

void clean_ip(char *raw_ip, char *clean_ip);


int main(void) 
{
    FILE *file = fopen("fast.log","r");
    if(file==NULL){
        printf("파일을 찾을수없습니다.");
        return 1;
    }
    char line[1100]; //로그파일의 한줄을 읽어올 버퍼 메모리 
    int total_pings=0; //전체 Ping발생 횟수 카운터
    IPcount ip_list[100]={0}; //IP와 횟수를 저장할 구조체(0으초 초기화) 
    int ip_list_count=0; // 저장된 서로 다른 ip의 개수 
    int hour_count[24]={0}; // 각시간대별로 요청 횟수(0으로 초기화)
    int hour;
    char *dash_ptr;
    char h1;
    char h2;
    char *src_start;
    char *arrow;
    char raw_ip[130]={0}; // 원본 IP 저장 버퍼
    char cleaned_ip[130]={0}; // 함수로 정리된 IP 저장 버퍼
    int found = 0; // 이미 목록에 존재하는 IP인지 확인용 플래그
    int i;
    int j;
    int max_hour_count = 0;

    while(fgets(line,sizeof(line),file))
    {
        if(strlen(line)<10) continue;
        total_pings++;
        dash_ptr=strchr(line,'-'); //'-'문자 위치 탐색
        if (dash_ptr !=NULL){
            h1 = dash_ptr[1]; //'-'바로 뒤 첫번째 시간문자 
            h2 = dash_ptr[2]; //'-'바로 뒤 두번째 시간문자 

            if(h1>='0'&&h1<='9'&&h2>='0'&&h2<='9') //두문자 모두 숫자인지 확인
            {
                hour=(h1-'0')*10+(h2-'0');  //문자 '0'~'9'를 정수로 계산
                if(hour>=0&&hour<24){ //해당 시간범위 내인 경우 
                    hour_count[hour]++; // 해당 시간대 카운터 +1
                }
            }

        }

        src_start = strstr(line,"}"); //"} " 위치 탐색
        arrow = strstr(line,"->");   // " -> " 위치 탐색
        if(src_start && arrow)  // 두 구분자를 모두 찾은 경우
        {
            src_start +=2;      // "} "의 문자 길이(2)만큼 포인터를 이동시켜 IP 시작점으로 지정
            strncpy(raw_ip, src_start,arrow-src_start); // "} "와 " -> " 사이의 문자열만 복사
            clean_ip(raw_ip,cleaned_ip);  // 포트 번호 제거 함수 호출

            for(i=0;i<ip_list_count;i++)
            {
                if(strcmp(ip_list[i].ip,cleaned_ip)==0){ // 동일한 IP가 이미 있다면
                    ip_list[i].count++;                  // 해당 IP의 카운트만 +1 증가
                    found=1;                             // 찾았음 표시
                    break;
                }
            }
            if(!found&&ip_list_count<100){                     // 목록에 없는 새로운 IP라면
                strcpy(ip_list[ip_list_count].ip,cleaned_ip); // IP 문자열 저장
                ip_list[ip_list_count].count=1;               // 횟수를 1로 설정
                ip_list_count++;                               // 저장된 IP 개수 목록 +1
            }

        }
        
    }
    fclose(file);

    // IP 등장 횟수를 기준으로 내림차순(큰 값 -> 작은 값) 정렬

    for(i=0;i<ip_list_count-1;i++)
    {
        for(j=0;j<ip_list_count-i-1;j++){
            if(ip_list[j].count<ip_list[j+1].count){ // 뒤의 카운트가 더 크면 위치 교환
                IPcount temp = ip_list[j];
                ip_list[j]=ip_list[j+1];
                ip_list[j+1]=temp;
            }
        }
    }

    // 0~23시 중 가장 많은 요청 건수(최대값) 찾기

    for(i=0;i<24;i++){
        if(hour_count[i]>max_hour_count){
            max_hour_count=hour_count[i]; // 최대 횟수 갱신
        }
    }

    //출력

    printf("ping은 몇회?\n");
    printf("->%d회\n\n",total_pings);
    
    printf("가장많이 보낸 주소 탑3\n");
    for(i=0;i<ip_list_count && i<3;i++){
        printf("%d. %s (%d회)\n",i+1,ip_list[i].ip,ip_list[i].count);
    }
    printf("\n");

    int first= 1;
    printf("가장 믾이 요청된 시간대\n");
    printf("->");
    for(i=0;i<24;i++){
        if(hour_count[i]==max_hour_count){
            if(!first) printf(",");
            printf("%02d시",i);
            first = 0;
        }
    }
    printf("각 %d회 발생\n",max_hour_count);
    
 return 0;
}

void clean_ip(char *raw_ip, char *clean_ip) {
    int len = strlen(raw_ip); // 입력된 원본 IP 문자열의 길이를 구함
    int last_colon = -1;      //마지막 콜론(:)의 위치를 저장할 변수 (초기값 -1)
    int i;
    int is_port;
    int p;

    //문자열 뒤에서부터 거꾸로 탐색하여 마지막 콜론의 위치를 찾음

    for (i = len - 1; i >= 0; i--) {
        if (raw_ip[i] == ':') {
            last_colon = i; //콜론을 찾으면 위치를 저장 
            break;          //반복문 종료
        }
    }

    if (last_colon != -1) {  //콜론을 찾은 경우
        is_port = 1;         //콜론 뒤의 문자들이 숫자인지(포트 번호인지) 판별 플래그
         //마지막 콜론바로 다음 문자부터 끝까지 검사
        for (p = last_colon + 1; raw_ip[p] != '\0'; p++) {
            if (raw_ip[p] < '0' || raw_ip[p] > '9') { //숫자가 아닌 문자가 섞여있다면
                is_port = 0;                          //포트 번호가 아님(IPv6 주소 자체의 콜론)
                break;
            }
        }
        if (is_port) {   //콜론 뒤가 순수 순자인 경우(포트 번호)
            strncpy(clean_ip, raw_ip, last_colon); //콜론 이전까지 IP만 복사
            clean_ip[last_colon] = '\0';           //문자끝에 널 문자를 넣어 자름
            return;
        }
    }
    strcpy(clean_ip, raw_ip);    //포트 번호가 없으면 원본 그대로 복사
}

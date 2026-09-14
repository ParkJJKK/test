// IP 주소와 해당 IP의 등장 횟수를 저장하기 위한 구조체 정의
typedef struct {
    char ip[130];  // IP 주소를 저장할 문자 배열 (IPv6 및 포트 제거 전 포맷 고려)
    int count;     // 해당 IP가 등장한 횟수
} IPCount;

// 함수 프로토타입 선언: raw_ip에서 포트 번호를 제거하고 pure IP만 clean_ip에 저장하는 함수
void clean_ip(char *raw_ip, char *clean_ip);

int main() {
    // 분석할 로그 파일인 "fast.log"를 읽기 전용("r") 모드로 열기
    FILE *file = fopen("fast.log", "r");
    if (!file) { // 파일 열기에 실패했을 경우 (NULL 반환)
        printf("파일을 열 수 없습니다.\n");
        return 1; // 오류 코드 1을 반환하며 프로그램 종료
    }

    char line[1100];        // 로그 파일의 한 줄을 읽어올 버퍼 메모리
    int total_pings = 0;    // 전체 핑(로그 행) 개수를 카운트할 변수
    
    IPCount ip_list[100] = {0}; // 고유 IP 목록과 횟수를 저장할 배열 (최대 100개, 0으로 초기화)
    int ip_list_count = 0;      // 현재까지 등록된 고유 IP의 개수
    
    int hourly_count[24] = {0}; // 0시부터 23시까지 시간대별 요청 수를 저장할 배열 (0으로 초기화)

    // 파일에서 한 줄씩 읽어와 line에 저장 (파일 끝까지 반복)
    while (fgets(line, sizeof(line), file)) {
        // 읽어온 줄의 길이가 10자 미만이면 유효하지 않은 로그로 간주하고 건너뜀
        if (strlen(line) < 10) continue;

        total_pings++; // 유효한 로그 라인 수 1 증가

        // 1. 시간대 추출 단계
        // 라인에서 첫 번째 '-' 문자의 위치를 찾음 (예: "09/14/2026-15:30:00...")
        char *dash_ptr = strchr(line, '-');
        if (dash_ptr != NULL) {
            // '-' 바로 뒤의 두 글자를 시(hour) 문자로 읽음
            char h1 = dash_ptr[1];
            char h2 = dash_ptr[2];
            
            // 두 글자가 모두 0~9 사이의 숫자 문자인지 검증
            if (h1 >= '0' && h1 <= '9' && h2 >= '0' && h2 <= '9') {
                // 문자를 정수로 변환하여 hour 값 계산 (예: '1'과 '5' -> 15)
                int hour = (h1 - '0') * 10 + (h2 - '0');
                // hour가 유효한 시간 범위(0~23)에 있는지 확인 후 카운트 증가
                if (hour >= 0 && hour < 24) {
                    hourly_count[hour]++;
                }
            }
        }

        // 2. 출발지 IP 추출 단계
        // Snort/Suricata 로그 형식 특성상 구분자인 "} "와 " -> "의 위치를 찾음
        char *src_start = strstr(line, "} ");
        char *arrow = strstr(line, " -> ");
        if (src_start && arrow) {
            src_start += 2; // "} " 문자열(2바이트) 바로 다음으로 포인터 이동 (출발지 IP 시작 지점)
            
            char raw_ip[130] = {0};     // 포트 번호가 포함되어 있을 수 있는 원본 IP 저장 버퍼
            char cleaned_ip[130] = {0}; // 포트 번호가 제거된 순수 IP 저장 버퍼
            
            // 시작 지점부터 " -> " 이전까지의 길이 계산
            int ip_len = (int)(arrow - src_start);
            // IP 길이가 버퍼 범위를 벗어나지 않는 유효한 길이인지 확인
            if (ip_len > 0 && ip_len < 130) {
                strncpy(raw_ip, src_start, ip_len); // 원본 IP 부분만 raw_ip에 복사
                raw_ip[ip_len] = '\0';               // 문자열 끝에 널 문자를 붙여 올바른 문자열로 만듦
                
                clean_ip(raw_ip, cleaned_ip); // 포트 번호를 정제하는 함수 호출

                // 추출한 IP가 기존 ip_list 배열에 이미 있는지 검사
                int found = 0;
                for (int i = 0; i < ip_list_count; i++) {
                    if (strcmp(ip_list[i].ip, cleaned_ip) == 0) { // 동일한 IP를 발견하면
                        ip_list[i].count++; // 카운트 1 증가
                        found = 1;          // 찾았음을 표시
                        break;              // 반복문 탈출
                    }
                }
                // 목록에 없는 새로운 IP이고, 배열 용량(100개)이 남아있다면 추가
                if (!found && ip_list_count < 100) {
                    strcpy(ip_list[ip_list_count].ip, cleaned_ip); // IP 문자열 복사
                    ip_list[ip_list_count].count = 1;              // 카운트 1로 초기화
                    ip_list_count++;                               // 고유 IP 개수 1 증가
                }
            }
        }
    }
    fclose(file); // 읽기 완료 후 파일 닫기

    // 3. IP 내림차순 정렬 (요청 횟수 기준, 버블 정렬 알고리즘)
    for (int i = 0; i < ip_list_count - 1; i++) {
        for (int j = 0; j < ip_list_count - i - 1; j++) {
            // 앞의 요소 카운트가 뒤의 요소 카운트보다 작으면 위치 교환 (내림차순)
            if (ip_list[j].count < ip_list[j + 1].count) {
                IPCount temp = ip_list[j];
                ip_list[j] = ip_list[j + 1];
                ip_list[j + 1] = temp;
            }
        }
    }

    // 4. 최다 요청 시간대 탐색
    int max_hour_count = 0; // 가장 많은 요청 건수를 찾기 위한 변수
    for (int i = 0; i < 24; i++) {
        if (hourly_count[i] > max_hour_count) {
            max_hour_count = hourly_count[i]; // 최댓값 갱신
        }
    }

    // 5. 최종 결과 출력
    printf("--- [로그 분석 결과] ---\n");
    printf("Ping은 몇회?\n");
    printf("-> %d회\n\n", total_pings); // 총 분석된 핑 횟수 출력

    printf("가장많이 보낸 주소 탑3는?\n");
    if (ip_list_count == 0) {
        printf("출력할 IP가 없습니다.\n");
    } else {
        // 정렬된 IP 목록 중 상위 최대 3개까지 출력
        for (int i = 0; i < ip_list_count && i < 3; i++) {
            printf("%d. %s (%d회)\n", i + 1, ip_list[i].ip, ip_list[i].count);
        }
    }
    printf("\n");

    printf("가장많이 요청된 시간대?\n");
    printf("-> ");
    int first = 1; // 쉼표(,) 출력을 조절하기 위한 플래그 변수
    for (int i = 0; i < 24; i++) {
        // 최다 요청 수를 기록한 시간대(동률 포함)를 찾아서 출력
        if (hourly_count[i] == max_hour_count) {
            if (!first) printf(", "); // 첫 번째 출력이 아니면 쉼표 추가
            printf("%02d시", i);       // 시간대를 두 자리 정수로 출력 (예: 09시)
            first = 0;
        }
    }
    printf(" (각 %d회 발생)\n", max_hour_count);

    return 0; // 프로그램 정상 종료
}

// IP 문자열 뒤에 붙은 포트 번호(예: :80, :8080)를 제거하는 함수
void clean_ip(char *raw_ip, char *clean_ip) {
    int len = (int)strlen(raw_ip);
    
    // raw_ip 문자열의 맨 뒤에서부터 역순으로 탐색하여 마지막 콜론(':')의 위치를 찾음
    int last_colon = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (raw_ip[i] == ':') {
            last_colon = i;
            break;
        }
    }

    // 콜론이 존재하는 경우 검사
    if (last_colon != -1) {
        int is_port = 1;       // 콜론 뒷부분이 포트 번호인지 여부 (기본값 1)
        int port_digits = 0;   // 포트 자릿수 카운트

        // 콜론 바로 다음 문자부터 끝까지 읽으며 순수 숫자인지 확인
        for (int p = last_colon + 1; raw_ip[p] != '\0'; p++) {
            if (raw_ip[p] < '0' || raw_ip[p] > '9') {
                is_port = 0; // 숫자가 아닌 문자가 섞여있으면 포트가 아님
                break;
            }
            port_digits++;
        }
        
        // 포트 번호 조건 검사: 1~5자리의 숫자이며
        if (is_port && port_digits > 0 && port_digits <= 5) {
            // IPv6의 '::' 표현식(콜론 바로 앞도 콜론인 경우)이 아닐 때만 포트로 간주
            if (last_colon > 0 && raw_ip[last_colon - 1] != ':') {
                // 콜론 이전까지(IP 주소 본체)만 clean_ip에 복사
                strncpy(clean_ip, raw_ip, last_colon);
                clean_ip[last_colon] = '\0'; // 문자열 끝 처리
                return;
            }
        }
    }
    // 포트가 없거나 포트 제거 조건에 해당하지 않으면 원본 그대로 복사
    strcpy(clean_ip, raw_ip);
}
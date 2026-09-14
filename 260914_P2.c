#include <stdio.h> 
#include <string.h>

int main(void) 
{
    FILE *fp = fopen("log.txt","r");

    if(fp==NULL){
        printf("파일을 찾을수없습니다.");
        return 1;
    }

    char line[300];
    int error = 0;
    int warning = 0;
    char *msg;

    printf("ERROR 목록\n");
    printf("========================================\n");

    while(fgets(line,sizeof(line),fp)!=NULL){
        if(strstr(line,"[ERROR]")!=NULL){
            error++;
            
            msg=strstr(line,"[ERROR]");
            msg+=8;

            msg[strcspn(msg,"\r\n")] = 0;
            printf(" %d. %s\n",error,msg);
        }
        else if (strstr(line,"[WARNING]")!=NULL){
            warning++;
        }
    }
    fclose(fp);

    printf("-ERROR 발생 횟수 :%d회\n",error);
    printf("-WARNING 발생 횟수 :%d회\n",warning);
    printf("========================================\n");

    
 return 0;
}



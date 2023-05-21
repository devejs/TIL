# Stream

## C에서의 입출력
입/출력(Input/Output); 사용자가 키보드를 이용해 문자열을 입력하는 것뿐 아니라, 장치를 파일로서 읽어오는 경우나 데이터 파일을 읽어오는 경우 등등 다양하게 사용됨   
대부분의 파일 입출력 함수들은 `<stdio.h>` 헤더에서 제공
- 파일 접근/입출력 fopen/fclose/fread/fwrite
- 표준 입출력 printf/scanf


### 예제
```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char buffer[5] = {0}; 
    int i;
    FILE *fp = fopen("some_file", "rb");

    if (fp == NULL) {
        perror("fail to open file. \"some_file\"");
        return EXIT_FAILURE;
    }

    for (i = 0; i < 5; i++) {
        int rc = getc(fp);
        if (rc == EOF) {
            fputs("error occurred while reading.\n", stderr);
            return EXIT_FAILURE;
        }
        buffer[i] = rc;
    }

    fclose(fp);

    printf("%x %x %x %x %x\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

    return EXIT_SUCCESS;
}
```

## Stream이란?
어떤 정보(데이터)의 집합으로, 모든 입력과 출력에 있어 Byte 들의 흐름(stream) 개념을 사용함   
```
WHY?
유닉스 이전에는 명시적으로 입력장치/출력장치와 연결해줘야 했고, 이 과정에서 입출력 처리 방식이 달라짐. (ex. 펀치 카드 리더기, )
```
- 장치 독립적: 입출력 장치와 관계 없이 바이트 단위로 입출력되므로 프로그램 작성시 장치를 고려할 필요 없음
- 버퍼 사용: 버퍼를 통해 데이터(여러 바이트들)를 한번에 CPU로 전달하거나 받을 수 있음
- 표준 입출력 스트림(Standard Input Ouput Stream): 프로그램 실행 시에 자동으로 생성되는 스트림
    - `stdin`: Standard Input, 0
    - `stdout`: Standard Output, 1
    - `stderr`: Standard Error, 2


### C++에서의 입출력
- iostream
    - `operator>>`
    - `cin`
- ostream
- streambuf
- fstream: 파일 스트림; ifstream과 ofstream 포함
    - ifstream
    - ofstream



### Reference
- [표준 스트림](https://ko.wikipedia.org/wiki/%ED%91%9C%EC%A4%80_%EC%8A%A4%ED%8A%B8%EB%A6%BC)



======================================================
###### 230521 TIL
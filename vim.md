# VIM

## How to use VIM
### Why?
- 회사 개발 서버가 리눅스라 vim을 쓸 일이 많은데 매번 마우스를 사용해야 하는 일이 빈번하게 발생하면서 불편함
- (아직은 없었지만) 가끔 내가 꾸려 놓은 개발 환경이 아닌 환경에서 디버깅해야 할 때, 리눅스에서 바로 쓸 수 있는 vi 에디터 활용 능력 함양
- ~~간지남~~

### 이미 알고 있던 것
1. 커서 이동은 h,j,k,l (순서대로 왼,아래,위,오)
2. 명령 모드는 ESC / 편집 모드는 i (다른 것도 있지만 i가 제일 익숙 편안) / 라인모드 : (대체로 :지 다른 명령어도 있음)

    2-1. 편집 모드
    - i: insert, 커서 위치에 삽입
    - a: append, 커서 다음 위치에 추가
    - o: open, 커서 다음 줄 새로 생성해 추가
    - x: 한 글자 삭제
    - dd: 한 줄 삭제

    2-2. 명령 모드
    - 편집 모드, 라인 모드로 이동 가능
    - 모든 모드에서 ESC로 컴백

    2-3. 라인 모드
    - `:w`: 저장
    - `:q`: quit, 종료
    - `:wq`: 저장 후 종료
    - `:q! or :wq!`: !는 강제로 실행, wq! 의 경우 저장하고 강제 종료
    - `/`: 커서 뒷 방향으로 문자열 찾기
    - `?`: 커서 전 방향으로 문자열 찾기     // 지금까지는 써본 적 없지만 추후 매크로 기능에서 쓸 수 있음
        - n: (정방향) 다음 문자열 이동
        - N: (역방향) 이전 문자열 이동

3. 복사/붙여넣기
    - yy: yank, 한 줄 복사
    - p: put, 붙여넣기
    - `{count}`yy/p: 원하는 count 수만큼 복사/붙여넣기 가능

4. 취소/재실행
    - `u`: undo, 실행 취소
    - `Ctrl+r` : redo, 
    
    근데 되돌리는 기준이 뭔지 잘 모르겠음


### 필요한데 맨날 까먹는 기능
1. 문자열 블록 -> 삭제, 복사, 대체 등등
    - 비주얼 모드
        - `v`: 현재 커서; 현재 커서 위치에서 h,j,k,l,web 등의 커서 이동으로 블럭 설정 가능; 주로 h,l,w,b를 쓰지 않을까 싶음
        - `V`: 라인 단위; 현재 커서 위치에서 줄 단위로 블럭 설정 가능
        - `Ctrl+V`: 블럭(열) 단위; 현재 커서 위치에서 아랫줄로 내려가 (x,y:y+1) 의 좌변을 만듦 -> h,l로 블럭을 늘릴 수 있다! 
    - 삭제
        - d: 기본 삭제 키
            - `dd`: 한 줄 삭제
            - `dw`: 현재 커서 위치에서부터 한 단어 삭제(현재 위치부터) =><주의> w로 커서가 이동하는 위치까지 삭제됨
                ```
                ex) `inclusion of the ...` 
                `u` 위치에서 dw 하면
                1. w -> o로 이동
                2. 현재 위치부터 삭제
                -> `inclof the ...`
                ```
            - `de`: e로 커서가 이동하는 위치까지 삭제됨; 즉, 위의 예시에서 `n` 위치로 이동하게 되므로 `incl of the ...`가 됨
            - `bde`: 현재 단어 앞으로 이동 + 삭제 + 단어 끝까지
            - 비주얼 모드에서는 선택된 블록 `d`로 바로 삭제됨
2. h,j,k,l 을 제외한 커서 이동 (라인 앞/뒤, 단어 이동)
    - w: 다음 단어; 커서는 단어 맨 앞
    - e: 단어 끝; 현재 단어의 끝으로 커서 이동
    - b: 이전 단어; 커서는 단어 맨 앞

        // 웹으로 외우기   
        // 소문자는 기호 제외, 대문자는 기호 포함
    - ^: 라인 처음
    - $: 라인 끝
    - `Ctrl+U`: 반 화면 위 이동
    - `Ctrl+D`: 반 화면 아래 이동
    - `gg`: 문서 처음 이동
    - `G`: 문서 끝 이동
3. 문자열 치환
    - `%s/old_string/new_string`: old_string -> new_string 치환
        - 옵션



### 보통은 필요하지 않지만 가끔 필요할 기능
(내 환경이 아니라서 .vimrc 세팅이 안 되있을 경우?)
```
:set number     // 라인 수 표시
:set nonu       // 라인 수 제거

```






======================================================
###### 230515 TIL
###### 230518 TIL



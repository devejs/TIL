# VIM

## How to use VIM
### Why?
- 회사 개발 서버가 리눅스라 vim을 쓸 일이 많은데 매번 마우스를 사용해야 하는 일이 빈번하게 발생하면서 불편함
- (아직은 없었지만) 가끔 내가 꾸려 놓은 개발 환경이 아닌 환경에서 디버깅해야 할 때, 리눅스에서 바로 쓸 수 있는 vi 에디터 활용 능력 함양
- ~~간지남~~

### 이미 알고 있던 것
1. 커서 이동은 h,j,k,l (순서대로 왼,아래,위,오)
    - 근데 특이한게 편집 모드일 때랑 명령 모드(표준 모드)일 때랑 커서 기준이 조금 다름
    - 편집 모드: 까만 커서 앞으로 입력됨
    - 표준 모드: 까만 커서 뒤로 입력됨 (p 같은 것)
    - 표준 모드 -> 편집 모드로 변경할 때는 커서 위치가 안 바뀜<br>
    편집 모드 -> 표준 모드로 변경할 때는 커서가 하나 앞으로 변경됨
2. 명령 모드는 ESC / 편집 모드는 i (다른 것도 있지만 i가 제일 익숙 편안) / 라인모드 : (대체로 :지 다른 명령어도 있음)

    2-1. 편집 모드
    - i: insert, 커서 위치에 삽입
    - a: append, 커서 다음 위치에 추가
    - o: open, 커서 다음 줄 새로 생성해 추가
    - x: 한 글자 삭제
    - dd: 한 줄 삭제

    2-2. 명령 모드(표준 모드)
    - 편집 모드, 라인 모드로 이동 가능
    - 모든 모드에서 ESC로 컴백

    2-3. 라인 모드(명령 라인 모드)
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
    - 치환
        - r: 한 글자로 대체(replace)
        - c: 삭제 후 변경 (change)
        - **`>`: 라인 앞에 탭 삽입**
        - **`<`: 라인 앞에 탭 삭제**
    - 찾기 (완전 유용!!!!!)
        - 단어에 커서 두고 `*`: `/` 로 찾기 할 필요 없이 해당 단어 찾아줌. 다음 찾은 문자로 커서 이동됨 (대소문자 구분)
        - 단어에 커서 두고 `#`: `?` 와 동일; * 와 방향 반대
        - 처음에는 문자열 블록 해서 찾아야되는 줄 알았는데 그럴 필요 없음; 그냥 단어 중간에 커서만 둬도 해당 단어 찾아줌. 문자열 블록 설정시 그 다음 단어까지 선택됨
    - 특정 라인 주석(중요!!!!1)
        - `:norm i<원하는문자>`
            - 예를 들어 C/C++ 에서는 `//` 입력, 쉘 스크립트에서는 `#` 입력
            - norm: normal mode; normal mode 에서 뒤에 오는 command 를 실행하는 역할 (normal mode: 실행시 기본 모드; ESC)
           - i: insert
                - 주의: i이후로 space 는 띄어쓰기로 입력됨
        - `:norm <count>x`
            - count에는 지우고 싶은 문자 개수; `//`일 때는 2, `#`일 때는 1 하면 됨

2. h,j,k,l 을 제외한 커서 이동 (라인 앞/뒤, 단어 이동)
    - motion: A command that moves the cursor
        - w: 다음 단어; 커서는 단어 맨 앞
        - e: 단어 끝; 현재 단어의 끝으로 커서 이동
        - b: 이전 단어; 커서는 단어 맨 앞

            // 웹으로 외우기   
            // 소문자는 기호 제외, 대문자는 기호 포함
        - ^: 라인 처음 (0도 동일)
        - $: 라인 끝
        - `Ctrl+U`: 반 화면 위 이동
        - `Ctrl+D`: 반 화면 아래 이동
        - `gg`: 문서 처음 이동
        - `G`: 문서 끝 이동
        - `:{line}`: 특정 라인으로 이동
        - `z.`: 현재 행을 화면의 중앙으로 이동
        - `ctrl+d`: 반 화면 아래 (page down)
        - `ctrl+u`: 반 화면 위 (page up)
3. 문자열 치환
    - `%s/old_string/new_string`: old_string -> new_string 치환
        - 옵션

4. vim 임시로 내리기<br>
    -> 파일 저장은 하고 싶지 않지만 터미널을 확인해야 할 때
    1. `ctrl+z`-`fg`: 현재 작성중인 vim 파일을 백그라운드 프로세스로 내린 후 `fg` 커맨드로 다시 포그라운드로 올리기
        - 터미널에서 뭔가 추가 작업이 필요할 때 유용
        - 작업하던 파일은 vim 프로세스 내부 버퍼에 저장됨
    2. `:sh`-`ctrl+d`: 1과 동일한 동작
    3. `:!`: 터미널만 확인 후 타이핑시 vim 파일로 돌아옴
    4. `:!{cmd}`: vim 건드리지 않고 쉘 명령어 실행

5. 터미널 작업 결과 vim 에 붙여넣기
    - `:read !~cmd~`
        - 여기서 cmd는 결과를 가져오고 싶은 터미널 명령어
            - ex. ls, cat some_file.md
        - 그럼 현재 커서에 명령어 결과 붙여넣기
        - `read` 말고 `r` 로만 해도 가능

6. 화면 분할
    - 윈도우 명령 `ctrl+w`
        - n: new window(위, 가로 분할)
        - v: new window(옆, 세로 분할)
    - 화면 이동: 분할 상태에서 `ctrl+w+{hjkl}`; 분할된 윈도우 방향키
    - 화면 크기 조절
        - `ctrl+w` + `-`: 화면 크기 축소
        - `ctrl+w` + `+`: 화면 크기 확대
        - `ctrl+w` + `=`: 화면 크기 동일

### 내용 정리
1. 모드
    - 표준 모드(Normal Mode)
    - 편집 모드(Insert Mode)
        - `i`: 커서 위치에 입력
            - **커서 위치에 입력한다: 커서(네모) 앞에 입력한다**
        - `a`: 커서의 다음 칸에 입력
        - `o`: 커서의 다음 행에 입력
        - **`cc`: 커서 행을 지우고 입력**
        - `A`: 커서 행의 맨 뒤에서부터 입력
        - `I`: 커서 행의 맨 앞에서부터 입력
        - `O`: 커서의 이전 행에 입력
    - 명령 모드(Command Mode)
        - 표준 모드에서 특정 커맨드 입력해서 바로 접근 가능
        - `:`: 커맨드 모드 진입
            - `:![shell_cmd]`: vim 을 잠시 빠져나갔다가 명령이 수행된 후 vim 으로 돌아옴
            - `:r ![shell_cmd]`: 명령이 수행된 결과가 현재 커서의 위치에 붙여넣어짐
                - `:r [파일명]`: 현재 커서의 위치에 파일의 내용을 붙여넣음; 동일한 원리
            - `:!bash`: 새로운 셸이 열리면서 vim 을 빠져나감
                - `exit` 로 셸을 종료하면 vim 으로 돌아옴
        - `%`: 전체 파일 라인들에 대해 접근
        - `s`: 치환
            - 기본 포맷: `:<범위>/<매칭 문자열>/<치환 문자열>/<행 범위>`
            - 복잡한 문자열은 정규표현식 사용: `:<범위>/<패턴>/<매칭 문자열>/<치환 문자열>/<행 범위>`
        - `/`: 찾기
            - `n`: 다음 방향 이동
            - `N`: 이전 방향 이동
        - `?`: 역방향 찾기
        ```
        //치환 예시 
        :%s/foo/bar/g
        전체 문서에서 모든 old 를 new 로 치환
        // :<범위>/<매칭 문자열>/<치환 문자열>/<행 범위>
        // 범위: 매칭 문자를 치환할 문서상 범위 -- %s 는 문서 전체
        // 매칭 문자열: /foo 는 변환하기 위해 찾을 문자열
        // 치환 문자열: /bar 는 변환할 문자열
        // 행 범위: 치환될 행의 범위; /g는 행 전체 치환 -> 해당되는 범위의 모든 문자열을 치환
        // g 가 없으면 한 행에서 여러 매칭 문자열이 있더라도 한 번만 치환됨(모든 행에 대해 동작) -> 주의: 범위와 행 범위 구별 필요
        // 범위: 어떤 행들에 대해서 동작할 것인지
        // 행 범위: 선택된 하나의 행 내부에서 어떻게 동작할 것인지

        //다른 예시
        :s/old/new/g
        전체 문서에서 제일 처음 매칭되는 라인의 old -> new 치환
        :2,4s/old/new/g
        2행~4행 사이에 매칭되는 문자열 치환
        :-1,+3s/old/new/g
        현재 커서에서 위로 1행, 아래로 3행의 범위에 매칭되는 문자열 치환
        :%s/old/new/
        전체 문서에서 매칭되는 라인의 문자열 1개(첫번째)만 치환
        :%s/old/new/gc
        전체 문서에서 매칭되는 문자열에 대해 치환할 것인지 사용자에게 물음
        ```
    - 비주얼 모드(Visual Mode)
        - 특정 문자열 선택해서 작업 가능;
            - `v`: 현재 커서 위치에서 블록 설정
            - `Shift+v(V)`: 현재 커서가 있는 라인 블록 설정
            - `Ctrl+v`: 커서 이동해서 상하좌우 블록 설정
    - 치환 모드(Replace Mode)
        - 표준 모드에서 `R` 로 접근
        - 윈도우에서 insert 누른 상태로, 기존 텍스트를 삭제하고 그 위를 덮어씌우는 모드
2. 이동
    - 기본 이동 `hjkl`: 좌/하/상/우
    - 단어 단위 이동
        - `w`: 단어의 첫 글자
        - `b`: 이전 단어의 첫 글자
        - `e`: 단어의 마지막 글자
    - 행 내 이동
        - `^/0`: 행의 첫번째 글자
        - `$`: 행의 마지막 글자
    - 기타
        - `+`: 다음 행의 첫 글자로 이동
        - `-`: 이전 행의 첫 글자로 이동
        - `(`, `)`: 문장 이동 (문장의 끝: 마침표(.)가 나오는 지점)
        - `{`, `}`: 문단 이동 (문단의 끝: 공백인 행)
        - `gg`: 문서의 맨 처음으로 이동
        - `G`: 문서의 맨 마지막으로 이동
        - `:{line}`: 특정 라인으로 이동
3. 편집
    - 삭제: `d` + `커서위치` (커서 위치: w,e,$ 등 적용 가능)
        - `x`: 현재 커서 위치 삭제로 단축해서 사용 가능
        - `dd`: 현재 커서 위치 행 삭제
    - 복사/붙이기
        - 복사: `y` + `커서위치`
            - `yy`: 현재 커서 위치 행 복사
        - 붙이기: `p`
            - 붙여넣을 때 특정 레지스터를 선택할 수 있음
        - `.`: 바로 이전에 했던 작업 반복
    - 잘라내기

    - 블록 지정
        - 기본 기능 `d`, `y`, `c` 동작
        - **`>`: 라인 앞에 탭 삽입**
        - **`<`: 라인 앞에 탭 삭제**
        - 대소문자
            - `~`: 대소문자 전환
            - `U`: 대문자로 전환
            - `u`: 소문자로 전환
    - `J`: 다음 행을 커서 행으로 붙임
    - 실행 취소: `u`, `ctrl+r`
    - 
4. 레지스터
- vim 에서 기본 제공해주는 문자열 메모리
    - 레지스터: `:reg` 로 확인 가능
        - `:reg` 를 실행한 결과 출력된 리스트에서 `^J` 는 줄바꿈, `^I` 는 탭을 의미
        - `""`-`"0`-`"1`-...-`"9`-`"k`-`"-`-`"*`-`".`-`":`-`"%`-`"/` 순서 (Mac 기준; 버전마다 다를 수 있음)
        - 지워지는 내용이 `""` 에 들어가고,
            - `dd`로 실행했을 경우 `"1` 에 입력되며 기존 1레지스터는 2로 밀림 (큐)
            - `de` 등으로 행 일부만 삭제했을 경우 1레지스터에는 입력되지 않음 (Mac 동작, 다른 버전에서 확인 필요)
        - 복사하는 내용은 `""`, `"0` 에 동시에 들어감
        - `".`: 최근까지 타이핑 한 내용 저장
        - `"%`: 현재 편집하는 파일명 저장
        - `"/`: 가장 최근에 검색한 문자열 저장
    - 네임 레지스터: 이전의 17개 레지스터 외에 a-z까지 26개의 레지스터를 추가 지원
        - 반복되는 문자열을 저장해 쓰기에 편리
            - 표준 모드에서 `"a3yy` 식으로 저장 가능
                - `"a`: a 레지스터에 저장해라
                - `3yy`: 현재 커서 위치에서 세 행을 복사해 저장
            - 저장된 내용은 `"ap`로 붙여넣기
                - `"a`: a레지스터에서 가져와서
                - `p`: 붙여넣기

5. 매크로
- 사용자의 키 입력을 기록해서 반복해주는 기능
    - 키 입력을 레지스터에 저장해 사용하는 방법
        - `q[네임 레지스터]`: 매크로를 등록할 레지스터 지정 (ex. qb)
            - 입력시 하단에 "기록 중" 글자 출력
            - 이후에 누르는 키들은 전부 레지스터에 저장됨
            - `q` 다시 누르면 지금까지 누른 키들이 등록됨
                - Q>> q가 등록되는 키로 생각되지는 않나???
        - `@b`: b 레지스터에 등록된 매크로 사용
            - `[N]@b`: b 레지스터에 등록된 매크로 N 회 사용하는 결과
        - 예시: `^i//Space_bar-Esc-Enter`
            - 커서를 맨 앞으로 이동 - 주석 처리(//) - 공백 - 표준 모드 전환 - 다음 행의 처음으로 커서 이동
    - Q>> 키 입력 저장이랑 문자열 저장이랑 저장/사용하는 키가 다른데 뭐가 다른가

6. 파일 버퍼
    - 여러 파일을 열게 될 경우, 각 파일은 vim의 파일 버퍼에 들어 있음
        - `:ls` 버퍼 내용 나열
            - `:buffers` 또는 `:files` 로도 확인 가능
        - `:b2` 2번 파일 버퍼로 전환
            - `:b[N]`: 으로 n번 버퍼로 전환 가능
        - `:bw[N]`: n번 버퍼를 완전 삭제 (n이 없으면 현재의 버퍼 완전 삭제)
        - `:bp`: 이전 버퍼로 이동
            - `:bp[N]`: N번만큼 이전 버퍼로 이동
        - `:bn`: 이후 버퍼로 이동
            - `:bn[N]`: N번만큼 이후 버퍼로 이동
    - vim에서 사용 가능한 파일 버퍼는 1000개 이상 (버퍼 걱정 하지 말 것)

7. 단축키 매핑(map)
    - `:map <단축키> <명령어><CR>`
        - `<CR>`은 vim 에서 Enter 의미
        - `map ,1 :b!1<CR>`: 1번 키에 *1번 파일 버퍼로 이동* 매핑
            - `b!1` 은 1번 버퍼에서 편집 작업 후 파일을 저장하지 않고 이동할 때 강제로 버퍼 전환
        - `map ,x :bn!<CR>`: x 키에 *다음 파일 버퍼로 이동* 매핑
        - `map ,z :bp!<CR>`: z 키에 *이전 파일 버퍼로 이동* 매핑
        - `map ,w :bw<CR>`: w 키에 *현재 파일 버퍼 닫음* 매핑
    - 동일한 내용을 `vimrc` 에 추가하여 실행할 때마다 사용 가능
    - <주의> map 명령으로 매핑할 때 표준 모드에서 사용하지 않는 단축키를 사용해야 함

8. 다중 창 기능
    - vim 의 화면을 여러 개로 분할해 사용
        - 표준 모드에서 `Ctrl-w + n`: 창이 가로로 분할(위아래) 되며 빈 파일 버퍼 생성
        - 표준 모드에서 `Ctrl-w + v`: 창이 세로로 분할(왼오) 되며 현재 파일 내용 분할
        - 표준 모드에서 `Ctrl-w + s`: 창이 가로로 분할(위아래) 되며 현재 파일 내용 분할
            - `:e 파일명`: 새 파일 불러오기
            - 화면 이동: 분할 상태에서 `ctrl+w+{hjkl}`; 분할된 윈도우 방향키
                - `Ctrl-ww`: 창간 커서 전환
                    - 분할된 창이 여러 개일 경우, 위->아래, 왼->오 순서로 전환됨
            - `Ctrl-wq` 또는 파일에서 `:q`: 창 종료
            - 화면 크기 조절
                - `ctrl+w` + `-`: 화면 크기 1행만큼 감소
                    - `[N]-`: N행만큼 감소
                    - `[N]<`: 왼쪽으로 N칸만큼 증가(수직 창 한정)
                - `ctrl+w` + `+`: 화면 크기 확대
                    - `[N]+`: N행만큼 확대
                    - `[N]>`: 오른쪽으로 N칸만큼 증가(수직 창 한정)
                - `ctrl+w` + `=`: 화면 크기 동일(균등 분할)
                - `ctrl+w` + `_`: 수평 분할에서 화면 크기 최대
                - `ctrl+w` + `|`: 수직 분할에서 화면 크기 최대

9. 마킹
- 커서의 특정 위치를 임의의 문자로 마킹해 나중에 표시한 위치로 한 번에 돌아가는 기능
    - 명령어
        - `m[임의의 알파벳]`: 마킹할 때
        - ``[마킹한 알파벳]`: 마킹된 위치로 돌아갈 때
            - 레지스터 사용은 `@`, 매크로 사용은 `,`, 마킹 사용은 '`' (backtick) 구별할 것
        - `:marks`: 마킹된 모든 정보 확인
        - `'[마킹한 알파벳]`: 마킹된 행의 처음으로 돌아갈 때
        - `''`: 직전에 커서가 위치하던 행의 처음
        - `'"`: 이전에 vim 으로 현재 파일을 닫았을 때 커서가 있던 행의 처음
        - ``(backtick 2개): 직전의 커서 위치
        - `"(backtick + "): 이전에 vim으로 현재 파일을 닫았을 때 커서가 있던 위치
    - 마킹 종류
        - 전역 마킹(A~Z): 현재 파일을 포함한 다른 파일간의 마킹 가능 -> 파일이 다르더라도 마킹한 위치로 이동 가능
        - 지역 마킹(a~z): 현재 파일 내에서만 마킹 가능 -> 현재 파일 내에서만 마킹이 유효함
        - 파일 마킹(0~9): `~/.viminfo` 파일에서 자동으로 지정한 마킹
            - vim이 실행/종료시 자동으로 지정되기 때문에 사용할 수 없음

10. 연동 프로그램
- 바이너리 형태의 실행 파일로 vim과 독자적으로 동작할 수 있는 프로그램
- ctags
    - 프로그래밍 소스 코드에서 태그(전역변수 선언, 함수 정의, 매크로 선언)들의 데이터베이스(tags 파일)를 생성하는 유닉스 명령<br>
    -> 특정 심볼을 찾을 때 활용
    - ctags 에서 인식하는 파일 종류
        > Assembler, ASP, Awk, **C**, **C++**, Cobol, Fortran, Java, **Make**, **Python**, Ruby, **Shell scripts**, Verilog, Vim, 등등
    - ctags 설정 및 기본 사용법
        - 설치 확인: `ctags --help`
        - 설치
        - vim 태그 데이터데이스 생성: 분석할 소스 들어가서 `ctags -R`
            - tags 파일 생성
                - 태그명
                - 파일명
                - 파일 내 태그 정의 형식
            - vim 에서 tags 변수에 생성한 태그 데이터베이스 파일 설정
                - 단일 지정 `:set tags=./tags`
                - 복수 지정 `:set tags=./tags, ~~/tags, ~~~~/tags`
            - vimrc 파일에 태그 변수 set 해서 매번 실행시 변수 자동으로 지정하도록 설정

- 내장 스크립트(vim 플러그인): 기능 확장을 위한 자체적인 스크립트
    - 내장 스크립트 문법을 이용해 vim에 새로운 기능을 추가할 수 있음
    - vim 이 실행될 때 전역 플러그인 디렉토리에 있는 내장 스크립트, 사용자 홈 디렉터리의 plugin 디렉터리의 내장 스크립트를 읽어 새로운 기능을 추가함


### 정규 표현식
기호나 문자를 사용해 문자열을 표현하는 방식<br>
vim 말고도 grep에서도 사용할 수 있음

|표현|내용|비고|
|---|----|---|
|^| 행의 첫 문자| [] 안에서는 not의 의미를 가짐|
|.|개행 문자를 제외한 아무 문자나 한 문자|
|[ ]|[] 사이의 문자 중 하나|
|*|앞의 내용이 0번 이상 반복됨| 없을 수도 있음|
|\\\<|단어의 시작|
|\n|new line 문자|vim에만 있는 확장 정규 표현식|
|$|행의 끝|
|\\\||or의 의미|
|\\\{min,max\\\}|min 이상 max 이하 반복됨|
|\+|앞의 내용이 1번 이상 반복됨| 최소 한 개는 있음|
|\\\>|단어의 끝|
|\t|tab 문자|vim에만 있는 확장 정규 표현식|

* meta character 나 정규 표현식 내에서 의미를 가지는 문자는 `\`(역슬래시)를 붙여 해당 의미를 없애줘야 문자열로 사용할 수 있다

- 예시
    - `[a-z]\+`: 소문자로 이루어진 문자열
        - a부터 z까지의 문자 중 하나 + 앞의 내용이 1번 이상 반복됨
    - `[a-z]\+[0-9]\+`: 소문자 문자열이 앞에 오고 뒤에 숫자가 있는 문자열
        - a부터 z까지의 문자 중 하나(1번 이상 반복)+ 0부터 9까지의 숫자 중 하나(1번 이상 반복)
    - `OK\ [a-z]\+[0-9]*`: `OK like`, `OK korea123` 처럼 `OK ` 문자열 뒤에 소문자 문자열, 그리고 숫자가 있을 수도/없을 수도 있는 문자열
        - OK 뒤에 `\ `로 띄어쓰기 표시 + 소문자 문자열 + 숫자 문자열이 0개 이상 반복(없을 수도 있음)
    - `^[0-9]\+.*`: 행의 처음이 숫자로 시작되는 문자열
        - 행 처음에 + 숫자가 1번 이상 반복 + 개행 문자를 제외한 어느 문자든 0개 이상 반복(없을 수도 있음)
    - `^[^0-9]\+.*`: 행의 처음이 숫자로 시작되지 않는 문자열
        - 행 처음에 + 숫자 아닌 것이 1번 이상 반복 + 개행 문자를 제외한 어느 문자든 0개 이상 반복(없을 수도 있음)
    - `.*[0-9]$`: 숫자로 끝나는 문자열
        - 개행 문자를 제외한 어느 문자든 0개 이상 반복(없을 수도 있음) + 행 마지막은 숫자
    - `\<ko`: `ko` 문자열로 시작하는 단어
        - 단어의 시작이 + ko
    - `ea\>`: `ea` 문자열로 끝나는 단어
        - ea 가 + 단어의 마지막
    - `[A-z]\+[0-9]\{3,4\}`: 영문자로 시작하고 3자리에서 4자리 숫자로 끝나는 문자열
        - A-z 까지의 대.소문자 모든 영문자 + 1번 이상 반복 + 숫자 문자열 3~4개 반복
    - `\(K\|k\)orea`: 첫 글자 K 대소문자 구별 없이 korea 검색
        - K또는 k(K|k) + orea

#### POSIX 문자 클래스
정규 표현식에서 사용하기 힘든 제어 문자들을 쉽게 사용할 수 있게 해주는 문자 클래스

|문자 클래스|내용|비고|
|---|----|---|
|[:alnum:]|알파벳과 숫자 [A-Za-z0-9]|
|[:alpha:]|알파벳 [A-Za-z]|
|[:cntrl:]|제어 문자|
|[:blank:]|탭과 공백 문자|
|[:digit:]|숫자 [0-9]|
|[:graph:]|제어 문자와 공백 문자를 제외한 문자|
|[:lower:]|소문자 [a-z]|
|[:upper:]|대문자 [A-Z]|
|[:print:]|제어 문자를 제외한 문자. 즉, 프린트할 수 있는 문자|
|[:punct:]|[:graph:]문자 중 [:alnum:]을 제외한 문자; ex) !,@#$%^..|
|[:space:]|화이트 스페이스; ex) 공백, 탭, 캐리지 리턴, 개행 문자, 수직 탭, 폼 피드|
|[:xdigit:]|16진수|

* vim 내에서 POSIX 문자 클래스를 사용할 경우 대괄호를 **두 개** 사용해야 한다!!
    - 모든 화이트 스페이스를 한 번에 표현하는 것이 가능해 자주 사용됨

- 예시
    - `[[:lower:]]\+`: 소문자로 이루어져 있는 문자열
        - 소문자 + 1번 이상 반복
    - `int[[:space:]]\+var;`: int var; 변수의 선언 부분
        - int + 화이트 스페이스 + var;
        - 정규 표현식으로 표현하려면 `int\(\ \|\t\|\n\)\+var;`

#### 확장 정규 표현식
확장 정규 표현식으로 정규 표현식을 훨씬 짧고 간결하게 작성할 수 있음

|표현|내용|비고|
|---|----|---|
|\i| 변수 지정에 사용되는 문자 [_0-9A-Za-z]|
|\I| \i와 같지만 숫자는 제외; [_A-Za-z]|
|\k| 키워드로 사용하는 문자 [_\.\-0-9A-Za-z>]|
|\K| \k와 같지만 숫자는 제외 [_\.\-A-Za-z>]|
|\f| 파일명으로 사용하는 문자|
|\F| \f와 같지만 숫자는 제외|
|\p| 프린트 가능한 문자|
|\P| \p와 같지만 숫자는 제외|
|\s| 화이트 스페이스 문자(공백과 탭)|
|\S| 화이트 스페이스가 아닌 문자|
|\d| 숫자[0-9]|
|\D| 숫자가 아닌 문자 [^0-9]|
|\x| 16진수 숫자 [0-9A-Fa-f]|
|\X| 16진수 숫자가 아닌 문자 [^0-9A-Fa-f]|
|\o| 8진수 숫자 [0-7]|
|\O| 8진수 숫자가 아닌 문자 [^0-7]|
|\w| 영문 단어에서 사용되는 문자 [0-9A-Za-z-]|
|\W| 영문 단어에서 사용되지 않는 문자 [^0-9A-Za-z-]|
|\h| 영문 단어의 시작에 사용되는 문자 [A-Za-z-]|
|\H| 영문 단어의 시작에 사용되지 않는 문자 [^A-Za-z-]|
|\a| 모든 알파벳 [A-Za-z]|
|\A| 알파벳이 아닌 문자 [^A-Za-z]|
|\l| 소문자 [a-z]|
|\L| 소문자가 아닌 문자 [^a-z]|
|\u| 대문자 [A-Z]|
|\U| 대문자가 아닌 문자 [^A-Z]|
|\e| esc|
|\t| tab|
|\r| 캐리지 리턴|
|\b| 백스페이스|
|\n| 개행 문자|



### 윈도우/버퍼   
```
A window is a viewport onto a buffer.  You can use multiple windows on one
buffer, or several windows on different buffers.

A buffer is a file loaded into memory for editing.  The original file remains
unchanged until you write the buffer to the file.
```
- 윈도우
- 버퍼
- 탭



### 보통은 필요하지 않지만 가끔 필요할 기능
(내 환경이 아니라서 .vimrc 세팅이 안 되있을 경우?)
```
:set number     // 라인 수 표시
:set nonu       // 라인 수 제거

```


### vimtutor 정리
#### Lesson 1
1. 방향키 hjkl  // 이 방향키에 익숙해지려면 타자법을 바꿔야 할 것 같음ㅠㅠ
2. 파일 시작/종료 `vim {filename}` / :q
3. `x`로 텍스트 지우기
4. `i`로 텍스트 삽입
5. `A`로 문장 맨 뒤에 텍스트 삽입

#### Lesson 2
1. 삭제 명령 `d`
    - `w`: 커서에서 그 단어 끝까지(공백 포함) -> 다음 단어의 첫 글자
    - `e`: 커서에서 그 단어 끝까지(공백 미포함) -> 현재 단어의 마지막 글자
    - `$`: 커서에서 그 줄의 끝까지
2. 커서를 문장 맨 앞으로 이동 `0`, `^`도 됨
3. 숫자로 명령 반복 -> {count}+명령
    ex) 2w, 3e, 4dw(d4w)
4. 한 줄 전체 지우기 `dd`
5. 취소(undo) `u`
    - 잘 쓸지 모르겠는데 한 줄에서 수정한 걸 모두 취소하려면 `U`
6. 취소를 취소 `ctrl+r`

#### Lesson 3
1. 붙여넣기 `p` // 버퍼에 있는 내용을 붙임
2. 한 글자 수정 `r+{바꿀 글자}` // 커서에 있는 한 글자를 이후 입력한 글자로 바꿈
    -> 여러 글자도 한꺼번에 수정이 되나 해서 여러 개 선택해서 바꿔봤더니 모두 같은 글자로 바뀜
3. 한 단어 수정 `ce`  // 커서부터 `e`까지 한 단어 삭제하고 insert 모드로 변경, 즉 `de + i`
    -> count 동일하게 작용, `w`나 `$`같은 거 다 적용 가능

#### Lesson 4 
1. 위치 이동
    - `ctrl+G`: 상태줄 표시 (파일 이름, 위치)
    - `G`/`Shift+g`: 파일의 마지막으로 이동
    - `gg`: 파일의 처음으로 이동
    - `줄 번호 + G`/`줄 번호 + Shift+g`: 입력한 줄로 이동<br>
        -> `:{line}` 으로 쉽게 이동 가능
2. `ruler` 옵션
3. 찾기 `/`
    - `n`
    - `N`
    - 역방향 찾기 `?`
    - 이전으로 가기 `ctrl+o` -> 추가 연습 필요
    - 뒤로 가기 `ctrl+i` -> 추가 연습 필요
4. 괄호 짝 찾기 `%`  // 특정 괄호에 커서를 두고 % 입력시 짝 괄호 위치로 커서 이동
5. 치환 `:s/old/new`  // 현재 줄에 있는 내용만 해당
    - 현재 줄 모든 문자열에 대해 치환할 경우 `/g` 추가
    - 두 줄 사이의 모든 문자열에 대해 치환할 경우 `:#,#s/old/new/g`
    - 파일 전체의 모든 문자열에 대해 치환할 경우 `:%s/old/new/g`
    - 파일 전체의 모든 문자열에 치환하되, 치환 여부는 프롬프트로 결정 `:%s/old/new/gc`
        <br>-> 프롬프트: `replace with the (y/n/a/q/l/^E/^Y)?`
        - y/n: yes/no
        - a: all
        - q: quit

#### Lesson 5
1. 외부 명령 실행 `:!{cmd}` // enter 쳐야 실행됨
2. 파일 저장 `:w {filename}` // filename인 파일로 저장 (현재 파일과 다르면 다른 파일, 현재 파일에는 저장되지 않음)
3. 비주얼 선택 `v`로 블록 지정 가능
    - 특정 부분만 저장: 블록 설정 후 `:` 입력시 `:'<,'>` 출력 -> 그대로 동일하게 w {filename} 으로 저장
    - 블록 지정 후 복사, 삭제 등 문자열 조작 가능
4. 파일/외부 내용 붙여넣기 `:r {filename}`  // 현재 커서 아래에 붙여넣음
    - `:r {filename}` 특정 파일 내용 붙여넣기
    - `:r !{cmd}` 특정 명령어 결과 붙여넣기

#### Lesson 6
1. 새 줄 열기 `o/O`
    - `o`: 커서 아래에 새 줄
    - `O`: 커서 위에 새 줄
2. 커서 뒤 추가 `a`
3. 치환 모드 `R` // 편집 모드와 동일하나, 글자가 입력되며 원래 있던 글자를 삭제하면서 들어감
4. 옵션 설정 `:SET {option}`
    - `ic`: ignore case  // 대소문자 구별 안 함
    - `noic`: no ignore case // 대소문자 구별함
    <br>-> 앞에 `no`를 붙여 옵션을 끌 수 있음
    - `hls`: hlsearch  // 검색한 내용 하이라이트
    - `is`: incsearch  // 찾기 위해 입력한 글자가 바로 적용 (바로바로 해당 글자 찾기); 즉, 부분 검색 결과 보여줌
5. 검색시 대소문자 구별을 옵션 설정이 아니라, 한 번만 적용하고 싶다면 `~/c` -> 이게 검색에만 해당되는건가? 대소문자 구별 안 할 때만 쓰는건가?

#### Lesson 7
1. Online help `:help`
    - `:q`로 종료
    - `:help {cmd}` cmd에 대한 도움말 확인
    - 새 창으로 열림
        - `ctrl+w` 로 다른 쪽 윈도우로 넘어갈 수 있음 (중요)
2. `vimrc` 파일: vim 기능 활용 스크립트
    - 매번 옵션을 치는 게 불편하기 때문에, 자주 쓰는 옵션 세팅 및 매핑 등을 vimrc 파일에 저장해 vim 시작시 설정
    - `:help vimrc-intro` 참고
3. 명령어 완성하기
    - `:set nocp` 확인: vim 이 이전 vi 와 호환이 안 되게 설정(vim 설정 활용); 기본적으로 vi 가 시작할 때는 이 설정이 on 이기 때문에 off 해줘야 함
    - 명령어 `:{cmd}` 입력 후 `ctrl+d` 입력시 해당 명령어로 시작하는 모든 명령어 출력
    - TAB 으로 파일 이름 완성
<br><br>

#### vi 환경 체크
```
:version
VIM - Vi IMproved 9.0 (2022 Jun 28, compiled Mar 21 2023 05:42:11)
macOS version - x86_64
Included patches: 1-1313
Compiled by root@apple.com
Normal version without GUI.  Features included (+) or not (-):
+acl               +cryptv            +fork()            +modify_fname      +persistent_undo   -sun_workshop      +viminfo
-arabic            +cscope            -gettext           +mouse             +popupwin          +syntax            +virtualedit
+autocmd           +cursorbind        -hangul_input      -mouseshape        +postscript        +tag_binary        +visual
+autochdir         +cursorshape       +iconv             +mouse_dec         +printer           -tag_old_static    +visualextra
-autoservername    +dialog_con        +insert_expand     -mouse_gpm         -profile           -tag_any_white     +vreplace
-balloon_eval      +diff              +ipv6              -mouse_jsbterm     +python/dyn        -tcl               +wildignore
-balloon_eval_term +digraphs          +job               +mouse_netterm     -python3           +termguicolors     +wildmenu
-browse            -dnd               +jumplist          +mouse_sgr         +quickfix          +terminal          +windows
++builtin_terms    -ebcdic            -keymap            -mouse_sysmouse    +reltime           +terminfo          +writebackup
+byte_offset       -emacs_tags        +lambda            +mouse_urxvt       -rightleft         +termresponse      -X11
+channel           +eval              -langmap           +mouse_xterm       +ruby/dyn          +textobjects       -xfontset
+cindent           +ex_extra          +libcall           +multi_byte        +scrollbind        +textprop          -xim
-clientserver      +extra_search      +linebreak         +multi_lang        +signs             +timers            -xpm
+clipboard         -farsi             +lispindent        -mzscheme          +smartindent       +title             -xsmp
+cmdline_compl     +file_in_path      +listcmds          +netbeans_intg     -sodium            -toolbar           -xterm_clipboard
+cmdline_hist      +find_in_path      +localmap          +num64             -sound             +user_commands     -xterm_save
+cmdline_info      +float             -lua               +packages          +spell             -vartabs
+comments          +folding           +menu              +path_extra        +startuptime       +vertsplit
+conceal           -footer            +mksession         -perl              +statusline        +vim9script
   system vimrc file: "$VIM/vimrc"
     user vimrc file: "$HOME/.vimrc"
 2nd user vimrc file: "~/.vim/vimrc"
      user exrc file: "$HOME/.exrc"
       defaults file: "$VIMRUNTIME/defaults.vim"
  fall-back for $VIM: "/usr/share/vim"
Compilation: gcc -c -I. -Iproto -DHAVE_CONFIG_H   -DMACOS_X_UNIX  -g -O2 -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=1
Linking: gcc   -L/usr/local/lib -o vim        -lm -lncurses  -liconv -framework Cocoa
```
- `./vimrc`, `defaults.vim` 차이
    - `./vimrc`: 사용자가 원하는 설정들 vi 시작시 자동으로 적용되게 만든 파일. 대표적으로 `:set {option}` 으로 적용되는 옵션들을 미리 줄 수 있다.
    - `defaults.vim`: Vim 8.0에 추가된 스크립트로 사용자가 설정한 `vimrc` 파일이 없으면 자동으로 적용됨. `nocp` (compatible 적용x), 하이라이팅 등 기본적인 설정들

### vimrc 자주 쓰는 설정들
```
""" General Settings
set nocompatible     " not compatible with original vi
set history=1000     " set how many lines of history VIM has to remember(.viminfo)
set autoread     " set auto read when opened file is changed from outside
set autowrite     " set auto write(:w) on opened file when reading other file; if current file is not written, cannot open other file
set mouse=a     " use mouse; click(cursor), drag(visual mode), cannot use right click(copy)
" set mouse-=a      " not using mouse 
set backspace=eol,start,indent     "  end of line, start, indent can be erased


""" VIM user interface
set ruler     " show current position (row, col) in right bottom
set hlsearch     " Highlight search results
set incsearch     " Makes search act like search in modern browsers
set ignorecase     " ignore lower/upper cases
set showmatch      " Show matching brackets when text indicator is over them
set number      " show line numbers


""" Colors and Fonts
syntax on     " language syntax highlight
colorscheme desert     " color scheme
set background=dark
set encoding=utf8     " Set utf8 as standard encoding


""" Text, tab and indent related
set shiftwidth=4     " auto indent's tab size
set tabstop=4     " 1 tab for 4 spaces
set cindent     " c style auto indent


""" Coding
set foldmethod=indent     " fold functions by indent or syntax; 
" open a folded function: 'zo'
" fold a function: 'zc'
set foldnestmax=1     " set max depth 1

```

#### reference
- 유닉스 리눅스 프로그래밍 필수 유틸리티
- [vimhelp](https://vimhelp.org/starting.txt.html)
- [simple-vim-guide](https://github.com/johngrib/simple_vim_guide/blob/master/README.md)


======================================================
###### 230515 TIL
###### 230518 TIL
###### 230930 TIL
###### 231001 TIL
###### 231003 TIL
###### 231004 TIL
###### 231007 TIL
###### 231008 TIL
###### 231009 TIL
###### 231013 TIL
###### 231014 TIL
###### 231015 TIL
###### 231018 TIL
###### 240103 TIL
###### 240104 TIL
###### 240105 TIL
###### 240108 TIL
###### 240109 TIL
###### 240113 TIL
###### 240114 TIL
###### 240115 TIL
###### 240116 TIL
###### 240119 TIL

======================================================
Vim practic log
1. download pracice source(linux)
    - no wget, download wget `brew install wget` in mac
    - 는 맥북 업데이트가 안 돼서 실패하고 그냥 linux kernel 소스 클론받음

2. vimtutor 연습
3. `E21: Cannot make changes, 'Modifiable' is off` 에러
    - 발생: vim 으로 파일을 보다가 `:help motion` 도움말을 보던 중, 연습하고 싶어 `r-> 변환할 문자` 입력
    - 원인: 아마 권한이 없어서 그런 것으로 추측. 확실하지는 x<br>
        -> `:set modifiable` 하고 나서 변경하려고 했더니 `W10: Warning: Changing a readonly file` 경고 발생. 강제 저장 하면 저장 될 것 같음
    - 해결: `set modifiable`

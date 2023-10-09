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
    - 치환
        - r: 한 글자로 대체(replace)
        - c: 삭제 후 변경 (change)
    - 찾기 (완전 유용!!!!!)
        - 단어에 커서 두고 `*`: `/` 로 찾기 할 필요 없이 해당 단어 찾아줌. 다음 찾은 문자로 커서 이동됨 (대소문자 구분)
        - 단어에 커서 두고 `#`: `?` 와 동일; * 와 방향 반대
        - 처음에는 문자열 블록 해서 찾아야되는 줄 알았는데 그럴 필요 없음; 그냥 단어 중간에 커서만 둬도 해당 단어 찾아줌. 문자열 블록 설정시 그 다음 단어까지 선택됨

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

5. 터미널 작업 결과 vim 에 붙여넣기
    - `:read !~cmd~`
        - 여기서 cmd는 결과를 가져오고 싶은 터미널 명령어
            - ex. ls, cat some_file.md
        - 그럼 현재 커서에 명령어 결과 붙여넣기


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

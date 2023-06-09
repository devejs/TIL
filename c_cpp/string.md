# String

## C에서의 문자열
C에서는 문자열을 직접적으로 다루는 자료형이 없음   
- char의 배열로 문자열을 간접적으로 저장함
    - char: 1byte; ASCII
    - char[]
        - 말 그대로 메모리에 배열 선언하여 문자열처럼 사용
        - 배열에 바로 리터럴 문자열 할당
        - 각 인덱스에 접근해 수정 가능
        - 마지막 char 데이터는 `\0`
        ```
        const int str_len = 10;
        char str[str_len] = "hello";
        ```
        - 미리 배열의 길이 지정이 필요함
        - 메모리 낭비 혹은 잘릴 위험이 있음

    - char*
        - 이어진 char들의 포인터
        - 특정 문자열 리터럴의 첫 주소값 저장
        - 문자열 리터럴은 상수이므로 접근은 가능하나 **변경 불가능**함
        - 문자열 상수는 `.rdata`(상수값 데이터)에 저장됨    //readOnly
        ```
        char* str = "hello";
        ```
        - 엄밀히 말해서 문자열 리터럴은 수정 불가능하므로 `const char* str`이 맞을 것 같긴 함
- 문자열 관련 라이브러리
    - <string.h>
        - 문자열 복사
        - 문자열 더하기
        - 문자열 비교
        - 문자열 찾기


## C++ 에서의 문자열 
C에서 사용하는 문자열 관련 라이브러리도 사용 가능하지만, 좀 더 문자열을 편하게 사용할 수 있게 `String` 클래스 구현됨
- `<cstring>` : C에서 사용하는 <string.h> 라이브러리를 C++에서도 사용 가능함
- `std::string` : 문자열 객체(Class)
    - C에서와 다르게 Size flexibility
    - 마지막 null 문자를 고려할 필요가 없음
    - `=` 로 문자열 복사 가능
    - `==` 로 문자열 비교 가능 
    - 문자열을 매번 초기화/재할당할 필요가 없음

- char* 와 std::string
    - char* -> string 묵시적 변환 가능
    - string -> char* 변환은 명시적 캐스팅 필요함
        ```
        char* str1 = "hello";
        std::string str2 = str1.c_str();
        ```


### 자주 쓰는 String 관련 함수
- string.compare()
    ```c++
    string str1 = "hello";
    string str2 = "HELLO";

    int result = str1.compare(str2);
    if(result == 0)
    {
        printf("같은 문자열");
        // 같으면 0 리턴
    }
    else
    {
        printf("다른 문자열");
        // 같으면 -1 리턴
    }
    ```
- string.find()
    ```c++
    string total_string = "I'm studying c++";
    string find_string = "study";

    int result = total_string.find(find_string);
    if (result >= 0)
    {
        // 찾으면 문자 또는 문자열의 시작 위치 반환;
        // 시작 위치는 0부터 시작
        printf("find it! location is : %d\n", result);
    }
    else
    {
        // 찾지 못 할 경우 -1 리턴
        printf("cannot find\n");
    }
    ```
- string.length()
- toupper()/tolower()
- string.append()
    ```c++
    string str1 = "hello";
    string str2 = "world";
    string result = "result: ";

    // append 와 += 동일한 기능
    // += 는 복합 할당 연산자
    result.append(str1);
    result += str2;

    cout << result << endl;
    ```
- string.insert()
- string.erase()
- string.remove()
- string.move()
- string.replace()
- stoi()
- sort()
- reverse()
- to_string()
- min()/max()/minmax()
    ```c++
    #include <algorithm>
    using namespace std;

    /* Definition
    template<class T>
    const T& min (const T& a, const T& b)

    template<class T>
    const T& max (const T& a, const T& b)

    template<class T> 
    pair<const T&, const T&> minmax(const T& a, const T& b);
        or
    template<class T>
    pair<const T&, const T&> minmax(initializer_list<T> ilist);

    */
    ```

### stringstream


### Reference
- [문자열 관련](https://www.sagacityjang@tistory.com/109)



======================================================
###### 230520 TIL
###### 230609 TIL

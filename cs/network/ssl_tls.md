# Network Protocols

## SSL/TLS
### SSL/TLS 란?
- 기존 웹: 웹에서 데이터가 암호화되지 않아 보안 이슈 발생 (패킷 가로채기 등)
- SSL(Secure Sockets Layer): 웹에서 전송되는 데이터를 암호화해 개인정보 보호 및 데이터 무결성 제공(데이터 디지털 서명)
- TLS(Transport Layer Security): SSL 업데이트 버전; 이름이 바뀐 것은 개발사의 소유권 이전 때문이라고 함. SSL과 큰 차이는 없어 SSL과 TLS가 혼용되어 사용되고, SSL/TLS라고도 함

> SSl/TLS 를 사용하는 웹사이트 URL은 HTTP 대신 HTTPS가 사용된다.

### SSL(TLS) 인증서
- SSL 인증: **SSL 인증서**가 있는 웹사이트만 실행 가능
- SSL 인증서는 웹사이트나 서버가 웹에 저장하고 표시
    - SSL 인증서는 인증 기관(CA)에서 발급한다. 
- 공개 키 암호화: 서로 다른 두 개의 키로 데이터를 암호화하거나 서명
    - 공개 키: 서로 다른 두 개의 키 중 하나로, 공개 키를 누구나 사용할 수 있도록 하는 방식
    - 개인 키: 공개 키로 암호화된 데이터를 해독
- 인증 프로세스: 핸드셰이크

> 인증서가 없는 웹 사이트 접속시 '주의 요함' 이라는 문구가 출력되는 걸 볼 수 있는데, 이는 해당 웹 서버가 인증서가 검증되지 않았음을 의미함. 즉, 데이터가 암호화되지 않은 채로 전송되고 있으며 스니핑(Sniffing), 스푸핑(Spoofing) 등으로 데이터가 전부 유출될 수 있음
> * 스니핑: 네트워크를 통과하는 패킷을 도청하여 데이터 해킹
> * 스푸핑: IP의 패킷을 구성하는 헤더에 사용자의 정보를 조작하여 IP 주인이 아닌 악의적인 목적을 가진 사용자가 사용하는 해킹 공격

### SSL/TLS 핸드셰이크
> 1. 사용자가 HTTPS를 통해 웹 사이트를 탐색하고 브라우저가 처음 해당 웹 사이트의 원본 서버를 쿼리하기 시작할 때마다 발생
> 2. 다른 통신이 API 호출 및 HTTPS를 통한 DNS 쿼리를 포함하는 HTTPS를 사용할 때 발생
> 3. 정확한 단계는 사용되는 키 교환 알고리즘의 종류와 양측에서 지원하는 암호 모음에 따라 달라진다

#### RSA 키 교환 알고리즘 사용 예시
1. 사용할 TLS 버전(TLS 1.0, 1.2, 1.3 등)을 지정
2. 사용할 암호 제품군(안전한 통신 연결을 수립하는 데 사용하는 알고리즘 세트)을 결정
    - 클라이언트 헬로: 클라이언트 -> 서버; 'Hello' message 전송
        - 헬로 메세지: 지원하는 TLS 버전, 지원되는 암호 제품군, `클라이언트 무작위`라고 하는 무작위 바이트 문자열이 포함됨
    - 서버 헬로: 서버 -> 클라이언트 응답
        - 헬로 메세지: 서버의 SSL 인증서, 서버에서 선택한 암호 제품군, 서버에서 생성한 또 다른 무작위 바이트 문자열인 `서버 무작위`가 포함됨
3. 서버의 공개 키와 SSL 인증서 기관의 디지털 서명을 통해 서버의 ID를 인증
    - 인증: 클라이언트가 서버의 SSL 인증서를 인증서 발행 기관을 통해 검증
        - 서버가 인증서에 명시된 서버인지 확인
        - 서버가 실제 해당 도메인의 소유자인지 확인
    - 예비 마스터 암호: 클라이언트가 `예비 마스터 암호`라고 하는 무작위 바이트 문자열을 하나 더 전송
        - 예비 마스터 암호는 서버의 SSL 인증서로부터 받은 공개 키로 암호화
    - 개인 키 사용: 서버는 예비 마스터 암호를 개인 키로 해독
4. 핸드셰이크가 완료된 후에 대칭 암호화를 사용하기 위하여 세션 키를 생성
    - 세션 키 생성: 클라이언트와 서버가 모두 `클라이언트 무작위`, `서버 무작위`, `예비 마스터 암호`를 이용해 세션 키 생성
        - 서버와 클라이언트의 세션 키는 동일해야 함
    - 클라이언트 준비 완료: 클라이언트 -> 서버; 세션 키로 암호화된 완료 메시지 전송
    - 서버 준비 완료: 서버 -> 클라이언트; 세션 키로 암호화된 완료 메시지 전송
    - 안전한 대칭 암호화 성공: 핸드셰이크 완료; 세션 키를 이용해 통신이 계속 진행됨


## HTTPS
### HTTPS 란?
- HTTP(HyperText Transfer Protocol): 클라이언트와 서버 간 통신을 위한 통신 프로토콜
    - 사용자가 웹 접속시 사용자 브라우저가 웹 서버에 HTTP 요청을 전송하고 웹 서버는 HTTP 응답으로 응답
        - ex. GET/PUT..., 200 OK/404 Not Found
    - 웹 서버와 사용자 브라우저가 데이터를 일반 텍스트로 교환
- HTTPS(HyperText Transfer Protocol Secure): HTTP 통신에 암호화 과정을 추가한 프로토콜
    - 브라우저와 서버가 데이터를 전송하기 전에 안전하고 암호화(SSL/TLS)된 연결을 설정([인증서 교환](#ssltls-핸드셰이크))



### Reference
- [what is ssl](https://www.cloudflare.com/ko-kr/learning/ssl/what-is-ssl/)
- [공개 키 암호](https://www.cloudflare.com/ko-kr/learning/ssl/how-does-public-key-encryption-work/)
- [TLS 핸드셰이크](https://www.cloudflare.com/ko-kr/learning/ssl/what-happens-in-a-tls-handshake/)
- [SSL 인증서 구조](https://m.blog.naver.com/alice_k106/221468341565)
- [sniffing](https://www.ahnlab.com/kr/site/securityinfo/secunews/secuNewsView.do?menu_dist=3&seq=5185)
- [spoofing](https://www.cloudflare.com/ko-kr/learning/ddos/glossary/ip-spoofing/)
- [what is https](https://www.cloudflare.com/ko-kr/learning/ssl/what-is-https/)

======================================================
###### 230722 TIL
###### 230723 TIL
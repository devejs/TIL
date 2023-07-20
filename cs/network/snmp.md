# Network Protocols

## SNMP
### SNMP란?

> **간이 망 관리 프로토콜(Simple Network Management Protocol)**<br>
> `망` `관리` 프로그램이라는 이름에서 알 수 있듯 말그대로 네트워크에 대해서 관리할 수 있는 프로토콜이다. 네트워크 장비의 성능과 핵심 기능의 현 상태, 기능 정보를 수집하고 관리, 저장한다. 더하여 snmp를 사용하여 장비를 설정할 수도 있다.<br>

- 지원 장치: 라우터, 스위치, 서버, 워크스테이션, 프린터 등 
- 정보 수집 관계
    - 정보 수집: Manager/Network Management System(NMS)
    - 정보 제공: Agent

### SNMP 버전
| version | Community | Description | Etc |
|--------|--------|--------|--------|
| SNMPv1 | 일반 평문(String) | | |
| SNMPv2 | 암호화된 평문| | |
| SNMPv2c | 일반 평문 | | |
| SNMPv3 | 계정(Username)/패스워드 | | |


### SNMP Message
- Get
- Set
- Trap: 요청이 없더라도 네트워크 장비가 스스로 생성/송신하는 SNMP 메세지
    - **스스로 송신** 한다는 것은 장비 운용에 치명적일 수 있는 사항들을 장비가 스스로 전송한다는 것; 즉, 무언가 장비에 이슈가 생겨 점검이 필요하다는 것을 어필
    - Get/Set 과는 달리 UDP 포트 **162** 번 따로 사용

#### Object ID




### Reference
- [SNMP 쉽게 이해하기](https://aws-hyoh.tistory.com/179)


======================================================
###### 230720 TIL
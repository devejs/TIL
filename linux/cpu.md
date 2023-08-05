# CPU

## Linux에서의 CPU 확인 방법
1. 하드웨어 정보 확인
    * 파일 `/proc/cpuinfo`
    * 명령어 `lscpu`
    * 명령어 `dmidecode`
2. CPU 사용 정보 확인
    * 명령어 top/htop
    * 명령어 mpstat: CPU 코어별 사용량을 확인
    * 파일 `/proc/stat`

### CPU 사용률 계산
> Jiffy: 리눅스에서 내부적으로 사용하는 단위 시간<br>
> 시스템이 시작한 이후 타이머 인터럽트의 발생 횟수를 누적 저장한다.

`/proc/stat` 에 저장된 jiffy 값들을 통해 CPU 사용률을 계산할 수 있다. 지금까지 몇 번의 jiffy 값들이 있었는지로 시간이 얼마나 지났는지 추론 가능하며, 총 total jiffies 값과 idle jiffies 값을 이용한다.<br>
* user : 사용자 영역 코드 실행 시간
* system: 기본보다 낮은 우선순위로 실행한 사용자 영역 코드 실행 시간
* nice : 커널 영역 코드 실행 시간
* idle : I/O 완료가 아닌 대기 시간
* wait : I/O 완료 대기 시간
* hi : Hard Interrupt(IRQ)
* si : Soft Interrupt(SoftIRQ)
* zero : 끝

> **계산식**<br>
> CPU(%) = `100*{1-(idle_jiffy/total_jiffy)}`


## 참고 디렉터리
- `/proc`: 가상 파일 시스템; 운영 중인 프로세스의 상태 정보, 하드웨어 정보, 기타 시스템 정보 등 
- `/sys`: 가상 파일 시스템인 `sysfs`에서 사용하는 디렉터리; `/proc`에서 기본적인 하드웨어 정보를 가지고 있다면 여기서는 계층적인 구조로 정보 제공



### Reference
- [리눅스 CPU/Memory 관련 명령어](https://inpa.tistory.com/entry/LINUX-%F0%9F%93%9A-CPU-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EB%94%94%EC%8A%A4%ED%81%AC-%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-%EC%A0%95%EB%B3%B4-%EB%AA%85%EB%A0%B9%EC%96%B4-%EC%B4%9D%EC%A0%95%EB%A6%AC)
- [/proc/stat 관련](http://www.dreamy.pe.kr/zbxe/CodeClip/163339)




======================================================
###### 230801 TIL
###### 230805 TIL
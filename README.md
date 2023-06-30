#  SOCKET 프로그래밍

소켓 구조체(IPv4)-struct sockaddr _in addr;  <br>
구성- sin_family(주소 체계),sin_port(포트 번호),sin_addr(IP주소),sin_zero(패딩)
<br><br>
### 1.소켓 초기화 <br>
    WSADATA wsa; 
    if(WSAStartup(MAKEWORD(2,2),&wsa)!=0)
    {  return 1; }
 <br> <br>
### 2.서버 소켓 생성 <br>
#### TCP<br>

    SOCKET listen_sock =socket(AF_INET, SOCK_STREAM, 0); 
    //AF_INET = IPv4 주소 체계 
#### UDP<br>

    SOCKET sock=socket(AF_INET,SOCK_DGRAM,0);
 <br> <br>
### 3.클라이언트와 연결(통신) 후 파일 디스크립터(I/O리소스 식별 정수) 반환 <br>
    client_sock = accept(listen_sock, (struct sockaddr *)&clientaddr, &addrlen);
 <br> <br>

###  4. 네트워크 바이트 정렬(호스트-라우터 IP주소의 바이트 상호약속) <br>
    u_short htons(u_short hostshort);//host-to-network-short; 
    u_long htonl(u_short hostshort);//host-to-network-short; 
    u_short ntohs(u_short hostshort);//network-to-host-short; 
    u_long ntohl(u_short hostshort);//network-to-host-long;
 <br> <br>
###  5.IP주소 변환 함수 <br>
    int inet_pton(int af, const char *src, void *dst) //Network Format(이진 형식) 변환 
    const char *inet_ntop(int af, const void *src, char *dst, socklen_t size) //Presentation Format(텍스트 형식)으로 변환
 <br> <br>
###  6.DNS <br>
    gethostbyname(name) //  도메인 이름 -> IPv4주소  <br>
    gethostbyaddr((const char*)&addr,sizeof(addr),AF_INET);// IPv4 주소->도메인 이름 <br>
 <br> <br>
###  7.Server-Client <br>
#### TCP<br>
(1)Server:socket()->bind():소켓에 local IP주소 할당 -> listen() -> accept() -> recv():데이터 수신함수 -> send():데이터 전송함수->closesocket() 종료   <br>
(2)Client:socket() -> connect():소켓 구조체를 서버의 원격 IP주소,포트번호로 초기화 -> send() -> recv() -> closesocket() <br>
#### UDP<br>
(1)Server:socket()->bind():소켓에 local IP주소 할당 ->  recvfrom():데이터 수신함수 -> sendto():데이터 전송함수->closesocket() 종료   <br>
(2)Client:socket() -> sendto() -> recvfrom() -> closesocket() or socket() ->connect() -> send() -> recv() -> closesocket() <br>
###  8.Thread <br>
(1)Windows API 데이터 타입<br>
HANDLE:운영체제의 리소스를 가리키는 포인터<br>
DWORD:Windows API에서 함수의 매개변수나 반환값,Unsigned 정수<br>
WINAPI:함수 호출 규약 __stdcall 를 따른다.<br>
SYSTEM_INFO:하드웨어 및 운영체제에 대한 정보<br>
LPVOID:long pointer<br>
CreateThread:CreateThread(핸들상속,보안디스크립터=NULL,스택 사이즈=0(기본크기),스레드 함수 시작 주소,전달할 인수(arg<포인터크기 ? 주소: data),제어 값,스레드ID )<br><br>
(2)우선순위 함수:SetThreadPriority(우선순위 변경),GetThreadPriority(우선순위 레벨반환)<br><br>
(3)스레드 종료(동기화):WaitForSingleObject(특정 스레드 종료까지 대기),WaitForSingleObject(여러 스레드(배열에 저장) 종료 대기)<br><br>
(4)동기화 객체:둘 이상의 스레드가 공유자원에 접근할때 독립적으로 실행하지 않고 상호작용하여 접근한다. 그러기 위해 동기화 객체가 필요한데 **Kernel의 메모리 영역**에 동기화 객체가 생성되고 이에 접근할수 있는 HANDLE이 리턴된다.<br><br>
(5)Critical Section(임계영역):두 스레드가 공유자원에 접근할때 하나의 스레드의 접근을 허용한다. 동기화 객체와 달리 개별 프로세스의 **사용자 메모리 영역**에 존재하는 단순한 구조체다. 즉, 한 프로세스에 속한 스레드 간의 동기화에만 사용된다<br><br>
(6)Event(동기화 객체):임계영역 만으로 어떤 스레드가 먼저 자원에 접근했는지 알수 가 없다.이벤트는 사건 발생을 다른 스레드에 알리는 동기화 기법이다.

    bool SetEvent(HANDLE hEvent);// 비신호상태 -> 신호상태
    bool ResetEvent(HANDLE hEvent);// 신호상태 -> 비신호상태<br><br>
### 9.UDP
(1)비연결형 프로토콜<br>
(2)일대일,일대다통신<br>
(3)신뢰성 없는 데이터 전송:데이터 재전송 X<br>
(4)데이터 경계 구분<br>

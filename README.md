#  SOCKET 프로그래밍

소켓 구조체(IPv4)-struct sockaddr _in addr;  <br>
구성- sin_family(주소 체계),sin_port(포트 번호),sin_addr(IP주소),sin_zero(패딩)
<br><br>
### 1.소켓 초기화 <br>
WSADATA wsa; <br>
if(WSAStartup(MAKEWORD(2,2),&wsa)!=0){ <br>
return 1; <br>
}
 <br> <br>
### 2.서버 소켓 생성 <br>
SOCKET listen_sock =socket(AF_INET, SOCK_STREAM, 0); <br>
//AF_INET = IPv4 주소 체계 <br>
 <br> <br>
### 3.클라이언트와 연결(통신) 후 파일 디스크립터(I/O리소스 식별 정수) 반환 <br>
client_sock = accept(listen_sock, (struct sockaddr *)&clientaddr, &addrlen); <br>
 <br> <br>

###  4. 네트워크 바이트 정렬(호스트-라우터 IP주소의 바이트 상호약속) <br>
u_short htons(u_short hostshort);//host-to-network-short; <br>
u_long htonl(u_short hostshort);//host-to-network-short; <br>
u_short ntohs(u_short hostshort);//network-to-host-short; <br>
u_long ntohl(u_short hostshort);//network-to-host-long; <br>
 <br> <br>
###  5.IP주소 변환 함수 <br>
int inet_pton(int af, const char *src, void *dst) //Network Format(이진 형식) 변환 <br>
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size) //Presentation Format(텍스트 형식)으로 변환 <br>
 <br> <br>
###  6.DNS <br>
gethostbyname(name) //  도메인 이름 -> IPv4주소  <br>
gethostbyaddr((const char*)&addr,sizeof(addr),AF_INET);// IPv4 주소->도메인 이름 <br>
 <br> <br>
###  7.Server-Client <br>
(1)Server:socket()->bind():소켓에 local IP주소 할당 -> listen() -> accept() -> recv():데이터 수신함수 -> send():데이터 전송함수->closesocket() 종료   <br>
(2)Client:socket() -> connect():소켓 구조체를 서버의 원격 IP주소,포트번호로 초기화 -> send() -> recv() -> closesocket() <br> <br>
###  8.Thread <br>
(1)Windows API 데이터 타입<br>
HANDLE:운영체제의 리소스를 가리키는 포인터<br>
DWORD:Windows API에서 함수의 매개변수나 반환값,Unsigned 정수<br>
WINAPI:함수 호출 규약 __stdcall 를 따른다.<br>
SYSTEM_INFO:하드웨어 및 운영체제에 대한 정보<br>
LPVOID:long pointer<br>
CreateThread:CreateThread(핸들상속,보안디스크립터=NULL,스택 사이즈=0(기본크기),스레드 함수 시작 주소,전달할 인수(arg<포인터크기 ? 주소: data),제어 값,스레드ID )<br><br>
(2)우선순위 변경:SetThreadPriority(우선순위 변경),GetThreadPriority(우선순위 레벨반환)<br><br>
(3)스레드 종료(동기화):WaitForSingleObject(특정 스레드 종료까지 대기),WaitForSingleObject(여러 스레드(배열에 저장) 종료 대기)<br><br>

# Headings SOCKET 프로그래밍

소켓 구조체(IPv4)-struct sockaddr _in addr; 
구성- sin_family(주소 체계),sin_port(포트 번호),sin_addr(IP주소),sin_zero(패딩)

# Level 1 1.소켓 초기화 <br>
WSADATA wsa;
if(WSAStartup(MAKEWORD(2,2),&wsa)!=0){
return 1;
}

# Level 1 2.서버 소켓 생성 <br>
SOCKET listen_sock =socket(AF_INET, SOCK_STREAM, 0);
//AF_INET = IPv4 주소 체계

# Level 1 3.클라이언트와 연결(통신) 후 파일 디스크립터(I/O리소스 식별 정수) 반환 <br>
client_sock = accept(listen_sock, (struct sockaddr *)&clientaddr, &addrlen);


# Level 1 4. 네트워크 바이트 정렬(호스트-라우터 IP주소의 바이트 상호약속) <br>
u_short htons(u_short hostshort);//host-to-network-short;
u_long htonl(u_short hostshort);//host-to-network-short;
u_short ntohs(u_short hostshort);//network-to-host-short;
u_long ntohl(u_short hostshort);//network-to-host-long;

# Level 1 5.IP주소 변환 함수 <br>
int inet_pton(int af, const char *src, void *dst) //Network Format(이진 형식) 변환
const char *inet_ntop(int af, const void *src, char *dst, socklen_t size) //Presentation Format(텍스트 형식)으로 변환

# Level 1 6.DNS <br>
gethostbyname(name) //  도메인 이름 -> IPv4주소 
gethistbyaddr((const char*)&addr,sizeof(addr),AF_INET);// IPv4 주소->도메인 이름

# Level 1 7.Server-Client <br>
(1)Server:socket()->bind():소켓에 local IP주소 할당 -> listen() -> accept() -> recv():데이터 수신함수 -> send():데이터 전송함수->closesocket() 종료  
(2)Client:socket() -> connect():소켓 구조체를 서버의 원격 IP주소,포트번호로 초기화 -> send() -> recv() -> closesocket()

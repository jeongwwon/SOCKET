#include "Common.h"
int main() {
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		return 1;
	}
	printf("[알림]윈속 초기화 성공\n");
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) err_quit("socket()");
	printf("[알림] 소켓 생성 성공\n");

	closesocket(sock);

	u_short x1 = 0x1234;
	u_long y1 = 0x12345678;
	u_short x2;
	u_long y2;
	printf("[호스트 바이트->네트워크 바이트]\n");
	printf("%#x->%#x\n", x1, x2 = htons(x1));
	printf("%#x->%#x\n", y1, y2 = htonl(y1));

	printf("[네트워크 바이트-> 호스트 바이트]\n");
	printf("%#x->%#x\n", x2, ntohs(x2));
	printf("%#x->%#x\n", y2, ntohl(y2));

	printf("[잘못된 사용의 예]\n");
	printf("%#x->%#x\n", x1, htonl(x1));
	WSACleanup();
	return 0;
	
}
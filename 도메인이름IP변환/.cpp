#include"Common.h"
#define TESTNAME "www.hanyang.ac.kr"
bool getipaddr(const char* name, struct in_addr* addr) {
	struct hostent* ptr = gethostbyname(name);
	if (ptr == NULL) {
		err_display("gethostbyname()");
		return false;
	}
	if (ptr->h_addrtype != AF_INET) {
		return false;
	}
	memcpy(addr, ptr->h_addr, ptr->h_length);
	return true;
}
bool getdomainname(struct in_addr addr, char* name, int namelen) {
	struct hostent* ptr = gethostbyaddr((const char*)&addr,sizeof(addr),AF_INET);
	if (ptr == NULL) {
		err_display("gethostbyaddr()");
		return false;
	}
	if (ptr->h_addrtype != AF_INET) {
		return false;
	}
	strncpy(name, ptr->h_name, namelen);
	return true;
}
int main(int argc,char* argv[]) {
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		return 1;
	}
	printf("도메인 이름(변환전)=%s\n", TESTNAME);
	
	struct in_addr addr;
	if (getipaddr(TESTNAME, &addr)) {
		char str[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &addr, str, sizeof(str));
		printf("IP주소(변환후)=%s\n", str);	
		char name[256];
		if (getdomainname(addr, name, sizeof(name))) {
			printf("도메인 이름(다시 변환후)=%s\n", name);
		}
	}
	WSACleanup();
	return 0;
	
}
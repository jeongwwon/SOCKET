#include "Common.h"

int main() {

	const char* ipv4test = "192.168.11.65";
	printf("ipv4 주소(변환전)=%s\n", ipv4test);

	struct in_addr ipv4num;
	inet_pton(AF_INET, ipv4test, &ipv4num);
	printf("ipv4 주소(변환후)=%#x\n", ipv4num.s_addr);

	char ipv4str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &ipv4num, ipv4str, sizeof(ipv4str));
	printf("Ipv4 주소(다시 변환후)=%s\n", ipv4str);
	printf("\n");

	const char* ipv6test = "fe80::a17a:53a3:1867:b49b";
	printf("ipv6 주소(변환전)=%s\n", ipv6test);

	struct in6_addr ipv6num;
	inet_pton(AF_INET6, ipv6test, &ipv6num);
	printf("ipv6 주소(변환후)=0x");
	for (int i = 0; i < 16; i++) {
		printf("%02x", ipv6num.s6_addr[i]);
	}
	printf("\n");

	char ipv6str[INET6_ADDRSTRLEN];
	inet_ntop(AF_INET6, &ipv6num, ipv6str, sizeof(ipv6str));
	printf("Ipv6 주소(변환후)=%s\n", ipv6str);
}
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


int merror(int redata, int error,char* showinfo) {
	if (redata == error) {
		perror(showinfo);
		getchar();
		return -1;
	}
	return 0;
}
void sendhtml(SOCKET s, char* filename);
int main() {
	printf("歡迎使用webser\n");
	WSADATA wsdata;
	int isok=WSAStartup(MAKEWORD(2,2),&wsdata);//確定socket版本
	//short 2 character 2.2
	char* str1 = (char*)"申請socket失敗";
	merror(isok, WSAEINVAL, str1);


	//第一個:協議族，決定socket地址類型
	//第二個:傳輸類型,SOC_STREAM傳輸
	//第三個:指定傳輸協議,tcp
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	char* str2 = (char*)"創建socket失敗";
	merror(server, INVALID_SOCKET, str2);

	struct sockaddr_in seraddr;
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(80);
	seraddr.sin_addr.s_addr = INADDR_ANY;//監聽任意地址


	isok=bind(server, (sockaddr*)&seraddr, sizeof(seraddr));
	char* str3 = (char*)"綁定失敗...\n";
	merror(isok, SOCKET_ERROR, str3);

	isok = listen(server, 5);
	char* str4 = (char*)"監聽失敗...\n";
	merror(isok, SOCKET_ERROR, str4);

	struct sockaddr_in claddr;
	int cllen = sizeof(claddr);
	while (1) {
		SOCKET client = accept(server, (sockaddr*)&claddr, &cllen);
		char* str5 = (char*)"連接失敗...\n";
		merror(client, INVALID_SOCKET, str5);


		char revdata[1024] = "";
		recv(client, revdata, 1024, 0);
		printf("%s 共接收到%d字節數據\n",revdata,strlen(revdata));

		char sendata[1024] = "<h1 style=\	color:red;\">你好，我成功了!</h1>";
		//send(client, sendata, strlen(sendata), 0);
		char *filename = (char*)"./index.html";
		sendhtml(client, filename);

		closesocket(client);
	}

	closesocket(server);
	WSACleanup();

	getchar();
	return 0;
}

void sendhtml(SOCKET s, char* filename) {
	FILE *pfile = fopen(filename,"r");
	if (pfile == NULL) {
		printf("開啟文件失敗\n");
		return;
	}
	char temp[1024] = "new";
	do {
		fgets(temp, 1024, pfile);
		send(s, temp, strlen(temp), 0);

	} while (!feof(pfile));
}
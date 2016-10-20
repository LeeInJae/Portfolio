#pragma comment(lib, "Ws2_32.lib")

#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

#define IP "127.0.0.1"
#define PORT 3000
#define MAX_DATA 1000

int main(int argc, char * argv[]){
	WSADATA wsaData;
	SOCKET clientSocket;
	SOCKADDR_IN serverAddr;
	int checkErr, recvCount;
	char sendBuf[MAX_DATA], sendBufSize = 0, recvBuf[MAX_DATA], recvBufSize = 0, sendCount = 0;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		perror("initiate winsock");
		return 0;
	}

	clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == SOCKET_ERROR){
		perror("initiate winsock");
		return 0;
	}

	serverAddr.sin_family = AF_INET; //���� ��û�� �� ������ �ּ�ü�� �ʱ�ȭ	
	inet_pton( AF_INET , IP , &(serverAddr.sin_addr) );//���� ��û�� �� ������ IP�ּ� �ʱ�ȭ

	//serverAddr.sin_addr.s_addr = inet_addr(IP);  //deprecated (������ ������ �Լ�)
	serverAddr.sin_port = htons(PORT); //���� ��û�� �� ������ ��Ʈ��ȣ �ʱ�ȭ

	checkErr = connect(clientSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr)); //�����û�� ������ �ּ������� ��� ����ü�� �̿��Ͽ� �����û
	if (checkErr == SOCKET_ERROR){ //�����û �õ��� �������� Ȯ��
		perror("socket");
		return 0;
	}

	while (1){
		fgets(sendBuf, MAX_DATA, stdin); //fgets�� ����, ������ ���� ���ڿ� �Է�
		sendBuf[strlen(sendBuf) - 1] = '\0'; //fgets�� ����Ű '\n' ���൵ �����ϹǷ� ���Ƿ� '\0'�� ä����
		
		if (strcmp(sendBuf, "Q") == 0) //Q�� �Է����� ������ ��� ����.
			break;

 		checkErr = send(clientSocket, sendBuf, strlen(sendBuf), 0); //client ���� ������ ������ �̿��Ͽ� ������ ���ڿ��� ����
		
		if (checkErr == -1){ //send�� ���� ���� Ȯ��
			perror("send");
			break;
		}
		
		memset(recvBuf,0,MAX_DATA); //�����κ��� ���� recvBuffer�� �ʱ�ȭ
		recvCount = 0;

		while (recvCount < strlen(sendBuf)){ //Ŭ���̾�Ʈ���� ���´� ��ŭ�� �����͸� �ޱ����� ���ǹ�
			recvBufSize = recv(clientSocket, &recvBuf[recvCount], 1, 0); //recv�� �̿��Ͽ� �����κ��� �����͸� 1����Ʈ�� ����,�׸��� ���������� recvBuf�� ����
			if (recvBufSize == SOCKET_ERROR){ //recv�� �������� Ȯ��
				perror("recv");
				break;
			}
			++recvCount; //�̺����� �̿��Ͽ� �����Ʈ�� �޾Ҵ��� Ȯ��.
		}
		printf("(client) �������� ���� ���ڿ� %s \n", recvBuf); //�����κ��� ���� ������ Ȯ��
	}

	closesocket(clientSocket);
	WSACleanup();
	getchar();
	return 0;
}
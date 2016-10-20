#pragma comment( lib , "Ws2_32.lib" )

#include <stdio.h>
#include <WinSock2.h>

#define PORT 3000 //server�� ����� ������ ��Ʈ ��ȣ�� ����
#define MAX_DATA 1000 //�ְ���� �� �ִ� �����͹����� �ִ� �뷮�� ���Ƿ� ����

int main(int argc, char * argv[]){
	WSADATA wsaData;  //������ ������ �ʱ�ȭ�� ���� ���ӵ����� ����ü ��������
	SOCKET serverSocket, acceptSocket; //�������� �ʿ��� ������ server ���ϰ� accept������ ����
	SOCKADDR_IN serverAddr, clientAddr; //������ �ּҿ�, �����͸� �ְ���� Ŭ���̾�Ʈ�� �ּ������� ������� ����ü ���� ���� ����
	int checkErr, sizeClientAddr; //error üũ�� ���� ������, client �ּ��� ũ�⸦ ������ ������ ����
	char recvBuf[MAX_DATA], recvBufSize, sendBuf[MAX_DATA], sendBufSize; //�����͸� �ְ���� �� ����� recvBuf,size, sendBuf,size�� ���� ����.

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){  //������ ������ ������ Ȯ���ϰ�, �ʱ�ȭ�ϴ� �۾�.
		perror("initiate winsock");
		return 0;
	}

	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//���������� ����(IPv4ü��, TCP���ϰ�, TCP��������) Ÿ��

	if (serverSocket == INVALID_SOCKET){ //������ ������ ���� Ȯ��
		perror("socket");
		return 0;
	}

	serverAddr.sin_family = AF_INET; //���Ͽ� �ּ�ü���� ����(IPv4 ���ͳ� �������� �ּ�ü��)
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); //IP�ּ� �ʱ�ȭ.
	serverAddr.sin_port = htons(PORT); //PORT �ʱ�ȭ

	checkErr = bind(serverSocket, (SOCKADDR *)&serverAddr, sizeof(serverAddr)); //�������Ͽ� �Ӽ��� �ش��ϴ� ������ �ּұ���ü�� �̿��Ͽ�, �Ҵ�����.

	if (checkErr == SOCKET_ERROR){ //bind�� �������� Ȯ��.
		perror("bind");
		return 0;
	}

	checkErr = listen(serverSocket, 1); //������ ť�� ũ�Ⱑ 1�� ���·�, �������Ͽ��� �����û�� ��ٸ�.
	if (checkErr == SOCKET_ERROR){ //listen�� �������� Ȯ��
		perror("listen");
		return 0;
	}

	sizeClientAddr = sizeof(clientAddr); //�����û�� ���� Ŭ���̾�Ʈ��  �ּ����� ũ�⸦ ���� ����
	acceptSocket = accept(serverSocket, (SOCKADDR *)&clientAddr, &sizeClientAddr); 
	//accept�� ���Ͽ� �����û�����¿� �ִ� Ŭ���̾�Ʈ�� ���� ��, accept������ ����

	if (acceptSocket == SOCKET_ERROR){//accept ������ �������� Ȯ��
 		perror("accept");
		return 0;
	}

	memset(recvBuf, 0, MAX_DATA); //recv�� buffer �ʱ�ȭ
	memset(sendBuf, 0, MAX_DATA); //send�� buffer �ʱ�ȭ
	while (recvBufSize = recv(acceptSocket, &recvBuf, sizeof(recvBuf), 0)){ //Ŭ���̾�Ʈ���� ���� �����͸� recv�� ���� recvBuf�� ����
 		if (recvBufSize == SOCKET_ERROR){ //recv�� ����� �ߴ��� �������� Ȯ��
			perror("recv");
			break;
		}

		strcpy_s(sendBuf,sizeof(recvBuf), recvBuf); //recvBuf�� ���� �����͸� �״�� send�ؾ��ϹǷ�, sendBuf�� ����
		checkErr = send(acceptSocket, sendBuf, strlen(sendBuf), 0);//����� Ŭ���̾�Ʈ������ ������ ����
		
		if (checkErr == -1){ //send�� ����� �ߴ��� �������� Ȯ��
			perror("send");
			break;
		}
	}

	closesocket(serverSocket); //���������� �Ҹ������
	closesocket(acceptSocket); //accept ������ �Ҹ������
	WSACleanup();//������ ���ϰ��� ���̺귯���� �ü���� ��ȯ
	getchar();
	return 0;
}
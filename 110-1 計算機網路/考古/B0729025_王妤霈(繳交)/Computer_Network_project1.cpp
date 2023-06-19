#include <winsock2.h>
#include <windows.h>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#include<fstream>
#include <string>
#include <ctime>
using namespace std;

char  host[500];
char othPath[800];
SOCKET sock;

//Only support the http protocol, resolve the host and IP address
bool analyUrl(char *url) {
	char *pos = strstr(url, "http://");
	if (pos == NULL)
		return false;
	else
		pos += 7;
	 sscanf(pos, "%[^/]%s", host, othPath); //The host name after http:// until / before
	cout << "host: " << host << "   repath:" << othPath << endl;
	return true;
}

//socket connect internet
void preConnect(){
	WSADATA wd;
	WSAStartup(MAKEWORD(2, 2), &wd);
    sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET){
		cout << "build socket failed! error code:" << WSAGetLastError() << endl;
		return;
	}
	sockaddr_in sa = { AF_INET };
	int n = bind(sock, (sockaddr*)&sa, sizeof(sa));
	if (n == SOCKET_ERROR){
		cout << "bind function failed! error code:" << WSAGetLastError() << endl;
		return;
	}
	struct hostent  *p = gethostbyname(host);
	if (p == NULL){
		cout << "can't identify IP! error code:" << WSAGetLastError() << endl;
		return;
	}
	sa.sin_port = htons(80);
	memcpy(&sa.sin_addr, p->h_addr, 4);
	n = connect(sock, (sockaddr*)&sa, sizeof(sa));
	if (n == SOCKET_ERROR){
		cout << "connect function failed! error code:" << WSAGetLastError() << endl;
		return;
	}
	//GET,download images 
	string  reqInfo = "GET " +(string)othPath+ " HTTP/1.1\r\nHost: " + (string)host + "\r\nConnection:Close\r\n\r\n";
	if (SOCKET_ERROR == send(sock, reqInfo.c_str(), reqInfo.size(), 0)){
		cout << "send error! error code:" << WSAGetLastError() << endl;
		closesocket(sock);
		return;
	}
}
//Name the picture and save it in the directory
void OutIamge(string imageUrl,int subLen,char dirName[10],int iname){
	CreateDirectoryA(dirName, 0);
	
    char str1[] = "./";
    char str2[] = "/";
    char str3[] = ".jpg";
    
    std::string tmp = std::to_string(iname);
    char const *num_char = tmp.c_str();
    

    int len = strlen(dirName) + 4;
    char concated[len];
    memset(concated, '\0', len);
    strcat(concated, str1);
    strcat(concated, dirName);
    strcat(concated, str2);
    strcat(concated, num_char);
    strcat(concated, str3);

	int n;
	char temp[800];
	strcpy(temp, imageUrl.c_str());
	analyUrl(temp);
	preConnect();
	string photoname;
	photoname.resize(imageUrl.size());
	int k = 0;
	for (int i = 0; i<imageUrl.length(); i++){
		char ch = imageUrl[i];
		if (ch != '\\'&&ch != '/'&&ch != ':'&&ch != '*'&&ch != '?'&&ch != '"'&&ch != '<'&&ch != '>'&&ch != '|')
			photoname[k++] = ch;
	}
	photoname = concated;
	fstream file;
	file.open(photoname, ios::out | ios::binary);
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	n = recv(sock, buf, sizeof(buf)-1, 0);
	char *cpos = strstr(buf, "\r\n\r\n");
 
	file.write(cpos + strlen("\r\n\r\n"), n - (cpos - buf) - strlen("\r\n\r\n"));
	while ((n = recv(sock, buf, sizeof(buf)-1, 0)) > 0){
		file.write(buf, n);
	}
	file.close();
}
int getHttp(string url,string body){
	//file
	ifstream inStream;
	ofstream outStream;
	outStream.open("html.txt"); 

	WSADATA wsaData;
	SOCKET Socket;
	SOCKADDR_IN SockAddr;
	int lineCount=0;
	int rowCount=0;
	struct hostent *host;
	locale local;
	char buffer[10000];
	int i = 0 ;
	int nDataLength;
	string website_HTML;

	//HTTP GET
	string get_http = "GET "+ body +" HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\n\r\n";

    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
        cout << "WSAStartup failed.\n";
        system("pause");
    }
    Socket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    host = gethostbyname(url.c_str());

    SockAddr.sin_port=htons(80);
    SockAddr.sin_family=AF_INET;
    SockAddr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

    if(connect(Socket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr)) != 0){
    	cout<<endl<<"information:"<<endl;
		cout<<"total files:0"<<endl;
		cout <<"download time:0"<<endl;
        cout << "state:Could not connect!url is invalid"<<endl;
        system("pause");
    }
    // send GET / HTTP
    send(Socket,get_http.c_str(), strlen(get_http.c_str()),0 );
    // recieve html
    while ((nDataLength = recv(Socket,buffer,10000,0)) > 0){ 
        int i = 0;
        while (buffer[i] >= 1 || buffer[i] == '\n' || buffer[i] == '\r'){
			outStream << buffer[i];
            website_HTML+=buffer[i];
            i += 1;
        }               
    }

    closesocket(Socket);
    WSACleanup();
    // Display HTML source 
    //cout<<website_HTML;
    outStream.close();
    closesocket(Socket);
        WSACleanup();
}
//how many lines in html.txt
int HowManyLines(){
	ifstream ifs;
	int i=0;
	char str[81];
	ifs.open("html.txt");
	
	while(ifs.getline(str,81)){	
		i++;
	} 
	ifs.close();
	return i;	
}
//how many lines in Newhtml.txt
int NewHowManyLines(){
	ifstream ifs;

	int i=0;
	char str[81];
	
	ifs.open("Newhtml.txt");
	
	while(ifs.getline(str,81)){	
		i++;
	} 
	ifs.close();
	return i;	
}
//save html
void saveHtml(char dirName[10]){
	char str1[] = "./";
    char str2[] = "/page.html";

    int len = strlen(dirName) + 4;
    char concated[len];
    memset(concated, '\0', len);

    strcat(concated, str1);
    strcat(concated, dirName);
    strcat(concated, str2);	
	
	int whichline=12,line=0;
	int Lines;
	
	Lines=NewHowManyLines();
	ifstream ifs;
	ofstream ofs;
	ifs.open("Newhtml.txt");
	ofs.open(concated);
	char ** array;
	array=new char *[Lines];
	
	for(int i=0;i<Lines;i++){
		array[i]=new char[81];
	}
	int i=0;
	while(true){
		ifs.getline(array[i],81);
		i++;
		if(i==Lines)
			break;
	}
	for(;;){
		if(whichline>=1&&whichline<=Lines){
			ofs << array[whichline-1] <<endl;
			whichline++;
			if(whichline==NewHowManyLines()+1)
				break;
			else continue;
		}
	}
	ifs.close();
	ofs.close();	
}

int main (){
	clock_t start, end;
//initialize url string	
	char url[50];
	for(int i=0;i<50;i++){
		url[i]=' ';
	}
//check url
	int urlLen;
	int check;
	while(check==0){
		urlLen=0;
		check=0;
		for(int i=0;i<50;i++){
			url[i]='~';
		}
		cout<<"Please input a url(ex:http://163.25.101.182/CN/test2.html):"<<endl;
		cin.getline(url,50);
		for(int j=0;j<50;j++){
			//cout<<"url:"<<url[j]<<" ";
			if(url[j]!='~'){
				urlLen+=1;
			}
		}
		urlLen-=1;
		for(int i=0;i<urlLen;i++){
			if(url[i]==' '){
				check=1;
				cout<<"url can not include space!"<<endl;
			}
		}
		if(check==1){
			check=0;
			continue;
		}
		if((url[0]!='h')||(url[1]!='t')||(url[2]!='t')||(url[3]!='p')||(url[4]!=':')||(url[5]!='/')||(url[6]!='/')){
			cout<<"URL format ERROR!!!"<<endl;
			continue;
		}
		else 
			break;
	}
//input output dirname
	char dirName[10];
	cout<<"please input destination dir name:"<<endl;
	cin>>dirName;
	cout<<endl;
	//url
	//int urlLen=0;
	for(int i=0;i<50;i++){
		if((url[0]!='h')||(url[1]!='t')||(url[2]!='t')||(url[3]!='p')||(url[4]!=':')||(url[5]!='/')||(url[6]!='/'))
		cout<<url[i];
	}
	cout<<endl;
	int count=0;
	int hosti=0;
	for(int i=0;i<50;i++){
		if(url[i]!=' ')
			//urlLen+=1;
		if((url[i]=='h')&&(url[i+1]=='t')&&(url[i+2]=='t')&&(url[i+3]=='p')&&(url[i+4]==':')&&(url[i+5]=='/')&&(url[i+6]=='/')){
			hosti=i+7;
		}
		else 
			continue;
	}
	//urlLen=urlLen-1;
	//host
	int hostLen=0;
	for(int i=hosti;i<30;i++){
		if(url[i] != '/')
			hostLen+=1;
		else if(url[i] == '/')
			break;
	}
	
	char hostArr[hostLen];
	for(int i=0;i<hostLen;i++){
		hostArr[i]=url[hosti];
		hosti+=1;
	}
	//request url
	int headLen=hosti;

	int requestLen=urlLen-headLen;
	char requestArr[requestLen];
	for(int i=0;i<requestLen;i++){
		requestArr[i]=url[headLen];
		headLen+=1;
	}	
	//save string
	string host=hostArr;
	string body=requestArr;
	//host end
	start = clock();
	getHttp(host,body);
//save html.txt to charArr 
	ifstream inStream;
	inStream.open("html.txt");
	char ch;	
	int state=5;
	//2D array
	int row=HowManyLines();
	int col=150;
	char chArr[row][col];
	int tempj;
	//initialize charArr
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			chArr[i][j]=' ';
		}
	}
	int tempj_1=0;
	int tempj_2=0;	
	//將檔案存入二維陣列 
	while(true){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){ 
				inStream.get(ch);
				chArr[i][j]=ch;
				if(chArr[i][j]=='\n')///
					break;
				if((chArr[i][j]=='>')&&(chArr[i][j-1]=='>')){
					tempj_1=j-1;
					tempj_2=j;
					break;
				}
			}
			if((chArr[i][tempj_1]=='>')&&(chArr[i][tempj_2]=='>')){
				chArr[i][tempj_2]=' ';
				break;
			}
		}
		break;
	}
	if((chArr[0][9]=='2')&&(chArr[0][10]=='0')&&(chArr[0][11]=='0'))
		state=1;
	else state=0;
	
	if(state==0){
		cout<<endl<<"information:"<<endl;
		cout<<"total files:0"<<endl;
		cout <<"download time:0"<<endl;
		cout<<"state:url is invalid"<<endl;
	}
	inStream.close();

//function saveImageSrc
	int irow=10;
	int icol=50;
	char imgArr[irow][icol];//url of all images
	//initialize imgArr 
	for(int i=0;i<irow;i++){
		for(int j=0;j<icol;j++){
			imgArr[i][j]=' ';
		}
	}
	//存網址到陣列 
	int imgNum=0;
	int imgi=0,imgj=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if((chArr[i][j]=='<')&&(chArr[i][j+1]=='i')&&(chArr[i][j+2]=='m')&&(chArr[i][j+3]=='g')&&(chArr[i][j+4]==' ')&&(chArr[i][j+5]=='s')&&(chArr[i][j+6]=='r')&&(chArr[i][j+7]=='c')&&(chArr[i][j+8]==' ')&&(chArr[i][j+9]=='=')&&(chArr[i][j+10]==' ')&&(chArr[i][j+11]=='"')){	
				imgi=i;
				imgj=j+12;
				//
				for(int l=0;l<icol;l++){
					if((chArr[imgi][imgj]=='"')&&(chArr[imgi][imgj+1]=='/')&&(chArr[imgi][imgj+2]=='>'))
						break;
					imgArr[imgNum][l]=chArr[imgi][imgj];
					imgj+=1;
				}
				imgNum+=1;
			}
		}
	}
	//download images
	int imgNameLen=0;
	for(int i=0;i<imgNum;i++){
		imgNameLen=0;
		string imageUrl=" ";
		for(int j=0;j<icol;j++){
			imageUrl=imageUrl+imgArr[i][j];
		}
		OutIamge(imageUrl,hosti-2,dirName,i);
	}
//creat new html
	//save html to array
	char t='0';
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			//cout<<chArr[i][j];
			if((chArr[i][j]=='<')&&(chArr[i][j+1]=='i')&&(chArr[i][j+2]=='m')&&(chArr[i][j+3]=='g')){
				//clear this row
				for(int c=14;c<col;c++){
					chArr[i][c]=' ';
				}
				//write new local img src
				chArr[i][15]='.';chArr[i][16]='/';chArr[i][17]=t;chArr[i][18]='.';chArr[i][19]='j';chArr[i][20]='p';chArr[i][21]='g';
				chArr[i][22]='"';chArr[i][23]='/';chArr[i][24]='>';
				t=t+1;
			}
		}
	}
	//output array to newHtml.txt
	ofstream outStream;
	outStream.open("Newhtml.txt");
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			outStream<<chArr[i][j];
			if((chArr[i][j]==' ')&&(chArr[i][j+1]==' ')&&(chArr[i][j+2]==' '))
				break;	
			else if((chArr[i][j-3]=='g')&&(chArr[i][j-2]=='"')&&(chArr[i][j-1]=='/')&&(chArr[i][j]=='>'))
				outStream<<endl;
			else continue;			
		}
	}
	saveHtml(dirName);
	end = clock();
	double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	//information
	int fileNum=imgNum+1;
	cout<<endl<<"information:"<<endl;
	cout<<"total files:"<<fileNum<<endl;
	cout <<"download time:"<<time_used<<endl;
	if(state==0)
		cout<<"state:url is invalid"<<endl;
	else if(state==1)
		cout<<"state:url is valid"<<endl;	
}

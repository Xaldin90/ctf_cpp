//============================================================================
// Name        : abc.cpp
// Author      : flo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <openssl/md5.h>
#include <algorithm>

#include "base64.h"

using namespace std;


void spawn_shell() {
    printf("Welcome to my Castle!\n");
    gid_t gid;
    uid_t uid;
    gid = getegid();
    uid = geteuid();
    setresgid(gid, gid, gid);
    setresuid(uid, uid, uid);
    system("/bin/sh");
}




int main() {

	char pw[12];

	char checkpw[] = "hello world";

	printf("enter Password: ");
	fgets(pw,12,stdin);

	int inputLen = sizeof(checkpw);


	int encodedLength = Base64::EncodedLength(checkpw);
	char encodedPw[encodedLength];
	Base64::Encode(checkpw, inputLen-1, encodedPw, encodedLength);

	printf(encodedPw);
	printf("\n");


	string revPw = string(encodedPw);

	revPw.pop_back();
	reverse(revPw.begin(),revPw.end());

	cout<<(revPw);
	printf("\n");



	 unsigned char digest[MD5_DIGEST_LENGTH];

	 MD5((unsigned char*)&revPw, revPw.length(), (unsigned char*)&digest);



	 char mdString[33];

	 for(int i = 0; i < 16; i++)
	      sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

	 printf("md5 digest: %s\n", mdString);




//	if(strcmp (pw,checkpw) == 0){
//		printf("richtig\n");
//		spawn_shell();
//	}else{
//		printf("falsch\n");
//	}

	return 0;
}

//int main() {
//
//	char pw[12];
//
//	printf("enter Password: ");
//	fgets(pw,12,stdin);
//
//
//
//	//-----------------------------------------------------------------
//
//	unsigned char digest[MD5_DIGEST_LENGTH];
//    char string[] = "hello world";
//
//    MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest);
//
//    char mdString[33];
//
//    for(int i = 0; i < 16; i++)
//         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
//
//    printf("md5 digest: %s\n", mdString);
//
//    return 0;
//}



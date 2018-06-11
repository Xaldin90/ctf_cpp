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

	char checkpw[12] = "hello world";

	printf("enter Password: ");
	fgets(pw,12,stdin);

	int inputLen = sizeof(checkpw);

	//Base64 bla = new Base64();
	int encodedLength = Base64::EncodedLength(checkpw);
	char encodedPw[encodedLength];
	Base64::Encode(checkpw, inputLen, encodedPw, encodedLength);

	 printf(encodedPw);


	if(strcmp (pw,checkpw) == 0){
		printf("richtig\n");
		spawn_shell();
	}else{
		printf("falsch\n");
	}

	return 0;
}



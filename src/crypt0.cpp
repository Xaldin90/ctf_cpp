
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>
#include <openssl/evp.h>
#include <algorithm>
#include <sstream>

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


string encrypt(char* x){

	string y = string(x);

	y.pop_back();
	reverse(y.begin(),y.end());

	return y;
}

string super_secret_encryption(string x){

	string b;
	std:stringstream s;
	for(int i = 0; i < x.length();i++){

		int y = static_cast<int>(x[i]);
		s << hex << y;

	}
	b = s.str();
	return b;
}

int main() {

	char enteredPw[20];
	char pw[12];
	char checkpwArray[34];
	FILE * fp = fopen("/home/flag/comparePw", "r");
	fgets(checkpwArray,34,fp);
	string checkpw = string(checkpwArray);
	//string checkpw = "3d4544546d687a645452474e744a4453";
	printf("Enter Password: ");
	fgets(enteredPw,20,stdin);

	int i = 0;
	for(; enteredPw[i] != '\0';i++);
	if(i >= 13){
			printf("Wrong PW!!!\n");
			return 0;
		}else{
			for(int x = 0; x <=12; x++){pw[x] = enteredPw[x];}
		}


	int encodedLength = Base64::EncodedLength(pw);
	char encodedPw[encodedLength];
	int inputLen = sizeof(pw);
	Base64::Encode(pw, inputLen-1, encodedPw, encodedLength);
	string b = super_secret_encryption(encrypt(encodedPw));


	if(b.compare(checkpw) == 0){
		printf("Correct PW!\n");
		spawn_shell();
	}else{
		printf("Wrong PW!\n");
	}

	return 0;
}

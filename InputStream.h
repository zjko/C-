#ifndef __INPUTSTREAM_H__
#define __INPUTSTREAM_H__
#include "Error.h"
struct InputStream{
	FILE * fp = NULL;
	
	int readFile(char * path) {
		
		fp = fopen(path,"r");
		if(fp == NULL)
	//	error(ERR_FILE_READ_FAILED);
		
		puts("�ļ���ȡ�ɹ�");
	};
	
	int closeFile(){
		fclose(fp);
		puts("�ļ��رճɹ�");
	};
	
//	int inputCode(char *str){
//	
//	};
//	
	char next(){
		char c;
		if(fp==NULL)puts("��δ���ļ�");
		return fgetc(fp);

	};
	
}InputStream;

#endif

#include<stdio.h>

#ifndef __ERROR_H__
#define __ERROR_H__

#define ERR_FILE_READ_FAILED  0x01000001
#define ERR_LLLEGAL_CHAR			0x01000002
#define ERR_STR_FAIL					0x01000003
/*
�������һλ����
�ڶ�λΪ1���� Analyzer������  2������
*/

////////
struct Error {
	int No(const int err){
		
		switch(err){
			case 0										:	return 0;
			
			case ERR_FILE_READ_FAILED :	puts("�ļ���ȡʧ��")	;
																	return 0;
			case ERR_LLLEGAL_CHAR			: puts("�ʷ�������������⵽�Ƿ��ַ�") ;
																	return 0;
			case ERR_STR_FAIL					:	puts("�Ƿ��ַ�");														
																																
		}
	
	};
	
}Error;

#endif

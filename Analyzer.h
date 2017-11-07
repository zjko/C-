#include"Error.h"
#include"RFA.h"
struct Analyzer{
	
	int readFile(char * path) {
		FILE * fp = NULL;
		fp = fopen(path,"r");
		if(fp == NULL)
//		error(ERR_FILE_READ_FAILED);
		
		while (feof(fp) == NULL)analyzer(fgetc(fp));
		fclose(fp);
	};
	
	int inputCode(char *str){
		while(*str){
			Analyzer(*str);
			str++;
		}
	};
	
	int analyzer(char c){
//		putchar(c);
		RFA.Model(classification(c)) ;
	};
	
	int classification(char c) {
		if( c== '#')return 1;//��һ�� ָ����
		if( c>='A'&&c<='Z' || c>='a'&&c<='z'||c == '_') return 2;//�ڶ��� ��ĸ�� 
		if( c>='0'&&c<='9')return 3;	//������ ������
		switch(c){	//ʹ��switch����ͨ���������Ż� ��������ٶ� 
			case '+':case '-':case '*':case '/':case '%':
			case '&':case '|':case '!':case '^':case '~':
			case '<':case '>':case '=':
			case '?':case ':':
			case ',':case '(':case ')':case '[':case ']':
			return 4;			//	����������� 
			case '\'':case '\"':
			return 5;	// ������ �ַ� �ַ��� ���� ��ʶ��
			case ';':	return 6;	//	������ �������� 
			default:    ;
//			error(0);  puts("�Ƿ�����");
			/* WAR ��δ���   */
		}
	}; 
	
}Analyzer;

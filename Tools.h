#ifndef __TOOLS_H__
#define __TOOLS_H__

#include<string.h>
struct Tools{

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
			case ';':	
			return 6;	//	������ �������� 
			case '{':case '}':
			return 7; 
			default:    ;
//			error(0);  puts("�Ƿ�����");
			/* WAR ��δ���   */
		}
	}; 
	
	int lookupStr(const char **str1,const char *str2){
		for(int i=0;str1[i];i++){
			if(strcmp(str1[i],str2)==0)return 1;
		}
		return 0;
	}
	
	
	}Tools; 
	
	#endif

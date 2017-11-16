#ifndef __RFA_H__
#define __RFA_H__

#include "Keyword.h"
#include "Error.h"
#include "Tools.h"
#include "InputStream.h"

#define BUFFERSIZE	512
struct RFA{
	char Buffer[BUFFERSIZE];		//�������� 
	int Model (char first){
		char c;
		int i;
		clean();
		switch(Tools.classification(first)){
			case 1://��һ�� ������
				for(i=0;(c=InputStream.next())!=EOF&&1<BUFFERSIZE;i++){
						if(Tools.classification(c)!=2&&Tools.classification(c)!=3)break;
						Buffer[i]=c;
						//ֻ�����ַ������� 
					}
					if(Tools.lookupStr(KeyWord.instructions,Buffer)){
						printf("�ؼ��֣�%s ����1\n",Buffer);
						clean();	
					}else {
						printf("%s",Buffer) ;
						Error.No(ERR_STR_FAIL);
					} 
					
					return 1;
					
			
			case 2://�ڶ��� ��ĸ��
			i = 0;
			Buffer[i++]=first;
			while((c=InputStream.next())!=EOF&&i<BUFFERSIZE){
						if(Tools.classification(c)!=2&&Tools.classification(c)!=3)break;
						Buffer[i++]=c;
						//ֻ�����ַ������� 
					}
					if(Tools.lookupStr(KeyWord.datatype,Buffer)){
						printf("�ؼ��֣�%s ����2\n",Buffer);
						clean();
					}else{
						printf("��ʶ����%s ����3\n",Buffer);
						
					}
					return 1;
			
			case 3://������ ������ 
			i = 0;
			Buffer[i++]=first;
			while((c=InputStream.next())!=EOF&&i<BUFFERSIZE){
						if(Tools.classification(c)!=2&&Tools.classification(c)!=3)break;
						Buffer[i++]=c;
						//ֻ�����ַ������� 
			}
//			if(checkNum(Buffer))			 ûд
			 if(Buffer[0]=='0')
			 		if(Buffer[1]=='x'||Buffer[1]=='X')printf("���ֳ��� ʮ�����ƣ�%s\n",Buffer) ;
					else printf("���ֳ��� �˽��ƣ�%s\n",Buffer);
				else printf("���ֳ��� ʮ���ƣ�%s\n",Buffer);
				clean();
				return 1;
			
			case 4://������ ������ 
				printf("�������%c \n",first) ;
				clean();
				return 1;
			case 5://������ �ַ����������� 
			
				
				i=0;
				while((c=InputStream.next())!=EOF&&i<BUFFERSIZE){
					if(c=='\"')break;
					Buffer[i++]=c;
				}
				printf("�ַ���������%s\n",Buffer);
				
				return 1;
			
			case 6://������ ���ֺŽ����� 
			
			clean();
			return 1;
			
			
			case 7:
//				printf("��� ��%c\n",first);
//				clean();
				return 1;
			default : 
			printf("%c �޷�ʶ��") ;
			Error.No(ERR_LLLEGAL_CHAR) ;
			
			
			; 
		}
	};
	
	
	
	int clean(){
		for(int i=0;Buffer[i];i++)Buffer[i]=0;
	}
	

}RFA;



#endif

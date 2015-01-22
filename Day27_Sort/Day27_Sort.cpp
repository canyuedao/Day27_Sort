// Day27_Sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
struct A{
	
	char c;
	int i;
	short s;
	char *cstr;
	char *str;

	A(char c1=0,int i1=0,short s1=0,char* pC1=0,char* pC2=0):cstr(pC1),str(pC2){
		c=c1;i=i1,s=s1;
	}
	void print(){
		printf("%c %d %d %s %s\n",c,i,s,cstr,str);
	}
};
void sort(A* pa,int iLen,int offset,bool border=true){		
	
	if(border){
		for(int j=0;j<iLen;j++){
			A *min=&pa[j];
			int iindex=j;	
			int cLen=strlen((const char*)(*(int*)((int)&pa[j]+offset)));
			//int cLen=strlen(pa[j].cstr);
			//int temp=sizeof(A)-cLen-offset;
			if(offset>=12){
				for(int i=j+1;i<iLen;i++){
					int temoff=0;
					while(temoff<cLen){
						if(*(char*)(*(int*)((int)&pa[i]+offset)+temoff)<*(char*)(*(int*)((int)min+offset)+temoff)){
							min=&pa[i];
							iindex=i;
							break;
						}
						else if(*(char*)(*(int*)((int)&pa[i]+offset)+temoff)==*(char*)(*(int*)((int)min+offset)+temoff)){
							temoff++;
						}
						else
							break;
					}
				
				}	
				A temp;
				temp=*min;
				pa[iindex]=pa[j];
				pa[j]=temp;
			}
			else{
				for(int i=j+1;i<iLen;i++){
					if(*(int*)((int)&pa[i]+offset)<*(int*)((int)min+offset)){
						min=&pa[i];
						iindex=i;
					}
				}	
				A temp;
				temp=*min;
				pa[iindex]=pa[j];
				pa[j]=temp;
			}
					
		}	
	}	
	else{
			for(int j=0;j<iLen;j++){
				A *max=&pa[j];
				int iindex=j;	
				int cLen=strlen((const char*)(*(int*)((int)&pa[j]+offset)));
				
				int temp=sizeof(A)-cLen-offset;
				if(offset>=12){
					for(int i=j+1;i<iLen;i++){
						int temoff=0;
						while(temoff<cLen){
							if(*(char*)(*(int*)((int)&pa[i]+offset)+temoff)>*(char*)(*(int*)((int)max+offset)+temoff)){
								max=&pa[i];
								iindex=i;
								break;
							}
							else if(*(char*)(*(int*)((int)&pa[i]+offset)+temoff)==*(char*)(*(int*)((int)max+offset)+temoff)){
								temoff++;
							}
							else
								break;
						}
				
					}	
					A temp;
					temp=*max;
					pa[iindex]=pa[j];
					pa[j]=temp;
				}
				else{
					for(int i=j+1;i<iLen;i++){
						if(*(int*)((int)&pa[i]+offset)>*(int*)((int)max+offset)){
							max=&pa[i];
							iindex=i;
						}
					}	
					A temp;
					temp=*max;
					pa[iindex]=pa[j];
					pa[j]=temp;
				}
					
			}	
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	/*A aarray[6];
	aarray[0].c='a';aarray[0].i=30;aarray[0].s=20,aarray[0].cstr="丁程",aarray[0].str="张三";
	aarray[1].c='b';aarray[1].i=20;aarray[1].s=10,aarray[1].cstr="陈新",aarray[1].str="李四";
	aarray[2].c='c';aarray[2].i=10;aarray[2].s=30,aarray[2].cstr="丁程程",aarray[2].str="王五";
	aarray[3].c='c';aarray[3].i=10;aarray[3].s=30,aarray[3].cstr="丁程波",aarray[3].str="王三";
	aarray[4].c='c';aarray[4].i=10;aarray[4].s=30,aarray[4].cstr="丁波程",aarray[4].str="张思";
	aarray[5].c='c';aarray[5].i=10;aarray[5].s=30,aarray[5].cstr="何海洋",aarray[5].str="陈新";*/
	
	//sort(aarray,6,(int)&(((A*)0)->str),1);
	
	//for(int i=0;i<6;i++){
	//	printf("%c %d %d %s %s\n",aarray[i].c,aarray[i].i,aarray[i].s,aarray[i].cstr,aarray[i].str);
	//}
	A *pA=new A[6];
	pA[0]=A('a',30,20,"丁程","张三");
	pA[1]=A('b',20,10,"陈新","李四");
	pA[2]=A('c',10,30,"丁程程","王五");
	pA[3]=A('a',30,20,"丁程波","王三");
	pA[4]=A('a',30,20,"丁波程","张思");
	pA[5]=A('a',30,20,"何海洋","陈新");
	sort(pA,6,(int)&(((A*)0)->cstr),1);
	//for(int i=0;i<6;i++){
	//	printf("%c %d %d %s %s\n",pA[i].c,pA[i].i,pA[i].s,pA[i].cstr,pA[i].str);
	//}
	for(int i=0;i<6;i++){
		pA[i].print();
	}
	return 0;
}


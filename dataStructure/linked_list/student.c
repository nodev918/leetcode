/* 一個以Linked list方式，儲存學生期末考成績的資料:
	具有下述功能:
		1.儲存單筆時會自動排序
		2.可以新增,顯示,修改,刪除及學生的成績
		3.資料格式為  |學生名稱|期末考成績|
		4.可輸出及讀入資料，資料格式為.bin
*/ 

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void add(void);//新增的涵式
void insert(void);//插入的函式
void delet(void);//刪除的涵式
void read(void);//讀檔的涵式
void write(void);//存檔的涵式
void display(void);//顯示的涵式
void modify(void);//修正成績的涵式
void introdu(void);//介紹功能

int set = 0;//鏈結串列總數

struct student{
	char name[20];
	int score;
	struct student *next;
};
struct student  *current, *inser, *previous;
//inser是要插入進去鏈結中的資料，previous是指向當前所參照的前一個鏈結處
struct student *head = (struct student *)malloc(sizeof(struct student));//宣告head
//head是第一個標頭，current是當前所參照的鏈結處


int main() 
{
	char key;
	introdu();//介紹功能
	printf("是否需要讀取已儲存資料:(Y/N)");
	scanf_s("%c", &key);
	if (key == 'Y' || key == 'y') {
		read();
	}
	while (1) {//具有表單讓使用者選擇功能
		printf("\n Please enter your choose:");
		scanf_s("\n%c",&key); //輸入選擇且避免前次輸入score時的\n導致影響此次輸入。
		switch (key) {
			case '1'://Inset the new student score
				add();
				set++;//紀錄linked list total numbers
				break;
			case '2'://2.Delete the student score
				delet();//由於不確定是否使用者輸入正確要刪除名稱，因此得看情況更新total numbers
				break;
			case '3'://3.Display all student scores
				display();
				break;
			case '4'://4.Modify the student score
				modify();
				break;
			case '5'://5.Save the data
				write();
				break;
			case '6'://6.Exit
				return 0;
				break;
			default://Error
				printf("Please enter the corrent key!\n");
				break;
		}
	}

}

void add(void) {//新增的涵式
	int score;
	inser = (struct student *) malloc(sizeof(struct student));
	//輸入學生姓名及成績
	printf("請輸入學生姓名:");
	scanf_s("%s",inser->name);
	printf("請輸入學生期末考成績:");
	scanf_s("%d", &score);
	inser->score = score;
	if (set == 0) {
		head->next = inser;//將head的next指向inser的位址
		printf("student name :%s  score:%d",inser->name, inser->score);
	}else insert();//插入
}
void insert(void) {//插入的函式
	int i = 0;
	previous = head;
	current = previous->next;
	while (current != NULL) {
		if (current->score != NULL) {
			if (current->score > inser->score) {
				previous = current; //紀錄原本的當前連結位置
				current = current->next; //依照當前鏈結往後尋找下一個鏈結
			}else if(i >= set) {
				break;
			}
			i++;
		}
		else break;
	}
	previous->next = inser;//將previous的next指向inser的位址
	inser->next = current;//然後將inser的next指向current的位址
}
void delet(){//刪除的涵式
	char delet_name[20] = {};
	bool exist = false;
	printf("請輸入欲刪除的學生姓名:");
	scanf_s("\n%s",delet_name);//輸入欲刪除學生姓名並避免前次輸入的\n影響輸入。
	previous = head;
	current = previous->next;
	for(int i = 0;i<set;i++){
		if (strcmp(delet_name, current->name) ==0) { //成功找到需要刪除的串列
			//strcmp(const char*, const char*) 若兩個字串相符，回傳0
			previous->next = current->next;
			free(current);//釋放掉刪除的串列
			exist = true; 
			printf("\n已找到學生資料並刪除\n");
			break;
		}
		previous = current;
		current = current->next;
		
	}
	if(exist)set--;//若成功找到相同學生名字，則此鏈結串列總數減一
	else printf("\n並未找到此學生資料，無法刪除\n");
}
void read(){//讀檔的涵式
	
	previous = head;
	char name[20];
	int score=0;
	FILE *fp;
	if ((fp = fopen("final test.bin", "rb")) != NULL) {
		while (fscanf(fp, "%s %d\n", name, &score) != EOF) {
			inser = (struct student*)malloc(sizeof(struct student));
			strcpy(inser->name, name);
			inser->score = score;
			if (set == 0) {
				head->next = inser;
				current = inser;
			}
			else {
				current->next = inser;
				current = inser;
			}
			set++;
		}
	}
	fclose(fp);
}
void write() {//存檔的涵式
	previous = head; 
	current = previous->next;
	FILE *fp;
	errno_t err;
	err= fopen_s(&fp,"final test.bin", "wb+");
	for (int i = 0; i < set;i++) {
		//_itoa_s(current->score,str_score,10); //將數字轉為字串
		fprintf(fp,"%s %d\n",current->name,current->score);//將資料存入檔案中
		current = current->next;
	}
	fclose(fp);
}
void display() {//顯示的涵式
	previous = head;
	current = head->next;
	printf("-----------------------------------\n");
	printf("  NAME                     SCORE  \n");
	printf("-----------------------------------\n");
	for(int i = 0 ; i < set;i++){
		printf("%-20s      %3d\n",current->name, current->score);
		current = current->next;
	}
	
}
void modify(){//修正成績的涵式
	char modify_name[20] = {};
	bool exist = false;
	int score=0;
	printf("請輸入欲修正成績的學生姓名:");
	scanf_s("\n%s", modify_name);//輸入輸入欲修正成績的學生姓名
	previous = head;
	current = previous->next;
	for (int i = 0; i < set; i++) {
		if (strcmp(modify_name, current->name) == 0) { //成功找到需要欲修正成績的串列
			//strcmp(const char*, const char*) 若兩個字串相符，回傳0
			printf("學生姓名:%-20s    期末考成績:%d分\n", current->name, current->score);
			printf("請輸入修正的成績:");
			scanf_s("%d", &score);
			current->score = score;
			exist = true;
			break;
			
		}
		previous = current;
		current = current->next;
	}
	if (exist==false)printf("\n並未找到此學生資料，無法修正\n");
}
void introdu() {//介紹功能
	printf("The program can save the student final exam scores. \n");
	printf("You can enter the number which choose the function:\n");
	printf("---------------------------------------\n");
	printf("    1.Inset the new student score \n");
	printf("    2.Delete the student score \n");
	printf("    3.Display all student scores \n");
	printf("    4.Modify the student score \n");
	printf("    5.Save the data\n");
	printf("    6.Exit\n");
	printf("---------------------------------------\n");
}

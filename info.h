#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define USR_NAME_LEN 20
#define USR_PWD_LEN 20

//�˻�struct
typedef struct usr_account_tag{
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	int usr_role;													//Ϊ0��������ԱȨ�ޣ�Ϊ1�������ͨѧ��Ȩ��
	struct usr_account_tag *pNext_Usr_Account;
}USR_ACCOUNT, *pUSR_ACCOUNT;

//ѧ����Ϣstruct
typedef struct usr_infor_tag
{
	int usr_id;
	char usr_name[USR_NAME_LEN];
	int usr_course_id;
	int usr_course_score;
	struct usr_infor_tag *pNext_Usr_Infor;
}USR_INFOR, *pUSR_INFOR;

//ͷ�巨�����˻���Ϣ
void listHeadInsert();

//ͷ�巨����ѧ����Ϣ
void listHeadInsert_infor();

//��ӡ�˻��ڵ���Ϣ
void listPrint();

//��ӡѧ���ڵ���Ϣ
void listPrint1();

//�Ա��û���������
int compare_name_pwd();

//����ѧ����Ϣ
void update_stu_infor();

//ɾ��ѧ����Ϣ
void delete_stu_infor();

//����ѧ����Ϣ
void search_Student_Infor();

//�жϵ�¼�û��Ľ�ɫ
int compare_role();

//����ѧ����Ϣ����
void update_Student_Infor();

//ɾ��ѧ����Ϣ����
void delete_Student_Infor();

//�����û��˻�����
void add_User_Account();

//�����û��˻�����
void update_User_Account();

//ɾ���û��˻�����
void delete_User_Account();

//����ѧ���˻�
void search_User_Account();

//��ѧ����Ϣ���˺���Ϣ���浽�ļ���ȥ
void save_data_to_file_account();
//��ѧ����Ϣ���浽�ļ���ȥ
void save_data_to_file_stu();
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define USR_NAME_LEN 20
#define USR_PWD_LEN 20

//账户struct
typedef struct usr_account_tag{
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	int usr_role;													//为0则代表管理员权限，为1则代表普通学生权限
	struct usr_account_tag *pNext_Usr_Account;
}USR_ACCOUNT, *pUSR_ACCOUNT;

//学生信息struct
typedef struct usr_infor_tag
{
	int usr_id;
	char usr_name[USR_NAME_LEN];
	int usr_course_id;
	int usr_course_score;
	struct usr_infor_tag *pNext_Usr_Infor;
}USR_INFOR, *pUSR_INFOR;

//头插法插入账户信息
void listHeadInsert();

//头插法插入学生信息
void listHeadInsert_infor();

//打印账户节点信息
void listPrint();

//打印学生节点信息
void listPrint1();

//对比用户名和密码
int compare_name_pwd();

//更新学生信息
void update_stu_infor();

//删除学生信息
void delete_stu_infor();

//搜索学生信息
void search_Student_Infor();

//判断登录用户的角色
int compare_role();

//更新学生信息功能
void update_Student_Infor();

//删除学生信息功能
void delete_Student_Infor();

//增加用户账户功能
void add_User_Account();

//更新用户账户功能
void update_User_Account();

//删除用户账户功能
void delete_User_Account();

//搜索学生账户
void search_User_Account();

//将学生信息和账号信息保存到文件里去
void save_data_to_file_account();
//将学生信息保存到文件中去
void save_data_to_file_stu();
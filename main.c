#include "info.h"

//共有2个txt文件，usr_account.txt存放用户账户信息，usr_infor.txt存放学生信息

int main(){

	//账户信息初始化部分，将数据从磁盘读入程序中的链表中
	FILE *fp;
	fp = fopen("usr_account.txt", "r+");
	if (fp == NULL){
		perror("fopen");
		goto error;
	}

	pUSR_ACCOUNT pHead = NULL;
	pUSR_ACCOUNT pTail = NULL;

	char usr_name[20];
	char usr_pwd[20];
	int usr_role;

	while (fscanf(fp, "%s%s%d", usr_name, usr_pwd,&usr_role) != EOF){
		listHeadInsert(&pHead, &pTail, usr_name, usr_pwd, usr_role);
	}

	//listPrint(pHead);				//可调试断点
	fclose(fp);
	
	//学生初始化部分，将数据从磁盘读入程序中的链表中-stu
	FILE *fp1;
	fp1 = fopen("usr_infor.txt", "r+");
	if (fp1 == NULL){
		perror("fopen");
		goto error;
	}

	pUSR_INFOR pHead1 = NULL;
	pUSR_INFOR pTail1 = NULL;

	int usr_id1;
	char usr_name1[20];
	int usr_course_id1;
	int usr_course_score1;

	while (fscanf(fp1,"%d%s%d%d",&usr_id1,usr_name1,&usr_course_id1,&usr_course_score1)!= EOF){
		listHeadInsert_infor(&pHead1, &pTail1, usr_id1, usr_name1, usr_course_id1, usr_course_score1);
	}

	//listPrint1(pHead1);         //可调试断点
	fclose(fp1);


	//登录部分
	int flag_pwd = 0;													//flag_pwd为0代表密码错误，为1代表密码正确，可以进入系统
	int flag_row = 0;													//flag_row代表用户角色，为0代表管理员用户，为1代表普通用户

login:

	printf("请输入您的用户名：");
	char usr_insert_name[20];
	char usr_insert_pwd[20];

	scanf("%s",usr_insert_name);
	printf("请输入密码：");
	for (int i = 0; i < 20; i++){
		usr_insert_pwd[i] = getch();
		if (usr_insert_pwd[i] == '\r'){
			usr_insert_pwd[i] = '\0';
			break;
		}
		if (usr_insert_pwd[i] == '\b'){
			usr_insert_pwd[i] = '\0';
			usr_insert_pwd[i - 1] = '\0';
			printf("\b");
			printf(" ");
			printf("\b");
			i=i-2;
			continue;
		}
		else{
			printf("*");
		}		
	}
	
	printf("\n");
	printf("\n");

	//输入完毕，验证账户密码是否正确
	flag_pwd=compare_name_pwd(pHead,usr_insert_name, usr_insert_pwd);
	if (flag_pwd == 1){
		printf("账户密码正确，正在跳往主界面\n");
		goto select_role;
	}
	else{
		printf("账户或密码输入错误，请重新输入：\n");
		goto login;
	}

	//判断角色
select_role:
	flag_row = compare_role(pHead,usr_insert_name);
	if (flag_row == 1){
		printf("您是管理员，正在跳往管理员界面：\n");
		goto admin_pic;
	}
	else{
		printf("正在跳往学生界面");
		goto stu_pic;
	}

	//管理员界面
admin_pic:
	system("cls");
		printf("-----------------------------------------------------------------------------\n");
		printf("------------Welcome login the Student Information Management System----------\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("\n");
		printf("			  1、Search Student Information\n");
		printf("			  2、Add Student Information\n");
		printf("			  3、Update Student Information\n");
		printf("			  4、Delete Student Information\n");
		printf("			  5、Add User Account\n");
		printf("			  6、Update User Account\n");
		printf("			  7、Delete User Account\n");
		printf("			  8、Search User Account\n");
		printf("			  9、exit\n");
		printf("\n");
		printf("请输入要选择的功能：");
		int admin_num_select;
		scanf("%d", &admin_num_select);
		switch (admin_num_select){

		case 1:				//搜索学生信息
			search_Student_Infor(pHead1);
			goto admin_pic;
		case 2:{			//增加学生信息
add_stu_infor:
				system("cls");
				int usr_id_temp;
				char usr_name_temp[20];
				int usr_course_id_temp;
				int usr_course_score_temp;

				printf("请输入您要增加的用户信息\n");
				printf("请输入您要增加的学生的学号:");
				scanf("%s", &usr_id_temp);
				printf("\n请输入您要增加的用户的姓名:");
				scanf("%s", usr_name_temp);
				printf("\n请输入您要增加的用户的课程号:");
				scanf("%s", &usr_course_id_temp);
				printf("\n请输入您要增加的用户的课程成绩:");
				scanf("%s", &usr_course_score_temp);
				printf("\n");

				listHeadInsert_infor(&pHead1, &pTail1, usr_id_temp, usr_name_temp, usr_course_id_temp, usr_course_score_temp);
				printf("增加学生信息完成，继续增加信息请按0，返回主界面按9");
				int num_temp;
				scanf("%d", &num_temp);
				if (num_temp == 9){
					goto admin_pic;
				}
				else{
					goto add_stu_infor;
				}
			}
			goto admin_pic;

		case 3:						//更新学生信息
			update_stu_infor(pHead1);
			goto admin_pic;

		case 4:						//删除学生信息
delete_stu :
			system("cls");
		   int delete_num;
					 printf("请输入要删除的学号：");
					 scanf("%d", &delete_num);
					 delete_stu_infor(&pHead, &pTail, delete_num);
					 printf("\n继续删除请按0，返回主界面请按9：");
					 int num_temp_delete_2;
					 scanf("%d", &num_temp_delete_2);
					 if (num_temp_delete_2 == 9){
						 goto admin_pic;
					 }
					 else{
						 goto delete_stu;
					 }
					 goto admin_pic;

		case 5:	{				//增加用户信息
add_usr:
			system("cls");
			char name_temp_add[20];
			char pwd_temp_add[20];
			int role_temp_add;
			int insert_temp_add;

			printf("请输入您要增加的用户信息\n");
			printf("请输入您要增加的用户的姓名:");
			scanf("%s", name_temp_add);
			printf("\n请输入您要增加的用户的密码:");
			scanf("%s", pwd_temp_add);
			printf("\n请输入您要增加的用户的权限类别，按0位管理员权限，按1位普通用户权限:");
			scanf("%d", &insert_temp_add);
			printf("\n");
			if (insert_temp_add == 0){
				role_temp_add = 0;
			}
			else if (insert_temp_add == 1){
				role_temp_add = 1;
			}
			else{
				printf("\n您输入的权限类别有误，请重新输入\n");
				goto add_usr;
			}
			listHeadInsert(&pHead, &pTail, name_temp_add, pwd_temp_add, role_temp_add);
			printf("\n增加账户信息完成，继续增加信息请按0，返回主界面按9：");
			int num_temp;
			scanf("%d", &num_temp);
			if (num_temp == 9){
				goto admin_pic;
			}
			else{
				goto add_usr;
			}
		}
			goto admin_pic;

		case 6:						//更新账户信息
			update_User_Account(pHead);
			goto admin_pic;

		case 7:						//删除账户信息
delete_again:
			system("cls");
			char delete_name[20];
			printf("请输入要删除的用户名：");
			scanf("%s", delete_name);
			delete_User_Account(&pHead,&pTail,delete_name);
			printf("\n继续删除请按0，返回主界面请按9：");
			int num_temp_delete;
			scanf("%d", &num_temp_delete);
			if (num_temp_delete == 9){
				goto admin_pic;
			}
			else{
				goto delete_again;
			}

			goto admin_pic;

		case 8:					//查找用户信息
			search_User_Account(pHead);
			goto admin_pic;

		case 9:
			printf("访问结束");
			goto error;
		default:
			printf("您的输入有误，请按照编号重新输入：");
			goto admin_pic;
		}

		goto admin_pic;

		//学生用户菜单界面
stu_pic:
		printf("-----------------------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("------------Welcome login the Student Information Management System----------\n");
		printf("\n");
		printf("          1、Search Student Information \n");
		printf("          9、exit\n");

		printf("\n请输入要选择的功能：\n");
		int stu_num_select;
		scanf("%d", &stu_num_select);

		switch (stu_num_select){
		case 1:							//搜索学生信息
			search_Student_Infor(pHead1);
			goto stu_pic;
		case 9:							//退出
			goto error;
		}

error:
	//在要结束退出的时候，将内存中的数据保存到磁盘中
	save_data_to_file_stu(pHead1);		//保存学生信息
	save_data_to_file_account(pHead);	//保存账户信息
	system("pause");

}
#include"info.h"

//头插法插入账户信息
void listHeadInsert(pUSR_ACCOUNT *ppHead, pUSR_ACCOUNT *ppTail, char name[20], char pwd[20], int role){

	pUSR_ACCOUNT pNew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	strcpy(pNew->usr_name, name, 20);
	strcpy(pNew->usr_pwd, pwd, 20);
	pNew->usr_role = role;

	if (NULL == *ppHead)//判断链表是否为空
	{
		*ppHead = pNew;
		*ppTail = pNew;
	}
	else{
		pNew->pNext_Usr_Account = *ppHead;
		*ppHead = pNew;
	}
}

//头插法增加学生信息
void listHeadInsert_infor(pUSR_INFOR *ppHead1, pUSR_INFOR *ppTail1, int usr_id,char usr_name[20], int usr_course_id,int usr_course_score){

	pUSR_INFOR pNew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	pNew->usr_id = usr_id;
	strcpy(pNew->usr_name,usr_name,20);
	pNew->usr_course_id = usr_course_id;
	pNew->usr_course_score = usr_course_score;

	if (NULL == *ppHead1)//判断链表是否为空
	{
		*ppHead1 = pNew;
		*ppTail1 = pNew;
	}
	else{
		pNew->pNext_Usr_Infor = *ppHead1;
		*ppHead1 = pNew;
	}
}

//打印账户节点信息
void listPrint(pUSR_ACCOUNT pHead){
	while (pHead){
		printf("%s %s %d\n", pHead->usr_name, pHead->usr_pwd, pHead->usr_role);
		pHead = (pHead)->pNext_Usr_Account;
	}
}

//打印学生节点信息
void listPrint1(pUSR_INFOR pHead){
	while (pHead){
		printf("%d %s %d %d\n", pHead->usr_id, pHead->usr_name, pHead->usr_course_id,pHead->usr_course_score);
		pHead = (pHead)->pNext_Usr_Infor;
	}
}

//判断输入的用户名和密码是否匹配
int compare_name_pwd(pUSR_ACCOUNT pHead,char *usr_insert_name,char *usr_insert_pwd){
	while (pHead){
		if (strcmp(pHead->usr_name, usr_insert_name)== 0){
			if (strcmp(pHead->usr_pwd, usr_insert_pwd) == 0){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			pHead = pHead->pNext_Usr_Account;
		}
	}
	return 0;
}

//判断登录用户的角色
int compare_role(pUSR_ACCOUNT pHead, char *usr_insert_name){
	while (pHead){
		if (strcmp(pHead->usr_name, usr_insert_name) == 0){
			return pHead->usr_role;
		}
		else{
			pHead = pHead->pNext_Usr_Account;
		}
	}
}

//搜索学生信息功能
void search_Student_Infor(pUSR_INFOR pHead){
search_Student_infor:

	system("cls");
	printf("请输入您要搜索的学号：");
	int num_temp_stu;
	scanf("%d",&num_temp_stu);

	while (pHead){
		if (pHead->usr_id==num_temp_stu){
			printf("该学生信息如下：");
			printf("学号：%d,姓名：%s ,课程1序号：%d,课程1成绩：%d",pHead->usr_id,pHead->usr_name,pHead->usr_course_id,pHead->usr_course_score);
			printf("搜索完毕，退出请按9，继续搜索请按0\n");
			int num_flag = 0;
			scanf("%d", &num_flag);
			if (num_flag == 9){
				return;
			}
			else{
				goto search_Student_infor;
			}
		}
		else{
			pHead = pHead->pNext_Usr_Infor;
		}
	}
	printf("该学生信息不存在，请重新输入,退出请按9\n");
	int num_flag;
	scanf("%d", &num_flag);
	if (num_flag == 9){
		return;
	}
	else{
		goto search_Student_infor;
	}
}

//更新学生信息功能
void update_stu_infor(pUSR_INFOR pHead){

update_stu:
	system("cls");
	int usr_id_temp;
	char usr_name_temp[20];
	int usr_course_id_temp;
	int usr_course_score_temp;

	printf("请输入要更新的学号:");
	scanf("%d",&usr_id_temp);

	while (pHead){
		if (pHead->usr_id==usr_id_temp){
update_select:
			printf("请输入要更新的信息，按0为更新学号，按1为更新姓名，按2位更新课程号，按3为更新课程成绩，按4为更新其他用户,按9退出：");
			int num_temp;
			scanf("%d", &num_temp);
			if (num_temp == 0){
				printf("请输入更新后的学号:");
				int update_id;
				scanf("%d",&update_id);
				pHead->usr_id = update_id;
				goto update_select;
			}
			else if (num_temp == 1){
				printf("请输入更新后的姓名：");
				char update_name[20];
				scanf("%s",update_name);
				strcpy(pHead->usr_name,update_name, sizeof(update_name));
				goto update_select;
			}
			else if (num_temp == 2){
				printf("请输入更新后的课程号");
				int update_course_id;
				scanf("%d", &update_course_id);
				pHead->usr_course_id = update_course_id;
				goto update_select;
			}
			else if (num_temp == 3){
				printf("请输入更新后的课程成绩");
				int update_score;
				scanf("%d", &update_score);
				pHead->usr_course_score = update_score;
				goto update_select;
			}
			else if (num_temp == 9){
				return;
			}
			else{
				goto update_select;
			}
		}
		pHead = pHead->pNext_Usr_Infor;
	}
	if (NULL == pHead)
	{
		printf("没有找到该用户，按任意键重新输入，按9返回主界面\n");
		int num_temp_2;
		scanf("%d", &num_temp_2);
		if (num_temp_2 == 9){
			return;
		}
		else{
			goto update_stu;
		}
	}
}

//删除学生信息功能
void delete_stu_infor(pUSR_INFOR *ppHead, pUSR_INFOR *ppTail, int delete_stu_num){

	pUSR_INFOR pCur = *ppHead, pPre;
	pPre = pCur;
	if (NULL == pCur)
	{
		printf("学生列表为空\n");
		return;
	}
	else if (pCur->usr_id==delete_stu_num){//删除的是头部
		*ppHead = pCur->pNext_Usr_Infor;
		if (NULL == *ppHead){
			*ppTail = NULL;
		}
	}
	else{
		while (pCur){//删除的是中间或者尾部
			if (pCur->usr_id == delete_stu_num){
				pPre->pNext_Usr_Infor = pCur->pNext_Usr_Infor;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext_Usr_Infor;
		}
		if (NULL == pCur){//没有找到对应结点
			printf("没有找到此学生");
			return;
		}
		if (pCur == *ppTail){
			*ppTail = pPre;
		}
	}
	free(pCur);
	pCur = NULL;
}

//更新用户账户功能
void update_User_Account(pUSR_ACCOUNT pHead){
	
update_usr:
	system("cls");
	char name_temp_update[20];
	char pwd_temp_update[20];
	int role_temp_update;

	printf("请输入要更新的账户名:");
	scanf("%s",name_temp_update);
	while (pHead){
		if (strcmp(pHead->usr_name,name_temp_update)==0){

update_select:
			printf("请输入要更新的信息，按0为更新用户名，按1为更新密码，按2位更新角色信息，按3为更新其他用户,按9推出：");
			int num_temp;
			scanf("%d", &num_temp);
			if (num_temp == 0){
				printf("请输入更新后的用户名:");
				char name_update_temp[20];
				scanf("%s", name_update_temp);
				strcpy(pHead->usr_name, name_update_temp, sizeof(name_update_temp));
				goto update_select;
			}
			else if (num_temp == 1){
				printf("请输入更新后的密码：");
				char pwd_update_temp[20];
				scanf("%s", pwd_update_temp);
				strcpy(pHead->usr_pwd, pwd_update_temp, sizeof(pwd_update_temp));
				goto update_select;
			}
			else if (num_temp == 2){
				printf("请输入更新后的角色权限，按0为管理员权限，按1位普通用户权限");
				int role_update;
				scanf("%d", &role_update);
				pHead->usr_role = role_update;
				goto update_select;
			}
			else if (num_temp == 9){
				return;
			}
			else{
				goto update_usr;
			}
		}
		pHead = pHead->pNext_Usr_Account;
	}
	if (NULL == pHead)
	{
		printf("没有找到该用户，按任意键重新输入，按9返回主界面\n");
		int num_temp_2;
		scanf("%d", &num_temp_2);
		if (num_temp_2 == 9){
			return;
		}
		else{
			goto update_usr;
		}
	}
}

//删除用户账户功能
void delete_User_Account(pUSR_ACCOUNT *ppHead,pUSR_ACCOUNT *ppTail,char *delete_name){

	pUSR_ACCOUNT pCur = *ppHead, pPre;
	pPre = pCur;
	if (NULL == pCur){
		printf("账户列表为空\n");
		return;
	}
	else if (strcmp(pCur->usr_name,delete_name)==0){//删除的是头部
		*ppHead = pCur->pNext_Usr_Account;
		if (NULL == *ppHead){
			*ppTail = NULL;
		}
	}
	else{
		while (pCur){//删除的是中间或者尾部
			if (strcmp(pCur->usr_name, delete_name) == 0){
				pPre->pNext_Usr_Account = pCur->pNext_Usr_Account;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext_Usr_Account;
		}
		if (NULL == pCur){//没有找到对应结点
			printf("没有找到此用户");
			return;
		}
		if (pCur == *ppTail){
			*ppTail = pPre;
		}
	}
	free(pCur);
	pCur = NULL;
}

//搜索用户账户功能
void search_User_Account(pUSR_ACCOUNT pHead){

	system("cls");
search_account:
	printf("请输入您要搜索的用户名：");
	char search_name[20];
	scanf("%s", search_name);

	while (pHead){
		if (strcmp(pHead->usr_name, search_name) == 0){
			printf("该账号信息如下：");
			printf("用户名：%s,密码：%s ,", pHead->usr_name, pHead->usr_pwd);
			if (pHead->usr_role == 1){
				printf("角色权限是：管理员\n");
			}
			else{
				printf("角色权限是：普通用户\n");
			}
			printf("搜索完毕，退出请按9，继续搜索请按0\n");
			int num_flag = 0;
			scanf("%d", &num_flag);
			if (num_flag == 9){
				return;
			}
			else{
				goto search_account;
			}
		}
		else{
			pHead = pHead->pNext_Usr_Account;
		}
	}
	printf("该用户不存在，请重新输入,退出请按9\n");
	int num_flag;
	scanf("%d", &num_flag);
	if (num_flag == 9){
		return;
	}
	else{
		goto search_account;
	}
}

//将学生信息保存到文件里去
void save_data_to_file_stu(pUSR_INFOR pHead){

	FILE *fp;
	fp = fopen("usr_infor.txt", "w+");
	while (pHead){
		fprintf(fp,"%d %s %d %d\n",pHead->usr_id,pHead->usr_name,pHead->usr_course_id,pHead->usr_course_score);
	}
	fclose(fp);
}

//将账号信息保存到文件里去
void save_data_to_file_account(pUSR_ACCOUNT pHead){

	FILE *fp1;
	fp1 = fopen("usr_account.txt", "w+");
	while (pHead){
		fprintf(fp1, "%s %s %d\n", pHead->usr_name, pHead->usr_pwd, pHead->usr_role);
	}
	fclose(fp1);
}

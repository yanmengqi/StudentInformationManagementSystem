#include"info.h"

//ͷ�巨�����˻���Ϣ
void listHeadInsert(pUSR_ACCOUNT *ppHead, pUSR_ACCOUNT *ppTail, char name[20], char pwd[20], int role){

	pUSR_ACCOUNT pNew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	strcpy(pNew->usr_name, name, 20);
	strcpy(pNew->usr_pwd, pwd, 20);
	pNew->usr_role = role;

	if (NULL == *ppHead)//�ж������Ƿ�Ϊ��
	{
		*ppHead = pNew;
		*ppTail = pNew;
	}
	else{
		pNew->pNext_Usr_Account = *ppHead;
		*ppHead = pNew;
	}
}

//ͷ�巨����ѧ����Ϣ
void listHeadInsert_infor(pUSR_INFOR *ppHead1, pUSR_INFOR *ppTail1, int usr_id,char usr_name[20], int usr_course_id,int usr_course_score){

	pUSR_INFOR pNew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	pNew->usr_id = usr_id;
	strcpy(pNew->usr_name,usr_name,20);
	pNew->usr_course_id = usr_course_id;
	pNew->usr_course_score = usr_course_score;

	if (NULL == *ppHead1)//�ж������Ƿ�Ϊ��
	{
		*ppHead1 = pNew;
		*ppTail1 = pNew;
	}
	else{
		pNew->pNext_Usr_Infor = *ppHead1;
		*ppHead1 = pNew;
	}
}

//��ӡ�˻��ڵ���Ϣ
void listPrint(pUSR_ACCOUNT pHead){
	while (pHead){
		printf("%s %s %d\n", pHead->usr_name, pHead->usr_pwd, pHead->usr_role);
		pHead = (pHead)->pNext_Usr_Account;
	}
}

//��ӡѧ���ڵ���Ϣ
void listPrint1(pUSR_INFOR pHead){
	while (pHead){
		printf("%d %s %d %d\n", pHead->usr_id, pHead->usr_name, pHead->usr_course_id,pHead->usr_course_score);
		pHead = (pHead)->pNext_Usr_Infor;
	}
}

//�ж�������û����������Ƿ�ƥ��
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

//�жϵ�¼�û��Ľ�ɫ
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

//����ѧ����Ϣ����
void search_Student_Infor(pUSR_INFOR pHead){
search_Student_infor:

	system("cls");
	printf("��������Ҫ������ѧ�ţ�");
	int num_temp_stu;
	scanf("%d",&num_temp_stu);

	while (pHead){
		if (pHead->usr_id==num_temp_stu){
			printf("��ѧ����Ϣ���£�");
			printf("ѧ�ţ�%d,������%s ,�γ�1��ţ�%d,�γ�1�ɼ���%d",pHead->usr_id,pHead->usr_name,pHead->usr_course_id,pHead->usr_course_score);
			printf("������ϣ��˳��밴9�����������밴0\n");
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
	printf("��ѧ����Ϣ�����ڣ�����������,�˳��밴9\n");
	int num_flag;
	scanf("%d", &num_flag);
	if (num_flag == 9){
		return;
	}
	else{
		goto search_Student_infor;
	}
}

//����ѧ����Ϣ����
void update_stu_infor(pUSR_INFOR pHead){

update_stu:
	system("cls");
	int usr_id_temp;
	char usr_name_temp[20];
	int usr_course_id_temp;
	int usr_course_score_temp;

	printf("������Ҫ���µ�ѧ��:");
	scanf("%d",&usr_id_temp);

	while (pHead){
		if (pHead->usr_id==usr_id_temp){
update_select:
			printf("������Ҫ���µ���Ϣ����0Ϊ����ѧ�ţ���1Ϊ������������2λ���¿γ̺ţ���3Ϊ���¿γ̳ɼ�����4Ϊ���������û�,��9�˳���");
			int num_temp;
			scanf("%d", &num_temp);
			if (num_temp == 0){
				printf("��������º��ѧ��:");
				int update_id;
				scanf("%d",&update_id);
				pHead->usr_id = update_id;
				goto update_select;
			}
			else if (num_temp == 1){
				printf("��������º��������");
				char update_name[20];
				scanf("%s",update_name);
				strcpy(pHead->usr_name,update_name, sizeof(update_name));
				goto update_select;
			}
			else if (num_temp == 2){
				printf("��������º�Ŀγ̺�");
				int update_course_id;
				scanf("%d", &update_course_id);
				pHead->usr_course_id = update_course_id;
				goto update_select;
			}
			else if (num_temp == 3){
				printf("��������º�Ŀγ̳ɼ�");
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
		printf("û���ҵ����û�����������������룬��9����������\n");
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

//ɾ��ѧ����Ϣ����
void delete_stu_infor(pUSR_INFOR *ppHead, pUSR_INFOR *ppTail, int delete_stu_num){

	pUSR_INFOR pCur = *ppHead, pPre;
	pPre = pCur;
	if (NULL == pCur)
	{
		printf("ѧ���б�Ϊ��\n");
		return;
	}
	else if (pCur->usr_id==delete_stu_num){//ɾ������ͷ��
		*ppHead = pCur->pNext_Usr_Infor;
		if (NULL == *ppHead){
			*ppTail = NULL;
		}
	}
	else{
		while (pCur){//ɾ�������м����β��
			if (pCur->usr_id == delete_stu_num){
				pPre->pNext_Usr_Infor = pCur->pNext_Usr_Infor;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext_Usr_Infor;
		}
		if (NULL == pCur){//û���ҵ���Ӧ���
			printf("û���ҵ���ѧ��");
			return;
		}
		if (pCur == *ppTail){
			*ppTail = pPre;
		}
	}
	free(pCur);
	pCur = NULL;
}

//�����û��˻�����
void update_User_Account(pUSR_ACCOUNT pHead){
	
update_usr:
	system("cls");
	char name_temp_update[20];
	char pwd_temp_update[20];
	int role_temp_update;

	printf("������Ҫ���µ��˻���:");
	scanf("%s",name_temp_update);
	while (pHead){
		if (strcmp(pHead->usr_name,name_temp_update)==0){

update_select:
			printf("������Ҫ���µ���Ϣ����0Ϊ�����û�������1Ϊ�������룬��2λ���½�ɫ��Ϣ����3Ϊ���������û�,��9�Ƴ���");
			int num_temp;
			scanf("%d", &num_temp);
			if (num_temp == 0){
				printf("��������º���û���:");
				char name_update_temp[20];
				scanf("%s", name_update_temp);
				strcpy(pHead->usr_name, name_update_temp, sizeof(name_update_temp));
				goto update_select;
			}
			else if (num_temp == 1){
				printf("��������º�����룺");
				char pwd_update_temp[20];
				scanf("%s", pwd_update_temp);
				strcpy(pHead->usr_pwd, pwd_update_temp, sizeof(pwd_update_temp));
				goto update_select;
			}
			else if (num_temp == 2){
				printf("��������º�Ľ�ɫȨ�ޣ���0Ϊ����ԱȨ�ޣ���1λ��ͨ�û�Ȩ��");
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
		printf("û���ҵ����û�����������������룬��9����������\n");
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

//ɾ���û��˻�����
void delete_User_Account(pUSR_ACCOUNT *ppHead,pUSR_ACCOUNT *ppTail,char *delete_name){

	pUSR_ACCOUNT pCur = *ppHead, pPre;
	pPre = pCur;
	if (NULL == pCur){
		printf("�˻��б�Ϊ��\n");
		return;
	}
	else if (strcmp(pCur->usr_name,delete_name)==0){//ɾ������ͷ��
		*ppHead = pCur->pNext_Usr_Account;
		if (NULL == *ppHead){
			*ppTail = NULL;
		}
	}
	else{
		while (pCur){//ɾ�������м����β��
			if (strcmp(pCur->usr_name, delete_name) == 0){
				pPre->pNext_Usr_Account = pCur->pNext_Usr_Account;
				break;
			}
			pPre = pCur;
			pCur = pCur->pNext_Usr_Account;
		}
		if (NULL == pCur){//û���ҵ���Ӧ���
			printf("û���ҵ����û�");
			return;
		}
		if (pCur == *ppTail){
			*ppTail = pPre;
		}
	}
	free(pCur);
	pCur = NULL;
}

//�����û��˻�����
void search_User_Account(pUSR_ACCOUNT pHead){

	system("cls");
search_account:
	printf("��������Ҫ�������û�����");
	char search_name[20];
	scanf("%s", search_name);

	while (pHead){
		if (strcmp(pHead->usr_name, search_name) == 0){
			printf("���˺���Ϣ���£�");
			printf("�û�����%s,���룺%s ,", pHead->usr_name, pHead->usr_pwd);
			if (pHead->usr_role == 1){
				printf("��ɫȨ���ǣ�����Ա\n");
			}
			else{
				printf("��ɫȨ���ǣ���ͨ�û�\n");
			}
			printf("������ϣ��˳��밴9�����������밴0\n");
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
	printf("���û������ڣ�����������,�˳��밴9\n");
	int num_flag;
	scanf("%d", &num_flag);
	if (num_flag == 9){
		return;
	}
	else{
		goto search_account;
	}
}

//��ѧ����Ϣ���浽�ļ���ȥ
void save_data_to_file_stu(pUSR_INFOR pHead){

	FILE *fp;
	fp = fopen("usr_infor.txt", "w+");
	while (pHead){
		fprintf(fp,"%d %s %d %d\n",pHead->usr_id,pHead->usr_name,pHead->usr_course_id,pHead->usr_course_score);
	}
	fclose(fp);
}

//���˺���Ϣ���浽�ļ���ȥ
void save_data_to_file_account(pUSR_ACCOUNT pHead){

	FILE *fp1;
	fp1 = fopen("usr_account.txt", "w+");
	while (pHead){
		fprintf(fp1, "%s %s %d\n", pHead->usr_name, pHead->usr_pwd, pHead->usr_role);
	}
	fclose(fp1);
}

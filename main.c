#include "info.h"

//����2��txt�ļ���usr_account.txt����û��˻���Ϣ��usr_infor.txt���ѧ����Ϣ

int main(){

	//�˻���Ϣ��ʼ�����֣������ݴӴ��̶�������е�������
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

	//listPrint(pHead);				//�ɵ��Զϵ�
	fclose(fp);
	
	//ѧ����ʼ�����֣������ݴӴ��̶�������е�������-stu
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

	//listPrint1(pHead1);         //�ɵ��Զϵ�
	fclose(fp1);


	//��¼����
	int flag_pwd = 0;													//flag_pwdΪ0�����������Ϊ1����������ȷ�����Խ���ϵͳ
	int flag_row = 0;													//flag_row�����û���ɫ��Ϊ0�������Ա�û���Ϊ1������ͨ�û�

login:

	printf("�����������û�����");
	char usr_insert_name[20];
	char usr_insert_pwd[20];

	scanf("%s",usr_insert_name);
	printf("���������룺");
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

	//������ϣ���֤�˻������Ƿ���ȷ
	flag_pwd=compare_name_pwd(pHead,usr_insert_name, usr_insert_pwd);
	if (flag_pwd == 1){
		printf("�˻�������ȷ����������������\n");
		goto select_role;
	}
	else{
		printf("�˻�����������������������룺\n");
		goto login;
	}

	//�жϽ�ɫ
select_role:
	flag_row = compare_role(pHead,usr_insert_name);
	if (flag_row == 1){
		printf("���ǹ���Ա��������������Ա���棺\n");
		goto admin_pic;
	}
	else{
		printf("��������ѧ������");
		goto stu_pic;
	}

	//����Ա����
admin_pic:
	system("cls");
		printf("-----------------------------------------------------------------------------\n");
		printf("------------Welcome login the Student Information Management System----------\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("\n");
		printf("			  1��Search Student Information\n");
		printf("			  2��Add Student Information\n");
		printf("			  3��Update Student Information\n");
		printf("			  4��Delete Student Information\n");
		printf("			  5��Add User Account\n");
		printf("			  6��Update User Account\n");
		printf("			  7��Delete User Account\n");
		printf("			  8��Search User Account\n");
		printf("			  9��exit\n");
		printf("\n");
		printf("������Ҫѡ��Ĺ��ܣ�");
		int admin_num_select;
		scanf("%d", &admin_num_select);
		switch (admin_num_select){

		case 1:				//����ѧ����Ϣ
			search_Student_Infor(pHead1);
			goto admin_pic;
		case 2:{			//����ѧ����Ϣ
add_stu_infor:
				system("cls");
				int usr_id_temp;
				char usr_name_temp[20];
				int usr_course_id_temp;
				int usr_course_score_temp;

				printf("��������Ҫ���ӵ��û���Ϣ\n");
				printf("��������Ҫ���ӵ�ѧ����ѧ��:");
				scanf("%s", &usr_id_temp);
				printf("\n��������Ҫ���ӵ��û�������:");
				scanf("%s", usr_name_temp);
				printf("\n��������Ҫ���ӵ��û��Ŀγ̺�:");
				scanf("%s", &usr_course_id_temp);
				printf("\n��������Ҫ���ӵ��û��Ŀγ̳ɼ�:");
				scanf("%s", &usr_course_score_temp);
				printf("\n");

				listHeadInsert_infor(&pHead1, &pTail1, usr_id_temp, usr_name_temp, usr_course_id_temp, usr_course_score_temp);
				printf("����ѧ����Ϣ��ɣ�����������Ϣ�밴0�����������水9");
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

		case 3:						//����ѧ����Ϣ
			update_stu_infor(pHead1);
			goto admin_pic;

		case 4:						//ɾ��ѧ����Ϣ
delete_stu :
			system("cls");
		   int delete_num;
					 printf("������Ҫɾ����ѧ�ţ�");
					 scanf("%d", &delete_num);
					 delete_stu_infor(&pHead, &pTail, delete_num);
					 printf("\n����ɾ���밴0�������������밴9��");
					 int num_temp_delete_2;
					 scanf("%d", &num_temp_delete_2);
					 if (num_temp_delete_2 == 9){
						 goto admin_pic;
					 }
					 else{
						 goto delete_stu;
					 }
					 goto admin_pic;

		case 5:	{				//�����û���Ϣ
add_usr:
			system("cls");
			char name_temp_add[20];
			char pwd_temp_add[20];
			int role_temp_add;
			int insert_temp_add;

			printf("��������Ҫ���ӵ��û���Ϣ\n");
			printf("��������Ҫ���ӵ��û�������:");
			scanf("%s", name_temp_add);
			printf("\n��������Ҫ���ӵ��û�������:");
			scanf("%s", pwd_temp_add);
			printf("\n��������Ҫ���ӵ��û���Ȩ����𣬰�0λ����ԱȨ�ޣ���1λ��ͨ�û�Ȩ��:");
			scanf("%d", &insert_temp_add);
			printf("\n");
			if (insert_temp_add == 0){
				role_temp_add = 0;
			}
			else if (insert_temp_add == 1){
				role_temp_add = 1;
			}
			else{
				printf("\n�������Ȩ�������������������\n");
				goto add_usr;
			}
			listHeadInsert(&pHead, &pTail, name_temp_add, pwd_temp_add, role_temp_add);
			printf("\n�����˻���Ϣ��ɣ�����������Ϣ�밴0�����������水9��");
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

		case 6:						//�����˻���Ϣ
			update_User_Account(pHead);
			goto admin_pic;

		case 7:						//ɾ���˻���Ϣ
delete_again:
			system("cls");
			char delete_name[20];
			printf("������Ҫɾ�����û�����");
			scanf("%s", delete_name);
			delete_User_Account(&pHead,&pTail,delete_name);
			printf("\n����ɾ���밴0�������������밴9��");
			int num_temp_delete;
			scanf("%d", &num_temp_delete);
			if (num_temp_delete == 9){
				goto admin_pic;
			}
			else{
				goto delete_again;
			}

			goto admin_pic;

		case 8:					//�����û���Ϣ
			search_User_Account(pHead);
			goto admin_pic;

		case 9:
			printf("���ʽ���");
			goto error;
		default:
			printf("�������������밴�ձ���������룺");
			goto admin_pic;
		}

		goto admin_pic;

		//ѧ���û��˵�����
stu_pic:
		printf("-----------------------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("------------Welcome login the Student Information Management System----------\n");
		printf("\n");
		printf("          1��Search Student Information \n");
		printf("          9��exit\n");

		printf("\n������Ҫѡ��Ĺ��ܣ�\n");
		int stu_num_select;
		scanf("%d", &stu_num_select);

		switch (stu_num_select){
		case 1:							//����ѧ����Ϣ
			search_Student_Infor(pHead1);
			goto stu_pic;
		case 9:							//�˳�
			goto error;
		}

error:
	//��Ҫ�����˳���ʱ�򣬽��ڴ��е����ݱ��浽������
	save_data_to_file_stu(pHead1);		//����ѧ����Ϣ
	save_data_to_file_account(pHead);	//�����˻���Ϣ
	system("pause");

}
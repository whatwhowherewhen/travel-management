#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#define MAX_EXPENSES 100
#define _CRT_SECURE_NO_WARNINGS
#define MAX_TRIPS 100
#define MAX_STR_LEN 100

/************************������ ��õ ���α׷�******************************/
void showLoading() {
	printf("��õ ��");
	for (int i = 0; i < 3; i++) {
		Sleep(500);  // 500ms ���
		printf(".");
		fflush(stdout);
	}
	printf("\n");
}

void recommendBeach() {
	showLoading();
	const char* beaches[] = {
		"�λ� �ؿ��", "�泲 ��õ", "���� ����", "���� ��ô", "�λ� ���ȸ�", "���� ������",
		"��õ �۵�", "��õ ���ո�", "���� ��Ҹ��� �غ�", "�泲 �ŵθ�", "���� �ݴ�",
		"���� ���ϴ�", "��� ������", "�泲 ������", "�泲 �뿵", "��� ����", "���� ���",
		"���� ����", "�泲 ����"
	};
	int index = rand() % (sizeof(beaches) / sizeof(beaches[0]));
	printf("��õ �ٴ尡: %s\n", beaches[index]);
}

void recommendMountain() {
	showLoading();
	const char* mountains[] = {
		"���ǻ�", "������", "�Ѷ��", "���ѻ�", "�¹��", "�Ȱ���", "�Ѷ��", "�ݿ���",
		"������", "ġ�ǻ�", "�Ⱥ���", "�Ӹ���", "�����", "�����", "���߻�", "�����",
		"�ֿջ�", "�ҹ��", "����"
	};
	int index = rand() % (sizeof(mountains) / sizeof(mountains[0]));
	printf("��õ ��: %s\n", mountains[index]);
}

void recommendCity() {
	showLoading();
	const char* cities[] = {
		"���� ��", "�λ� ����", "�뱸 ������", "���� �����", "��õ ������",
		"���� ���ൿ", "��� ��굿", "���� �ΰ赿", "���� �д�", "��� �ϻ�",
		"û�� ���ȱ�", "â�� �󳲵�", "���� �ѿ�����", "���ֵ� �߹�"
	};
	int index = rand() % (sizeof(cities) / sizeof(cities[0]));
	printf("��õ ��ȭ��: %s\n", cities[index]);
}

void recommendRestaurant() {
	showLoading();
	const char* restaurants[] = {
		"���� �����", "�λ� �и�", "�뱸 ��â", "���� ������", "���� �Ұ��",
		"��õ �߰���", "�ȵ� ������", "���� �ʴ���κ�", "���� ȫ��", "��õ ����",
		"���� ��ȸ�����", "���� ���ɴ�"
	};
	int index = rand() % (sizeof(restaurants) / sizeof(restaurants[0]));
	printf("��õ ����: %s\n", restaurants[index]);
}

/*****************************�ؿ� ������ ��õ ���α׷�************************/
void recommendTravelDestination() {
	
	const char* destinations[] = {
		"����", "����ī", "�����ī", "������", "����",
		"�ĸ�", "����", "�θ�", "�ٸ����γ�", "������",
		"����", "�ν���������", "�󽺺��̰Ž�", "�������ý���",
		"�����", "�����", "�õ��", "�����", "����ڽ�Ʈ",
		"����", "��Ÿ��", "ġ�Ӹ���", "Ǫ��",
		"�ϳ���", "ȣġ��", "�̰�����", "ȫ��", "��ī��",
		"Ÿ�̺���", "������", "����¡", "������", "������",
		"Ī�ٿ�", "�Ͼ��", "�Ͽ���", "��", "������",
		"�߸�", "��˶��Ǫ��", "�ι���", "�̽�ź��", "�Ͻ��׸���",
		"������", "�δ��佺Ʈ", "���Ű", "����Ȧ��",
		"�����ϰ�", "������", "������ D.C.", "��ī��",
		"���ֹ̾�", "���", "��Ʋ��Ÿ", "���ø���"
	};

	// ����ġ �迭�� �� ������ �°� �����մϴ�.
	int weights[][56] = {
		// �� (�ѱ��� ���� ��ü�� 3��, 4��, 5��)
		{8, 8, 8, 5, 5, 6, 6, 6, 6, 6, 4, 4, 3, 3, 5, 5, 5, 5, 5, 7, 7, 7, 7, 5, 5, 8, 8, 8, 6, 6, 4, 4, 4, 5, 5, 5, 8, 8, 7, 7, 5, 5, 6, 6, 6, 6, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5},
		// ���� (�ѱ��� ������ ��ü�� 6��, 7��, 8��)
		{8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 5, 5, 4, 4, 5, 5, 5, 5, 5, 8, 8, 8, 8, 5, 5, 8, 8, 8, 7, 7, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 6, 6, 5, 5, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 5, 5},
		// ���� (�ѱ��� ������ ��ü�� 9��, 10��, 11��)
		{8, 8, 8, 5, 5, 6, 6, 6, 6, 6, 4, 4, 3, 3, 5, 5, 5, 5, 5, 7, 7, 7, 7, 5, 5, 8, 8, 8, 6, 6, 4, 4, 4, 5, 5, 5, 8, 8, 7, 7, 5, 5, 6, 6, 6, 6, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5},
		// �ܿ� (�ѱ��� �ܿ��� ��ü�� 12��, 1��, 2��)
		{8, 8, 8, 7, 7, 5, 5, 5, 5, 5, 4, 4, 3, 3, 5, 5, 5, 5, 5, 8, 8, 8, 8, 5, 5, 8, 8, 8, 7, 7, 4, 4, 4, 5, 5, 5, 8, 8, 7, 7, 5, 5, 5, 5, 5, 5, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5}
	};

	int season;
	printf("������ ���ڷ� �Է��ϼ��� (1=��, 2=����, 3=����, 4=�ܿ�): ");
	scanf_s("%d", &season);

	if (season < 1 || season > 4) {
		printf("�߸��� ���� �Է��Դϴ�.\n");
		return;
	}

	int seasonIndex = season - 1;

	int totalWeight = 0;
	for (int i = 0; i < 56; i++) {
		totalWeight += weights[seasonIndex][i];
	}

	srand(time(NULL));
	int randValue = rand() % totalWeight;
	int sum = 0;
	int index = -1;

	for (int i = 0; i < 56; i++) {
		sum += weights[seasonIndex][i];
		if (randValue < sum) {
			index = i;
			break;
		}
	}
	showLoading();
	printf("��õ ������: %s\n", destinations[index]);
}

/*******************************���� �޷� ���α׷�*********************************/

// ����ü ����
typedef struct {
	char destination[MAX_STR_LEN];
	char startDate[MAX_STR_LEN];
	char endDate[MAX_STR_LEN];
	char notes[MAX_STR_LEN];
} Trip;

//�Լ��� ����
void printMonth(int year, int month, Trip trips[], int tripCount);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month, Trip trips[], int tripCount);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);
int isLeapYear(int year);
int isTripDay(int day, int month, int year, Trip trips[], int tripCount);

//year�� month�� ���� �޾� �ش� ���� ��� -> title, body
void printMonth(int year, int month, Trip trips[], int tripCount) {
	printMonthTitle(year, month);
	printMonthBody(year, month, trips, tripCount);
}

//���� �⵵�� ���
void printMonthTitle(int year, int month) {
	printMonthName(month);
	printf(" %d\n", year);
	printf("-----------------------------\n");

	printf(" \033[0;31mSun\033[0m Mon Tue Wed Thu Fri \033[0;34mSat\033[0m\n"); //ANSI Color�� ���� �ٲ�
}

//month�� ���� �޾� �ش� ���� ���� �̸��� ���
void printMonthName(int month) {
	switch (month) {
	case 1: printf("\nJanuary"); break;
	case 2: printf("\nFebruary"); break;
	case 3: printf("\nMarch"); break;
	case 4: printf("\nApril"); break;
	case 5: printf("\nMay"); break;
	case 6: printf("\nJune"); break;
	case 7: printf("\nJuly"); break;
	case 8: printf("\nAugust"); break;
	case 9: printf("\nSeptember"); break;
	case 10: printf("\nOctober"); break;
	case 11: printf("\nNovember"); break;
	case 12: printf("\nDecember"); break;
	}
}

//year�� month�� ���� �޾� ���ϰ� ���� ���
void printMonthBody(int year, int month, Trip trips[], int tripCount) {
	int startday = getStartDay(year, month);
	int numberofdaysinmonth = getNumberOfDaysInMonth(year, month);

	for (int i = 0; i < startday; i++) printf("    ");
	for (int i = 1; i <= numberofdaysinmonth; i++) {
		if (isTripDay(i, month, year, trips, tripCount)) {
			printf("\033[1;32m%4d\033[0m", i); // ���� ��¥�� ������� ����
		}
		else {
			printf("%4d", i);
		}
		if ((i + startday) % 7 == 0) printf("\n");
	}
}

// �ش� ���� �����ϴ� ���� �� �������� ã�� �Լ�
int getStartDay(int year, int month) {
	int startday1800 = 3;
	int totalnumberofdays = getTotalNumberOfDays(year, month);
	return (startday1800 + totalnumberofdays) % 7;
}

// 1800�� 1�� 1�� ���� ��ĥ�� �Ǵ��� ���
int getTotalNumberOfDays(int year, int month) {
	int total = 0;
	for (int i = 1800; i < year; i++) {
		if (isLeapYear(i)) total += 366;
		else total += 365;
	}
	for (int i = 1; i < month; i++) total = total + getNumberOfDaysInMonth(year, i);
	return total;
}

//year�� month�� ���� �޾� �ش���� ������ �ִ���
int getNumberOfDaysInMonth(int year, int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	if (month == 2) {
		if (isLeapYear(year) == 1) return 29;
		else return 28;
	}
}

//year�� ���޹޾� �������� Ȯ��
int isLeapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return 1;
	else return 0;
}

// Ư�� ��¥�� ���� ��¥���� Ȯ���ϴ� �Լ�
int isTripDay(int day, int month, int year, Trip trips[], int tripCount) {
	char date[11];
	sprintf_s(date, sizeof(date), "%04d-%02d-%02d", year, month, day);

	for (int i = 0; i < tripCount; i++) {
		if (strcmp(trips[i].startDate, date) <= 0 && strcmp(trips[i].endDate, date) >= 0) {
			return 1;
		}
	}
	return 0;
}

/******************************���� ���***************************************/
void addTrip(Trip trips[], int* tripCount);
void saveTripsToFile(Trip trips[], int tripCount);
void loadTripsFromFile(Trip trips[], int* tripCount);
void displayTrips(Trip trips[], int tripCount);
int compareDates(const void* a, const void* b);

void addTrip(Trip trips[], int* tripCount) {
	if (*tripCount >= MAX_TRIPS) {
		printf("�� �̻� ������ �߰��� �� �����ϴ�.\n");
		return;
	}

	Trip newTrip;

	printf("������: ");
	scanf_s("%99s", newTrip.destination, (unsigned)_countof(newTrip.destination));
	getchar(); // '\n' ���� ����

	printf("���� ��¥ (YYYY-MM-DD): ");
	scanf_s("%99s", newTrip.startDate, (unsigned)_countof(newTrip.startDate));
	getchar(); // '\n' ���� ����

	printf("���� ��¥ (YYYY-MM-DD): ");
	scanf_s("%99s", newTrip.endDate, (unsigned)_countof(newTrip.endDate));
	getchar(); // '\n' ���� ����

	printf("�޸�: ");
	scanf_s("%99[^\n]", newTrip.notes, (unsigned)_countof(newTrip.notes));
	getchar(); // '\n' ���� ����

	trips[*tripCount] = newTrip;
	(*tripCount)++;
}

void saveTripsToFile(Trip trips[], int tripCount) {
	FILE* file;
	errno_t err = fopen_s(&file, "trips.txt", "w");
	if (err != 0) {
		printf("������ �� �� �����ϴ�.\n");
		return;
	}

	for (int i = 0; i < tripCount; i++) {
		fprintf(file, "%s\n%s\n%s\n%s\n", trips[i].destination, trips[i].startDate, trips[i].endDate, trips[i].notes);
	}

	fclose(file);
}

void loadTripsFromFile(Trip trips[], int* tripCount) {
	FILE* file;
	errno_t err = fopen_s(&file, "trips.txt", "r");
	if (err != 0) {
		return; // ������ ������ �׳� ����
	}

	while (fscanf_s(file, "%99s\n%99s\n%99s\n%99[^\n]\n", trips[*tripCount].destination, (unsigned)_countof(trips[*tripCount].destination), trips[*tripCount].startDate, (unsigned)_countof(trips[*tripCount].startDate), trips[*tripCount].endDate, (unsigned)_countof(trips[*tripCount].endDate), trips[*tripCount].notes, (unsigned)_countof(trips[*tripCount].notes)) == 4) {
		(*tripCount)++;
	}

	fclose(file);

	// ��¥���� ����
	qsort(trips, *tripCount, sizeof(Trip), compareDates);
}

void displayTrips(Trip trips[], int tripCount) {
	if (tripCount == 0) {
		printf("��ϵ� ������ �����ϴ�.\n");
		return;
	}

	for (int i = 0; i < tripCount; i++) {

		printf("\n���� #%d:\n", i + 1);
		printf("  ������: %s\n", trips[i].destination);
		printf("  ���� ��¥: %s\n", trips[i].startDate);
		printf("  ���� ��¥: %s\n", trips[i].endDate);
		printf("  �޸�: %s\n", trips[i].notes);
		printf("\n");
	}
}

int compareDates(const void* a, const void* b) {
	Trip* tripA = (Trip*)a;
	Trip* tripB = (Trip*)b;
	return strcmp(tripA->startDate, tripB->startDate);
}

void deleteTrip(Trip trips[], int* tripCount, int index) {
	if (index < 0 || index >= *tripCount) {
		printf("��ȿ���� ���� ���� ��ȣ�Դϴ�.\n");
		return;
	}

	// ������ ���� ��� ���� �� �迭 ��迭
	for (int i = index; i < *tripCount - 1; i++) {
		trips[i] = trips[i + 1];
	}
	(*tripCount)--;

	printf("���� ����� �����Ǿ����ϴ�.\n");
}

/************************�Һ� ���� ��� ���α׷�*****************************/


typedef struct {
	char category[50];
	float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;
float budget = 0;

void formatNumberWithCommas(char* dest, size_t size, float num);

// ���� ������ ���Ͽ� �����ϴ� �Լ�
void saveExpensesToFile() {
	FILE* file;
	errno_t err = fopen_s(&file, "expenses.txt", "w");
	if (err != 0) {
		printf("\033[1;31m������ �� �� �����ϴ�.\033[0m\n");
		return;
	}

	for (int i = 0; i < numExpenses; ++i) {
		fprintf(file, "%s %.2f\n", expenses[i].category, expenses[i].amount);
	}

	fclose(file);
}

// ���Ͽ��� ���� ������ �о���� �Լ�
void loadExpensesFromFile() {
	FILE* file;
	errno_t err = fopen_s(&file, "expenses.txt", "r");
	if (err != 0) {
		printf("\033[1;31m������ �� �� �����ϴ�.\033[0m\n");
		return;
	}

	while (!feof(file)) {
		fscanf_s(file, "%s %f", expenses[numExpenses].category, sizeof(expenses[numExpenses].category), &expenses[numExpenses].amount);
		numExpenses++;
	}

	fclose(file);
}

// ���� ������ �ʱ�ȭ�ϴ� �Լ�
void clearExpenses() {
	numExpenses = 0;
	printf("\033[1;32m���� ������ �ʱ�ȭ�Ǿ����ϴ�.\033[0m\n");
}

// ������ �Է��ϴ� �Լ�
void setBudget() {
	printf("\033[1;34m�� ������ �Է��ϼ���: \033[0m");
	scanf_s("%f", &budget);
	printf("\033[1;32m������ �����Ǿ����ϴ�.\033[0m\n");
}

// ������ �Է��ϴ� �Լ�
void addExpense() {
	if (numExpenses < MAX_EXPENSES) {
		Expense newExpense;
		printf("\033[1;34m���� ī�װ��� �Է��ϼ���: \033[0m");
		scanf_s("%s", newExpense.category, sizeof(newExpense.category));
		printf("\033[1;34m���� �ݾ��� �Է��ϼ���: \033[0m");
		scanf_s("%f", &newExpense.amount);
		if (newExpense.amount > budget) {
			printf("\033[1;31m���: ������ �ʰ��߽��ϴ�!\033[0m\n");
		}
		expenses[numExpenses++] = newExpense;
	}
	else {
		printf("\033[1;31m�� �̻� ������ �߰��� �� �����ϴ�.\033[0m\n");
	}
}

// ���� ������ ����ϰ� ���� ������ ǥ���ϴ� �Լ�
void printExpenses() {
	printf("\033[1;33m==== ���� ���� ====\033[0m\n");
	float totalExpenses = 0;
	char formattedAmount[50];

	for (int i = 0; i < numExpenses; ++i) {
		formatNumberWithCommas(formattedAmount, sizeof(formattedAmount), expenses[i].amount);
		printf("\033[1;36m%d. %s: %s\033[0m\n", i + 1, expenses[i].category, formattedAmount);
		totalExpenses += expenses[i].amount;
	}

	formatNumberWithCommas(formattedAmount, sizeof(formattedAmount), budget - totalExpenses);
	printf("\033[1;33m���� ����: %s\033[0m\n", formattedAmount);

	// ����ڰ� �Է��� ��ٸ� �� �ֵ��� �߰�
	printf("\033[1;34m�ڷ� ���÷��� ���� Ű�� �����ּ���...\033[0m");
	getchar(); // ���� Ű �Է� ���
	getchar(); // �߰� ���� �Է� �� ����
}

// ���� ������ �����ϴ� �Լ�
void deleteExpense() {
	int index;
	if (numExpenses == 0) {
		printf("\033[1;31m������ ���� ������ �����ϴ�.\033[0m\n");
		return;
	}
	printf("\033[1;33m==== ���� ���� ====\033[0m\n");
	for (int i = 0; i < numExpenses; ++i) {
		printf("\033[1;36m%d. %s: %.2f\033[0m\n", i + 1, expenses[i].category, expenses[i].amount);
	}
	printf("\033[1;34m������ ���� ������ ��ȣ�� �Է��ϼ���: \033[0m");
	scanf_s("%d", &index);
	if (index < 1 || index > numExpenses) {
		printf("\033[1;31m�ùٸ� ��ȣ�� �Է��ϼ���.\033[0m\n");
		return;
	}
	for (int i = index - 1; i < numExpenses - 1; ++i) {
		strcpy_s(expenses[i].category, sizeof(expenses[i].category), expenses[i + 1].category);
		expenses[i].amount = expenses[i + 1].amount;
	}
	numExpenses--;
	printf("\033[1;32m���� ������ �����Ǿ����ϴ�.\033[0m\n");
}

// ���ڸ� �޸��� ���е� ���ڿ��� ��ȯ�ϴ� �Լ�
void formatNumberWithCommas(char* dest, size_t size, float num) {
	char src[50];
	snprintf(src, sizeof(src), "%.2f", num); // �Ҽ��� ��° �ڸ����� ���

	int len = strlen(src);
	int decimal_pos = len - 3; // �Ҽ��� �ڸ� ã��

	// ���� �κ� ���� ���
	int integer_len = decimal_pos;

	int comma_count = (integer_len - 1) / 3; // �޸� ���� ���
	int dest_index = 0;
	int src_index = 0;

	// ���� �κ� ó��
	for (int i = 0; i < integer_len; i++) {
		if (i > 0 && (integer_len - i) % 3 == 0) {
			dest[dest_index++] = ','; // �޸� �߰�
		}
		dest[dest_index++] = src[src_index++];
	}

	// �Ҽ��� �� �Ҽ� �κ� ����
	while (src[src_index]) {
		dest[dest_index++] = src[src_index++];
	}
	dest[dest_index] = '\0'; // ���ڿ� ����
}
/****************************�޴� ��� ���α׷�**********************************/
void printMenu() {
	printf("\n\n\t<<���� ���� ���� ���α׷��Դϴ�.>>");
	printf("\n\n\n\t\tMAIN MENU:");

	printf("\n\n\t������ ��õ ver2.0\t[1]");
	printf("\n\n\t���� �޷�\t\t[2]");
	printf("\n\n\t������\t\t[3]");
	printf("\n\n\t�Һ�����/��������\t[4]");
	printf("\n\n\n\t���Ͻô� �޴��� �����Ͽ� �ֽʽÿ�: ");
}

/*********************************�����Լ�*************************************/
int main() {
	Trip trips[MAX_TRIPS];
	int tripCount = 0;

backMenu:
	printMenu();

	int menu;
	scanf_s("%d", &menu);
	switch (menu) {
	case 1:
	{
		int choice;
		while (1) {
			printf("\n=== ������ ��õ ���α׷� ===\n");
			printf("1. �ٴ尡 ��õ\n");
			printf("2. �� ��õ\n");
			printf("3. ��ȭ�� ��õ\n");
			printf("4. ���� ��õ\n");
			printf("5, �ؿ� ��õ\n");
			printf("0. �ڷ� ����\n");
			printf("����: ");
			scanf_s("%d", &choice);

			switch (choice) {
			case 1:
				recommendBeach();
				break;
			case 2:
				recommendMountain();
				break;
			case 3:
				recommendCity();
				break;
			case 4:
				recommendRestaurant();
				break;
			case 5:
				recommendTravelDestination();
				break;

			case 0:
			{
				system("cls");
				goto backMenu;
			}
			default:
				printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
			}
		}
	}

	case 2:
	{
		system("cls");
		int year, month;
		// �⵵ �Է�
		printf("\n\nyear : ");
		scanf_s("%d", &year);
		// �� �Է�
		printf("month : ");
		scanf_s("%d", &month);
		printMonth(year, month, trips, tripCount);

		int ch2;
		printf("\n\n�޴��� ���ư��÷��� [3]�� �����ּ���: ");
		scanf_s("%d", &ch2);
		if (ch2 == 3) {
			system("cls");
			goto backMenu;
		}
	}
	case 3:
	{
		int choice;

		loadTripsFromFile(trips, &tripCount);

		while (1) {
			printf("\n1. ���� �߰�\n");
			printf("2. ���� ��� ����\n");
			printf("3. ���� ����\n"); // ���ο� �޴� �߰�
			printf("4. �޴� ����\n");
			printf("����: ");
			scanf_s("%d", &choice);
			getchar(); // '\n' ���� ����

			switch (choice) {
			case 1:
				addTrip(trips, &tripCount);
				saveTripsToFile(trips, tripCount);
				break;
			case 2:
				displayTrips(trips, tripCount);
				break;
			case 3:
			{
				int index;
				printf("������ ���� ��ȣ�� �Է��ϼ���: ");
				scanf_s("%d", &index);
				deleteTrip(trips, &tripCount, index - 1); // �ε����� 1���� �����ϹǷ� 1�� ���ݴϴ�.
				saveTripsToFile(trips, tripCount);
				break;
			}
			case 4:
			{
				system("cls");
				goto backMenu;
			}
			default:
				printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
			}
		}
	}
	case 4:
	{
		// ���Ͽ��� ���� ������ �ҷ���
		loadExpensesFromFile();

		int choice;
		do {
			Sleep(500);
			system("cls");
			printf("\n\033[1;35m===== �޴� =====\033[0m\n");
			printf("\033[1;37m1. \033[1;37m�� ���� ����\n");
			printf("\033[1;37m2. \033[1;37m���� �Է�\n");
			printf("\033[1;37m3. \033[1;37m���� ���� ��ȸ\n");
			printf("\033[1;37m4. \033[1;37m���� ���� ����\n");
			printf("\033[1;37m5. \033[1;37m���� ���� �ʱ�ȭ\n");
			printf("\033[1;37m6. \033[1;37m�޴� ���ư���\n");
			printf("\033[1;35m�޴��� �����ϼ���: \033[0m");
			scanf_s("%d", &choice);

			switch (choice) {
			case 1:
				setBudget();
				break;
			case 2:
				addExpense();
				// ���� ������ ���Ͽ� ����
				saveExpensesToFile();
				break;
			case 3:
				printExpenses();
				break;
			case 4:
				deleteExpense();
				// ���� �� ���� ������ ���Ͽ� ����
				saveExpensesToFile();
				break;
			case 5:
				clearExpenses();
				// �ʱ�ȭ �� ���Ͽ� ����
				saveExpensesToFile();
				break;
			case 6:
				printf("\033[1;32m�޴��� ���ư��ϴ�.\033[0m\n");
				system("cls");
				goto backMenu;
				break;
			default:
				printf("\033[1;31m�ùٸ��� ���� �����Դϴ�. �ٽ� �������ּ���.\033[0m\n");
				break;
			}
		} while (choice != 6);
	}
	}
}

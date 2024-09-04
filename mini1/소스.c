#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#define MAX_EXPENSES 100
#define _CRT_SECURE_NO_WARNINGS
#define MAX_TRIPS 100
#define MAX_STR_LEN 100

/************************여행지 추천 프로그램******************************/
void showLoading() {
	printf("추천 중");
	for (int i = 0; i < 3; i++) {
		Sleep(500);  // 500ms 대기
		printf(".");
		fflush(stdout);
	}
	printf("\n");
}

void recommendBeach() {
	showLoading();
	const char* beaches[] = {
		"부산 해운대", "충남 대천", "강원 속초", "강원 삼척", "부산 광안리", "강릉 경포대",
		"인천 송도", "인천 을왕리", "거제 농소몽돌 해변", "충남 신두리", "제주 금능",
		"포항 영일대", "울산 간절곶", "충남 만리포", "경남 통영", "경북 울진", "강원 양양",
		"전남 여수", "경남 남해"
	};
	int index = rand() % (sizeof(beaches) / sizeof(beaches[0]));
	printf("추천 바닷가: %s\n", beaches[index]);
}

void recommendMountain() {
	showLoading();
	const char* mountains[] = {
		"설악산", "지리산", "한라산", "북한산", "태백산", "팔공산", "한라산", "금오산",
		"덕유산", "치악산", "팔봉산", "속리산", "무등산", "오대산", "가야산", "내장산",
		"주왕산", "소백산", "계룡산"
	};
	int index = rand() % (sizeof(mountains) / sizeof(mountains[0]));
	printf("추천 산: %s\n", mountains[index]);
}

void recommendCity() {
	showLoading();
	const char* cities[] = {
		"서울 명동", "부산 서면", "대구 동성로", "광주 충장로", "인천 구월동",
		"대전 은행동", "울산 삼산동", "수원 인계동", "성남 분당", "고양 일산",
		"청주 성안길", "창원 상남동", "전주 한옥마을", "제주도 중문"
	};
	int index = rand() % (sizeof(cities) / sizeof(cities[0]));
	printf("추천 번화가: %s\n", cities[index]);
}

void recommendRestaurant() {
	showLoading();
	const char* restaurants[] = {
		"전주 비빔밥", "부산 밀면", "대구 막창", "광주 떡갈비", "서울 불고기",
		"춘천 닭갈비", "안동 간고등어", "강릉 초당순두부", "목포 홍어", "순천 꼬막",
		"진주 육회비빔밥", "대전 성심당"
	};
	int index = rand() % (sizeof(restaurants) / sizeof(restaurants[0]));
	printf("추천 맛집: %s\n", restaurants[index]);
}

/*****************************해외 여행지 추천 프로그램************************/
void recommendTravelDestination() {
	
	const char* destinations[] = {
		"도쿄", "오사카", "후쿠오카", "삿포로", "교토",
		"파리", "런던", "로마", "바르셀로나", "베를린",
		"뉴욕", "로스앤젤레스", "라스베이거스", "샌프란시스코",
		"밴쿠버", "토론토", "시드니", "멜버른", "골드코스트",
		"방콕", "파타야", "치앙마이", "푸켓",
		"하노이", "호치민", "싱가포르", "홍콩", "마카오",
		"타이베이", "가오슝", "베이징", "상하이", "광저우",
		"칭다오", "하얼빈", "하와이", "괌", "사이판",
		"발리", "쿠알라룸푸르", "두바이", "이스탄불", "암스테르담",
		"프라하", "부다페스트", "헬싱키", "스톡홀름",
		"코펜하겐", "오슬로", "워싱턴 D.C.", "시카고",
		"마이애미", "댈러스", "애틀랜타", "뉴올리언스"
	};

	// 가중치 배열을 각 계절에 맞게 조정합니다.
	int weights[][56] = {
		// 봄 (한국의 봄은 대체로 3월, 4월, 5월)
		{8, 8, 8, 5, 5, 6, 6, 6, 6, 6, 4, 4, 3, 3, 5, 5, 5, 5, 5, 7, 7, 7, 7, 5, 5, 8, 8, 8, 6, 6, 4, 4, 4, 5, 5, 5, 8, 8, 7, 7, 5, 5, 6, 6, 6, 6, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5},
		// 여름 (한국의 여름은 대체로 6월, 7월, 8월)
		{8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 5, 5, 4, 4, 5, 5, 5, 5, 5, 8, 8, 8, 8, 5, 5, 8, 8, 8, 7, 7, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 6, 6, 5, 5, 5, 5, 5, 5, 4, 4, 5, 5, 5, 5, 5, 5},
		// 가을 (한국의 가을은 대체로 9월, 10월, 11월)
		{8, 8, 8, 5, 5, 6, 6, 6, 6, 6, 4, 4, 3, 3, 5, 5, 5, 5, 5, 7, 7, 7, 7, 5, 5, 8, 8, 8, 6, 6, 4, 4, 4, 5, 5, 5, 8, 8, 7, 7, 5, 5, 6, 6, 6, 6, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5},
		// 겨울 (한국의 겨울은 대체로 12월, 1월, 2월)
		{8, 8, 8, 7, 7, 5, 5, 5, 5, 5, 4, 4, 3, 3, 5, 5, 5, 5, 5, 8, 8, 8, 8, 5, 5, 8, 8, 8, 7, 7, 4, 4, 4, 5, 5, 5, 8, 8, 7, 7, 5, 5, 5, 5, 5, 5, 4, 4, 3, 3, 5, 5, 5, 5, 5, 5}
	};

	int season;
	printf("계절을 숫자로 입력하세요 (1=봄, 2=여름, 3=가을, 4=겨울): ");
	scanf_s("%d", &season);

	if (season < 1 || season > 4) {
		printf("잘못된 계절 입력입니다.\n");
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
	printf("추천 여행지: %s\n", destinations[index]);
}

/*******************************여행 달력 프로그램*********************************/

// 구조체 정의
typedef struct {
	char destination[MAX_STR_LEN];
	char startDate[MAX_STR_LEN];
	char endDate[MAX_STR_LEN];
	char notes[MAX_STR_LEN];
} Trip;

//함수의 원형
void printMonth(int year, int month, Trip trips[], int tripCount);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month, Trip trips[], int tripCount);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);
int isLeapYear(int year);
int isTripDay(int day, int month, int year, Trip trips[], int tripCount);

//year와 month를 전달 받아 해당 월을 출력 -> title, body
void printMonth(int year, int month, Trip trips[], int tripCount) {
	printMonthTitle(year, month);
	printMonthBody(year, month, trips, tripCount);
}

//월과 년도를 출력
void printMonthTitle(int year, int month) {
	printMonthName(month);
	printf(" %d\n", year);
	printf("-----------------------------\n");

	printf(" \033[0;31mSun\033[0m Mon Tue Wed Thu Fri \033[0;34mSat\033[0m\n"); //ANSI Color로 색깔 바꿈
}

//month를 전달 받아 해당 달의 영어 이름을 출력
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

//year와 month를 전달 받아 요일과 일을 출력
void printMonthBody(int year, int month, Trip trips[], int tripCount) {
	int startday = getStartDay(year, month);
	int numberofdaysinmonth = getNumberOfDaysInMonth(year, month);

	for (int i = 0; i < startday; i++) printf("    ");
	for (int i = 1; i <= numberofdaysinmonth; i++) {
		if (isTripDay(i, month, year, trips, tripCount)) {
			printf("\033[1;32m%4d\033[0m", i); // 여행 날짜는 녹색으로 강조
		}
		else {
			printf("%4d", i);
		}
		if ((i + startday) % 7 == 0) printf("\n");
	}
}

// 해당 월의 시작하는 날이 몇 요일인지 찾는 함수
int getStartDay(int year, int month) {
	int startday1800 = 3;
	int totalnumberofdays = getTotalNumberOfDays(year, month);
	return (startday1800 + totalnumberofdays) % 7;
}

// 1800년 1월 1일 부터 며칠이 되는지 계산
int getTotalNumberOfDays(int year, int month) {
	int total = 0;
	for (int i = 1800; i < year; i++) {
		if (isLeapYear(i)) total += 366;
		else total += 365;
	}
	for (int i = 1; i < month; i++) total = total + getNumberOfDaysInMonth(year, i);
	return total;
}

//year와 month를 전달 받아 해당월에 몇일이 있는지
int getNumberOfDaysInMonth(int year, int month) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	if (month == 2) {
		if (isLeapYear(year) == 1) return 29;
		else return 28;
	}
}

//year를 전달받아 윤년인지 확인
int isLeapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return 1;
	else return 0;
}

// 특정 날짜가 여행 날짜인지 확인하는 함수
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

/******************************여행 기록***************************************/
void addTrip(Trip trips[], int* tripCount);
void saveTripsToFile(Trip trips[], int tripCount);
void loadTripsFromFile(Trip trips[], int* tripCount);
void displayTrips(Trip trips[], int tripCount);
int compareDates(const void* a, const void* b);

void addTrip(Trip trips[], int* tripCount) {
	if (*tripCount >= MAX_TRIPS) {
		printf("더 이상 여행을 추가할 수 없습니다.\n");
		return;
	}

	Trip newTrip;

	printf("목적지: ");
	scanf_s("%99s", newTrip.destination, (unsigned)_countof(newTrip.destination));
	getchar(); // '\n' 문자 제거

	printf("시작 날짜 (YYYY-MM-DD): ");
	scanf_s("%99s", newTrip.startDate, (unsigned)_countof(newTrip.startDate));
	getchar(); // '\n' 문자 제거

	printf("종료 날짜 (YYYY-MM-DD): ");
	scanf_s("%99s", newTrip.endDate, (unsigned)_countof(newTrip.endDate));
	getchar(); // '\n' 문자 제거

	printf("메모: ");
	scanf_s("%99[^\n]", newTrip.notes, (unsigned)_countof(newTrip.notes));
	getchar(); // '\n' 문자 제거

	trips[*tripCount] = newTrip;
	(*tripCount)++;
}

void saveTripsToFile(Trip trips[], int tripCount) {
	FILE* file;
	errno_t err = fopen_s(&file, "trips.txt", "w");
	if (err != 0) {
		printf("파일을 열 수 없습니다.\n");
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
		return; // 파일이 없으면 그냥 리턴
	}

	while (fscanf_s(file, "%99s\n%99s\n%99s\n%99[^\n]\n", trips[*tripCount].destination, (unsigned)_countof(trips[*tripCount].destination), trips[*tripCount].startDate, (unsigned)_countof(trips[*tripCount].startDate), trips[*tripCount].endDate, (unsigned)_countof(trips[*tripCount].endDate), trips[*tripCount].notes, (unsigned)_countof(trips[*tripCount].notes)) == 4) {
		(*tripCount)++;
	}

	fclose(file);

	// 날짜별로 정렬
	qsort(trips, *tripCount, sizeof(Trip), compareDates);
}

void displayTrips(Trip trips[], int tripCount) {
	if (tripCount == 0) {
		printf("등록된 여행이 없습니다.\n");
		return;
	}

	for (int i = 0; i < tripCount; i++) {

		printf("\n여행 #%d:\n", i + 1);
		printf("  목적지: %s\n", trips[i].destination);
		printf("  시작 날짜: %s\n", trips[i].startDate);
		printf("  종료 날짜: %s\n", trips[i].endDate);
		printf("  메모: %s\n", trips[i].notes);
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
		printf("유효하지 않은 여행 번호입니다.\n");
		return;
	}

	// 선택한 여행 기록 삭제 후 배열 재배열
	for (int i = index; i < *tripCount - 1; i++) {
		trips[i] = trips[i + 1];
	}
	(*tripCount)--;

	printf("여행 기록이 삭제되었습니다.\n");
}

/************************소비 지출 계산 프로그램*****************************/


typedef struct {
	char category[50];
	float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;
float budget = 0;

void formatNumberWithCommas(char* dest, size_t size, float num);

// 지출 내역을 파일에 저장하는 함수
void saveExpensesToFile() {
	FILE* file;
	errno_t err = fopen_s(&file, "expenses.txt", "w");
	if (err != 0) {
		printf("\033[1;31m파일을 열 수 없습니다.\033[0m\n");
		return;
	}

	for (int i = 0; i < numExpenses; ++i) {
		fprintf(file, "%s %.2f\n", expenses[i].category, expenses[i].amount);
	}

	fclose(file);
}

// 파일에서 지출 내역을 읽어오는 함수
void loadExpensesFromFile() {
	FILE* file;
	errno_t err = fopen_s(&file, "expenses.txt", "r");
	if (err != 0) {
		printf("\033[1;31m파일을 열 수 없습니다.\033[0m\n");
		return;
	}

	while (!feof(file)) {
		fscanf_s(file, "%s %f", expenses[numExpenses].category, sizeof(expenses[numExpenses].category), &expenses[numExpenses].amount);
		numExpenses++;
	}

	fclose(file);
}

// 지출 내역을 초기화하는 함수
void clearExpenses() {
	numExpenses = 0;
	printf("\033[1;32m지출 내역이 초기화되었습니다.\033[0m\n");
}

// 예산을 입력하는 함수
void setBudget() {
	printf("\033[1;34m총 예산을 입력하세요: \033[0m");
	scanf_s("%f", &budget);
	printf("\033[1;32m예산이 설정되었습니다.\033[0m\n");
}

// 지출을 입력하는 함수
void addExpense() {
	if (numExpenses < MAX_EXPENSES) {
		Expense newExpense;
		printf("\033[1;34m지출 카테고리를 입력하세요: \033[0m");
		scanf_s("%s", newExpense.category, sizeof(newExpense.category));
		printf("\033[1;34m지출 금액을 입력하세요: \033[0m");
		scanf_s("%f", &newExpense.amount);
		if (newExpense.amount > budget) {
			printf("\033[1;31m경고: 예산을 초과했습니다!\033[0m\n");
		}
		expenses[numExpenses++] = newExpense;
	}
	else {
		printf("\033[1;31m더 이상 지출을 추가할 수 없습니다.\033[0m\n");
	}
}

// 지출 내역을 출력하고 남은 예산을 표시하는 함수
void printExpenses() {
	printf("\033[1;33m==== 지출 내역 ====\033[0m\n");
	float totalExpenses = 0;
	char formattedAmount[50];

	for (int i = 0; i < numExpenses; ++i) {
		formatNumberWithCommas(formattedAmount, sizeof(formattedAmount), expenses[i].amount);
		printf("\033[1;36m%d. %s: %s\033[0m\n", i + 1, expenses[i].category, formattedAmount);
		totalExpenses += expenses[i].amount;
	}

	formatNumberWithCommas(formattedAmount, sizeof(formattedAmount), budget - totalExpenses);
	printf("\033[1;33m남은 예산: %s\033[0m\n", formattedAmount);

	// 사용자가 입력을 기다릴 수 있도록 추가
	printf("\033[1;34m뒤로 가시려면 엔터 키를 눌러주세요...\033[0m");
	getchar(); // 엔터 키 입력 대기
	getchar(); // 추가 엔터 입력 시 진행
}

// 지출 내역을 삭제하는 함수
void deleteExpense() {
	int index;
	if (numExpenses == 0) {
		printf("\033[1;31m삭제할 지출 내역이 없습니다.\033[0m\n");
		return;
	}
	printf("\033[1;33m==== 지출 내역 ====\033[0m\n");
	for (int i = 0; i < numExpenses; ++i) {
		printf("\033[1;36m%d. %s: %.2f\033[0m\n", i + 1, expenses[i].category, expenses[i].amount);
	}
	printf("\033[1;34m삭제할 지출 내역의 번호를 입력하세요: \033[0m");
	scanf_s("%d", &index);
	if (index < 1 || index > numExpenses) {
		printf("\033[1;31m올바른 번호를 입력하세요.\033[0m\n");
		return;
	}
	for (int i = index - 1; i < numExpenses - 1; ++i) {
		strcpy_s(expenses[i].category, sizeof(expenses[i].category), expenses[i + 1].category);
		expenses[i].amount = expenses[i + 1].amount;
	}
	numExpenses--;
	printf("\033[1;32m지출 내역이 삭제되었습니다.\033[0m\n");
}

// 숫자를 콤마로 구분된 문자열로 변환하는 함수
void formatNumberWithCommas(char* dest, size_t size, float num) {
	char src[50];
	snprintf(src, sizeof(src), "%.2f", num); // 소수점 둘째 자리까지 출력

	int len = strlen(src);
	int decimal_pos = len - 3; // 소수점 자리 찾기

	// 정수 부분 길이 계산
	int integer_len = decimal_pos;

	int comma_count = (integer_len - 1) / 3; // 콤마 개수 계산
	int dest_index = 0;
	int src_index = 0;

	// 정수 부분 처리
	for (int i = 0; i < integer_len; i++) {
		if (i > 0 && (integer_len - i) % 3 == 0) {
			dest[dest_index++] = ','; // 콤마 추가
		}
		dest[dest_index++] = src[src_index++];
	}

	// 소수점 및 소수 부분 복사
	while (src[src_index]) {
		dest[dest_index++] = src[src_index++];
	}
	dest[dest_index] = '\0'; // 문자열 종료
}
/****************************메뉴 출력 프로그램**********************************/
void printMenu() {
	printf("\n\n\t<<여행 종합 관리 프로그램입니다.>>");
	printf("\n\n\n\t\tMAIN MENU:");

	printf("\n\n\t여행지 추천 ver2.0\t[1]");
	printf("\n\n\t여행 달력\t\t[2]");
	printf("\n\n\t여행기록\t\t[3]");
	printf("\n\n\t소비지출/남은예산\t[4]");
	printf("\n\n\n\t원하시는 메뉴를 선택하여 주십시오: ");
}

/*********************************메인함수*************************************/
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
			printf("\n=== 여행지 추천 프로그램 ===\n");
			printf("1. 바닷가 추천\n");
			printf("2. 산 추천\n");
			printf("3. 번화가 추천\n");
			printf("4. 맛집 추천\n");
			printf("5, 해외 추천\n");
			printf("0. 뒤로 가기\n");
			printf("선택: ");
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
				printf("잘못된 선택입니다. 다시 시도하세요.\n");
			}
		}
	}

	case 2:
	{
		system("cls");
		int year, month;
		// 년도 입력
		printf("\n\nyear : ");
		scanf_s("%d", &year);
		// 월 입력
		printf("month : ");
		scanf_s("%d", &month);
		printMonth(year, month, trips, tripCount);

		int ch2;
		printf("\n\n메뉴로 돌아가시려면 [3]을 눌러주세요: ");
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
			printf("\n1. 여행 추가\n");
			printf("2. 여행 목록 보기\n");
			printf("3. 여행 삭제\n"); // 새로운 메뉴 추가
			printf("4. 메뉴 가기\n");
			printf("선택: ");
			scanf_s("%d", &choice);
			getchar(); // '\n' 문자 제거

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
				printf("삭제할 여행 번호를 입력하세요: ");
				scanf_s("%d", &index);
				deleteTrip(trips, &tripCount, index - 1); // 인덱스는 1부터 시작하므로 1을 빼줍니다.
				saveTripsToFile(trips, tripCount);
				break;
			}
			case 4:
			{
				system("cls");
				goto backMenu;
			}
			default:
				printf("잘못된 선택입니다. 다시 시도하세요.\n");
			}
		}
	}
	case 4:
	{
		// 파일에서 지출 내역을 불러옴
		loadExpensesFromFile();

		int choice;
		do {
			Sleep(500);
			system("cls");
			printf("\n\033[1;35m===== 메뉴 =====\033[0m\n");
			printf("\033[1;37m1. \033[1;37m총 예산 설정\n");
			printf("\033[1;37m2. \033[1;37m지출 입력\n");
			printf("\033[1;37m3. \033[1;37m지출 내역 조회\n");
			printf("\033[1;37m4. \033[1;37m지출 내역 삭제\n");
			printf("\033[1;37m5. \033[1;37m지출 내역 초기화\n");
			printf("\033[1;37m6. \033[1;37m메뉴 돌아가기\n");
			printf("\033[1;35m메뉴를 선택하세요: \033[0m");
			scanf_s("%d", &choice);

			switch (choice) {
			case 1:
				setBudget();
				break;
			case 2:
				addExpense();
				// 지출 내역을 파일에 저장
				saveExpensesToFile();
				break;
			case 3:
				printExpenses();
				break;
			case 4:
				deleteExpense();
				// 삭제 후 지출 내역을 파일에 저장
				saveExpensesToFile();
				break;
			case 5:
				clearExpenses();
				// 초기화 후 파일에 저장
				saveExpensesToFile();
				break;
			case 6:
				printf("\033[1;32m메뉴로 돌아갑니다.\033[0m\n");
				system("cls");
				goto backMenu;
				break;
			default:
				printf("\033[1;31m올바르지 않은 선택입니다. 다시 선택해주세요.\033[0m\n");
				break;
			}
		} while (choice != 6);
	}
	}
}

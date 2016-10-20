// HW.DS2.C3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct human{
	char * name;
	int age;
	float salary;
}human_t;

void setPerson(human_t * person, char * name, int age, float salary){
	person->name = name;
	person->age = age;
	person->salary = salary;
}

int humansEqualvalue(human_t person1, human_t person2){
	if (strcmp(person1.name, person2.name)){
		return FALSE;
	}
	else if (person1.age != person2.age){
		return FALSE;
	}
	else if (person1.salary != person2.salary)
	{
		return FALSE;
	}
	return TRUE;
}

int humansEqualReference(human_t * person1, human_t * person2){
	if (strcmp(person1->name, person2->name)){
		return FALSE;
	}
	else if (person1->age != person2->age){
		return FALSE;
	}
	else if (person1->salary != person2->salary)
	{
		return FALSE;
	}
	return TRUE;
}

int _tmain(int argc, _TCHAR* argv[])
{
	human_t	person1, person2;
	
	setPerson(&person1, "LeeInJae", 26, 1000000000);
	setPerson(&person2, "LeeInJae", 22, 1000000000);

	printf("CallByValue Check Person1, Person2 = %d\n", humansEqualvalue(person1, person2));
	printf("CallByReference Check Person1, Person2 = %d\n", humansEqualReference(&person1, &person2));
	getchar();
	return 0;
}


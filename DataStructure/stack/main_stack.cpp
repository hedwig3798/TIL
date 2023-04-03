/// 
/// 스택
///	자료구조 알고리즘 시간에 만들어봤다.
/// 
/// 함수, 배열, 전역변수를 이용한 스택
/// 인덱스의 예외처리, 타입의 1개로 고정
/// 2023.04.02
///  
// 외부 라이브러리 헤더 포함
#include <iostream>

/// 전역변수
char * g_Stack;			// 동적 할당을 받을 스텍
int g_StackIndex = 0;	// 배열 내에 값을 넣을 수 있는 곳을 가르킨다.
int g_StackSize = 0;	// 스텍의 총 크기

// 함수들
// 스텍의 내용을 초기화한다.
void ResetStack() {
	for (int i = 0; i < g_StackSize; i++) {
		// 인덱스를 사용한 스텍은 이 초기화가 필요 없을 수도 있다.
		// 그러나 명시적으로 초기화 해준다.
		g_Stack[i] = -1;
	}
}

// 스텍 시작
void InitStack(int _size) {
	g_StackSize = _size;
	g_Stack = new char[_size];
	ResetStack();
}

// 스텍의 내용 출력
void PrintStack() {
	std::cout << "사이즈: " << g_StackSize << ", 인덱스: " << g_StackIndex << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	for (int i = 0; i < g_StackSize; i++) {
		if (g_Stack[i] == -1) 
			continue;
		
		std::cout<<'['<< g_Stack[i] <<']'<< ' ';

	}

	std::cout << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << std::endl;
}


void ResizeStack(int _size) {
	char* temp = new char[_size];
	g_StackSize = _size;

	for (int i = 0; i < g_StackSize; i++) {
		temp[i] = g_Stack[i];
	}
	delete[]g_Stack;
	g_Stack = temp;
}

// 스텍 데이터 푸쉬
void PushDataToStack(int data) {
	if (g_StackIndex >= g_StackSize) {
		// 문제 있음
		std::cout << "스텍이 가득 차, 사이즈를 " << g_StackSize+1 << "로 증가시켰습니다." << std::endl << std::endl;
		ResizeStack(g_StackSize + 1);
	}

	// 스텍의 top을 가리키는 인덱스를 통해서 데이터를 실제로 넣는다.
	g_Stack[g_StackIndex] = data;

	// 인덱스를 증가시킨다.
	g_StackIndex++;
	PrintStack();
}

// 스텍 데이터 팝
int PopDataToStack() {
	if (g_StackIndex <= 0) {
		// 문제 있음
		std::cout << "스텍이 비어있어 작업에 실패 했습니다." << std::endl << std::endl;
		return -1;
	}

	// 반환이 될 값을 임시로 담는 지역 변수
	// 인덱스가 스텍의 top을 가리키므로 바로 아래 데이터를 뽑는다.
	char _result = g_Stack[g_StackIndex - 1];

	g_Stack[g_StackIndex - 1] = -1;

	// 인덱스를 감소시킨다.
	g_StackIndex--;
	std::cout << std::endl << "스텍에서 " << _result << "을 뺐습니다." << std::endl;
	PrintStack();
	return _result;
}

int main() {
	// 스텍의 시작
	InitStack(10);
	// 스텍 초기화
	ResetStack();
	// 빈 스텍 상태 출력
	PrintStack();
	// 스텍에 0 부터 가득찰 때까지 데이터 입력
	for (int i = 0; i < g_StackSize; i++) {
		PushDataToStack(i + '0');
	}

	// 가득 찬 스텍에 추가 데이터 입력
	PushDataToStack('a');

	// 스텍에서 데이터 전부 지우기
	for (int i = 0; i < g_StackSize; i++) {
		PopDataToStack();
	}

	// 빈 스텍에서 데이터 지우기 시도
	PopDataToStack();

	int stop;
	std::cin >> stop;
}
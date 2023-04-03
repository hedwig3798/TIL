/// 
/// 큐
///	자료구조 알고리즘 시간에 만들어봤다.
/// 
/// 함수, 배열, 전역변수를 이용한 스택
/// 인덱스의 예외처리, 타입의 1개로 고정
/// 2023.04.02
///  


#include <iostream>

char* g_Queue;			// 동적 할당을 받을 큐
int g_QueueRear = 0;	// 배열 내에 값을 넣을 수 있는 곳을 가르킨다.
int g_QueueFront = 0;	// 배열 내의 값을 빼는 곳을 가르킨다.
int g_QueueSize = 0;	// 큐의 총 크기
int g_QueueDataSize = 0;


// 함수들

// 큐의 내용을 초기화한다.
void ResetQueue() {
	for (int i = 0; i < g_QueueSize; i++) {
		// 인덱스를 사용한 스텍은 이 초기화가 필요 없을 수도 있다.
		// 그러나 명시적으로 초기화 해준다.
		g_Queue[i] = -1;
	}
}

// 큐 시작
void InitQueue(int _size) {
	g_QueueSize = _size;
	g_Queue = new char[_size];
	ResetQueue();
}

void ResizeQueue(int _size) {
	char* temp = new char[_size];
	g_QueueSize = _size;

	for (int i = 0; i < g_QueueSize-1; i++) {
		temp[i] = g_Queue[(i + g_QueueFront) % (g_QueueSize-1)];
	}
	g_QueueFront = 0;
	g_QueueRear = g_QueueSize - 1;
	delete[]g_Queue;
	g_Queue = temp;
}

// 큐의 내용 출력
void PrintQueue() {
	std::cout << "사이즈: " << g_QueueSize << ", 앞: " << g_QueueFront << ", 뒤: " << g_QueueRear << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;

	for (int i = 0; i < g_QueueSize; i++) {
		if (g_Queue[i] == -1)
			continue;
		if (i == g_QueueFront) 
			std::cout << "[[" << g_Queue[i] << "]]" << ' ';
		else 
			std::cout << '[' << g_Queue[i] << ']' << ' ';

	}

	std::cout << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

// 스텍 데이터 푸쉬
void PushDataToQueue(int data) {
	if (g_QueueDataSize >= g_QueueSize) {
		// 문제 있음
		std::cout << "큐가 가득 차, 사이즈를 " << g_QueueSize + 1 << "로 증가시켰습니다." << std::endl << std::endl;
		ResizeQueue(g_QueueSize + 1);
	}

	// 스텍의 top을 가리키는 인덱스를 통해서 데이터를 실제로 넣는다.
	g_Queue[g_QueueRear] = data;

	// 인덱스를 증가시킨다.
	g_QueueRear = (g_QueueRear + 1) % g_QueueSize;
	g_QueueDataSize++;
	PrintQueue();
}

// 스텍 데이터 팝
int PopDataToQueue() {
	if (g_QueueDataSize <= 0) {
		// 문제 있음
		std::cout << "큐가 비었습니다." << std::endl << std::endl;
		return -1;
	}

	// 반환이 될 값을 임시로 담는 지역 변수
	// 인덱스가 스텍의 top을 가리키므로 바로 아래 데이터를 뽑는다.
	char _result = g_Queue[g_QueueFront];

	g_Queue[g_QueueFront] = -1;

	// 인덱스를 감소시킨다.
	g_QueueFront = (g_QueueFront + 1) % g_QueueSize;
	g_QueueDataSize--;
	std::cout << std::endl << "큐에서 " << _result << "을 뺐습니다." << std::endl;
	PrintQueue();
	return _result;
}

int main() {
	// 크기가 10인 큐 선언 및 초기화
	InitQueue(10);
	ResetQueue();
	PrintQueue();

	// 큐에 데이터를 12번 넣고 빼기 (환형 큐)
	for (int i = 0; i < 12; i++) {
		PushDataToQueue(i + 'a');
		PopDataToQueue();
	}

	// 11개의 데이터를 넣기 (오버플로우 발생시 크기 증가)
	for (int i = 0; i < 11; i++) {
		PushDataToQueue(i + 'a');
	}

	// 데이터를 모드 지우고 난 후 한번 더 지우기 시도 (언더플로우 예외처리)
	for (int i = 0; i <= g_QueueSize; i++) {
		PopDataToQueue();
	}

	int stop;
	std::cin >> stop;

}
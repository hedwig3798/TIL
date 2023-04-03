/// 
/// ť
///	�ڷᱸ�� �˰��� �ð��� �����ô�.
/// 
/// �Լ�, �迭, ���������� �̿��� ����
/// �ε����� ����ó��, Ÿ���� 1���� ����
/// 2023.04.02
///  


#include <iostream>

char* g_Queue;			// ���� �Ҵ��� ���� ť
int g_QueueRear = 0;	// �迭 ���� ���� ���� �� �ִ� ���� ����Ų��.
int g_QueueFront = 0;	// �迭 ���� ���� ���� ���� ����Ų��.
int g_QueueSize = 0;	// ť�� �� ũ��
int g_QueueDataSize = 0;


// �Լ���

// ť�� ������ �ʱ�ȭ�Ѵ�.
void ResetQueue() {
	for (int i = 0; i < g_QueueSize; i++) {
		// �ε����� ����� ������ �� �ʱ�ȭ�� �ʿ� ���� ���� �ִ�.
		// �׷��� ��������� �ʱ�ȭ ���ش�.
		g_Queue[i] = -1;
	}
}

// ť ����
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

// ť�� ���� ���
void PrintQueue() {
	std::cout << "������: " << g_QueueSize << ", ��: " << g_QueueFront << ", ��: " << g_QueueRear << std::endl;
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

// ���� ������ Ǫ��
void PushDataToQueue(int data) {
	if (g_QueueDataSize >= g_QueueSize) {
		// ���� ����
		std::cout << "ť�� ���� ��, ����� " << g_QueueSize + 1 << "�� �������׽��ϴ�." << std::endl << std::endl;
		ResizeQueue(g_QueueSize + 1);
	}

	// ������ top�� ����Ű�� �ε����� ���ؼ� �����͸� ������ �ִ´�.
	g_Queue[g_QueueRear] = data;

	// �ε����� ������Ų��.
	g_QueueRear = (g_QueueRear + 1) % g_QueueSize;
	g_QueueDataSize++;
	PrintQueue();
}

// ���� ������ ��
int PopDataToQueue() {
	if (g_QueueDataSize <= 0) {
		// ���� ����
		std::cout << "ť�� ������ϴ�." << std::endl << std::endl;
		return -1;
	}

	// ��ȯ�� �� ���� �ӽ÷� ��� ���� ����
	// �ε����� ������ top�� ����Ű�Ƿ� �ٷ� �Ʒ� �����͸� �̴´�.
	char _result = g_Queue[g_QueueFront];

	g_Queue[g_QueueFront] = -1;

	// �ε����� ���ҽ�Ų��.
	g_QueueFront = (g_QueueFront + 1) % g_QueueSize;
	g_QueueDataSize--;
	std::cout << std::endl << "ť���� " << _result << "�� �����ϴ�." << std::endl;
	PrintQueue();
	return _result;
}

int main() {
	// ũ�Ⱑ 10�� ť ���� �� �ʱ�ȭ
	InitQueue(10);
	ResetQueue();
	PrintQueue();

	// ť�� �����͸� 12�� �ְ� ���� (ȯ�� ť)
	for (int i = 0; i < 12; i++) {
		PushDataToQueue(i + 'a');
		PopDataToQueue();
	}

	// 11���� �����͸� �ֱ� (�����÷ο� �߻��� ũ�� ����)
	for (int i = 0; i < 11; i++) {
		PushDataToQueue(i + 'a');
	}

	// �����͸� ��� ����� �� �� �ѹ� �� ����� �õ� (����÷ο� ����ó��)
	for (int i = 0; i <= g_QueueSize; i++) {
		PopDataToQueue();
	}

	int stop;
	std::cin >> stop;

}
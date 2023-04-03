/// 
/// ����
///	�ڷᱸ�� �˰��� �ð��� �����ô�.
/// 
/// �Լ�, �迭, ���������� �̿��� ����
/// �ε����� ����ó��, Ÿ���� 1���� ����
/// 2023.04.02
///  
// �ܺ� ���̺귯�� ��� ����
#include <iostream>

/// ��������
char * g_Stack;			// ���� �Ҵ��� ���� ����
int g_StackIndex = 0;	// �迭 ���� ���� ���� �� �ִ� ���� ����Ų��.
int g_StackSize = 0;	// ������ �� ũ��

// �Լ���
// ������ ������ �ʱ�ȭ�Ѵ�.
void ResetStack() {
	for (int i = 0; i < g_StackSize; i++) {
		// �ε����� ����� ������ �� �ʱ�ȭ�� �ʿ� ���� ���� �ִ�.
		// �׷��� ��������� �ʱ�ȭ ���ش�.
		g_Stack[i] = -1;
	}
}

// ���� ����
void InitStack(int _size) {
	g_StackSize = _size;
	g_Stack = new char[_size];
	ResetStack();
}

// ������ ���� ���
void PrintStack() {
	std::cout << "������: " << g_StackSize << ", �ε���: " << g_StackIndex << std::endl;
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

// ���� ������ Ǫ��
void PushDataToStack(int data) {
	if (g_StackIndex >= g_StackSize) {
		// ���� ����
		std::cout << "������ ���� ��, ����� " << g_StackSize+1 << "�� �������׽��ϴ�." << std::endl << std::endl;
		ResizeStack(g_StackSize + 1);
	}

	// ������ top�� ����Ű�� �ε����� ���ؼ� �����͸� ������ �ִ´�.
	g_Stack[g_StackIndex] = data;

	// �ε����� ������Ų��.
	g_StackIndex++;
	PrintStack();
}

// ���� ������ ��
int PopDataToStack() {
	if (g_StackIndex <= 0) {
		// ���� ����
		std::cout << "������ ����־� �۾��� ���� �߽��ϴ�." << std::endl << std::endl;
		return -1;
	}

	// ��ȯ�� �� ���� �ӽ÷� ��� ���� ����
	// �ε����� ������ top�� ����Ű�Ƿ� �ٷ� �Ʒ� �����͸� �̴´�.
	char _result = g_Stack[g_StackIndex - 1];

	g_Stack[g_StackIndex - 1] = -1;

	// �ε����� ���ҽ�Ų��.
	g_StackIndex--;
	std::cout << std::endl << "���ؿ��� " << _result << "�� �����ϴ�." << std::endl;
	PrintStack();
	return _result;
}

int main() {
	// ������ ����
	InitStack(10);
	// ���� �ʱ�ȭ
	ResetStack();
	// �� ���� ���� ���
	PrintStack();
	// ���ؿ� 0 ���� ������ ������ ������ �Է�
	for (int i = 0; i < g_StackSize; i++) {
		PushDataToStack(i + '0');
	}

	// ���� �� ���ؿ� �߰� ������ �Է�
	PushDataToStack('a');

	// ���ؿ��� ������ ���� �����
	for (int i = 0; i < g_StackSize; i++) {
		PopDataToStack();
	}

	// �� ���ؿ��� ������ ����� �õ�
	PopDataToStack();

	int stop;
	std::cin >> stop;
}
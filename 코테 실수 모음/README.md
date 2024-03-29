# 코딩테스트 자주하는 실수 모음
### 아무리 봐도 정답이 맞는데 자꾸 틀릴 때 보는 체크리스트
---
#### 시간 초과
  1. cout, cin의 싱크 처리를 했는지   
    안했다면 싱크 처리를 하거나, printf, scanf를 대신 사용할 것
  2. cout << endl;   
    endl 보다 "\n" 의 실행속도가 월등히 빠르므로 대신 사용할 것

---
#### 메모리 초과
  1. BFS 사용의 경우   
    큐에 넣기 전에 방문 여부 체크하기, 뺴면서 체크하면 중복 방문이 일어나게 된다.
  2. DFS 사용의 경우 (stack)   
    스텍에서 빼면서 방문 여부 체크하가, BFS 처럼 넣기 전에 체크하면 DFS가 이루어지지 않는다.
---
#### 기타
  1. 자료형 체크하기   
    가끔 int 자료를 제공하는데 연산시 INT_MAX를 넘기는 경우가 있다. 결과가 매우 커질것 같으면 long long을 사용해보자
  2. 배열의 축 생각하기   
    배열의 row,col을 잘못 입력했을 수 도 있다.
  3. 예외처리   
    백준의 경우 예외 처리 후 return 0 을 해야된다. 진짜 기본적이지만 은근 까먹는 경우가 많다.
  4. 입력 및 출력
    백준의 2차원 배열 입력에 띄어쓰기가 없이 주어질떄 cin을 사용하면 한 줄 전체를 가져오게 된다. 이 때문에 배열이 제대로 만들어 지지 않으므로 주의해야 된다.   
    사용할 수 있는 방법은 아래와 같다.   
        string으로 입력을 받아서 한 줄 전체를 다 받는다.   
        일일히 하나씩 파싱한다.
---
#### 알고리즘 실수   
  1. 와샬-플로이드   
    3중 for문 설정시 거처가는 정점 -> 출발 정점 -> 도착 정점 순으로 순회 해야 된다.

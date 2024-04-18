//#include <iostream>
//#include <vector>
//#define MAX 8
//using namespace std;
//
//int arr[MAX]; //�־��� ����
//bool visited[MAX]; //�湮, �ߺ� ����
//vector<int> vec; //����� ����
//int cnt;
//int N, M;
//
//void Print()
//{
//	for (int i = 0; i < vec.size(); i++)
//		cout << vec[i] << ' ';
//	cout << '\n';
//	return;
//}
//
//void DFS(int cnt)
//{
//	if (cnt == M) {
//		Print();
//		return;
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//		if (visited[i]) continue;
//		visited[i] = true;
//		vec.push_back(arr[i]);
//		DFS(cnt + 1);
//		vec.pop_back();
//		visited[i] = false;
//	}
//}
//
//
//int main() {
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//	{
//		arr[i] = i + 1;
//		visited[i] = false;
//	}
//	DFS(0);
//}
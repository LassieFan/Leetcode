#include <iostream>
#include <vector>
using namespace std;

//����n����λ����Ӧÿ���ˣ�ֻ��һ��������λ�ã����е������
//���Դӷ�������n���ˣ������������������� S(n) = (n-1)* (F(n-1)+F(n-2));
//��ô����n����ֻ��һ�������ԣ�����n-1���������ܹ���n�֣�����Ϊ n * S(n-1);


//�ݹ�汾
int Judge1(int m)
{
	if (m == 1)       //1����������0
		return 0;
	if (m == 2)       //2����������1
		return 1;

	return (m - 1)*(Judge1(m - 1)+ Judge1(m - 2));
}


//�ǵݹ�汾
int Judge2(int m)
{
	vector<int> vec;
	if (m == 1)
		return 0;
	if (m == 2)
		return 1;
	vec.push_back(0);
	vec.push_back(1);
	int x = m;
	int y = 2;
	int i = 0;
	int j = 1;
	while (x > 3)
	{
		vec.push_back(y*(vec[i++] + vec[j++]));
		x--;
		y++;
	}
	return (m - 1)*(vec[m - 2] + vec[m - 3]);
}

int main()
{
	int m;
	cin >> m;
	cout << m * Judge1(m - 1) << endl;
	cout << m * Judge2(m - 1) << endl;
}

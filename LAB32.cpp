//Дано натуральное число N.Необходимо представить его в виде сум/*мы точных кубов, содержащей наименьшее число слагаемых.
//Программа должна вывести это число слагаемых и разложение в виде суммы.Если возможных решений несколько, выведите любое из них.*/
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int max = cbrt(n);
	if (max * max * max == n)
	{
		cout << 1 << endl;
		cout << max << "^3";
		return 0;
	}
	int max1 = 10;
	vector<int> answer;
	for (int i = 1; i < max + 1; i++)
	{
		vector<int> curr;
		curr.push_back(i);
		int m = n - i * i * i;

		while (m > 0)
		{
			int a = int(cbrt(m));
			curr.push_back(a);
			m -= a * a * a;
		}
		if (curr.size() < max1)
		{
			max1 = curr.size();
			answer = curr;
		}
	}
	cout << answer.size() << endl;
	for (int i = 0; i < max1 - 1; i++)
		cout << answer[i] << "^3+";
	cout << answer[answer.size() - 1] << "^3" << endl;
}
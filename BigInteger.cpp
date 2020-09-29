#include <iostream>
#include <string>
using namespace std;

void reverse(string &str)
{
  int mid = str.size()/2;
  for(int start = 0,end = str.size() - 1;start < mid;start++,end--)
  {
    swap(str[start],str[end]);
  }
}
class BigInt
{

public:

  string add(string a, string b)
  {
    string result = "";
    int carry = 0;
    int length_a = a.size();
    int length_b = b.size();
    string temp = "";

    for(int i=0;i < abs(length_b - length_a);i++)
    {
      temp += '0';
    }

    string A = a, B = b;

    if(length_a < length_b)
    {
      A = temp + a;
    }
    else
    {
      B = temp + b;
    }

    for(int start = max(length_a,length_b)-1; start >= 0; start--)
    {
      int first = A[start] - '0';
      int second = B[start] - '0';
      result += char('0' + (first + second + carry) % 10);
      carry = (first + second + carry) / 10;
    }

    if(carry != 0)
      result += char('0' + carry);

    reverse(result);
    return result;
  }
// 97885667775464976464649445458761321646 58784121659784613133454587946131
};

int main()
{

  string a,b;
  cout << "Enter two operands \n";
  cin >> a >> b;
  cout << a << " " << b;
  BigInt obj;
  string ans = obj.add(a,b);
  cout << endl << ans << endl;
  return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int num[100000] = { 0 };
	int n, s;
	int is = 0, ie = 0;
	int mLen = 1000000, tsum=0;
	cin >> n >> s;
	for (int i = 0; i < n; i++) { cin >> num[i]; }
	while (true) {
		if ((is == ie && is == n) || (ie == n && tsum < s)) break;
		//cout << "tsum : " << tsum << endl;
		if (tsum >= s) {
			//cout << "is : " << is << " ie : " << ie << endl;
			mLen = mLen < ie - is ? mLen : ie - is;
			tsum -= num[is++]; /*cout << "Len : " << mLen << endl;*/  continue;
		}
		tsum += num[ie++];
	}
	if (mLen == 1000000) cout << 0;
	else cout << mLen;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n;

const int N=1e5+3;

int r[N],y[N],cnt[N],k[N];

int main() {
	cin>>n;

	for(int i=1; i<=n; i++) {
		cin>>y[i]>>r[i];
		//从这几位同学的指数中选择阈值
		//选择阈值最准确的（预测命中率最高的）
		//如果相同，取最大的指数作为阈值
		k[i]=y[i];
	}
	int maxi=0,res=0;

	sort(k+1,k+n+1);

	int s=unique(k+1,k+n+1)-k;

	for(int i=1; i<s; i++) {
// 		cout<<k[i]<<endl;
		int yi=k[i];
		for(int j=1; j<=n; j++) {
//			cout<<y[j]<<" "<<r[j]<<endl;
			if(y[j]>=yi && r[j]==1)cnt[i]++;
			else if(y[j]<yi && r[j]==0)cnt[i]++;
		}
// 		cout<<cnt[i]<<endl;
//		cout<<r[i]<<endl;
		if(cnt[i]>maxi) {
			maxi=cnt[i];
			res=k[i];
		} else if(cnt[i]==maxi && k[i]>res) {
			maxi=cnt[i];
			res=k[i];
		}
	}

	cout<<res;
	return 0;
}

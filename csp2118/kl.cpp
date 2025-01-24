#include <iostream>
using namespace std;
int upperlim,sum;
int cheets[1000];
int ans[100000],l,r;
void test(int row,int ld,int rd, int k)
{
  int pos,p;
  if(row!=upperlim)//未填满，即不为11111111时
  {
    pos=upperlim & ~(row | ld | rd);//取反后得到所有可以放的位置
    while(pos!=0)
    {
      p = pos & -pos;//取出最右边的1进行尝试
      pos = pos-p;//将该位置的P从pos中移除
      cheets[k] = p;
      test(row+p,(ld+p)<<1,(rd+p)>>1, k+1);
    }  
  }
  else {
	sum++;
	if(sum>=l&&sum<=r)
		for(int i=0; i<k; i++){
      		cout << ans[cheets[i]] << ' ';
    	}
    cout << endl;
    
  }
}

int main()
{
  int n;
  cin>>n>>l>>r;
  upperlim=(1 << n)-1;//结果为11111111
  ans[1]=0;
  ans[2]=1;
  ans[4]=2;
  ans[8]=3;
  ans[16]=4;
  ans[32]=5;
  ans[64]=6;
  ans[128]=7;
  ans[256]=8;
  ans[512]=9;
  ans[1024]=10;
  ans[2048]=11;
  ans[4096]=12;
  ans[8192]=13;
  ans[16384]=14;
  test(0,0,0, 0);//纵列，左对角线，右对角线
  cout<<sum<<endl;
  return 0;
}
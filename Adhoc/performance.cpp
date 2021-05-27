#include<iostream>
#include<ctime>
#include<cassert>
using namespace std;
#define CYCLE 99999
int main(){
	clock_t start, stop;
	double t1 =0.0, t2 = 0.0;
	
	/*this below code is for \n or endl 
	 *  \n is less costly as it just put newline (for unix its carried return + new line ) 
	 * but std::endl put new line and flush output stream, so its costly 
	 * for less transactions you may find endl is costeffactive but to test you need to test for high numbber of instructions 
	 */
	
	assert((start = clock())!=-1);
	for (long long i=0; i<CYCLE;++i)
		cout<<"Hello\n";
	stop = clock();
	t1=(double) (stop-start)/CLOCKS_PER_SEC;
	
	assert((start = clock())!=-1);
	for(long long  i=0;i<CYCLE;++i)
		cout<<"Hello"<<endl;
	stop = clock();
	t2=(double) (stop-start)/CLOCKS_PER_SEC;
	cout<<endl<<"Time taken for \\n "<<t1<<":: Time taken for endl "<<t2<<endl;
	
	
	/*  i ++ vs ++i 
	 * 	i++ its create copy for i then incremnet i so at a momnet there would be two copy 
	 * 	++i is only uses one main copy so its cost effactive 
	 * 
	 * */
	
	long long 	x	=	0,
				y 	= 	0,
				z 	= 	0,
				p 	= 	0,
				q 	= 	0,
				r 	= 	0;
	
	assert((start = clock())!=-1);
	for (long long i=0; i<CYCLE;++i)
	{
		++x;++y;++z;++p;++q;++r;
	}
	stop = clock();
	t1=(double) (stop-start)/CLOCKS_PER_SEC;
		
	assert((start = clock())!=-1);
	for(long long  i=0;i<CYCLE;i++)
	{
		x++;y++;z++;p++;q++;r++;
	}
	stop = clock();
	t2=(double) (stop-start)/CLOCKS_PER_SEC;
		
	cout<<endl<<"++i"<<t1<<":: i++"<<t2<<endl;
	
	/* executable memory analysis
	 * satendra@workBook:~/Desktop/sattuGit$ size a.out
   text	   data	    bss	    dec	    hex	filename
   3531	    688	    280	   4499	   1193	a.out
	 *
	 */
	

	
}

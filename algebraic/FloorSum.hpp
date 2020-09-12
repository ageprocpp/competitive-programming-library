#include "../other/template.hpp"
lint FloorSum(lint N,lint M,lint A,lint B){
	lint ans=0;
	if(A>=M){
		ans+=(N-1)*N/2*(A/M);
		A%=M;
	}
	if(B>=M){
		ans+=B/M*N;
		B%=M;
	}
	lint ymax=(A*N+B)/M,xmax=ymax*M-B;
	if(ymax==0)return ans;
	ans+=(N-(xmax+A-1)/A)*ymax;
	ans+=FloorSum(ymax,A,M,(A-xmax%A)%A);
	return ans;
}
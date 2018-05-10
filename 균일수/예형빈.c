#include<stdio.h>
#include<math.h>

int main(void) {
	int t, N;
	int solve(int);
	//setbuf(stdout, NULL);
	scanf("%d", &t);
	for (int test_case = 0; test_case < t; test_case++) {
		scanf("%d", &N);
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", solve(N));
	}
	return 0;
}

int solve(int N) {
	int digit2 = N, digit3 = N, b, basis, answer;
	/*
	for(basis=2;basis<=N;basis++){
	long temp=1;
	for(i=1;i<=N;i++){
	if(temp>N)
	break;
	if (N % (int)((temp*basis - 1) / (basis - 1)) == 0 && N / (int)((temp*basis - 1) / (basis - 1))<basis) {
	return N;
	break;
	}
	}
	}   --> for(basis<=N) -> overflow
	N = 1000000007인 경우 모든 for문을 도는데 if문에 걸리지 않음 -> time limit
	for문의 N을 어떻게 줄일까?
	3자리 수 이상의 경우 b^2 + b^1 + b^0 --> b^2 b가 루트N이 넘으면 N보다 크므로
	루트N까지의 범위로 바꾸고 계산하여 답이 없는 경우에만
	2자리 경우를 따로 계산해주면 됨(자리수가 클수록 b가 작기 때문에)
	*/
	// i==3이상인 경우 N = (b^i + b^i-1 + .... + b^1 + b^0)k
	for (basis = 2; basis <= (int)sqrt(N); basis++) {
		long temp = basis * basis;
		for (int i = 3; i <= (int)sqrt(N); i++) {
			if (temp>N)
				break;
			if (N % (int)((temp*basis - 1) / (basis - 1)) == 0 && N / (int)((temp*basis - 1) / (basis - 1))<basis) {
				digit3 = basis;
				basis = N;
				break;
			}
			temp *= basis;
		}
	}
	if (basis == (int)sqrt(N) + 1) {     // if문 통과 x -> 답 x
		digit3 = N - 1;

		// i==2인 경우 N = (b^1 + b^0)k       k가 클수록 b값 감소
		// k는 b(진수)보다 낮아야 하므로 k>루트N
		for (int k = (int)sqrt(N); k >= 1; k--) {
			if (N%k == 0) {
				b = N / k - 1;
				if (b > k) {
					digit2 = b;
					break;
				}
			}
		}
	}
	if (digit2<digit3)
		digit3 = digit2;

	//N-1의 예외상황 : N=1,N=2 -> b=0,1이 나오지만 b>=2여야 하므로 
	if (N == 1) digit3 = 2;
	if (N == 2) digit3 = 3;

	return digit3;
}


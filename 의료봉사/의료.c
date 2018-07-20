#include <stdio.h>
#include<stdlib.h>

int Answer;
int N, P, M, linked[101][51][51], connected[51][51], J[51];
// linked[team][주][위치] linked[team][0][0] 은 team의 봉사활동 총 횟수 linked[team][주][0]은 team이 해당 주에 한 봉사활동 횟수
// connected[주][위치]  i번째 주 j위치에 있는 봉사기관에 연결된 팀의 수
// J[i] i번째 주의 봉사활동기관 수
int main(void)
{
	int T, test_case;
//	FILE *file;
	void initialize();
	int start(int, int);
	setbuf(stdout, NULL);
//	freopen_s(&file, "sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d %d", &N, &P, &M);
		for (int i = 1; i <= P; i++)
			scanf("%d", &J[i]);
		initialize();
		for (int length = 1; length <= N; length++) {
			int len;
			scanf("%d", &len);
			for (int i = 1; i <= len; i++) {
				int week, position;
				scanf("%d %d", &week, &position);
				linked[length][week][position] = 1;
				//printf("linked[%d][%d][%d]---=%d\n", length, week, position, linked[length][week][position]);
				connected[week][position]++;
			}
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", start(1, 1));
	}
	return 0;//Your program should return 0 on normal termination.
}
void initialize() {
	for (int j = 0; j <= P; j++) {
		for (int q = 0; q <= J[j]; q++) {
			for (int i = 0; i <= N; i++) {
				linked[i][j][q] = 0;
			}
			connected[j][q] = 0;
		}
	}
}
int start(int week, int position) { // return 1 = possible 0 = impossible
	//printf("week %d  position %d\n", week, position);
	if (week > P) // 문제가 없을 경우만 진행되기 때문에 week가 P가 넘어갔다=> 배치가능하다
		return 1;
	if (connected[week][position] == 0) // week, position에 연결된 봉사기관이 없다
		return 0;
	else if (connected[week][position] == 1) { // week, position에 연결된 봉사기기관이 1개만 있다
		int i;
		for (i = 1; i <= N; i++) {
			if (linked[i][week][position] == 1) {     // 연결된 봉사기관 찾기
				//		printf("connected==1 i = %d와 연결\n", i);
				break;
			}
		}
		//	printf("%d팀이 %d주에 한 횟수linked = %d\n", i,week,linked[i][week][0]);
		if (linked[i][week][0] != 0 || linked[i][0][0] >= M) { // i번째 team이 week 주에 이미 봉사활동 함 or i번째 팀의 총 봉사활동 횟수가 M값 초과
			//연결된 봉사기관이 그 주에 이미 봉사를 했거나 봉사 횟수가 최대치를 초과
	//		printf("이미 봉사함 or 횟수초과");
			return 0;   // 연결된 게 1개밖에 없기 때문에 바로 리턴
		}
		else { // 봉사가능 봉사했다고 가정
			linked[i][week][0]++; // i번째 team week 주에 봉사활동 횟수 증가
			linked[i][0][0]++; // i번째 team 총 봉사활동 횟수

			if (position == J[week]) { // week 주에 있는 봉사기관 끝 다음 주로 넘어가기
				// 1주 3번째 봉사기관이다 => 다음 week position은 2주 1번째 봉사기관
				position = 1;
				week++;
			}
			else
				position++;
			// 다음 week, position에서 봉사가능한지 확인
			if (start(week, position)) // 봉사 성공
				return 1;
			else { // 봉사 실패 봉사활동 수 빼고 week, position 전으로 되돌려놓기
				linked[i][week][0]--; linked[i][0][0]--;
				if (position == 1)
				{
					week--;
					position = J[week];
				}
				else
					position--;
				return 0; // 연결된 봉사기관이 1개밖에 없기 때문에 바로 실패
			}
		}
		return 0;
	}
	else { // 연결된 게 2개 이상
		int i,count=0;
		for (i = 1; i <= N; i++) {
			if (linked[i][week][position] == 1) { // 연결된 봉사기관 찾기
			    count++;
				if (linked[i][week][0] != 0 || linked[i][0][0] >= M) // i번째 team이 week 주에 이미 봉사활동 함 || i번째 팀의 총 봉사활동 횟수 초과
					continue; // 연결된 게 2개 이상이기 때문에 이번 봉사기관이 실패했더라도 다음 봉사기관 확인해야함
				else { // 봉사성공했다고 가정
					linked[i][week][0]++; // i번째 team week 주에 봉사활동 횟수 증가
					linked[i][0][0]++; // i번째 팀의 총 봉사활동 횟수 증가

					if (position == J[week]) {
						position = 1;
						week++;
					}
					else
						position++;
					if (start(week, position) == 1)
						return 1;
					else {
						if (position == 1)
						{
							week--;
							position = J[week];
						}
						else
							position--;
						linked[i][week][0]--; linked[i][0][0]--;
						//연결된 게 2개 이상이기 때문에 리턴하지 않고 다음 봉사기관찾음
					}
				}
			}
			if (count > connected[week][position])
				return 0;
		}
		return 0;
	}
}

#include <stdio.h>
#include <math.h>

// 연산 함수의 경우 calc_ 뒤에 연산하는 함수 이름을 작성한다.
// 데이터를 찾는 함수의 경우 find_ 뒤에 찾는 데이터의 이름을 작성한다.

// 문제. 0 ~ 3까지 y = x^2에 대해 정적분을 수행해보자!
//       [1/3 * x^3] 0 ~ 3 = 9
int main(void) {
	// 1. 0 ~ 3 까지의 범위를 몇 개로 분할할까 ?
	//    실제로 무한 등분을 수행할 수 없다는 한계가 있다.
	//    메모리 크기 문제, 주어진 시간내에 계산을 끝낼 수 있는가
	//    (결론: 적정한 정밀도와 정확성을 가진 미소값을 잡아야 한다)
	//    dx = 0.001
	int i;
	float area = 0.0f;
	const float dx = 0.0001;	// 밑변의 길이
	float curX = 0;
	float y;
	int start = 0, end = 3;
	// math 라이브러리 사용되면 반드시 -lm 옵션을 줘서 컴파일 해야 한다.
	int loop_num = round((end - start) / dx);

	printf("loop_num = %d\n", loop_num);
	// 2. 각각의 분할 지점들은 무엇을 의미하는가 ?
	//    y값을 계산하기 위한 데이터
	//    (결론: 현재의 x값을 일시적으로 보관하기 위한 curX의 필요성)
	for(i = 0; i < loop_num; i++)
	{
		// 작은 사각형들의 합이 결국 적분을 의미하므로
		// 높이와 밑변을 곱한 결과를 누산(시그마)함으로써 적분을 완성한다.
		y = curX * curX;
		area += y * dx;
		curX += dx;
	}

	printf("integral results: %f\n", area);

	return 0;
}

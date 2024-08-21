function solution(triangle) {
    var cur_floor = triangle.length - 1;

    // 초기화: 마지막 층의 값을 기준으로 합계를 시작
    var sum_arr = triangle[cur_floor].slice();

    while (cur_floor > 0) {
        cur_floor--; // 한 층 위로 올라감
        for (var i = 0; i <= cur_floor; i++) {
            // 현재 층의 각 요소에 대해 가능한 두 경로의 합 중 큰 값을 선택
            sum_arr[i] = triangle[cur_floor][i] + Math.max(sum_arr[i], sum_arr[i + 1]);
        }
    }
    
    // 최종적으로 남은 최상단 값이 최대 경로 합
    return sum_arr[0];
}

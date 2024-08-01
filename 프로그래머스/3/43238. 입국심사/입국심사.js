function solution(n, times) {
    times.sort((a, b) => a - b);
    let left = 1;
    let right = times[times.length - 1] * n;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        let total = 0;
        for (var time of times) {
            total += Math.floor(mid / time);
        }
        total>=n?right=mid-1:left=mid+1;
    }
    return left;
}
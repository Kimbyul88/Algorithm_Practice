function solution(priorities, location) {
    var new_arr = [];
  var order = [...new Set(priorities)].sort((a, b) => b - a); // 큰 순서 정렬
  while (new_arr.length !== priorities.length) {
    for ([index, el] of priorities.entries()) {
      if (el === order[0]) {
        //현재 우선순위가 가장 크면 푸시
        new_arr.push(index);
        priorities[index] = 0;
      } else continue;
      if (priorities.filter((el) => el === order[0]).length === 0)
        order.shift(); //더이상 이 우선순위를 가진 것이 없으면 우선순위 바꾸기
    }
  }
  return new_arr.indexOf(location) + 1;
}
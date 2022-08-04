#include <stdio.h>
int count = 0;
int debug;

int risawa(int m, int n) {
  count++;
  if (debug)
    printf("%d丁目%d番地:", m, n);
  if (m == 0) { // 0丁目
    if (debug)
      printf("ケース1: リサワ数は%dです。\n", n + 1);
    return n + 1;      // n+1リサワ
  } else if (n == 0) { // 0番地
    if (debug)
      printf("ケース2: %d丁目%d番地のリサワ数を計算します。\n", m - 1, 1);
    return risawa(m - 1, 1);
  } else {
    if (debug)
      printf("ケース3: %d丁目X番地: ", m - 1);
    if (debug)
      printf("ただし、Xは%d丁目%d番地のリサワ数\n", m, n - 1);
    return risawa(m - 1, risawa(m, n - 1));
  }
}

int main(void) {
  int m, n;
  printf("m丁目？");
  scanf("%d", &m);
  printf("n番地？");
  scanf("%d", &n);
  printf("デバッグ出力する [Yes:1 / No:0]?");
  scanf("%d", &debug);
  printf("%d丁目%d番地のリサワ数は%dです。\n", m, n, risawa(m, n));
  printf("リサワ関数の呼び出し回数は%d回です。\n", count);
  return 0;
}
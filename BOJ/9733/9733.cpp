#define _CRT_SECURE_NO_WARNINGS 
#include <bits/stdc++.h>

int main(void) {
	int w = 24;
	int r = 0, p = 0, c = 0, e = 0, t = 0, m = 0, x = 0, total = 0;
	char in[3];
	while (w--) {
		scanf("%s", in);
		if ((0 <= in[0] && in[0] <= 64) || 
			(91 <= in[0] && in[0] <= 96) || 
			(123 <= in[0] && in[0] <= 127))
			break;

		if (in[0] == 'R') {
			r++;
			continue;
		}
		if (in[0] == 'P') {
			p++;
			continue;
		}
		if(in[0] == 'C'){
			if (in[1] == 'c') {
				c++;
			}
			else if (in[1] == 'm') {
				m++;
			}
			else {
				total++;
			}
			continue;
		}
		if(in[0] == 'E'){
			if (in[1] == 'a') {
				e++;
			}
			else if (in[1] == 'x') {
				x++;
			}
			else {
				total++;
			}
			continue;
		}
		if (in[0] == 'T') {
			t++;
			continue;
		}
		if ((65 <= in[0] && in[0] <= 90) || (97 <= in[0] && in[0] <= 122)) {
			total++;
		}
	}

	total += r + p + c + e + m + x + t;
	printf("Re %d %.2lf\n", r, ((double)r/ (double)total));
	printf("Pt %d %.2lf\n", p, ((double)p/ (double)total));
	printf("Cc %d %.2lf\n", c, ((double)c/ (double)total));
	printf("Ea %d %.2lf\n", e, ((double)e/ (double)total));
	printf("Tb %d %.2lf\n", t, ((double)t/ (double)total));
	printf("Cm %d %.2lf\n", m, ((double)m/ (double)total));
	printf("Ex %d %.2lf\n", x, ((double)x/ (double)total));
	printf("Total %d %.2lf", total, 1.00);
}
int x;

/*int main(void)
{
    int y[6];
    int i;

    x = 7;
    if (x > 6) {
        *//* output(int x) is predefined *//*
        output(x); *//* 7 *//*
    }
    if (x > 6) {
        int x;
        x = 10;
        output(x); *//* 10 *//*
    }
    while (x >= 3) {
        x = x - 1;
    }
    output(x); *//* 2 *//*

    i = 0;
    while (i < 6) {
        y[i] = i;
        i = i + 1;
    }
    output(y[5]); *//* 5 *//*

}*/


int min(int u, int v)
{
	if (u < v) return u;
	else return v;
}

int main(void)
{
	int x;
	int y;
	int z[3];
    int t;
	x = 1;
	y = 1 + 2;
	z[2] = 4;
	if (x < 3) {
	    int t;
		while (y > 0) {
			y = y - 1;
		}
	}
	x = min(x, y);
	output(x);
	output(y);
	return 0;
}

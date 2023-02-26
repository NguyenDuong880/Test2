#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

class Ptb1
{
protected:
	float b, c;
public:
	Ptb1(float m = 0, float n = 0);
	void Nhap(float x, float y);
	void Xuat();
	void Giai_b1();
};

class Ptb2 : public Ptb1
{
private:
	float a;
public:
	Ptb2(float m = 0, float n = 0, float p = 0);
	void Nhap(float x, float y, float z);
	void Xuat();
	void Giai_b2();
};


// Ham khoi tao phuong trinh bac 1
Ptb1::Ptb1(float m, float n)
{
	b = m;
	c = n;
}

// Ham nhap b,c
void Ptb1::Nhap(float x, float y)
{
	b = x;
	c = y;
}

// Ham xuat b,c
void Ptb1::Xuat()
{
	printf("%.2fx + %.2f = 0\r\n", b, c);
}

// Ham giai phuong trinh bac 1
void Ptb1::Giai_b1()
{
	if (b != 0)
		printf("Phuong trinh co nghiem: x = %.2f\r\n", (-c / b));
	else if (c == 0)
		printf("Phuong trinh vo nghiem\r\n");
	else
		printf("Phuong trinh co vo so nghiem\r\n");
}

// Ham khoi tao phuong trinh bac 2
Ptb2::Ptb2(float m, float n, float p) : Ptb1()
{
	a = m;
}

// Ham nhap a
void Ptb2::Nhap(float x, float y, float z)
{
	a = x;
	Ptb1::Nhap(y, z);
}

// Ham xuat ra phuong trinh bac 2
void Ptb2::Xuat()
{
	if (a != 0)
		printf("(%.2f)x^2 + (%.2f)x + (%.2f) = 0\r\n", a, b, c);
	else
		Ptb1::Xuat();
}


// Ham giai phuong trinh bac 2
void Ptb2::Giai_b2()
{
	float delta;
	float x1, x2;
	if (a != 0)
	{
		delta = b * b - 4 * a * c;
		printf("Delta = %.2f\r\n", delta);
		if (delta < 0)
			printf("Phuong trinh vo nghiem\r\n");
		else if (delta == 0)
			printf("Phuong trinh co mot nghiem x = %.2f", (-b) / (2 * a));
		else
		{
			x1 = ((-b) - sqrt(delta)) / (2 * a);
			x2 = ((-b) + sqrt(delta)) / (2 * a);
			printf("Phuong trinh co hai nghiem: x1 = %.2f, x2 = %.2f", x1, x2);
		}
	}
	else Ptb1::Giai_b1();
}


int main()
{
	Ptb2 x;
	float a, b, c;
	printf("Nhap gia tri a,b,c: \r\n");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	x.Nhap(a, b, c);
	printf("Phuong trinh co dang: \r\n");
	x.Xuat();
	x.Giai_b2();
	return 0;
}
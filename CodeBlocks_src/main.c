#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>

struct labData
{
    int a;
    int b;
    float c;
    int d;
    int f1;
    int f2;
    int g1;
    int g2;
    int h1;
    int h2;
};

void pause();
void lab();
void task0(struct labData data, double x_left, double x_right, double step);
void task1(struct labData data, double x_left, double x_right, double step);
void task2(struct labData data, double x_left, double x_right, double step);
double get_f(double x, struct labData data);

int main()
{
    lab();
    pause();
    return 0;
}

void pause()
{
    printf("\n\nPress any key to close program\n");
    getch();
    printf("\n\n");
}

void lab()
{
    char name[20];
    printf("Your name: ");
    scanf("%s", name);

    char surname[20];
    printf("Your surname: ");
    scanf("%s", surname);

    struct labData data;

    char volves[] = "AaEeIiOoUuYy";
    data.a = 0;
    for (int i = 0; i < strlen(surname); i++)
    {
        for (int j = 0; j < strlen(volves); j++)
        {
            if (surname[i] == volves[j])
            {
                data.a++;
            }
        }
    }

    data.b = strlen(name) % 2 == 0 ? 0 : 1;
    data.c = (double) strlen(surname) / strlen(name);
    data.d = strlen(name) % 2 == 0 ? 1 : 0;
    data.f1 = strlen(surname) % 2 == 0 ? 1 : 0;
    data.f2 = strlen(surname);
    data.g1 = strlen(surname) % 2 == 0 ? 1 : 0;
    data.g2 = strlen(name);
    data.h1 = (data.f2 + data.a) * data.b;
    data.h2 = (data.g2 + data.a) * data.d;

    double x_left;
    printf("left border: ");
    scanf("%lf", &x_left);

    double x_right;
    printf("Right border: ");
    scanf("%lf", &x_right);

    double step;
    printf("Step: ");
    scanf("%lf", &step);

    printf("\n\nTask 0\n\n");
    task0(data, x_left, x_right, step);
    printf("\n\nTask 1\n\n");
    task1(data, x_left, x_right, step);
    printf("\n\nTask 2\n\n");
    task2(data, x_left, x_right, step);
}

void task0(struct labData data, double x_left, double x_right, double step)
{
    double x1 = x_left;
    double x2 = x_left + step;

    printf("           #|");
    printf("          x1|");
    printf("          x2|");
    printf("          f1|");
    printf("          f2|");
    printf("\n");

    int i = 1;
    for (double x = x_left; x < x_right; x += step)
    {
        printf("%12d|", i);
        printf("% 12.6lf|", x1);
        printf("% 12.6lf|", x2);
        printf("% 12.6lf|", get_f(x1, data));
        printf("% 12.6lf|", get_f(x2, data));
        printf("\n");

        x1 += step;
        x2 += step;
        i++;
    }
}

void task1(struct labData data, double x_left, double x_right, double step)
{
    struct
    {
        double value;
        double arg;
    } maxf;

    maxf.arg = x_left; //x
    maxf.value = get_f(x_left, data); // f(x) = y

    for (double x = x_left, i = 0; x <= x_right; x += step, i++)
    {
        if (maxf.value < get_f(x, data))
        {
            maxf.arg = x; //x
            maxf.value = get_f(x, data); // f(x) = y
        }
    }

    printf("\nMax value\n");
    printf("f(%lf) = %lf\n", maxf.arg, maxf.value);
}

void task2(struct labData data, double x_left, double x_right, double step)
{
    double e;
    printf("\nFunc ~= [-e; e] in this cases:\n");
    printf("e := ");
    scanf("%lf", &e);

    int i = 0;
    for (double x = x_left; x <= x_right; x += step)
    {
        double y = get_f(x, data);
        if (fabs(y) < fabs(e))
        {
            printf("f(%lf) = %lf\n", x, y);
            i++;
        }
    }
    if (i == 0)
    {
        printf("none cases found on range [%lf; %lf] whith step %lf\n", x_left, x_right, step);
    }
}

double get_f(double x, struct labData data)
{
    return data.a * pow(x, 2)
        + data.b * pow(x, 3)
        - data.c * x
        - data.d * exp(x)
        + data.f1 * cos(data.f2 * x)
        + data.g1 * sin(data.g2 * x)
        + data.h1 * pow(cos(x), 2)
        + data.h2 * pow(sin(x), 2);
}

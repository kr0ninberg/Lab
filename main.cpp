#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

double aver1(double *a , int);
double sqrt_aver(double *a , int);
double * defl(double *a , int);
double std_defl(double *a , int);
double stu_koef(int , double);
double fai_inter(double *a , int);
double full_mis(double *a , int, double);
void std_printer(double *a , int , double, int);
void std_input();
void amount_par_pac();
int random1(int);
void pass_gen(int);

int main(){
    return 0;
}

double aver1(double *a , int len){
    // Counts the average of an array of doubles of lenght len
    double aver = 0;
    for (int q = 0 ; q != len ; q++){
        aver += *(a + q);
    }
    return aver / len;
}

double sqrt_aver(double *a , int len){
    double aver = 0;
    for (int q = 0 ; q != len ; q++){
        aver += *(a + q) * *(a + q);
    }
    return sqrt(aver);
}

double * defl(double *a , int len){
    double *b = new double[len];
    double aver = aver1(a , len);
    for (int q = 0 ; q != len ; q++){
        *(b + q) =  aver - *(a + q);
    }
    return b;
}

double std_defl(double *a , int len){
    if (len < 2) std::cout << "warning : isn't enough parameters" << std::endl;
    return sqrt_aver(defl(a , len) , len) / (sqrt(len * (len - 1)));
}

double stu_koef(int len , double var=0.95){
    if (len == 2 && var == 0.95) return 12.71;
    if (len == 3 && var == 0.95) return 4.3;
    if (len == 4 && var == 0.95) return 3.18;
    if (len == 5 && var == 0.95) return 2.77;
    if (len == 6 && var == 0.95) return 2.57;
    if (len == 7 && var == 0.95) return 2.36;
    if (len == 8 && var == 0.95) return 2.36;
    if (len == 9 && var == 0.95) return 2.3;
    if (len == 10 && var == 0.95) return 2.26;
    if (len == 11 && var == 0.95) return 2.23;
    std::cout << "ERROR: stue_koef(int , double) len out of range";
    return 0;
}

double fai_inter(double *a , int len){
    return std_defl(a , len) * stu_koef(len);
}

double full_mis(double *a , int len , double instr){
    double b[2];
    *(b + 1) = instr;
    *b = fai_inter(a , len);
    return sqrt_aver(b , 2);
}

void std_printer(double *a , int len , double instr , int prec=8){
    std::cout << "parameters" << std::endl;
    for (int q = 0 ; q != len ; q++){
        std::cout << std::fixed << std::setprecision(prec) << *(a + q) << std::endl;
    }
    double *b = defl(a , len);
    std::cout << "average" << std::endl;
    std::cout << std::fixed << std::setprecision(prec) << aver1(a , len) << std::endl;
    std::cout << "deflections" << std::endl;
    for (int q = 0 ; q != len ; q++){
        std::cout << *(b + q) << std::endl;
    }
    std::cout << "standart deflection" << std::endl;
    std::cout << std::fixed << std::setprecision(prec) << std_defl(a , len) << std::endl;
    std::cout << "full mistake" << std::endl;
    std::cout << std::fixed << std::setprecision(prec) << full_mis(a , len , instr) << std::endl;
}

void std_input(){
    int len;
    std::cout << "enter amount" << std::endl;
    std::cin >> len;
    double a[len];
    std::cout << "enter parameters" << std::endl;
    for (int q = 0 ; q != len ; q++){
        std::cin >> *(a + q);
    }
    double instr;
    std::cout << "enter instr. mis." << std::endl;
    std::cin >> instr;
    std_printer(a , len , instr);
}

void amount_par_pac(){
    std::cout << "enter amount of packages with parameters" << std::endl;
    int n;
    std::cin >> n;
    for (int q = 0 ; q != n ; q++){
        std_input();
    }
}

int random1(int n){
    static uint a = 5;
    a = (a * 8723761 + n) % 62;
    return a;
}

void pass_gen(int a){
    int n;
    std::cin >> n;
    for (int q = 0 ; q < n ; q++){
        uint t = random1(a);
        if (t < 10) t += 48;
        else if (t < 36) t += 55;
        else t += 61;
        std::cout << char(t);
    }
    std::cout << "\n";
    return;
}

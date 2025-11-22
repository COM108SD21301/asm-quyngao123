#include <stdio.h>
#include <math.h>

// ------------------- PAUSE -------------------
void pauseScreen() {
    printf("\nNh?n Enter d? quay l?i menu...");
    getchar();
    getchar();
}

// ------------------- CN1: KI?M TRA S? -------------------
void kiemTraSo() {
    float x;
    printf("Nh?p s? x: ");
    scanf("%f", &x);

    if (x == (int)x) {
        int n = (int)x;
        printf("%d là s? nguyên\n", n);

        // Ki?m tra chính phuong
        int sq = sqrt(n);
        if (sq * sq == n) printf("%d là s? chính phuong\n", n);
        else printf("%d KHÔNG ph?i s? chính phuong\n", n);

        // Ki?m tra nguyên t?
        int isPrime = 1;
        if (n <= 1) isPrime = 0;
        else {
            for (int i = 2; i <= sqrt(n); i++)
                if (n % i == 0) { isPrime = 0; break; }
        }

        if (isPrime) printf("%d là s? nguyên t?\n", n);
        else printf("%d KHÔNG ph?i s? nguyên t?\n", n);

    } else {
        printf("%.2f là s? th?c\n", x);
    }

    pauseScreen();
}

// ------------------- CN2: UCLN - BCNN -------------------
int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void ucln_bcnn() {
    int a, b;
    printf("Nh?p a: "); scanf("%d", &a);
    printf("Nh?p b: "); scanf("%d", &b);

    int u = UCLN(a, b);
    int bcnn = (a / u) * b;

    printf("UCLN = %d\n", u);
    printf("BCNN = %d\n", bcnn);

    pauseScreen();
}

// ------------------- CN3: TÍNH TI?N KARAOKE -------------------
void tinhKaraoke() {
    int bd, kt;
    printf("Gi? b?t d?u: "); scanf("%d", &bd);
    printf("Gi? k?t thúc: "); scanf("%d", &kt);

    if (bd < 0 || bd > 24 || kt < 0 || kt > 24 || kt <= bd) {
        printf("Gi? không h?p l?!\n");
        pauseScreen();
        return;
    }

    int sogio = kt - bd;
    float tien = 0;

    if (sogio <= 3)
        tien = sogio * 150000;
    else
        tien = 3 * 150000 + (sogio - 3) * 120000;

    printf("Ti?n Karaoke = %.0f VND\n", tien);
    pauseScreen();
}

// ------------------- CN4: TI?N ÐI?N -------------------
void tinhTienDien() {
    int kw;
    printf("Nh?p s? KW: ");
    scanf("%d", &kw);

    float tien = 0;

    if (kw <= 50)                tien = kw * 1678;
    else if (kw <= 100)          tien = 50 * 1678 + (kw - 50) * 1734;
    else                          tien = 50 * 1678 + 50 * 1734 + (kw - 100) * 2014;

    printf("Ti?n di?n = %.0f VND\n", tien);
    pauseScreen();
}

// ------------------- CN6: VAY NGÂN HÀNG -------------------
void vayNganHang() {
    float goc, lai;
    int thang;

    printf("Nh?p ti?n g?c: "); scanf("%f", &goc);
    printf("Nh?p lãi su?t (%%/tháng): "); scanf("%f", &lai);
    printf("Nh?p s? tháng: "); scanf("%d", &thang);

    if (goc <= 0 || lai < 0 || thang <= 0) {
        printf("D? li?u không h?p l?!\n");
        pauseScreen();
        return;
    }

    float tienLai = goc * (lai / 100) * thang;
    float tong = goc + tienLai;

    printf("Ti?n lãi: %.0f VND\n", tienLai);
    printf("T?ng ph?i tr?: %.0f VND\n", tong);

    pauseScreen();
}

// ------------------- MENU -------------------
void menu() {
    printf("============= MENU CHUONG TRÌNH =============\n");
    printf("1. Ki?m tra s? (nguyên, chính phuong, nguyên t?)\n");
    printf("2. Tìm UCLN và BCNN\n");
    printf("3. Tính ti?n Karaoke\n");
    printf("4. Tính ti?n di?n\n");
    printf("6. Tính ti?n vay ngân hàng\n");
    printf("0. Thoát\n");
    printf("=============================================\n");
    printf("Ch?n ch?c nang: ");
}

// ------------------- MAIN -------------------
int main() {
    int lc;

    do {
        menu();
        scanf("%d", &lc);

        switch (lc) {
            case 1: kiemTraSo(); break;
            case 2: ucln_bcnn(); break;
            case 3: tinhKaraoke(); break;
            case 4: tinhTienDien(); break;
            case 6: vayNganHang(); break;
            case 0: printf("Thoát chuong trình!\n"); break;
            default: printf("L?a ch?n không h?p l?!\n\n");
        }

    } while (lc != 0);

    return 0;
}


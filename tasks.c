#include <stdio.h>

void task1() {
    int n, a[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int maxLen=1, len=1, start=0, maxStart=0;
    for (int i=1; i<n; i++) {
        if (a[i]==a[i-1]) {
            len++;
        }
        else {
            if (len>maxLen) {
                maxLen=len;
                maxStart=start;
            }
            start=i;
            len=1;
        }
    }
    if (len>maxLen) {
        maxLen=len;
        maxStart=start;
    }
    printf("Start index: %d\nLength: %d", maxStart, maxLen);
}

void task2() {
    int n, a[100], ok=1;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int i=0; i<n-1; i++) {
        if (i%2==0) {
            if (!(a[i]<a[i+1]))
                ok=0;
        }
        else {
            if (!(a[i]>a[i+1]))
                ok=0;
        }
    }
    if (ok)
        printf("Yes");
    else
        printf("No");
}

void task3() {
    int n, a[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int i=n-1; i>=0; i--)
        printf("%d", a[i]);
}

void task4() {
    int n, k, a[100], temp[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for (int i=0; i<n; i++)
        temp[(i+k)%n]=a[i];
    for (int i=0; i<n; i++)
        printf("%d", temp[i]);
}

void task5() {
    int n, k, a[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (a[i]<a[j]) {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
    printf("%d", a[n-1]);
}

void task6() {
    int n, a[100];
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int maxLen=1, len=1, start=0, maxStart=0;
    for (int i=1; i<n; i++) {
        if (a[i]>a[i-1]) {
            len++;
        }
        else {
            if (len>maxLen) {
                maxLen=len;
                maxStart=start;
            }
            start=i;
            len=1;
        }
    }
    for (int i=maxStart; i<maxStart+maxLen; i++)
        printf("%d", a[i]);
}

void task7() {
    int n, a[100], target;

    printf("Enter N: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += a[j];

            if(sum == target) {
                printf("Sequence: ");
                for(int k = i; k <= j; k++)
                    printf("%d ", a[k]);

            }
        }
    }

}

void task8() {
    int a[20];
    int n=10;
    int i;
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (n<20) {
        int num, pos;
        printf("Enter the number and position: ");
        scanf("%d", &num);
        if(num==0)
            break;
        scanf("%d", &pos);
        if (pos<0)
            pos=0;
        if (pos>n)
            pos=n;
        for(i=n; i>pos; i--) {
            a[i]=a[i-1];
        }
        a[pos]=num;
        n++;
    }
    printf("Result:\n");
    for (i=0; i<n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void task9() {
    int n, a[100];
    int len = 1, maxLen = 1;
    int value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    value = a[0];

    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            len++;

            if(len > maxLen) {
                maxLen = len;
                value = a[i];
            }
        } else {
            len = 1;
        }
    }
    for(int i = 0; i < maxLen; i++)
        printf("%d ", value);
}
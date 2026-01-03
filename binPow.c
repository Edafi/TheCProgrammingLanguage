#define TRUE 1
#define FALSE 0

long double binPow_double(long double base, long long power){
    int negativeFlag = 0;
    long double answer = 1.0;
    negativeFlag = (power < 0)? 1 : 0;
    power = (power < 0)? power * (-1) : power;
    while(power > 0){
        if(power & 1){
            answer *= base;
            power--;
        }
        base *= base;
        power >>= 1;
    }
    return (negativeFlag == 0)? answer : 1/answer;
}

long long binPow_int(long long base, long long power){
    int answer = 1;
    while(power > 0){
        if(power & 1){
            answer *= base;
            power--;
        }
        base *= base;
        power >>= 1;
    }
    return answer;
}

//int main(){
//    int state = TRUE;
//    long long base = {0}, power = {0};
//    while (state == TRUE){
//        scanf("%lld %lld", &base, &power);
//        if(base == EOF || power == EOF){
//            state = FALSE;
//            break;
//        }
//        else
//            printf("%lld\n", binPow(base, power));
//    }
//}
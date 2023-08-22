n = 187654346878;
digit_sum = 0;
while (n > 0):
    digit_sum += n % 10;
    n = n // 10;
print(digit_sum);

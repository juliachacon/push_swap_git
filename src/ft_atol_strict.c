
static long ft_atol_strict(const char *s)
{
    long sign;
    long res;

    sign = 1;
    res = 0;
    if (*s == '+' || *s == '-')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    while (*s)
    {
        res = res * 10 + (*s - '0');
        s++;
    }
    return (res * sign);
}

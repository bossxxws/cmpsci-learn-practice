int sum_of_first_n_natural_numbers(int n)
{
    if(n==1)return 1;
    return n+sum_of_first_n_natural_numbers(n-1);
}



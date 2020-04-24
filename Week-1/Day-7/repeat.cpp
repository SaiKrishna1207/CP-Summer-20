// Lets only consider looking for a number more than n/2 times.
// The idea is if we remove one majority element and one minority element the majority element remains the same. How the numbers are removed it by keeping track of a ‘selected number’
// initialized by index 0. we compare it to the A[i] for 0<i<n. Every time we see A[selected] == A[i] we increase count of selected number else we decrease the count. Decreasing the 
// count means you have removed A[i] and one copy of the A[selected]. If the count reaches 0, you update the selected = i and keep on doing the process. In the end a check is required 
// to see if A[selected] is really the number which occurs > n/2 times. This can be easily done in one iteration of the array.

// Now let’s say we want to see if a number occurs more than n/k times. If we remove k-1 minority elements and 1 majority element the majority element remains the same. K was 2 in our
//  previous case. For this questions k = 3, hence we remove 3 distinct numbers, and at the end check if any of the 2 numbers we kept is occurring more than n/3 or not.

int Solution::repeatedNumber(const vector<int> &A) {
    int l = A.size();
    int c1 = 0, c2 = 0, i;
    int a = 999999999, b = 999999999;
    for(i = 0;i < l; i++)
    {
        if(A[i] == a)
            c1++;
        else if(A[i] == b)
            c2++;
        else if(c1 == 0)
        {
            c1++;
            a = A[i];
        }
        else if(c2 == 0)
        {
            c2++;
            b = A[i];
        }
        else
        {
            c2--;
            c1--;
        }
    }   
    c1 = 0;
    c2 = 0;
    for(i = 0;i < l;i++)
    {
        if(A[i] == a)
            c1++;
        else if(A[i] == b)
            c2++;
    }
    if(c1 > l/3)
        return a;
    if(c2 > l/3)
        return b;
    return -1;
}
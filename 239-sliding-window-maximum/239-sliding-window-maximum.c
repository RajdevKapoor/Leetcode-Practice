

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool in_window_range(int i,int k,int j);
int* maxSlidingWindow(int* arr, int n, int k, int* returnSize)
{
    int stack[n];
    int nge_index[n];
    nge_index[n-1]=INT_MAX;
    int TOP=-1;
    stack[++TOP]=n-1;
    for(int i=(n-2);i>=0;i--)
    {
        while(TOP!=-1 && arr[i]>=arr[stack[TOP]])
            TOP--;
        if(TOP==-1)
            nge_index[i]=INT_MAX;
        else
            nge_index[i]=stack[TOP];
        stack[++TOP]=i;
    }
    int *window = (int*)malloc((n-k+1) *sizeof(int));
    for(int i=0;i<=(n-k);i++)
    {
        int j=i;
        while(1)
        if(in_window_range(i,k,nge_index[j])==false)
            break;
         else
            j=nge_index[j];
       window[i]=arr[j];
    }
    
    *returnSize=(n-k+1);
    return window;
}
bool in_window_range(int i,int k,int j)
{
  
    if(j<i+k)
       return true;
    else
        return false;
}
#include <stdio.h>

int side_sum(int data[], int left, int right)
{
    int mid = 0;
    int left_sum = 0;
    int right_sum = 0;
    int sum = 0;
    int mid_to_left = 0;
    int mid_to_right = 0;
    

    if(left > right)
        return -1;
    else if(left == right)
        {
            if(data[left] >= 0)
                return data[left];
            else
                return 0;
        }
    else {
        mid = (right + left) / 2;
        left_sum = side_sum(data, left, mid);
        right_sum = side_sum(data, mid+1, right);
        int sum_left = 0;
        int sum_right = 0;
        for(int i = mid; i >= left; i--)
        {
            sum_left += data[i];
            if(sum_left > mid_to_left)
                mid_to_left = sum_left;
        }       
        for(int j = mid+1; j <= right; j++)
        {
            sum_right += data[j];
            if(sum_right > mid_to_right)
                mid_to_right = sum_right;
        }       
        
        sum = mid_to_left + mid_to_right;
        if(sum < left_sum )
            sum = left_sum;
        if(sum < right_sum )
            sum = right_sum;
       
        return sum;
    }
}




int main(){
    int data[8] = {4,-3,5,-2,-1,2,6,-2};
    int a = 0;
    a = side_sum(data,0,7);
    printf("%d\n",a);
    return 0;
}

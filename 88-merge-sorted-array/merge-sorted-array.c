void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i=m-1;
    int j=n-1;
    int a[m+n];
    int temp=m+n-1;

    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j])
            a[temp--]= nums1[i--];
        else 
            a[temp--]=nums2[j--];    
    }

    while(i>=0){
        a[temp--]=nums1[i--];
    }

    while(j>=0){
        a[temp--]=nums2[j--];
    }

    for(int i=0;i<m+n;i++){
        nums1[i]=a[i];
    }
}
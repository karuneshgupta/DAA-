package com.company;

import java.util.Scanner;

public class Selection_sort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.println("enter size");
        n = sc.nextByte();

        int[]arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        selection_sort(arr,n);
        for (int i = 0; i < n; i++) {
            System.out.print(" "+ arr[i]);
        }

    }

    private static void selection_sort(int[] arr, int n) {
         // 64 25 12 22 10  n = 5
        // total comaprosns will be n-1; for 5 elements = 4+3+2+1 =10
        //  0   1  2  3  4
        int swaps = 0;
        int comparisons = 0 ;
        for( int i = 0 ; i<n-1 ;i++)
        {
            int min = i ;
            // ab hum pure array mae minimum element ka index nikalenge
            // or usko i ke saath swap karenge
            int j = i+1;
            for(j = i+1 ; j<n ; j++)
            {
                    comparisons++;
                if(arr[j] < arr[min])
                {
                    min = j;
                }
            }
            // swapping of(a[i],a[min])

            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            swaps++;
        }


        System.out.printf(" \ntotal swaps = %d\n",swaps);
        System.out.printf("total comparisons = %d\n",comparisons);
    }
}

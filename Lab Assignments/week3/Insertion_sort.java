package com.company;

import java.util.Scanner;

public class Insertion_sort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.println("enter size");
        n = sc.nextByte();

        int[]arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        insertion_sort(arr);



    }

    public static void insertion_sort(int[] arr) {
                int shifts =0, comparisons=0;
        for(int i = 1 ;i< arr.length ;i++)
        {

            int temp = arr[i];
            int j = i-1;
            if(arr[j]<temp)comparisons++;
            while(j>=0 && arr[j]>temp)
            {
                comparisons++;
                shifts++;
                arr[j+1] =arr[j];
                j--;
            }
            if(j!=-1 && arr[j]<temp)comparisons++;

            arr[j+1] = temp;
            shifts++;
         }

        for (int i = 0; i < arr.length; i++) {
            System.out.println(arr[i]);
        }
            System.out.println("comparisons  = " +  comparisons +"\n" +"shifts = " + shifts );


    }
}

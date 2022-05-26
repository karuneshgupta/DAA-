import java.util.Scanner;

public class Quick_sort {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n ;
        System.out.println("enter size");
        n= sc.nextInt();
        int []arr = new int[n];


        inputarray(arr);
        Qsort q = new Qsort();
        q.comparison = 0;
        q.swaps= 0 ;
        q.quicksort(arr,0, arr.length-1);
        printarray(arr);
        System.out.printf("comparison = %d \t swaps = %d",q.comparison,q.swaps );


    }
    public static void inputarray(int[] arr) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter elements");
        for (int i = 0; i <arr.length; i++) {
            arr[i] = sc.nextInt();
        }

    }
    public static void printarray(int[] arr) {
        for (int i = 0; i <arr.length; i++) {
            System.out.println(arr[i]);
        }
    }

}

class Qsort
{
    public int comparison;
    public int swaps;
    public void quicksort(int[] arr , int l ,int h)
    {
        if(l<h)
        {

            int pivot = partition(arr,l,h);
            // now pivot element is at its position
            quicksort(arr,l,pivot-1);
            quicksort(arr,pivot+1,h);
        }
    }

    public int partition(int []arr,int l , int h )
    {
        //i 10j 5 9 2 1 3 4
        //  2i 5 9 10j 1 3 4
        //  2 1i 9 10 5j 3 4
        //  2 1 3i 10 5 9 4  j exhausted it cannot go to right index
//      now swapping i+1 index with right or high means pivot element
        //  2 1 3  |4|  5 9 10
        // now pivot at its position

        int pivot = arr[h];
        int i = l-1;
        for(int j = l ; j<h ;j++)
        {
            if(arr[j] <=pivot)
            {
                i++;
                swap(arr,i,j);
            }
            comparison++;
        }
        swap(arr,i+1,h);
        return i+1;
    }

    public void swap(int []arr, int i , int j )
    {
        int temp = arr[i];
        arr[i] =arr[j];
        arr[j] =temp;
        swaps++;
    }

}
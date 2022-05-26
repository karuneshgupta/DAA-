import java.util.Scanner;

public class Merge_sort {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n ;
            System.out.println("enter size");
            n= sc.nextInt();
            int []arr = new int[n];

            int inversion =0;
            inputarray(arr);
            for(int i =  0 ; i < n-1 ; i++)
            {
                for(int j = i+1 ; j<n ;j++ )
                {
                    if(arr[i] > arr[j] && i<j)
                    {
                        inversion++;
                    }
                }
            }
            Msort m = new Msort();
            m.comparison = 0;
            m.merge_sort(arr , 0 , arr.length-1);
            printarray(arr);
            System.out.println("\ncomparison = " + m.comparison);
            System.out.println("inversion = " + inversion);


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

class Msort{
    public int comparison;
    public void merge_sort(int[] A , int l , int r)

    {
        if(l<r)
        {
            int mid = l+(r-l)/2;
            merge_sort(A,l ,mid);
            merge_sort(A, mid+1 , r);
            merge(A,l , mid , r);
        }
    }

    public void merge(int []A , int l , int mid, int r)
    {
        // left sub array size
        int n1 = mid - l +1;
        // right sub array size
        int n2 = r - mid;

        // declaring 2 sub arrays
        int []Left = new int[n1];
        int []Right = new int[n2];

        // intitalising 2 arrays
        for (int i = 0; i < n1; i++) {
            Left[i] = A[ i + l];
        }
        for (int i = 0; i < n2; i++) {
            Right[i] = A[mid + 1 + i];
        }
        // merging 2 sorted arrays into 1
        int i = 0 , j = 0 , k = l;
        while(i< n1 && j< n2)
        {
            comparison++;
            if(Left[i] < Right[j])
            {
                A[k] = Left[i];
                k++;
                i++;
            }
            else{
                A[k] = Right[j];
                k++;
                j++;
            }
        }
        while(i<n1)
        {
            A[k] = Left[i];
            i++ ; k++;
        }

        while(j<n2)
        {
            A[k] = Right[j];
            k++; j++;
        }


    }
}




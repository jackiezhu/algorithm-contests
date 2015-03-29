package com.jackiezhu;

public class Main {
    public static int firstMissingPositive(int[] A) {
        for(int i=0; i<A.length; i++) {
            while(A[i] > 0 && A[i] <= A.length && A[A[i]-1] != A[i]) {
                int temp = A[i];
                A[i] = A[A[i]-1];
                A[A[i]-1] = temp;
            }
        }
        for(int i=0; i<A.length; i++) {
            if(A[i] != i+1) return i+1;
        }
        return A.length+1;
    }
    public static void main(String[] args) {
	// write your code here
        int[] A =  {1,2};
        System.out.println(firstMissingPositive(A));
    }
}

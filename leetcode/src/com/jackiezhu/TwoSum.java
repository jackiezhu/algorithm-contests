package com.jackiezhu;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;

/**
 * Created by JackieZhu on 15/3/29.
 */
/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
* */
public class TwoSum {
    public int[] twoSum(int[] numbers, int target) {
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
        int []ret = new int[2];
        for(int i=0; i<numbers.length; i++) {
            if(hash.containsKey(target-numbers[i])) {
                ret[0] = hash.get(target-numbers[i]);
                ret[1] = i+1;
                return ret;
            } else {
                hash.put(numbers[i], i+1);    // assume that input have exactly one solution.
            }
        }

        return ret;
    }
}

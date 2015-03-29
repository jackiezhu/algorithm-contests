package com.jackiezhu;

/**
 * Created by JackieZhu on 15/3/29.
 */
/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
* */
public class LongestSubstringWithoutRepeatingCharacters {
    public int lengthOfLongestSubstring(String s) {
        int []hash = new int[256];
        int start = 0, end = 0, ret = 0;
        while(end < s.length()) {
            int c = s.charAt(end);
            if(hash[c] == 0) {
                hash[c] ++;
                ret = Math.max(ret, end-start+1);
                end ++;
            } else {
                hash[s.charAt(start)] --;
                start ++;
            }
        }
        return ret;
    }
}

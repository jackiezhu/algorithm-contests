package com.jackiezhu;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by JackieZhu on 15/3/5.
 */
public class FindHackerRankSolution {

    public static int findHackerRank(String s) {
        String regex = "\\bhackerrank\\b";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(s);
        boolean isStart = false, isEnd = false;
        while(matcher.find()) {
            if(matcher.start() == 0) {
                isStart = true;
            }
            if(matcher.start() == s.length() - "hackerrank".length()) {
                if(isStart) {
                    return 0;
                } else {
                    return 2;
                }
            }
        }
        if(isStart) {
            return 1;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        for(int i=0; i<n; i++) {
            String s = scanner.nextLine();
            System.out.println(findHackerRank(s));
        }
    }
}

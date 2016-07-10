package com.jackiezhu;

/**
 * Created by JackieZhu on 15/3/29.
 */
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
* */

/**
  Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
 }


public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1), iter = dummy;
        int carry = 0;
        for(;l1 != null || l2 != null;
            l1 = (l1 == null ? null : l1.next), l2 = (l2 == null ? null : l2.next), carry /= 10) {
            carry += (l1 == null ? 0 : l1.val);
            carry += (l2 == null ? 0 : l2.val);
            iter.next = new ListNode(0);
            iter = iter.next;
            iter.val = carry % 10;
        }
        if(carry != 0) {
            iter.next = new ListNode(carry);
        }
        return dummy.next;
    }
}

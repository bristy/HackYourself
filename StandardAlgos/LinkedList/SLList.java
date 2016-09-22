package LinkedList;

import mock.Mock;

/**
 * Created by brajesh.k on 21/09/16.
 */
public class SLList<T> {
    ListNode<T> head;

    // push element at beginning
    public void push(T val) {
        ListNode<T> node = new ListNode<T>(val, head);
        head = node;
    }

    public ListNode<T> getNthNode(int n) {
        if (n <= 0) {
            return null;
        }
        ListNode<T> current = head;
        while (current != null) {
            n--;
            if (n == 0) {
                return current;
            }
            current = current.getNext();
        }
        return null;
    }

    public ListNode<T> getNthNodeFormLast(int n) {
        if (n <= 0) {
            return null;
        }
        ListNode<T> slow = head;
        ListNode<T> fast = head;
        while (n > 0 ) {
            if (fast == null) {
                return null;
            }
            fast = fast.getNext();
            n--;
        }

        while (fast != null) {
            slow = slow.getNext();
            fast = fast.getNext();
        }

        return slow;
    }


    public ListNode<T> getMiddleNode() {
        ListNode<T> slow = head;
        ListNode<T> fast = head;
        while (fast != null && fast.getNext() != null) {
            fast = fast.getNext().getNext();
            slow = slow.getNext();
        }
        return slow;
    }

    public void reverse() {
        if (head != null) {
            ListNode<T> current = head;
            ListNode<T> prev = null;
            ListNode<T> next = null;
            while (current != null) {
                next = current.getNext();
                current.setNext(prev);
                prev = current;
                current = next;
            }
            head = prev;
        }
    }

    public void reverseRecursion() {
        head = reverseRecursion(head);
    }

    public ListNode<T> reverseRecursion(ListNode<T> head) {
        if (head == null) {
            return head;
        }

        ListNode<T> first = head;
        ListNode<T> rest = head.getNext();
        if (rest == null) {
            // only one element
            return head;
        }
        // reverse rest of list
        rest = reverseRecursion(rest);

        first.getNext().setNext(first);
        first.setNext(null);
        head = rest;
        return  head;
    }

    public ListNode<T> reverseInPair(ListNode<T> head) {
        ListNode<T> current = head;
        if (current != null
                && current.getNext() != null) {
            // swap pair
            ListNode<T> temp = current.getNext();
            current.setNext(temp.getNext());
            temp.setNext(current);
            ListNode<T> pairFirst =  reverseInPair(current.getNext());
            current.setNext(pairFirst);
            return temp;

        }
        if (current == null) {
            return null;
        }
        return current.getNext();
    }

    public void reverseInPair() {
        head = reverseInPair(head);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        ListNode<T> current = head;
        while (current != null) {
            sb.append(current.getVal() + "->");
            current = current.getNext();
        }
        return sb.toString();
    }



    public static void main(String[] args) {
        // list is 6->5->4->3->2->1->
        SLList<Integer> list = Mock.getIntegerList();
        System.out.println("List is \n" + list );

        int n = 3;
        System.out.println(String.format("%d node is %s", n, list.getNthNode(n)));

        System.out.println(String.format("Middle node is %s", list.getMiddleNode()));

        System.out.println(String.format("%d Node from last is %s", n, list.getNthNodeFormLast(n)));

        System.out.println("List before reverse is \n" + list );
        list.reverseRecursion();
        System.out.println("List after reverse is \n" + list );




        System.out.println("List before reverse in Pair is \n" + list );
        list.reverseInPair();
        System.out.println("List after reverse in pair is \n" + list );

    }
}

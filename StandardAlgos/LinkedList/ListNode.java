package LinkedList;

/**
 * Created by brajesh.k on 21/09/16.
 */
public class ListNode<T> {
    private T val;
    private ListNode<T> next;
    private ListNode<T> prev;

    public ListNode(T val) {
        this.val = val;
    }

    public ListNode(T val, ListNode<T> next) {
        this.val = val;
        this.next = next;
    }

    public ListNode(T val, ListNode<T> next, ListNode<T> prev) {
        this.val = val;
        this.next = next;
        this.prev = prev;
    }

    public T getVal() {
        return val;
    }

    public void setVal(T val) {
        this.val = val;
    }

    public ListNode<T> getNext() {
        return next;
    }

    public void setNext(ListNode<T> next) {
        this.next = next;
    }

    public ListNode<T> getPrev() {
        return prev;
    }

    public void setPrev(ListNode<T> prev) {
        this.prev = prev;
    }

    @Override
    public String toString() {
        return "val = " + val;
    }
}

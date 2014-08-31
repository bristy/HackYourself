public class LinkedListRev {
	ListNode heads = null;
	//ListNode result = null;
	ListNode slow = null;
	ListNode fast = null;

	public ListNode sortList(ListNode head) {
		// ListNode headref=head;

		if (head == null || head.next == null) {
			return head;
		} else {
			ListNode secondHalf = devide(head);
			slow.next = null;
			return(merge(sortList(head), sortList(secondHalf)));

		}
		//return result;
	}

	ListNode merge(ListNode head1, ListNode head2) {
		/////////////////////////new code
        ListNode result = new ListNode(0);// sentinal for escaping null checks
        ListNode curr = result;
        
		while(null != head1 && null != head2){
            if(head1.val < head2.val){
                curr.next = head1;
                head1 = head1.next;
            } else{
                curr.next = head2;
                head2 = head2.next;
            }

            curr = curr.next;
        }

        if (null != head1 ){
            curr.next = head1;
        }
        if(null != head2){
            curr.next = head2;
        }
		return result.next;
	}

	ListNode devide(ListNode head) {

		if (head == null || head.next == null) {
			return null;
		} else {
			slow = head;
			fast = head.next;
			while (fast != null) {
				fast = fast.next;
				if (fast != null) {
					slow = slow.next;
					fast = fast.next;
				}

			}
		}
		// start1 = head;
		ListNode secondHalf = slow.next;
        	slow.next = null; /////////////////////////new code
		return secondHalf;
		// slow.next = null;
	}

	public static void main(String[] args) {
		LinkedListRev linkrev = new LinkedListRev();
		linkrev.insert(10);
		linkrev.insert(5);
		linkrev.insert(20);
		linkrev.insert(3);
		linkrev.insert(50);
		ListNode node = linkrev.sortList(linkrev.heads);
		while (node!= null) {
			System.out.println(node.val);
			node = node.next;
		}
	}

	void insert(int val) {
		ListNode newnode = new ListNode(val);
		if (heads == null) {
			heads = newnode;
		} else {
			ListNode tmp = heads;
			while (tmp.next != null) {
				tmp = tmp.next;
			}
			tmp.next = newnode;
		}
	}

}

class ListNode {

	ListNode next;
	int val;

	public ListNode(int val) {
		// TODO Auto-generated constructor stub
		this.val = val;
		next = null;
	}
}

import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
import java.util.Vector;

public class ListDemo {
	public static void main(String[] args) {
		// 声明List并实例化为ArrayList
		List l1 = new ArrayList();
		l1.add("a");
		l1.add("b");
		l1.add("c");
		// 使用Iterator迭代器遍历出集合的元素
		for(Iterator i = l1.iterator(); i.hasNext(); ) {
			String str = (String) i.next();
			System.out.println(str);
		}

		System.out.println("--------------------");
		// 声明List并实例化为Vector
		List l2 = new Vector();
		l2.add("a");
		l2.add("b");
		l2.add("c");
		for(Iterator i = l2.iterator(); i.hasNext(); ) {
			String str = (String) i.next();
			System.out.println(str);
		}

		System.out.println("--------------------");
		// 声明List并实例化为ArrayList
		List l3 = new LinkedList();
		l3.add("a");
		l3.add("b");
		l3.add("c");
		for(Iterator i = l3.iterator(); i.hasNext(); ) {
			String str = (String) i.next();
			System.out.println(str);
		}

		System.out.println("--------------------");
		ArrayList l4 = new ArrayList();
		l4.add(0, "a");
		l4.add(1, "b");
		l4.add(2, "c");
		for(int i = 0; i < 10; i++) {
			l4.add(Integer.toString(i));
		}
		for(int i = 0; i < l4.size(); i++) {
			System.out.println(l4.get(i));
		}
		for(Iterator i =l4.iterator(); i.hasNext(); ) {
			String str = (String) i.next();
			System.out.println(str);
		}
		
		System.out.println("--------------------");
		// ArrayList类实现一个可增长的动态数组
		List<String> l5 = new ArrayList<String>();
		l5.add("a");
		l5.add("b");
		l5.add("c");
		System.out.println(l5.size());
		l5.remove(0);
		l5.remove("c");
		System.out.println(l5.size());
		l5.clear();

		System.out.println("--------------------");
		// LinkedList类实现了链表，可初始化为空或者已存在的集合
		LinkedList<String> l6 = new LinkedList<String>();
		l6.add("a");
		l6.add("b");
		l6.addFirst("c");
		l6.addLast("d");
		for(String str:l6) {
			System.out.println(str);
		}
		System.out.println("Head: " + l6.getFirst());
		System.out.println("Tail: " + l6.getLast());
	}
}
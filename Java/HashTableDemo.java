import java.util.HashMap;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Map;

public class HashTableDemo {
	public static void main(String[] args) {
		// new一个Hashtable
		Hashtable table = new Hashtable();
		table.put("one", 2);
		table.put("two", 4);
		table.put("three", 5);
		System.out.println("table: " + table);
		
		Iterator iter = table.entrySet().iterator();
		while(iter.hasNext()) {
			Map.Entry entry = (Map.Entry) iter.next();
			System.out.println("next: " + entry.getKey() + " - " + entry.getValue());
		}
		
		System.out.println("size: " + table.size());
		System.out.println("contains key two: " + table.containsKey("two"));
		System.out.println("contains key five: " + table.containsKey("five"));
		System.out.println("contains value 0: " + table.containsValue(0));
		System.out.println("contains value 5: " + table.containsValue(5));
		
		table.remove("three");
		System.out.println("table: " + table);
		
		table.clear();
		System.out.println(table.isEmpty() ? "table is empty" : "table is not empty");
		
		System.out.println("--------------------");
		// new一个HashMap
		Map map = new HashMap();
		map.put("one", 4);
		map.put("two", 9);
		map.put("three", 2);
		System.out.println("map: " + map);
		
		Iterator iter2 = map.entrySet().iterator();
		while(iter2.hasNext()) {
			Map.Entry entry = (Map.Entry) iter2.next();
			System.out.println("next: " + entry.getKey() + " - " + entry.getValue());
		}
		
		System.out.println("size: " + map.size());
		System.out.println("contains key two: " + map.containsKey("two"));
		System.out.println("contains key five: " + map.containsKey("five"));
		System.out.println("contains value 0: " + map.containsValue(9));
		System.out.println("contains value 5: " + map.containsValue(5));
		
		map.remove("three");
		System.out.println("table: " + map);
		
		map.clear();
		System.out.println(map.isEmpty() ? "table is empty" : "table is not empty");
	}
}
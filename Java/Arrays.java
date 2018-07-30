import java.util.Arrays;
public class ArraysUtilDemo {
	public static void main(String[] args) {
		int[] arr1 = {2, 1, 4, 5, 8, 9, 7};
		// 拷贝数组
		int[] arr2 = Arrays.copyOf(arr1, 10);
		for(int i = 0; i < arr2.length; i++) {
			System.out.print(arr2[i] + " ");
		}
		System.out.println("\n**********************");
		// 拷贝数组中指定范围数据
		int[] arr3 = Arrays.copyOfRange(arr1, 2, 4);
		for(int i = 0; i < arr3.length; i++) {
			System.out.print(arr3[i] + " ");
		}
		System.out.println("\n**********************");
		// 比较数组
		int[] arr4 = {2, 1, 4, 5, 8, 9, 3};
		boolean flag = Arrays.equals(arr1, arr4);
		System.out.print(flag);
		System.out.println("\n**********************");
		// 数组填充
		int[] arr5 = new int[10];
		Arrays.fill(arr5, 1, 5, 10);
		for(int i = 0; i < arr5.length; i++) {
			System.out.print(arr5[i] + " ");
		}
		System.out.println("\n**********************");
		// 数组排序
		Arrays.sort(arr1);
		for(int i = 0; i < arr1.length; i++) {
			System.out.print(arr1[i] + " ");
		}
		System.out.println("\n**********************");
		// 二分查找
		int x1 = Arrays.binarySearch(arr1, 5);
		System.out.println(x1);
	}
}
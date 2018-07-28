import java.util.Scanner;

public class BinarySearch {
	public static void main(String[] args) {
		int[] arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		Scanner input = new Scanner(System.in);
		int num = input.nextInt();
		int start = 0;
		int end = arr1.length - 1;
		int sign = -1;
		int middle;
		while(start <= end) {
			middle = (start + end) / 2;
			if(num == arr1[middle]) {
				sign = middle + 1;
				break;
			}
			if(num > arr1[middle]) {
				start = middle + 1;
			}
			if(num < arr1[middle]) {
				end = middle - 1;
			}
		}
		if(sign == -1) {
			System.out.println("Not find");
		}
		else {
			System.out.println("Find it");
		}
	}
}

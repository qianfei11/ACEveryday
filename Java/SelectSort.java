public class SelectSort {
	public static void main(String[] args) {
		int[] arr1 = {20, 30, 11, 98, 44, 12, 35};
		int min = 0;
		for(int i = 0; i < arr1.length - 1; i++) {
			min = i;
			for(int j = i + 1; j < arr1.length; j++) {
				if(arr1[min] > arr1[j]) {
					min = j;
				}
			}
			if(i != min) {
				int tmp = arr1[i];
				arr1[i] = arr1[min];
				arr1[min] = tmp;
			}
		}
		for(int i = 0; i < arr1.length; i++) {
			System.out.println(arr1[i]);
		}
	}
}

public class BubbleSort {
	public static void main(String[] args) {
		int[] arr1 = {20, 30, 11, 98, 44, 12, 35};
		for(int i = 0; i < arr1.length - 1; i++) {
			for(int j = 0; j < arr1.length - 1 - i; j++) {
				if(arr1[j] > arr1[j + 1]) {
					int tmp = arr1[j];
					arr1[j] = arr1[j + 1];
					arr1[j + 1] = tmp;
				}
			}
		}
		for(int i = 0; i < arr1.length; i++) {
			System.out.println(arr1[i]);
		}
	}
}

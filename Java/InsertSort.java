public class InsertSort {
	public static void main(String[] args) {
		int[] arr1 = {20, 30, 11, 98, 44, 12, 35};
		for(int i = 1; i < arr1.length; i++) {
			int tmp = arr1[i];
			int j = i;
			while(j > 0 && tmp < arr1[j - 1]) {
				arr1[j] = arr1[j - 1];
				j--;
			}
			arr1[j] = tmp;
		}
		for(int i = 0; i < arr1.length; i++) {
			System.out.println(arr1[i]);
		}
	}
}

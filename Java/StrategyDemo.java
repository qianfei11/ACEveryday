public class StrategyDemo {
    public static void main(String[] args) {
        int[] array = {1, 56, 44, 33, 22, 11, 66, 90, 80};
        ISort bubblesort = new BubbleSort();
        ISort selectsort = new SelectSort();
        ISort insertsort = new InsertSort();
        Context context = new Context(insertsort);
        context.sort(array);
        context.printArray(array);
    }
}

class Context {
    private ISort iSort = null;
    public Context(ISort iSort) {
        this.iSort = iSort;
    }

    public void sort(int[] array) {
        iSort.sort(array);
    }

    public void printArray(int[] array) {
        for(int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }
}

interface ISort {
    public void sort(int[] array);
}

class BubbleSort implements ISort {
    public void sort(int[] array) {
        System.out.println("BubbleSort:");
        for(int i = 0; i < array.length - 1; i++) {
            for(int j = 0; j < array.length - i - 1; j++) {
                if(array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}

class SelectSort implements ISort {
    public void sort(int[] array) {
        System.out.println("SelectSort:");
        int min = 0;
        for(int i = 0; i < array.length - 1; i++) {
			min = i;
			for(int j = i + 1; j < array.length; j++) {
				if(array[min] > array[j]) {
					min = j;
				}
			}
			if(i != min) {
				int tmp = array[i];
				array[i] = array[min];
				array[min] = tmp;
			}
		}
    }
}

class InsertSort implements ISort {
    public void sort(int[] array) {
        System.out.println("InsertSort:");
        for(int i = 1; i < array.length; i++) {
			int tmp = array[i];
			int j = i;
			while(j > 0 && tmp < array[j - 1]) {
				array[j] = array[j - 1];
				j--;
			}
			array[j] = tmp;
		}
    }
}
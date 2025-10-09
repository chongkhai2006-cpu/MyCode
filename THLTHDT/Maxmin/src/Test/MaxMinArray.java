package Test;

import java.util.Scanner;  // thêm import

public class MaxMinArray {
    private int[] intArray;  // khai báo biến tham chiếu mảng (chưa khởi tạo số phần tử)

    // Constructor: khởi tạo mảng với độ dài len
    public MaxMinArray(int len) {
        intArray = new int[len];
    }

    // Nhập dữ liệu cho mảng
    public void input() {
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < intArray.length; i++) {
            System.out.print("Nhập intArray[" + i + "] = ");
            intArray[i] = scanner.nextInt();
        }
    }

    // Tìm giá trị lớn nhất
    public int findMax() {
        int max = intArray[0];
        for (int i = 1; i < intArray.length; i++) {
            if (intArray[i] > max) {
                max = intArray[i];
            }
        }
        return max;
    }

    // Tìm giá trị nhỏ nhất
    public int findMin() {
        int min = intArray[0];
        for (int i = 1; i < intArray.length; i++) {
            if (intArray[i] < min) {
                min = intArray[i];
            }
        }
        return min;
    }
}

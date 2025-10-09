package Test;

public class MaxMintTest {
    public static void main(String[] args) {
        MaxMinArray arr = new MaxMinArray(5); // mảng 5 phần tử
        arr.input();
        System.out.println("Giá trị lớn nhất: " + arr.findMax());
        System.out.println("Giá trị nhỏ nhất: " + arr.findMin());
    }
}

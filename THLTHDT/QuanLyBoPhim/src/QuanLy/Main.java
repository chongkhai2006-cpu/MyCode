package QuanLy;

public class Main {
	public static void main(String[] args) {
		Ngay ngay1 = new Ngay(15, 05, 2022);
		Ngay ngay2 = new Ngay(31, 01, 2025);
		Ngay ngay3 = new Ngay(16, 02, 2030);
		
		HangSanXuat hangSanXuat1 = new HangSanXuat("Hãng A", "Việt Nam");
		HangSanXuat hangSanXuat2 = new HangSanXuat("Hãng B", "Mỹ");
		HangSanXuat hangSanXuat3 = new HangSanXuat("Hãng C", "Ba Lan");
		
		BoPhim boPhim1 = new BoPhim("Bố Già", 2020, hangSanXuat1, 65000, ngay1);
		BoPhim boPhim2 = new BoPhim("Running Man", 2021, hangSanXuat2, 100000, ngay2);
		BoPhim boPhim3 = new BoPhim("Khám phá Ba Lan", 2025, hangSanXuat3, 115000, ngay3);
		System.out.println("Gia ve bo phim 2 re hon bo phim 1: " + boPhim2.kiemTraGiaVe(boPhim1));
		System.out.println("Ten hang san xuat bo phim 1:" +boPhim1.layTenHangSX());
		System.out.println("Bo phim 1 giam gia 10%: " + boPhim1.giaVeKhuyenMai(100));
	}
}

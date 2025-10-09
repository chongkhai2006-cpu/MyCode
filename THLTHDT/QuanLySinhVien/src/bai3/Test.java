package bai3;

public class Test {
	public static void main(String[] args) {
		NgaySinh ngay1 = new NgaySinh(19, 7, 2002);
		NgaySinh ngay2 = new NgaySinh(17, 2, 2001);
		NgaySinh ngay3 = new NgaySinh(19, 7, 2002);
		
		
		Lop lop1 = new Lop("DH01", "Khoa Công nghệ Thông tin");
		Lop lop2 = new Lop("DH02", "Khoa Khoa học Máy tính");
		Lop lop3 = new Lop("DH03", "Khoa An ninh mạng");
		
		SinhVien sv1 = new SinhVien("0001", "Tùng ITV", ngay1, 9.0, lop1);
		SinhVien sv2 = new SinhVien("0002", "Peter Le", ngay2, 4.0, lop2);
		SinhVien sv3 = new SinhVien("0003", "Lê Tùng", ngay3, 6.0, lop3);
		System.out.println("Ten Khoa");
		System.out.println("SV 2: " + sv2.tenKhoaSVHoc());
		System.out.println("SV2: " +sv2.xetKQ() );
		System.out.println("Kiem tra ngay sinh SV1 va SV 2 co trung nhau khong:" + sv1.kiemTraCungNgaySinh(sv2));
		System.out.println("Kiem tra ngay sinh SV1 va SV 3 co trung nhau khong:" + sv1.kiemTraCungNgaySinh(sv3));
	}
}

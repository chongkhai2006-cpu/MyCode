package QuanLy;

public class BoPhim {
	private String tenPhim;
	private int namSX;
	private  HangSanXuat hangSX;
	double giaVe;
	private Ngay ngayChieu;
	public BoPhim(String tenPhim, int namSX, HangSanXuat hangSX, double giaVe, Ngay ngayChieu) {
		super();
		this.tenPhim = tenPhim;
		this.namSX = namSX;
		this.hangSX = hangSX;
		this.giaVe = giaVe;
		this.ngayChieu = ngayChieu;
	}
	public String getTenPhim() {
		return tenPhim;
	}
	public void setTenPhim(String tenPhim) {
		this.tenPhim = tenPhim;
	}
	public int getNamSX() {
		return namSX;
	}
	public void setNamSX(int namSX) {
		this.namSX = namSX;
	}
	public HangSanXuat getHangSX() {
		return hangSX;
	}
	public void setHangSX(HangSanXuat hangSX) {
		this.hangSX = hangSX;
	}
	public double getGiaVe() {
		return giaVe;
	}
	public void setGiaVe(double giaVe) {
		this.giaVe = giaVe;
	}
	public Ngay getNgayChieu() {
		return ngayChieu;
	}
	public void setNgayChieu(Ngay ngayChieu) {
		this.ngayChieu = ngayChieu;
	}
public boolean kiemTraGiaVe(BoPhim phimKhac) {
	return this.giaVe < phimKhac.giaVe;	
}
public String layTenHangSX() {
	return this.hangSX.getTenHangSanXuat();
}
public double giaVeKhuyenMai(double x) {
	return this.giaVe*(1-x/100);
}
}
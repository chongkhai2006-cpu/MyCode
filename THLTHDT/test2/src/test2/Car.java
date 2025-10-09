package test2;
public class Car {
String color;
String brand;
double weight;
String model;
public Car() {
}
public Car(String color, String brand) {
this.color = color;
this.brand = brand;
}
public Car(String color, String brand, 
double weight, String model) {
this.color = color;
this.brand = brand;
this.weight = weight;
this.model = model;
}
@Override
public String toString() {
return "Car [color=" + color + ", brand=" + 
brand + ", weight=" + weight + ", model=" +
model + "]";
}
}
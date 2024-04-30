package mathematik;

public class Klasse1 {
    public static void main(String[] args) {
        Klasse1 klasse = new Klasse1();
        System.out.println("Queersumme von 192: " + klasse.queersumme(192));
        
    }

    public int queersumme(int input) {
        int sum = 0;
        while (input > 0) {
            sum += input % 10;
            input = input / 10;
        }
        return sum;
    }
}

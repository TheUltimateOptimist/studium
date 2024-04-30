import mathematik.Klasse1;

public class Klasse2 {
    public static void main(String[] args) {
        Klasse2 klasse = new Klasse2();
        System.out.println("Quersumme von 192: " + klasse.quersumme(192));
        
    }

    public int quersumme(int input) {
        int sum = 0;
        while (input > 0) {
            sum += input % 10;
            input = input / 10;
        }
        return sum;
    }
}
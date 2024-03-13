import java.util.Scanner;

public class VowelAge {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    String name = scan.nextLine();
    int age = scan.nextInt();
    int vowels = 0;
    char[] vow = {'a', 'o', 'e', 'i', 'u'};
    String youth = "minor";
    if(age >= 18){
        youth = "adult";
    }
    for(int i = 0;i < name.length(); ++i){
        char tmp = name.charAt(i);
        for(int j = 0; j < vow.length;++j){
            if(vow[j] == Character.toLowerCase(tmp)){
                ++vowels;
            }
        }
    }
    if(youth == "adult"){
        System.out.println("Hello " + name + ", you have " + vowels + " vowels, and you are an " + youth);
    } else {
        System.out.println("Hello " + name + ", you have " + vowels + " vowels, and you are a " + youth);
    }
  }
}

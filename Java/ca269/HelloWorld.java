import java.util.Scanner;

public class AlarmClock {
    public static void main(String [] args){
        Scanner input = new Scanner(System.in);    // get the entire line after the prompt 
        String[] numbers = input.nextLine().split(" "); // split by spaces
        int hour = Integer.parseInt(numbers[0]);
        int min = Integer.parseInt(numbers[1]);
        int nhour = 0;
        int nmin = 0;
        int count = -1;
        while(hour >= nhour){
            if(min < nmin && hour < nhour){
                break;
            }
            String[] num = input.nextLine().split(" "); // split by spaces
            nhour = Integer.parseInt(num[0]);
            nmin = Integer.parseInt(num[1]);
            ++count;
        }
        System.out.println("false alarms: " + count);
    }
}

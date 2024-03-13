import java.util.Scanner;
import java.time.LocalDate;

public class Task{
    private final String title;
    private String descriptiion;
    private LocalDate scheduled;
    private LocalDate deadline;
    public State state;
    Task(String title, State state){
        this.title = title;
        this.State = State.state;
    }
}

enum State {
    TODO, BEGN, HALT, WAIT, DONE;
}

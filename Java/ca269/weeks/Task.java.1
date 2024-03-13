import java.util.Date;

class Task {
  private final String title;
  private String description;
  private Date scheduledDate;
  private final Date deadlineDate;
  private TaskState state;

  public Task(String title, Date deadlineDate) {
    this.title = title;
    this.deadlineDate = deadlineDate;
    this.state = TaskState.TODO;
  }

  public String getTitle() {
    return title;
  }

  public String getDescription() {
    return description;
  }

  public void setDescription(String description) {
    this.description = description;
  }

  public Date getScheduledDate() {
    return scheduledDate;
  }

  public void setScheduledDate(Date scheduledDate) {
    this.scheduledDate = scheduledDate;
  }

  public Date getDeadlineDate() {
    return deadlineDate;
  }

  public TaskState getState() {
    return state;
  }

  public void setState(TaskState state) {
    this.state = state;
  }
}

enum TaskState {
  TODO, BEGN, HALT, WAIT, DONE
}

class Chore extends Task {
  private Date repeatDate;

  public Chore(String title, Date deadlineDate, Date repeatDate) {
    super(title, deadlineDate);
    this.repeatDate = repeatDate;
  }

  public Date getRepeatDate() {
    return repeatDate;
  }

  public void setRepeatDate(Date repeatDate) {
    this.repeatDate = repeatDate;
  }

  public void reset() {
    setScheduledDate(getRepeatDate());
    setRepeatDate(new Date(getRepeatDate().getTime() + 7 * 24 * 60 * 60 * 1000));
  }
}

class RepeatingTask extends Task {
  public RepeatingTask(String title, Date deadlineDate) {
    super(title, deadlineDate);
  }

  public void reset() {
    setState(TaskState.TODO);
  }
}

class SharedTask extends Task {
  private String person;

  public SharedTask(String title, Date deadlineDate, String person) {
    super(title, deadlineDate);
    this.person = person;
    setState(TaskState.WAIT);
  }

  public String getPerson() {
    return person;
  }

  public void setPerson(String person) {
    this.person = person;
  }
}

class Dependency extends Task {
  private Task dependentTask;

  public Dependency(String title, Date deadlineDate, Task dependentTask) {
    super(title, deadlineDate);
    this.dependentTask = dependentTask;
  }

  public Task getDependentTask() {
    return dependentTask;
  }

  public void setDependentTask(Task dependentTask) {
    this.dependentTask = dependentTask;
  }

  public boolean canBeMarkedDone() {
    return dependentTask.getState() == TaskState.DONE;
  }
}

public class PersonalTaskManager {
  public static void main(String[] args

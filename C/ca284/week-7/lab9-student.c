typedef struct Student Student;

struct Student
{
    char name[20];
        char programme[20];
            float grade;
            };

            void addStudent(Student *student, char *name, char *programme, float grade);
            void printStudent(Student *student);

            int main(int argc, char *argv[])
            {

                int student_count = (argc - 1) / 3; // Number of students inputted by user.
                    int start_capacity = 2;  // Initally set to store 2 students, reallocation will be done if necessary.
                        Student *p_students;
                            p_students = (Student*)malloc(start_capacity * sizeof(Student));  // Allocate initial memory to pStudent.

                                if(!p_students)  // Check if allocation is successful.
                                    {
                                            printf("Not enough memory.\n");
                                                    free(p_students);
                                                            p_students = NULL;
                                                                    exit(0);
                                                                        }

                                                                            for(int i = 0; i < argc - 1; i += 3)
                                                                                {
                                                                                        if(student_count > start_capacity)  // Reallocation of memory needed if user adds more than inital capactiy.
                                                                                                {
                                                                                                            start_capacity = student_count;
                                                                                                                        // Student *p_te

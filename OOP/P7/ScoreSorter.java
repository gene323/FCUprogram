import java.util.*;

public class ScoreSorter{
    public static void main(String[] args){
        ArrayList<Student> arr = new ArrayList<Student>();
        Scanner sc = new Scanner(System.in);
        System.out.print("Input student number: ");
        int n = sc.nextInt();

        for(int i=0; i<n; i++){
            System.out.printf("Input st.%d Chinese, English, Math grade: ", i);
            int chinese = sc.nextInt();
            int english = sc.nextInt();
            int math = sc.nextInt();
            arr.add(new Student(chinese, english, math));
        }

        Collections.sort(arr);
        arr.forEach((e) -> {
            System.out.println(e);
        });
        sc.close();
    }
}

class Student implements Comparable<Student>{
    int total;
    int chinese;
    int english;
    int math;

    public Student(int chinese, int english, int math){
        this.chinese = chinese;
        this.english = english;
        this.math = math;
        this.total = chinese + english + math;
    }
    public int compareTo(Student st){
        if(total == st.total)
            return 0;
        if(total > st.total)
            return -1;
        return 1;
    }
    public String toString(){
        return String.format("Total: %d Chinese: %d English: %d Math: %d", total, chinese, english, math);
    }
}

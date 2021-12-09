import java.util.*;

public class Task {

    static int NumSt = 1;

    public static void main(String[] args) {

        Student[] s = new Student[NumSt];
        for (int i = 0; i < NumSt; i++) {
            System.out.println("Student No." + (i + 1));
            s[i] = new Student();
            double cgpa = s[i].getCGPA();
            System.out.println("CGPA of the Student No." + s[i].sid + " is " + cgpa);
        }
    }
}

class Student {
    static int NumSub = 4;
    static int NumSem = 2;

    String mail, sid, gender, name;
    Grade[] gpa = new Grade[NumSem];

    Student() {
        System.out.println("Please input your name, id, mail and gender");
        Scanner inp = new Scanner(System.in);
        String mail, sid, gender, name;
        name = inp.next();
        sid = inp.next();
        mail = inp.next();
        gender = inp.next();
        getInfo(name, sid, mail, gender);
        System.out.println("Please enter your Semester Results sequentially!");
        for (int i = 0; i < NumSem; i++) {
            System.out.println("Enter " + (i + 1) + "th Semester results");
            gpa[i] = new Grade();
            gpa[i].getGrade();
        }
        inp.close();
    }

    public void getInfo(String ... sd/*String _name, String _sid, String _mail, String _gender*/) {
        mail = sd[0];// _mail;
        sid = sd[1];//_sid;
        gender = sd[2];//_gender;
        name = sd[3];//_name;
    }

    public double getCGPA() {
        double result = 0, sum = 0;
        int i = 0;
        double[] perSem = new double[NumSub];
        for (Grade a : gpa) {
            sum=0;
            for (Double val : a.gr)
                sum += val;
            perSem[i++] = sum / NumSub;
        }
        for (double c : perSem)
            result += c;
        result /= NumSem;
        return result;
    }
}

class Grade {
    static int NumSub = 4;
    String[] grade = new String[NumSub];
    public ArrayList<Double> gr = new ArrayList<Double>();

    public void getGrade() {
        Scanner ind = new Scanner(System.in);
        for (int i = 0; i < NumSub; i++) {
            System.out.println((i + 1) + "th Subject result: ");
            grade[i] = ind.next();
        }
        //ind.close();
        convert();
    }

    public void convert() {
        for (String val : grade) {
            switch (val) {
                case "A+":
                    gr.add(4.00);
                    break;
                case "A":
                    gr.add(3.50);
                    break;
                case "A-":
                    gr.add(3.00);
                    break;
                case "B":
                    gr.add(2.50);
                    break;
                case "C":
                    gr.add(2.00);
                    break;
                default:
                    gr.add(0.0);
                    break;
            }
        }
    }
}
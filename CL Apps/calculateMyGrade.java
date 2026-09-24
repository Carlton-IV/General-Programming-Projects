public class calculateMyGrade {

    public static void main(String[] args) {
        System.out.println("\n");

        String Class1 = "Weather & Climate";

        //Weights
        double Class1AssignWeight = 0.25;
        double Class1LabsWeight = 0.25;
        double Class1MidtermsWeight = 0.25;
        double Class1FinalWeight = 0.25;

        //Marks
        double[] cClass1Assign = {
            (5.5 / 6.0) * 100,
            (5.5 / 6.0) * 100,
            (4.0 / 6.0) * 100,
            (5.0 / 6.0) * 100,
            (5.0 / 5.0) * 100,
            (5.0 / 7.0) * 100,
            0,
            (6.0 / 6.0) * 100,
            (5.0 / 6.0) * 100,
            (4.0 / 6.0) * 100,
        };
        double[] cClass1Labs = { (29.0 / 52.0) * 100 };
        double[] cClass1Midterms = { (31.0 / 50.0) * 100 };
        double cClass1Final = (80.0 / 80.0) * 100;
        int class1Grade = calculate(
            cClass1Assign,
            Class1AssignWeight,
            cClass1Labs,
            Class1LabsWeight,
            cClass1Midterms,
            Class1MidtermsWeight,
            cClass1Final,
            Class1FinalWeight
        );
        String class1Letter = letter(class1Grade);
        System.out.println(
            Class1 + " grade: " + class1Letter + ", " + class1Grade + "\n"
        );

        String Class2 = "Discrete Structures and Programming";

        //Weights
        double Class2AssignWeight = 0.10;
        double Class2LabsWeight = 0.30;
        double Class2MidtermsWeight = 0.20;
        double Class2FinalWeight = 0.40;

        //Marks
        double[] cClass2Assign = { 100 };
        double[] cClass2Labs = { 70, 100, 100, 98, 100, 85, 100, 100 };
        double[] cClass2Midterms = { 74 };
        double cClass2Final = 93;
        int class2Grade = calculate(
            cClass2Assign,
            Class2AssignWeight,
            cClass2Labs,
            Class2LabsWeight,
            cClass2Midterms,
            Class2MidtermsWeight,
            cClass2Final,
            Class2FinalWeight
        );
        String class2Letter = letter(class2Grade);
        System.out.println(
            Class2 + " grade: " + class2Letter + ", " + class2Grade + "\n"
        );

        String Class3 = "Applied Linear Algebra";

        //Weights
        double Class3AssignWeight = 0.25;
        double Class3LabsWeight = 0.0;
        double Class3MidtermsWeight = 0.35;
        double Class3FinalWeight = 0.40;

        //Marks
        double[] cClass3Assign = { 94.29, 100, 100 };
        double[] cClass3Labs = { 0 };
        double[] cClass3Midterms = { 76, 32 };
        double cClass3Final = 93;
        int class3Grade = calculate(
            cClass3Assign,
            Class3AssignWeight,
            cClass3Labs,
            Class3LabsWeight,
            cClass3Midterms,
            Class3MidtermsWeight,
            cClass3Final,
            Class3FinalWeight
        );
        String class3Letter = letter(class3Grade);
        System.out.println(
            Class3 + " grade: " + class3Letter + ", " + class3Grade + "\n"
        );

        String Class4 = "Applied Statistics";

        //Weights
        double Class4AssignWeight = 0.60;
        double Class4LabsWeight = 0;
        double Class4MidtermsWeight = 0;
        double Class4FinalWeight = 0.4;

        //Marks
        double[] cClass4Assign = { 94.12, 94, 98, 83, 83 };
        double[] cClass4Labs = { 0 };
        double[] cClass4Midterms = { 0 };
        double cClass4Final = 90;
        int class4Grade = calculate(
            cClass4Assign,
            Class4AssignWeight,
            cClass4Labs,
            Class4LabsWeight,
            cClass4Midterms,
            Class4MidtermsWeight,
            cClass4Final,
            Class4FinalWeight
        );
        String class4Letter = letter(class4Grade);
        System.out.println(
            Class4 + " grade: " + class4Letter + ", " + class4Grade + "\n"
        );

        String Class5 = "Computational Methods in Graph Theory";

        //Weights
        double Class5AssignWeight = 0.60;
        double Class5LabsWeight = 0;
        double Class5MidtermsWeight = 0;
        double Class5FinalWeight = 0.4;

        //Psych Marks
        double[] cClass5Assign = { 96, 96.25, 90, 90 };
        double[] cClass5Labs = { 0 };
        double[] cClass5Midterms = { 0 };
        double cClass5Final = 86;
        int class5Grade = calculate(
            cClass5Assign,
            Class5AssignWeight,
            cClass5Labs,
            Class5LabsWeight,
            cClass5Midterms,
            Class5MidtermsWeight,
            cClass5Final,
            Class5FinalWeight
        );
        String class5Letter = letter(class5Grade);
        System.out.println(
            Class5 + " grade: " + class5Letter + ", " + class5Grade + "\n"
        );

        System.out.println(
            "\nGPA:" +
                gradePointAverage(
                    class1Letter,
                    class2Letter,
                    class3Letter,
                    class4Letter,
                    class5Letter
                ) +
                "\n"
        );
    }

    public static int calculate(
        double[] assigns,
        double assignWeight,
        double[] labs,
        double labsWeight,
        double[] midterms,
        double midtermsWeight,
        double finalE,
        double finalWeight
    ) {
        double assignsAvg = 0;
        double labsAvg = 0;
        double midtermsAvg = 0;
        for (int i = 0; i < assigns.length; i++) assignsAvg += assigns[i];
        assignsAvg /= assigns.length;
        for (int i = 0; i < labs.length; i++) labsAvg += labs[i];
        labsAvg /= labs.length;
        for (int i = 0; i < midterms.length; i++) midtermsAvg += midterms[i];
        midtermsAvg /= midterms.length;

        return (int) (assignsAvg * assignWeight +
            labsAvg * labsWeight +
            midtermsAvg * midtermsWeight +
            finalE * finalWeight);
    }

    public static String letter(int grade) {
        String letterG = "F";
        if (grade >= 90) letterG = "A+";
        else if (grade >= 85) letterG = "A";
        else if (grade >= 80) letterG = "A-";
        else if (grade >= 77) letterG = "B+";
        else if (grade >= 73) letterG = "B";
        else if (grade >= 70) letterG = "B-";
        else if (grade >= 67) letterG = "C+";
        else if (grade >= 63) letterG = "C";
        else if (grade >= 60) letterG = "C-";
        else if (grade >= 50) letterG = "D";
        return letterG;
    }

    public static float gradePoint(String letterG) {
        float gp = 0;
        switch (letterG) {
            case "A+":
                gp = (float) 12.90;
                break;
            case "A":
                gp = (float) 12.0;
                break;
            case "A-":
                gp = (float) 11.10;
                break;
            case "B+":
                gp = (float) 9.90;
                break;
            case "B":
                gp = (float) 9.0;
                break;
            case "B-":
                gp = (float) 8.10;
                break;
            case "C+":
                gp = (float) 6.90;
                break;
            case "C":
                gp = (float) 6.0;
                break;
            case "C-":
                gp = (float) 5.10;
                break;
            case "D":
                gp = (float) 3.0;
                break;
        }
        return gp;
    }

    public static float gradePointAverage(
        String one,
        String two,
        String three,
        String four,
        String five
    ) {
        return (float) ((6.0 +
                11.1 +
                3.0 +
                9.0 +
                11.1 +
                5.1 +
                12.0 +
                12.0 +
                12.9 +
                9.9 +
                11.1 +
                11.1 +
                11.1 +
                9.9 +
                6.9 +
                gradePoint(one) +
                gradePoint(two) +
                gradePoint(three) +
                gradePoint(four) +
                gradePoint(five)) /
            3.0 /
            20.0);
    }
}

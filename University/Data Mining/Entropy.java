import java.util.*;
public class Entropy {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int problems = Integer.parseInt(in.nextLine());

        for(int i = 0; i < problems; i++) {
            //gets the line we're working with
            String chs = "", line = in.nextLine();
            int classes, events = 1, j = 0, col = 0, row = 0;

            //parsing the amount of classes
            while(line.charAt(j) != ':') chs += line.charAt(j++);
            classes = Integer.parseInt(chs);

            //parsing the amount of events
            for(j = 0; j < line.length(); j++)
                if(line.charAt(j) == ';') events++;

            //creating an array to hold the values
            double[][] arr = new double[events][classes];

            //parsing the events to the array
            for(j = 0; j < line.length(); j++) {
                switch (line.charAt(j)) {
                    case ';':   arr[row++][col] = Integer.parseInt(chs);
                                col = 0;
                    case ':':   chs = "";
                                break;
                    case ',':   arr[row][col++] = Integer.parseInt(chs);
                                chs = "";
                                break;
                	default:    chs += line.charAt(j);
                		        break;
                }
            }
            arr[row][col] = Integer.parseInt(chs);
            System.out.printf("%.4f\n",entropy(arr));
        }
        in.close();
    }



    public static double surprise(double event) {
        if(event == 0) event = 1;
        return Math.log10(1.0/event) / Math.log10(2);
    }

    //code version of my theorized mathematical generalization "H([[x₀...xₙ]₀...[x₀...xₙ]ₙ]) = ∑(([∑(xₙ)]ₙ/∑([∑(xₙ)]ₙ)) * ∑(([xₙ]ₙ/[∑(xₙ)]ₙ) * log₂([∑(xₙ)]ₙ/[xₙ]ₙ))"
    public static double entropy(double[][] x) {
        double h = 0;
        for(double[] xi : x)
            h += (sum(xi)/sumsum(x)) * entropy(xi);
        return h;
    }
    public static double entropy(double[] x) {
        double h = 0;
        for(double xi : x)
            h += (xi/sum(x)) * surprise(xi/sum(x));
        return h;
    }



    //These sum classes were made to make the entropy code look closer to its mathematical generalization counterpart
    public static double sum(double[] x) {
        double sum = 0;
        for(double xi : x) sum += xi;
        return sum;
    }
    public static double sumsum(double[][] x) {
        double sum = 0;
        for(double[] xi : x) sum += sum(xi);
        return sum;
    }
}

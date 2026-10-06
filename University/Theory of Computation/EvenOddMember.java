import java.io.*;
import java.util.*;
import java.util.regex.*;

public class EvenOddMember
{

    public static void main(String[] args) throws IOException
    {
        File in = new File(args[0]);
        File out = new File(args[1]);

        String line;

        String evenEven = "(aa|bb|((ab|ba)(aa|bb)*(ab|ba)))*";
        String evenOdd = evenEven + "(b|((a|ab|ba)b(bb)*(a|ab|ba)))" + evenEven;
        Pattern patEO = Pattern.compile("^(aa|bb|((ab|ba)(aa|bb)*(ab|ba)))*(b|((ab|ba)b(bb)*(ba|ab))|(ab(bb)*a))(aa|bb|((ab|ba)(aa|bb)*(ab|ba)))*$");
        Matcher testEO;

        try (Scanner read = new Scanner(in))
        {
            int lines = Integer.parseInt(read.nextLine());

            for(int i = 0; i <= lines; i++)
            {
                line = read.nextLine();
                testEO = patEO.matcher(line);
                System.out.println(testEO.find());
            }
        }
        catch (FileNotFoundException e)
        {
            System.out.println("An error occured.");
        }
    }
}
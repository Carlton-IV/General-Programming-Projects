import java.io.*;
import java.util.*;
import java.util.regex.*;

public class EvenOddMember
{

    public static void main(String[] args) throws IOException
    {
        File in = new File(args[0]);
        File out = new File(args[1]);

        String line = "";
        String output = "";

        String evenEven = "(aa|bb|((ab|ba)(aa|bb)*(ab|ba)))*";
        String evenOdd = evenEven + "(b|(ab(bb)*a))" + evenEven;
        Pattern patEO = Pattern.compile("^"+evenOdd+"$");
        Matcher testEO;

        try (Scanner read = new Scanner(in))
        {
            int lines = Integer.parseInt(read.nextLine());

            for(int i = 0; i < lines; i++)
            {
                if(read.hasNext())
                {
                    line = read.nextLine();
                    testEO = patEO.matcher(line);
                    output += testEO.find();
                    if(i < lines - 1) output += "\n";
                }
            }
            System.out.println(output);
        }
        catch (FileNotFoundException e)
        {
            System.out.println("Could not find input file.");
        }

        try
        {
            FileWriter write = new FileWriter(out);
            write.write(output);
            write.close();
        }
        catch (IOException e)
        {
            System.out.println("Could not write to file.");
        }
    }
}
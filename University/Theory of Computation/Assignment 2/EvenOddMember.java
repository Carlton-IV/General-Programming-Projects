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

        String evenEven = "(aa|bb|((ab|ba)(aa|bb)*(ab|ba)))*";
        String evenOdd = evenEven + "(b|(ab(bb)*a))" + evenEven;
        Pattern patEO = Pattern.compile(evenOdd);
        Matcher testEO;

        try (Scanner read = new Scanner(in))
        {
            int start, end, lines = Integer.parseInt(read.nextLine());

            FileWriter write = new FileWriter(out);

            for(int i = 0; i < lines; i++)
            {
                if(!read.hasNext()) break;
                start = 0;
                end = 0;
                line = read.nextLine();
                for(int j = 0; j < line.length(); j++)
                {
                    testEO = patEO.matcher(line.substring(j));
                    if(!testEO.find()) break;
                    if(end - start <= testEO.end() - testEO.start())
                    {
                        start = testEO.start() + j;
                        end = testEO.end() + j;
                    }
                }
                if(end == 0) write.write("NONE");
                else write.write(
                    line.substring(start,end) + " " + start + " " + end + " " + (end - start)
                );
                if(i < lines - 1) write.write("\n");
            }
            write.close();
        }
        catch (IOException e)
        {
            System.out.println("Could not find file.");
        }
    }
}
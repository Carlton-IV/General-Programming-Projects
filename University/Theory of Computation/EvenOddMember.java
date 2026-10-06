import java.io.*;
import java.util.regex.*;

public class EvenOddMember
{

    public static void main(String[] args) throws IOException
    {
        FileInputStream in = null;
        FileInputStream out = null;

        String line;

        String evenEven = "(aa|bb|((ab|ba)(aa|bb)*(ab|ba)))*";
        String evenOdd = evenEven + "(b|((a|ab|ba)b(bb)*(a|ab|ba)))" + evenEven;
        Pattern patEO = Pattern.compile("^"+evenOdd+"$");
        Matcher testEO;

        try
        {
            in = new FileInputStream(args[0]);
            out = new FileInputStream(args[1]);

            char ch = (char) in.read();
            int lines = ch;

            for (int i = 0; i <= lines; i++)
            {
                line = "";
                ch = (char) in.read();
                while (ch != '\n')
                {
                    line = line + ch;
                    ch = (char) in.read();
                }
                testEO = patEO.matcher(line);
                System.out.println(testEO.find());
            }
        }
        finally
        {
            if (in != null)
            {
                in.close();
            }
            if (out != null)
            {
                out.close();
            }
        }
    }
}
import java.util.Scanner;
public class RockPaperScisors 
{
    //A delay method for allowing staggered code
    static void delay(int ms)
    {
        try{
            // Wait for sec seconds 
            Thread.sleep(ms); 
        } 
        catch (InterruptedException e) { 
            e.printStackTrace(); 
        }
    }
    
    static void typePrint(String phrase) {
        for(int i = 0; i < phrase.length(); i++) 
        {
            System.out.print(phrase.charAt(i));
            delay(30);
        }
    }
    
    public static void main(String[] args) {
        //Scanner object
        Scanner user = new Scanner(System.in);
        
        //CPU Rock paper scissors options
        String[] cpuRockPaperScissors = new String[]{"rock", "paper", "scissors"};
        
        //Scores
        int uScore = 0;
        int cpuScore = 0;
        
        //Initiates user's choice variable
        String userRockPaperScissors;
        
        while(true) {
            //Stores CPU's choice
            String cpuRPS = cpuRockPaperScissors[(int)(Math.random() * 3)];
            
            //User input prompts
            typePrint("Ready?\n");
            //Delay between prints
            delay(1000); 
            typePrint("Rock!\n");
            delay(400);
            typePrint("Paper!\n");
            delay(400);
            typePrint("Scissors!\n");
            delay(400);
            typePrint("SHOOT!: ");
            
            //Awaits appropriate user input
            while (true){
                //Grabs user choice
                userRockPaperScissors = user.nextLine();
                //Converts user choice to all caps
                String uRPS = userRockPaperScissors.toUpperCase();
                
                //Converts short form into long form
                if (uRPS.equals("R")) {
                    uRPS = "ROCK";
                    userRockPaperScissors = "rock";
                }
                else if (uRPS.equals("P")) {
                    uRPS = "PAPER";
                    userRockPaperScissors = "paper";
                }
                else if (uRPS.equals("S")) {
                    uRPS = "SCISSORS";
                    userRockPaperScissors = "scissors";
                }
                
                //Verifies user input is valid
                if (uRPS.equals("ROCK") || uRPS.equals("PAPER") || uRPS.equals("SCISSORS")) {
                    //If valid, continue
                    break;
                }
                else {
                    //If invalid, ask for new input
                    typePrint("\nPlease choose rock, paper,\nor scissors: ");
                }
            }
            //Print out user and cpu choices
            typePrint("\nYou chose " + userRockPaperScissors.toLowerCase() + "!\n");
            delay(750);
            typePrint("I chose " + cpuRPS + "!\n\n");
            
            //Converts user choice to all caps
            String uRPS = userRockPaperScissors.toUpperCase();
            
            //Determines winner, loser, or draw
            delay(1000);
            if (uRPS.equals(cpuRPS.toUpperCase())) {
                //Allows random draw statement
                String[] draw = new String[]{"It's a draw!","We both win!","We lost.","Let's try that again!"};
                typePrint(draw[(int)(Math.random()*4)]+"\n\n");
            }
            else if ((uRPS.equals("ROCK") && cpuRPS.equals("paper")) || (uRPS.equals("PAPER") && cpuRPS.equals("scissors")) || (uRPS.equals("SCISSORS") && cpuRPS.equals("rock"))) {
                //Random loser statement
                String[] loser = new String[]{"HAHAHHAHAA YOU SUCK!","I WIN, LOOOOSSERRR!","You lost.","I win!","Suck on dem apples!","Oh well, try again!"};
                typePrint(loser[(int)(Math.random()*6)]+"\n\n");
                cpuScore ++;
            }
            else {
                //Random winner statement
                String[] win = new String[]{"You win!","Congrats, winner!","you win, i guess.","WE HAVE A WINNER!"};
                typePrint(win[(int)(Math.random()*4)]+"\n\n");
                uScore ++;
            }
            delay(1500);
            String playAgain;
            String pA;
            typePrint("Play again? ");
            while(true) {
                playAgain = user.nextLine();
                pA = playAgain.toLowerCase();
                //Failsafe to prevent an exception error
                if (pA.equals("")) {
                    typePrint("Please enter yes or no: ");
                }
                //Checks for valid input
                else if ((pA.charAt(0) == 'y') || (pA.charAt(0) == 'n')) {
                    break;
                }
                //Tells to redo if input is invalid
                else {
                    typePrint("Please enter yes or no: ");
                }
            }
            
            //Checks if user doesnt want to play again
            if (pA.charAt(0) == 'n') {
                break;
            }
            //If user doesnt say no, clear the screen and play again
            else {
                System.out.print("\033[H\033[2J");  
                System.out.flush();
            }
        }
        //If user does say no, print the final score
        typePrint("\nYour score is: " + uScore + "\nMy score is: " + cpuScore);
    }
    
}
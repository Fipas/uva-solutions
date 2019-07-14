// @JUDGE_ID:  1000AA  100  Java  "Easy algorithm"

import java.io.*;
import java.util.*;

class Main
{
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }

    public static void main (String args[])  // entry point from OS
    {
        int dayPred, day, month, year;
        String input = Main.ReadLn(255);
        StringTokenizer idata;
        
        idata = new StringTokenizer(input);
        dayPred = Integer.parseInt(idata.nextToken());
        day = Integer.parseInt(idata.nextToken());
        month = Integer.parseInt(idata.nextToken());
        year = Integer.parseInt(idata.nextToken());
        
        while (dayPred != 0 || day != 0 || month != 0 || year != 0) {
            Calendar c = new GregorianCalendar(year, month - 1, day);
            c.add(Calendar.DAY_OF_MONTH, dayPred);
            System.out.println(c.get(Calendar.DAY_OF_MONTH) + " " +
                              (c.get(Calendar.MONTH) + 1) + " " + 
                               c.get(Calendar.YEAR));
            
            input = Main.ReadLn(255);

            idata = new StringTokenizer(input);
            dayPred = Integer.parseInt(idata.nextToken());
            day = Integer.parseInt(idata.nextToken());
            month = Integer.parseInt(idata.nextToken());
            year = Integer.parseInt(idata.nextToken());
        }
        
        
    }
}
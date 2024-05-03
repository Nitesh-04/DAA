import java.util.*;

public class lcs
{
    public static int LCS(char[] str1, char[] str2,int a , int b)
    {
        if(a==0 || b == 0)
        {
            return 0;
        }
        if(str1[a-1] == str2[b-1])
        {
            return 1 + LCS(str1,str2,a-1,b-1);

        }
        else{
            return Math.max(LCS(str1,str2,a,b-1),LCS(str1,str2,a-1,b));
        }
        
    }

    public static void main(String[] args) 
    {
        Scanner inp = new Scanner(System.in);

        String s1 = inp.nextLine();
        String s2 = inp.nextLine();

        char[] str1 = s1.toCharArray();
        char[] str2 = s2.toCharArray();

        int a = str1.length;
        int b = str2.length;

        boolean isthere = a == LCS(str1, str2, a, b);

        if(isthere)
        {
            System.out.println("YES");
        }
        else{
            System.out.println("NO");
        }

    }
}
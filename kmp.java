import java.util.*;

public class kmp
{
    public static String kmp(char[] T, char[] P)
    {
        int n= T.length;
        int m =P.length;
        int[] PI  = comp_prefix(String.valueOf(P));
        int q=0;
        String location ="";
        for(int i=0;i<n;i++)
        {
            while(q>0 && P[q] != T[i])
            {
                q=PI[q-1];
            }
            if(P[q]==T[i])
            {
                q++;
            }
            if(q==m)
            {
                location += (int)i-m+1 + ",";
                q=PI[q-1];
            }
        }
        
        return location.isEmpty() ? "-1," : location;
    }
    
    public static int[] comp_prefix(String pat)
    {
        int m = pat.length();
        int[] PI = new int[m];
        PI [0] = 0;
        int k=0;
        for(int q=1;q<m;q++)
        {
            while(k>0 && pat.charAt(q) != pat.charAt(k))
            {
                k = PI[k-1];
            }
            
            if(pat.charAt(k) == pat.charAt(q))
            {
                k++;
            }
            PI[q]=k;
        }
        
        return PI;
    }
    
    public static void main(String[] args)
    {
        Scanner inp = new Scanner(System.in);
        String t=inp.next();
        String p=inp.next();
        System.out.println(kmp(t.toCharArray(),p.toCharArray()).substring(0,kmp(t.toCharArray(),p.toCharArray()).length()-1));
    }
}
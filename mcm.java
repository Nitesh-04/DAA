import java.util.*;

public class mcm {
    public static void main(String[] args) 
    {   
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        int p[] = new int[n];
        for(int i=0;i<n;i++)
        {
            p[i] = inp.nextInt();
        }
        System.out.println(matrix(p,1,n-1));
    }

    public static int matrix(int p[],int i,int j)
    {
        if(i==j)
        {
            return 0;
        }
        
        int min = Integer.MAX_VALUE;
        for(int k=i;k<j;k++)
        {    
            int count = matrix(p,i,k)+matrix(p,k+1,j)+p[i-1]*p[k]*p[j];
            if(count <min)
            {
                min = count;
            }
        }

        return min;
    }
}

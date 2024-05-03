import java.util.*;

public class fra_knap
{
    public static void swap(int[] arr, int x, int y)
    {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
    public static void swap(double[] arr, int x, int y)
    {
        double temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }
    public static void main(String[] args)
    {
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        int[] wt = new int[n];
        for(int i =0; i<n; i++)
            wt[i] = inp.nextInt();
        int[] p = new int[n];
        for(int i = 0; i<n; i++)
            p[i] = inp.nextInt();
        int W = inp.nextInt();
        
        
        double y[] = new double[n];
        
        for(int i = 0; i<n; i++)
            y[i] = (double)p[i]/wt[i];
        
        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n;j++)
            {
                if(y[i]<y[j])
                {
                    swap(y, i, j);
                    swap(wt, i, j);
                    swap(p, i, j);
                }
            }
        }

        double[] x = new double[n];
        Arrays.fill(x,0);
        int weight=0;

        for(int i=0;i<n;i++)
        {
            if(weight + wt[i] <= W)
            {
                x[i]=1;
                weight+=wt[i];
            }
            else
            {
                x[i] = (double)(W-weight)/wt[i];
                weight=W;
                break;
            }
        }

        double profit=0;

        for(int i=0;i<n;i++)
        {
            profit += p[i]*x[i];
        }
        
        System.out.println((double)Math.round(profit*100)/100);

    }
}
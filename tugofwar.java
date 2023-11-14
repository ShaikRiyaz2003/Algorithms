import java.util.*;
class tugofwar
{
    public static void main(String []args)
    {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t!=0)
        {
            int n=sc.nextInt();
            ArrayList<Integer> a=new ArrayList<>();
            //int a[]=new int[n];
            for(int i=0;i<n;i++)
            {
                a.add(sc.nextInt());
            }
            Collections.sort(a);
            int left=0;
            int right=0;
            for(int i=n-1;i>=0;i--)
            {
                if(left>=right)
                {
                    right+=a.get(i);
                }
                else
                    left+=a.get(i);
            }
            if(left>=right)
                System.out.println(right+" "+left);
            else
            System.out.println(left+" "+right);
            t--;
        }
        sc.close();
    }
}
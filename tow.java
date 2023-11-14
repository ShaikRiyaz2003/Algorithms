import java.util.*;
// import java.io.*;
public class tow{
    static int mindiff =Integer.MAX_VALUE;
    static String ans="";
    public static void solve(int[] arr,int vidx,ArrayList<Integer>set1,ArrayList<Integer>set2,int soset1,int soset2){
        if(vidx==arr.length){
            int temp=Math.abs(soset1-soset2);
            if(temp<mindiff){
                mindiff=temp;
                ans=set1+" "+set2;
            }
        }
        if(set1.size()<=(arr.length+1)/2){
            set1.add(arr[vidx]);
            solve(arr,vidx+1,set1,set2,soset1+arr[vidx],soset2);
            set1.remove(arr[vidx]);
        }
        if(set2.size()<=(arr.length+1)/2){
            set2.add(arr[vidx]);
            solve(arr,vidx+1,set1,set2,soset1,soset2+arr[vidx]);
            set2.remove(arr[vidx]);
        }
    }

        public static void main(String[] args){
        Scanner sc =new Scanner(System.in);
        int[] arr = new int[sc.nextInt()];
        for(int i=0;i<arr.length;i++)
            arr[i]=sc.nextInt();
            solve(arr,0,new ArrayList<>(),new ArrayList<>(),0,0);
            System.out.println(ans);
            sc.close();
    }


}
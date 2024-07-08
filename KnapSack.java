import java.util.ArrayList;
import java.util.Scanner;

public class KnapSack {
    static int max(int a, int b){
        return a > b ? a : b;
    }
    
    static int knapsack(int m, int n, int profit[], int wt[], int V[][]){
        int i, j;
        for(i = 0; i <= n; i++){
            for(j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    V[i][j] = 0;
                } else if(j < wt[i - 1]){
                    V[i][j] = V[i - 1][j];
                } else {
                    V[i][j] = max(V[i - 1][j], profit[i - 1] + V[i - 1][j - wt[i - 1]]);
                }
            }
        }
        return V[n][m];
    }
    
    static ArrayList<Integer> composition(int n, int m, int V[][], int wt[]){
        ArrayList<Integer> items = new ArrayList<>();
        int j = m;
        for(int i = n; i > 0; i--){
            if(V[i][j] > V[i - 1][j]){
                items.add(i);
                j -= wt[i - 1];
            }
        }
        return items;
    }
    
    static void printComposition(ArrayList<Integer> items){
        System.out.println("Items included in the knapsack:");
        for(int item : items){
            System.out.print(item + " ");
        }
        System.out.println();
    }
    
    static void print(int m, int n, int V[][]){
        System.out.println("0/1 knapsack problem using (bottom up) dynamic programming approach:");
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                System.out.print(V[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        System.out.println("Enter the capacity of knapsack:");
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        
        System.out.println("Enter the number of items:");
        int n = sc.nextInt();
        
        System.out.println("Enter the weight and values (profit) of items:");
        int profit[] = new int[n];
        int wt[] = new int[n];
        
        for(int i = 0; i < n; i++){
            System.out.println("Weight and Values of item " + (i + 1) + ":");
            wt[i] = sc.nextInt();
            profit[i] = sc.nextInt();
        }
        
        int V[][] = new int[n + 1][m + 1];
        
        int maxProfit = knapsack(m, n, profit, wt, V);
        System.out.println("Maximum profit: " + maxProfit);
        
        print(m, n, V);
        
        ArrayList<Integer> items = composition(n, m, V, wt);
        printComposition(items);
    }
}

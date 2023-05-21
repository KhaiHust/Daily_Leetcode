package Daily_Leetcode;

import java.util.*;
import java.math.*;

public class Triangle {
    public static int minimumTotal(List<List<Integer>> a) {
        int n = a.size();
        System.out.println(n);
        int res[][] = new int[n][a.get(n - 1).size()];
        res[0][0] = a.get(0).get(0);
        for (int i = 1; i < n; i++) {
            res[i][0] = a.get(i).get(0) + res[i - 1][0];
            int m = a.get(i).size();
            for (int j = 1; j < m; j++) {
                res[i][j] = j < m - 1 ? Math.min(res[i - 1][j - 1] + a.get(i).get(j), res[i - 1][j] + a.get(i).get(j))
                        : res[i - 1][j - 1] + a.get(i).get(j);
                System.out.printf("%d ", res[i][j]);
            }
            System.out.println();
        }
        int m = a.get(n - 1).size();
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < m; i++) {

            ans = Math.min(ans, res[n - 1][i]);
        }
        return ans;
    }

    public static void main(String[] args) {
        // List<List<Integer>> a = [[2],[3,4],[6,5,7],[4,1,8,3]];
    }
}

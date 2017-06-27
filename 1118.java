import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] bird = new int[10001];
        for (int i = 0; i < bird.length; i++) {
            bird[i] = i;
        }
        Set<Integer> set = new HashSet<Integer>();
        Set<Integer> tree = new HashSet<Integer>();
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();
            int first = scanner.nextInt();
            set.add(first);
            for (int j = 1; j < k; j++) {
                int temp = scanner.nextInt();
                union(bird, first, temp);
                set.add(temp);
            }
        }
        for (Integer integer : set) {
            int root = findfather(bird, integer);
            tree.add(root);
        }
        System.out.println(tree.size() + " " + set.size());
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            if (findfather(bird, scanner.nextInt()) != findfather(bird, scanner.nextInt())) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
            }
        }
    }

    public static void union(int[] bird, int m, int n) {
        int prem = findfather(bird, m);
        int pren = findfather(bird, n);
        if (prem != pren) {
            bird[prem] = pren;
        }
    }
    public static int findfather(int[] bird, int n) {
        int pre = bird[n];
        while (pre != bird[pre]) {
            pre = bird[pre];
        }
        while (n != pre) {
            int tmp = bird[n];
            bird[n] = pre;
            n = tmp;
        }
        return n;
    }
}

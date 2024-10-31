import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers) {
        ArrayList<Integer> answer = new ArrayList<Integer>();
        for(int i=0; i<numbers.length; i++){
            for(int j=i+1; j<numbers.length; j++){
                answer.add(numbers[i]+numbers[j]);
            }
        }
        int[] arr = new int[answer.size()];
        for(int i=0; i<answer.size(); i++){
            arr[i] = answer.get(i);
        }
        Arrays.sort(arr);
        arr = Arrays.stream(arr).distinct().toArray();
        return arr;
    }
}
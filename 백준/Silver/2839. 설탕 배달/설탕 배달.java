import java.io.*;
import java.util.Scanner;
class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int input = in.nextInt();
		int answer = 0;
		while(input>0){
			if(input%5 == 0){
				answer += input/5;
				System.out.println(answer);
				return;
			}
			if(input<3){
				System.out.println(-1);
				return;
			}
			input -= 3;
			answer ++;
		}
			System.out.println(answer);
//		return answer;
	}
}
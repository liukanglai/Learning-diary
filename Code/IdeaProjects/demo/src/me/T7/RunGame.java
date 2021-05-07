import java.math.*;

public class RunGame extends Thread{
	
		 String player1 = "甲同学";
		 String player2 = "乙同学";
		 String player3 = "同丙学";
	int length1 = 0, length2 = 0, length3 = 0;
	int who = 0;
	public RunGame(int who){
		this.who = who;
	}
	public void run(){
		if(who == 1){
		 //for(int i = 0; length1 < 1000 && length2 < 1000 && length3 < 1000 ;i++) {
		 length1 += (int)(Math.random()*21);
			System.out.println("1run, the length1 is: "+length1);
		 //}
		}
		if(who == 2){
		 //for(int i = 0; length1 < 1000 && length2 < 1000 && length3 < 1000 ;i++) {
		 length2 += (int)(Math.random()*18);
			System.out.println("2run, the length2 is: "+length2);
		 //}
		}
		if(who == 3){
		// for(int i = 0; length1 < 1000 && length2 < 1000 && length3 < 1000 ;i++) {
		 length3 += (int)(Math.random()*16);
			System.out.println("3run, the length3 is: "+length3);
		//	}
		}
	}

	public static void main(String[] args) {
		 
		 RunGame run1 = new RunGame(1);
		 RunGame run2 = new RunGame(2);
		 RunGame run3 = new RunGame(3);

		while(run1.length1 < 1000 && run1.length2 < 1000 && run1.length3 < 1000) {
			 run1.run();
			 run2.run();
			 run3.run();
		}

	}

}

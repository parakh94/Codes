public class threadsInJava extends Thread{
 
  private long totalsum = 0;

  
  public long gettotalsum(){
    return totalsum;
  }

  public void run(){
    totalsum = add(20);
  }

  private long add(int n){
    return n*(n+1)/2;
  }



	  public static void main(String[] args){
	  
	    threadsInJava tsum = new threadsInJava();

	    tsum.start();

	  
	    try{
	      tsum.join();
	    }catch(InterruptedException ie){}

	
	    long totalsum = tsum.gettotalsum();

	    System.out.println("The totalsum = " + totalsum);
	  }
	}

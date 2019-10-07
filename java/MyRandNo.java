public class MyRandNo{
    public static void main(String ... args){
        for(int i=0; i<10; i++) {                         
            int random = (int)(Math.random()*20+1);  
            //double random = Math.random() *50+1;
            System.out.print(random + " ");
        }
    }
}

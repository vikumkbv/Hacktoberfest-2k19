// in this question queen are placed in level and boxes are choice for queen
class nqueen{
public static boolean isQueensafe(boolean[][] chess,int r,int c){
   for(int j=c-1;j>=0;j--){
     if(chess[r][j]==true){
       return false;
     }
   }
    for(int i=r-1;i>=0;i--){
     if(chess[i][c]==true){
       return false;
     }
   }
  for(int i=r-1,j=c-1 ;i>=0 && j>=0; i-- ,j--){
    
     if(chess[i][j]==true){
       return false;
     }
  
  }

   for(int i=r-1 ,j=c+1;i>=0 && j<chess[0].length ; i-- ,j++){
     
     if(chess[i][j]==true){
       return false;
     }
 
   }


   return true;

}
// for combination with no kill queen
  public static int count=0; 
  public static void path(boolean[][] chess,int cq,int lqi,int lqj,String asf){

      if(cq==chess.length){
        System.out.println(asf);
        return;
      }
      
      for(int i=lqi;i<chess.length;i++){
        /*int j=lqj+1;
        if(i>lqi){
          j=0;
        }*/
        for(int j=(i==lqi?lqj+1:0) ;j<chess[0].length;j++){
        if(chess[i][j]==false && isQueensafe(chess,i,j)==true){
          chess[i][j]=true;
          path(chess,cq+1,i,j,asf+i+j+"-");
          chess[i][j]=false;  
         }
      }

      }
    }




//only for permutation of 16 boxes for 4 queen = total permuuataion is 43680
public static void pathpermu(boolean[][] chess ,int cq,String asf){
   if(cq>chess.length){
      System.out.println(++count+"-"+asf);
      return;
   }
   for(int i=0;i<chess.length;i++){
     for(int j=0;j<chess.length;j++){
       if(chess[i][j]==false){
         chess[i][j]=true;
         pathpermu(chess,cq+1,asf+i+j+"-");
         chess[i][j]=false;
       }
     }
   }
   
}
//only for combination of 16 boxes for 4 queen = total combination is 1820
public static void pathcombi(boolean[][] chess ,int cq,int lqi,int lqj,String asf){
   if(cq==chess.length){
      System.out.println(++count+"-"+asf);
      return;
   }
   for(int i=lqi;i<chess.length;i++){
    
      int j=lqj+1;
        if(i>lqi){
          j=0;
        }
     for(;j<chess.length;j++){
       if(chess[i][j]==false){
         chess[i][j]=true;
         pathcombi(chess,cq+1,i,j,asf+i+j+"-");
         chess[i][j]=false;
       }
     }
   }
   
   }
public static void main(String[] args){
        boolean[][] chess=new boolean[4][4];
       
        path(chess,0,0,-1,"");//parameters chess array,current queen,initial index for row,initial index for col. -1 because int function +1 usefor j
        //pathpermu(chess,1,"");
        //pathcombi(chess,0,0,-1,"");
       
    }
}
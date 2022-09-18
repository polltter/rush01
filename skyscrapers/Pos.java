package skyscrapers;

public class Pos{

  final int x, y;

  public Pos(int x,int y){
    this.x=x;
    this.y=y;
  }

  public boolean equals(Object o){
    if (o instanceof Pos){
      Pos obj = (Pos) o;
      return (x==obj.x)&&(y==obj.y);
    }
    return false;
  }

  public int hashCode(){
    return (((x+y)*(x+y+1))/2)+x;
  }

  public String toString(){
    return "("+x+","+y+")";
  }

  // Constructor with
  //  n: size of matrix
  //  p: a reference cell
  //  j: on the same line or column as that of p, position of square counting from one of its two ends 
  //  b: whether we are covering p's line (b=true) or p's column (b=false) 

  Pos(int n, Pos p, int j, boolean b){
    this(n,p,j,b,true);
  }

  // Constructor with
  //  n: size of matrix
  //  p: a reference cell
  //  j: on the same line or column as that of p, position of square counting from one of its two ends 
  //  b: whether we are covering p's line (b=true) or p's column (b=false) 
  //  side: whether j concerns the jth square counting from North/West (side=true) or from South/East (side=false) 

  Pos(int n, Pos p, int j, boolean b, boolean side){
    if (b){
      if (side){
        this.x=p.x;
        this.y=j;
      }
      else{
        this.x=p.x;
        this.y=n-j-1;
      }
    }
    else{
      if (side){
        this.x=j;
        this.y=p.y;
      }
      else{
        this.x=n-j-1;
        this.y=p.y;
      }
    }
  }

}

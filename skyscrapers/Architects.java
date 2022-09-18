package skyscrapers;

import java.util.Queue;
import java.util.LinkedList;

public class Architects{

  int[][] constraints;

  public Architects(int n, String[] cons){
    constraints = new int[4][n];
    int j=0;
    for(int d=0;d<4;d++){
      for(int i=0;i<n;i++){
        constraints[d][i]=Integer.parseInt(cons[j]);
        j++;
      }
    }
  }

  public Architects(Architects archi){
    this.constraints = archi.constraints;
  }

  int size(){return constraints[0].length;}

  int[] north(){ return constraints[0];}
  int[] south(){ return constraints[1];}
  int[] west() { return constraints[2];}
  int[] east() { return constraints[3];}

  // Checks whether a state (assumed to be entirely determined) satisfies the constraints
  public boolean checkState(State cs){
    for (int i=0;i<size();i++){
      for (int j=0;j<size();j++)
        if (!cs.isDefined(new Pos(i,j))||!cs.isDefined(new Pos(j,i))) return false;
      if (!viable(cs,new Pos(i,i))) return false;
    }
    return true;
  }
	
  boolean viable(State cs,Pos p){
    return viable(cs,p,new LinkedList<Action>());
  }

  boolean viable(State cs,Pos p,Queue<Action> todo){
    // Checking p's line
    if (!viable(cs,p,true,todo)) return false;
    // Checking p's column
    if (!viable(cs,p,false,todo)) return false;
    // Seems ok
    return true;
  }
	
  boolean viable(State cs,Pos p,boolean b,Queue<Action> todo){
    if (!isPermutation(cs,p,b,todo)) return false;
    int side1, side2;
    if (b) { 
      side1 = west()[p.x];
      side2 = east()[p.x];
    }
    else {
      side1 = north()[p.y];
      side2 = south()[p.y];
    }
    if (!visible(side1,cs,p,b,true,todo)) return false;
    if (!visible(side2,cs,p,b,false,todo)) return false;
    return true;
  }

  // Computes whether p's line or p's column could be completed into a permutation of 1-n
  // b=true: line, b=false: column
  boolean isPermutation(State cs, Pos p, boolean b,Queue<Action> todo){
    int n = size();
    boolean[] aux = new boolean[n];
    int a = 0;
    for (int j=0;j<n;j++){
      Pos q = new Pos(n,p,j,b);
      if (cs.isDefined(q)){
        a = cs.get(q);
        assert( a>0 && a<=n );
        if (aux[a-1]) return false;
        else aux[a-1]=true;
      }
    }
    return true;
  }

  // Computes whether p's line or p's column could be completed so that the number of visible buildings matches the expected number 
  // b=true: line, b=false: column
  // side=true: looking from North/West, b=false: looking from South/East
  boolean visible(int expected,State cs, Pos p, boolean b, boolean side,Queue<Action> todo){
    int n = size();
    int max1   = 0;
    int max2   = 0;
    int result1 = 0;
    int result2 = 0;
    int a = 0;
    for (int j=0;j<n;j++){
      Pos q = new Pos(n,p,j,b,side);
      if (cs.isDefined(q)){
        a = cs.get(q);
        if (a>max1) {max1=a;result1++;}
        if (a>max2) {max2=a;result2++;}
      }
      else{
        a=cs.getPossibilities(q).maxElement();
        if (a>max1) {max1=n;result1++;}
        if (a>max2) {max2++;result2++;}
      }
    }
    return (result1<=expected)&&(expected<=result2);
  }

  public String toString(State cs){
    int n=size();
    StringBuilder sb = new StringBuilder(" |");
    for(int i=0;i<n;i++){
      sb.append(" "+constraints[0][i]);
    }
    sb.append(" |\n-+");
    for(int i=0;i<2*n+1;i++){
      sb.append("-");
    }
    sb.append("+-");
    for(int i=0;i<n;i++){
      sb.append("\n"+constraints[2][i]+"|");
      for(int j=0;j<n;j++){
        Pos p = new Pos(i,j);
        if (cs.isDefined(p))
          sb.append(" "+cs.get(p));
        else
          sb.append("  ");					
      }
      sb.append(" |"+constraints[3][i]);
    }
    sb.append("\n-+");
    for(int i=0;i<2*n+1;i++){
      sb.append("-");
    }
    sb.append("+-\n |");
    for(int i=0;i<n;i++){
      sb.append(" "+constraints[1][i]);
    }
    sb.append(" |");
    return sb.toString();
  }

  public String toString(){
    return toString(new State(size()));
  }

}

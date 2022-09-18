package skyscrapers;

import java.util.Queue;

public class SmartArchitects extends Architects{
	
  public SmartArchitects(Architects archi){
    super(archi);
  }

  // Computes whether p's line or p's column could be completed into a permutation of 1-n
  // b=true: line, b=false: column
  boolean isPermutation(State cs, Pos p, boolean b,Queue<Action> todo){

    if (!super.isPermutation(cs,p,b,todo)) return false;

    //To be completed in Ex5

    return true;
  }

}
package skyscrapers;

public class State{

  private int[][] terrain;
  final int size;
  public int decisionNodes;

  // Basic search for undefined position, in O(n^2)
  Pos selectUndefinedPos(){
    decisionNodes++;
    for (int i=0;i<size;i++){
      for (int j=0;j<size;j++){
        Pos p = new Pos(i,j);
        if (!isDefined(p)) return p;
      }
    }
    return null;
  }

  // Private set of all numbers between 1 and size
  private ISet allPossibilities;

  public State(int n){
    size = n;
    // Initialises the set of all possible heights.
    allPossibilities = new ISet ();
    for(int h = 1; h <= n; h++)
      allPossibilities = allPossibilities.add(h);
    terrain = new int[n][n];
  }

  public boolean isDefined(Pos p){
    return terrain[p.x][p.y] != 0;
  }

  public int get(Pos p){
    if (isDefined(p)) return terrain[p.x][p.y];
    else throw new DecisionException("Undecided square "+p);
  }

  public void set(Pos p, int h){
    if (!isDefined(p)) terrain[p.x][p.y]=h;
    else throw new DecisionException("Wanting to set square "+p+" to "+h+" but already set to "+terrain[p.x][p.y]);
  }

  public void unset(Pos p){
    if (isDefined(p)) terrain[p.x][p.y]=0;
    else throw new DecisionException("Wanting to unset square "+p+" but it was not set");
  }

  ISet getPossibilities(Pos pos){
    return allPossibilities;
  }

  Action createSetAction(Pos p,int h){
    return null;
  }

  Action createForbidAction(Pos p,int h){
    return null;
  }
}
package skyscrapers;

public class SmartState extends State {

  private	ISet[][] terrain;

  SmartState(int n){
    super(n);
    // Initialize each element of the array
    // terrain with (a copy of) the set of all possibilities.
    terrain = new ISet[n][n];
    Pos p = new Pos(0,0);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        terrain[i][j] = super.getPossibilities(p);
  }

  //@override
  public boolean isDefined(Pos p){
    return terrain[p.x][p.y].isSingleton();
  }

  //@override
  public int get(Pos p){
    if (!isDefined(p))
      throw new DecisionException("Undecided square "+p);
    return terrain[p.x][p.y].minElement();
		
  }

  //@override
  ISet getPossibilities(Pos p){
    return terrain[p.x][p.y];
  }

  void setPossibilities(Pos p,ISet possib){
    terrain[p.x][p.y] = possib;
  }

  Action createSetAction(Pos p,int h){
    return new ToSet(this,p,h);
  }

  Action createForbidAction(Pos p,int h){
    return new ToForbid(this,p,h);
  }

}
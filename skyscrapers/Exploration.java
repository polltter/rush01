package skyscrapers;

public abstract class Exploration{
  final Architects archi;

  public abstract State getState();
  public abstract boolean search();

  public Exploration(Architects archi){
    this.archi = archi;
  }

  int size(){return archi.size();}
  public String toString(){return archi.toString(getState());}

}
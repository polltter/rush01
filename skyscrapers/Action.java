package skyscrapers;

abstract class Action{

  final SmartState cs;
  final Pos p;
  final int h;
  ISet backup=null;

  abstract boolean perform();

  void undo(){
    if (backup!=null) cs.setPossibilities(p,backup);
  }

  Pos needsChecking(){
    if (backup!=null) return p;
    else return null;
  }

  Action(SmartState cs,Pos p,int h){
    this.cs = cs;
    this.p = p;
    this.h = h;
  }

}

class ToSet extends Action{

  ToSet(SmartState cs,Pos p,int h){
    super(cs,p,h);
  }

  boolean perform(){
    //To be completed in Ex4
    return true;
  }

}

class ToForbid extends Action{

  ToForbid(SmartState cs,Pos p,int h){
    super(cs,p,h);
  }

  boolean perform(){
    //To be completed in Ex5
    return true;
  }

}
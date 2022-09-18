import java.io.BufferedReader;
import java.io.LineNumberReader;
import java.io.FileReader;
import java.io.IOException;
import skyscrapers.*;


class Test{

  static String path = "examples";
    //static String path = "/users/profs/info/stephane.lengrand/TD11";

  static Architects[][] instances;

  public static void main(String[] args){
    init(args);
    test0();
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
  }

  static void test0(){
    // testing data structure State (To Do) 
    State state = new State(2);
    for(int i=0;i<2;i++)
      for(int j=0;j<2;j++){
        Pos p = new Pos(i,j);
        if (state.isDefined(p)) throw new RuntimeException("Position "+p+" should not be defined");
      }
    Pos q =new Pos(1,1);
    try{
      state.get(q);
      throw new RuntimeException("get should raise DecisionException if position is not defined");
    }
    catch(RuntimeException e){}
    state.set(q,2);
    for(int i=0;i<2;i++)
      for(int j=0;j<2;j++){
        Pos p = new Pos(i,j);
        if (state.isDefined(p)&&!p.equals(q)) throw new RuntimeException("Position "+p+" should not be defined");
        if (!state.isDefined(p)&&p.equals(q)) throw new RuntimeException("Position "+p+" should be defined after set");
      }
    if (state.get(q)!=2) 
      throw new RuntimeException("Value of "+q+" should be 2 after set");
    try{
      state.set(q,1);
      throw new RuntimeException("set should raise DecisionException if position is defined");
    }
    catch(RuntimeException e){}
    try{
      state.unset(new Pos(0,0));
      throw new RuntimeException("unset should raise DecisionException if position is not defined");
    }
    catch(RuntimeException e){}
    state.unset(q);
    for(int i=0;i<2;i++)
      for(int j=0;j<2;j++){
        Pos p = new Pos(i,j);
        if (state.isDefined(p)) throw new RuntimeException("Position "+p+" should not be defined");
      }
    System.out.println("test0 seems ok");
  }

  static void test(Architects archi,Exploration ex){
    long start = System.currentTimeMillis();
    boolean b = ex.search();
    float time  = ((float)(System.currentTimeMillis()-start))/1000;
    if (b){
      State state = ex.getState();
      if (archi.checkState(state))
        System.out.println("You have found a correct solution in "+time+" seconds, with "+state.decisionNodes+" decision nodes:\n"+ex.toString());
      else
        System.out.println("Your \"solution\" is incorrect:\n"+ex.toString());
    }
    else
      System.out.println("No solution found for "+archi+", but there is one!!!");
  }

  static void test1(){
    for (int i=0;i<instances.length;i++)
      for (int j=0;j<instances[i].length;j++){
        System.out.println("N="+(i+3)+", instance "+(j+1)+":");
	test(instances[i][j],new Naive(instances[i][j]));
    }
  }

  static void test2(){
    for (int i=0;i<instances.length;i++)
      for (int j=0;j<instances[i].length;j++){
        System.out.println("N="+(i+3)+", instance "+(j+1)+":");
	test(instances[i][j],new EarlyChecks(instances[i][j]));
    }
  }

  static void test3(){
    for (int i=0;i<instances.length;i++)
      for (int j=0;j<instances[i].length;j++){
        System.out.println("N="+(i+3)+", instance "+(j+1)+":");
	test(instances[i][j],new SmartEarlyChecks(instances[i][j]));
    }
  }

  static void test4(){
    for (int i=0;i<instances.length;i++)
      for (int j=0;j<instances[i].length;j++){
        System.out.println("N="+(i+3)+", instance "+(j+1)+":");
	test(instances[i][j],new Propagation(instances[i][j]));
      }
  }

  static void test5(){
    for (int i=0;i<instances.length;i++)
      for (int j=0;j<instances[i].length;j++){
        System.out.println("N="+(i+3)+", instance "+(j+1)+":");
	Architects smartarchi = new SmartArchitects(instances[i][j]);
	test(instances[i][j],new Propagation(smartarchi));
    }
  }

  static void init(String[] files){
    //		instances = new Architects[files.length];
    instances = new Architects[7][];
    for (int i=0;i<instances.length;i++){
      try {
        String file = path+"/sky"+(i+3);
        // FileReader fr = new FileReader(files[i]);
        LineNumberReader  lnr = new LineNumberReader(new FileReader(file));
        lnr.skip(Long.MAX_VALUE);
        instances[i] = new Architects[lnr.getLineNumber()];
        BufferedReader reader = new BufferedReader(new FileReader(file));
        String line = reader.readLine();
        for(int j=0;line != null;j++){
          String[] s1 = line.split(":");
          int size = Integer.parseInt(s1[0]);
          s1 = s1[1].split(",");
          s1 = s1[0].split("/");
          instances[i][j] = new Architects(size,s1);
          line = reader.readLine();
        }
      }
      catch(IOException e){
        System.out.println("Warning: IOException while reading file. "+e);
      }
    }
  }

}
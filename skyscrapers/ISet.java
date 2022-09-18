package skyscrapers;

import java.util.Iterator;

/*
 * Persistent sets of small integers (between 0 and 31)
 * @author Jean-Christophe Filliatre
 */

public class ISet implements Iterable<Integer> {

  private final int bits;

  ISet() {
    this.bits = 0;
  }

  private ISet(int bits) {
    this.bits = bits;
  }

  public boolean isEmpty() {
    return this.bits == 0;
  }

  public boolean isSingleton() {
    return (this.bits != 0) && (this.bits == (this.bits & -this.bits));
  }

  public ISet add(int x) {
    if (x < 0 || x >= 32)
      throw new IllegalArgumentException("add");
    return new ISet(this.bits | 1 << x);
  }

  public boolean contains(int x) {
    if (x < 0 || x >= 32)
      throw new IllegalArgumentException("contains");
    return (this.bits & (1 << x)) != 0;
  }

  public ISet remove(int x) {
    if (x < 0 || x >= 32)
      throw new IllegalArgumentException("remove");
    return new ISet(this.bits & ~(1 << x));
  }

  // assumes b=2^i and returns i
  // naive implementation
  // private int bit(int b) {
  // for (int i = 0; i < 32; i++)
  // if (b == 1<<i) return i;
  // throw new IllegalArgumentException("bit");
  // }

  // better implementation, using Martin's constant
  static int hash32(int x) {
    return (int) ((0x03f79d71b4ca8b09L * (long) x) >> 58) & 0x3f;
  }

  static int[] ntz32 = new int[64];
  static {
    for (int i = 0; i <= 31; i++) {
      ntz32[hash32(1 << i)] = i;
    }
  }

  // assumes b=2^i and returns i
  private static int bit(int b) {
    if (b == 0 || b != (b & -b))
      throw new IllegalArgumentException("bit");
    return ntz32[hash32(b)];
  }

  private int size() {
    int s = 0;
    for (int x = this.bits; x != 0; s++)
      x -= (x & -x);
    return s;
  }

  // returns the smallest element
  public int minElement() {
    if (this.bits == 0)
      throw new IllegalArgumentException("minElement");
    return bit(this.bits & -this.bits);
  }

  // to get the greatest element, we need to get the highest bit
  private static int highestBitNaive(int x) {
    for (int i = 7; i >= 0; i--)
      if ((x & (1 << i)) != 0)
        return 1 << i;
    throw new IllegalArgumentException("highestBitNaive");
  }

  // and we tabulate it
  static int[] highestBit = new int[256];
  static {
    for (int x = 1; x < 256; x++)
      highestBit[x] = highestBitNaive(x);
  }

  private static int highestBit(int x) {
    int b = x >> 24;
    if (b != 0) return highestBit[b] << 24;
    b = x >> 16;
    if (b != 0) return highestBit[b] << 16;
    b = x >> 8;
    if (b != 0) return highestBit[b] << 8;
    return highestBit[x];
  }
	
  // returns the greatest element
  public int maxElement() {
    if (this.bits == 0)
      throw new IllegalArgumentException("maxElement");
    return bit(highestBit(this.bits));
  }

  public String toString() {
    String s = "[";
    for (int x = this.bits; x != 0;) {
      int b = x & -x;
      s += "" + bit(b);
      x -= b;
      if (x != 0)
        s += ", ";
    }
    return s + "]";
  }

  private class Iter implements Iterator<Integer> {

    private int state;

    Iter() {
      this.state = ISet.this.bits;
    }

      public boolean hasNext() {
      return this.state != 0;
    }

      public Integer next() {
      int b = this.state & -this.state;
      this.state -= b;
      return bit(b);
    }

      public void remove() {
      throw new Error("not implemented");
    }
  }

  public Iterator<Integer> iterator() {
    return new Iter();
  }

}

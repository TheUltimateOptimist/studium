package javashooter.gameutils ;
import java.util.* ;

class ValueWrapper {
  private Object value ;
  private Object def ;
  public ValueWrapper(Object init) {
    this.value = init ;
    this.def = init ;
  }
  public Object get() { return this.value; }
  public Object getDefault() { return this.def; }
  public void set(Object v) { this.value = v; }
  public void reset() {
	  this.value = this.def ;
  }
}



public class Flag<T> {
  private static HashMap<String, ValueWrapper > flags = new HashMap<String, ValueWrapper > () ;
  //private static HashMap<String, ValueWrapper<T> > flags = new HashMap<String, ValueWrapper<T> > () ;
  ValueWrapper value ;
  
  public Flag(String name, T def) {
    ValueWrapper tmp = flags.get(name) ;
    if (tmp == null) {
       this.value = new ValueWrapper(def) ;
       flags.put(name, this.value) ;
    } else {
      String storedClass = tmp.get().getClass().getSimpleName() ;
      String requestedClass = def.getClass().getSimpleName() ;
      if(storedClass != requestedClass) {
    	  throw new RuntimeException("Stored and requested class are not identical for Flags") ;
      } else {
        this.value = tmp ;
      }
    }
  }
  
   public T get() {
     return ((T) this.value.get()) ;
   }
  
    public String toString() {
      return this.value.get().toString() ;
    }
  
    public void set(T val) {
       this.value.set(val) ;
    }

    public Integer getInt() {
      return (Integer) this.value.get() ;
    }
    
    
    public void reset() {
    	for (String key: flags.keySet()) {
    		ValueWrapper v = flags.get(key) ;
    		v.set(v.getDefault()) ;
    	}
    }


    public Double getDouble() {
      return (Double) (this.value.get()) ;
    }

    public String getString() {
      return (String) (this.value.get()) ;
  }
}

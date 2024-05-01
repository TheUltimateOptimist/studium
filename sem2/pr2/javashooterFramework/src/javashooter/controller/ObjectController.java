package javashooter.controller;

import javashooter.gameobjects.GameObject;
import javashooter.playground.Playground;

/**
 * Class that controls the LOGICAL behavior of an object independently of how it is displayed or
 * drawn. The most important method here is {@link #updateObject}: this method is, by various
 * indirections, called exactly once per game time step for every object that is on the javashooter.playground.
 * It has, by virtue of the member variable {@link gameObject} (of type {@link GameObject}), full
 * access to
 * <ul>
 * <li>the object it is controlling
 * <li>the javashooter.playground this object belongs to
 * </ul>
 * Typically, updateObject would check whether an object leaves the screen to react appropriately.
 * In that case the object can be marked for deletion (by adding it to the flag "deleted" that is
 * always defined for any javashooter.playground), but of course other reactions are possible like rebounding,
 * emerging on the other side, ...
 */

public abstract class ObjectController {
  protected GameObject gameObject = null;
  protected String dummy = "";

  public void setObject(GameObject gameObject) {
    this.gameObject = gameObject;
  }


  public void setDummy(String x) {
    System.out.println("DUMMY called!!");
    this.dummy = x;
    System.out.println("DUMMY is now:" + dummy);
  }

  /**
   * Is called once every game time step by the game itself. NEVER call this directly, not
   * necessary!<br>
   * The method can do whatever it likes, including nothing. The field {@link #gameObject} contains
   * a reference to the controlled object.
   */
  public abstract void updateObject();

  /**
   * Convenience method: simply moves the object forward one step from its present position, using
   * its present speed.
   */
  public void applySpeedVector() {
    double ts = this.getPlayground().getTimestep();
    this.setX(this.getX() + this.getVX() * ts);
    this.setY(this.getY() + this.getVY() * ts);
    this.setPhi(this.getPhi() + this.getOmega() * ts);
  }


  public double getTimestep() {
    return this.gameObject.getPlayground().getTimestep();
  }
  
  public double getGameTime() {
    return this.gameObject.getPlayground().getGameTime() ;
  }
  
  
  public void setPhi(double phi) {
    gameObject.setPhi(phi) ;
  }
 
  

  public double getX() {
    return this.gameObject.getX();
  }

  public double getY() {
    return this.gameObject.getY();
  }
    
  
  public double getOmega() {
    return this.gameObject.getOmega();
  }
  
  

  public double getVX() {
    return this.gameObject.getVX();
  }

  
  public double getPhi() {
    return this.gameObject.getPhi();
  }
  

  public double getVY() {
    return this.gameObject.getVY();
  }

  public void setX(double x) {
    this.gameObject.setX(x);
  }


  public void setY(double y) {
    this.gameObject.setY(y);
  }

  public void setVX(double vx) {
    this.gameObject.setVX(vx);
  }

  public void setVY(double vy) {
    this.gameObject.setVY(vy);
  }
  
  
  /*
  public Object getLevelFlag(String s) {
    return this.getPlayground().getLevelFlag(s) ;
  }
  
  public Object getOrCreateLevelFlag(String s, Object def) {
    return this.getPlayground().getOrCreateLevelFlag(s, def) ;
  }
  
  public void setLevelFlag(String s, Object o) {
    this.getPlayground().setLevelFlag(s, o) ;
  }
  
  
  public void setGlobalFlag(String s, Object o) {
    this.getPlayground().setGlobalFlag(s, o) ;
  }
  
  
  public Object getOrCreateGlobalFlag(String s, Object def) {
    return this.getPlayground().getOrCreateGlobalFlag(s, def) ;
  } */
  
  
  
  

  public Playground getPlayground() {
    return this.gameObject.getPlayground();
  }

  public void setPlayground(Playground playground) {
    this.gameObject.setPlayground(playground);
  }



}

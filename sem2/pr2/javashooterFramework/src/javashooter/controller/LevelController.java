package javashooter.controller;

import java.awt.Color;
import java.awt.event.KeyEvent;

import javashooter.collider.*;
import javashooter.controller.*;
import javashooter.gameobjects.*;
import javashooter.gameutils.*;
import javashooter.playground.*;

import java.util.*;
import java.awt.event.*;

/** Ein LevelController erhält alle Inputs (Keyboard, Maus) und setzt sie in
 *  Level-Flags um. Diese Level-Flags können dann von anderen Controllern gelesen werden.
*   So muss ein Objekt-Controller nicht jedesmal eine potentiell komplizierte Steuerung
*   implementieren.
*/
public class LevelController extends ObjectController {
  double t0 = 0;

  Integer pressedKey = null;
  Integer lastPressedKey = null;

  GameObject clickObject = null ;
  RectCollider clickCollider = null ;

  HashMap<Integer,Boolean> memory = new HashMap<Integer,Boolean>() ;
  HashMap<Integer,String> keyTable = new HashMap<Integer,String>() ;

  LevelFlag<Integer> mouseX = new LevelFlag<Integer>("/mouseX",-1) ;
  LevelFlag<Integer> mouseY = new LevelFlag<Integer>("/mouseY",-1) ;
  LevelFlag<Integer> mouseButton = new LevelFlag<Integer>("/mousebutton",-1) ;
  

  public LevelController() {

    this.keyTable.put(KeyEvent.VK_RIGHT,"right") ;
    this.keyTable.put(KeyEvent.VK_LEFT,"left") ;
    this.keyTable.put(KeyEvent.VK_DOWN,"down") ;
    this.keyTable.put(KeyEvent.VK_UP,"up") ;
    this.keyTable.put(KeyEvent.VK_SPACE,"shoot") ;
    


  }

  public void updateObject() {

    Stack<KeyEvent> keyEvents = getPlayground().getKeyEvents();
    Stack<MouseEvent> mouseEvents = getPlayground().getMouseEvents();
    int pgSizeX = getPlayground().preferredSizeX();
    int pgSizeY = getPlayground().preferredSizeY();
    double ts = getPlayground().getTimestep();
    //if (keyEvents.size() > 0)
    //System.out.println("Raw mouse: "+keyEvents.size() + "/" + mouseEvents.size()) ;

    this.mouseX.set(-1) ;
    this.mouseY.set(-1) ;
    this.mouseButton.set(-1) ;
    
    //getPlayground().setLevelFlag("mouseX", -1) ;
    //getPlayground().setLevelFlag("mouseY", -1) ;
    //getPlayground().setLevelFlag("mousebutton", -1) ;

    // wir loopen über alle neuen Maus-Events und publizieren sie
    boolean last = true ;
    int b = -1 ;
    while (mouseEvents.isEmpty()==false) {
      MouseEvent e = mouseEvents.pop();
      //getPlayground().setLevelFlag("mouseX", e.getX()) ;
      //getPlayground().setLevelFlag("mouseY", e.getY()) ;
      //getPlayground().setLevelFlag("mousebutton", e.getButton()) ;
      if ((e.getButton() != 0) && e.getModifiersEx() == MouseEvent.BUTTON1_DOWN_MASK) b = e.getButton();
      if(last) {
        this.mouseX.set(e.getX()) ;
        this.mouseY.set(e.getY()) ;
      }
      this.mouseButton.set(b) ;
      last = false ;
      //System.out.println("Mouse="+e.getX() ) ;

    } // while


    // selbes Spuiel mit Keyboard-Events
    // auslesen und als Level-Flags publizieren!
    int i=-1 ;
    memory.clear() ;
    while (!keyEvents.isEmpty()) {
      //System.out.println("Iteration  is"+ (++i)) ;
      KeyEvent e = keyEvents.pop();
      boolean pressed = false;
      boolean released = true;
      int kc = e.getKeyCode();
      //System.out.println("KEY is"+e.paramString()) ;

      if (e.paramString().indexOf("PRESSED") >= 0) {
        pressed = true;
        released = false;
      }
      // ok komplziert: wenn in einem update-Zyklus eine Taste sowohl geddrückt als auch losgelassen wird
      // (gibt es)  --> dann gilt sie als losgelassen, dh der Drück-Event wird ignoriert
      Boolean memAccess =  memory.get(kc) ;
      if (memAccess == null) ;
      else if (memAccess.equals(false)) continue ;
      memory.put(kc,pressed) ;

      String rel = (pressed?"pressed":"released") ;
      String inv = (pressed?"released":"pressed") ;

      for (HashMap.Entry<Integer,String> entry : keyTable.entrySet()) {
        Integer key = entry.getKey();
        String keyName = entry.getValue();

        if (kc == key) {
          LevelFlag<Boolean> tmp1 = new LevelFlag<Boolean>(keyName+'_'+rel, true) ;
          LevelFlag<Boolean> tmp2 = new LevelFlag<Boolean>(keyName+'_'+inv, true) ;
          tmp1.set(true) ;
          tmp2.set(false) ;
          //getPlayground().setLevelFlag(keyName+'_'+rel, true) ;
          //getPlayground().setLevelFlag(keyName+'_'+inv, false) ;
        }  
      }
    } 



  }


}

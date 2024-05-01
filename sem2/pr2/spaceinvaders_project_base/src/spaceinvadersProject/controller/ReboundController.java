package spaceinvadersProject.controller;
import javashooter.controller.*;

public class ReboundController extends ObjectController {

  private int limitx = -1 ;
  private int limity = -1 ;
  public ReboundController(int lx, int ly) {
	super() ;
    this.limitx = lx ;
    this.limity = ly ;
  }
  
  @Override
  public void updateObject() {
    if (this.getX() >= this.getPlayground().preferredSizeX()-this.limitx) {
      this.setVX(this.getVX()*-1) ;
    }
    
    if (this.getX() < this.limitx) {
      this.setVX(this.getVX()*-1) ;
    }
    
    if (this.getY() >= this.getPlayground().preferredSizeY()-this.limity) {
      this.setVY(this.getVY()*-1) ;
    }
    
    if (this.getY() < this.limity) {
      this.setVY(this.getVY()*-1) ;
    }
    
    
    // unverändert lassen, sogt dafür dass Objekt weiterbewegt wird!
    this.applySpeedVector() ;
  }

}

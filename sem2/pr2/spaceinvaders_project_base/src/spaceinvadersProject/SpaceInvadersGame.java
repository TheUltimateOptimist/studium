package spaceinvadersProject;
import java.awt.Font;
import java.io.BufferedReader;
import java.io.File;
import java.awt.font.TextAttribute;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.AttributedString;
import java.util.ArrayList;

import javashooter.gameobjects.GameObject;
import javashooter.gameutils.GameLoop;
import javashooter.playground.Playground;
import javashooter.ui.GameUI;
import javashooter.ui.Menu;
import spaceinvadersProject.playground.*;

import java.awt.event.*;


/**
 * Klasse die ein Beispiel für ein komplettes Spiel darstellt. Erbt von GameLoop und überschreibt
 * die Methode defineLevels.
 */
public class SpaceInvadersGame extends GameLoop {

  Playground currentLevel=null ;

  public Playground nextLevel(Playground currentLevel) {  
	if (currentLevel != null) {
		return null;
	}
    return new Level0();
  }

  public static void main(String[] args) {
    SpaceInvadersGame game = new SpaceInvadersGame();
    game.runGame(args);
  }
}

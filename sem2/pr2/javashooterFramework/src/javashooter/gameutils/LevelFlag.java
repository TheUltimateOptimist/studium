package javashooter.gameutils;

public class LevelFlag<T> extends Flag<T> {
	public LevelFlag (String name, T def) {
		super("/currentLevel"+name, def) ;
	}
}

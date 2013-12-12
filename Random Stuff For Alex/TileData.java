package com.ludusamo.LD28.levels.tiles;

public class TileData {
	public static TileData[] tiles = new TileData[256];
	public static TileData VOID;
	public static TileData STONE;
	public static TileData GRASS;

	private int id;
	private int levelColor;
	private boolean isSolid;

	public TileData(int id, int levelColor, boolean isSolid) {
		this.id = id;
		this.levelColor = levelColor;
		this.isSolid = isSolid;

		tiles[id] = this;
	}

	public int getId() {
		return id;
	}

	public int getLevelColor() {
		return levelColor;
	}

	public boolean isSolid() {
		return isSolid;
	}

}

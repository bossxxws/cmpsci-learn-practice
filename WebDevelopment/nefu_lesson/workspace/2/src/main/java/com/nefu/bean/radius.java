package com.nefu.bean;

public class radius {
	public int getRadius() {
		return radius;
	}

	public void setRadius(int radius) {
		this.radius = radius;
	}

	private int radius;
	public double cirlearea() {
		return Math.PI*radius*radius;
	}
	public double circlelength() {
		return Math.PI*radius*2;
	}

}

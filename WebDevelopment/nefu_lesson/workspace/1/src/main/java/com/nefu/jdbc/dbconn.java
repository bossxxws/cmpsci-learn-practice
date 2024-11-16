package com.nefu.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class dbconn {
Connection conn=null;
Statement stmt=null;
ResultSet rs=null;
int i=0;
String str="jdbc:mysql://localhost:3306/book";
String user="root";
String ps="root";
	public dbconn() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			conn=DriverManager.getConnection(str, user, ps);
			System.out.println("连接成功");
			//conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
    

    public ResultSet executequery(String sql) {
    	try {
			stmt=conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
    		//stmt=conn.createStatement();
    		rs=stmt.executeQuery(sql);
    	    //conn.close();
    	} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    	return rs;
    }
    public int executeupdate(String sql) {
    	try {
			stmt=conn.createStatement();
			i=stmt.executeUpdate(sql);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	return i;
    }
    public void connclose() {
    	try {
			conn.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
}
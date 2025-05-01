import java.sql.*;
import java.util.*;
class demo1
{
	public static void main(String ro[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Name.....");
		String s1=sc.nextLine();
		System.out.println("Enter Password.....");
		String s2=sc.nextLine();
		try
		{
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con=DriverManager.getConnection("jdbc:mysql:///iclass","root","root");
			PreparedStatement ps=con.prepareStatement("select * from login where c1=? AND c2=?");
			ps.setString(1,s1);
			ps.setString(2,s2);
			ResultSet rs=ps.executeQuery();
			if(rs.next())
			{
				System.out.println("welcome");
			}
			else 
			{
				System.out.println("invalid");
			}
			con.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}
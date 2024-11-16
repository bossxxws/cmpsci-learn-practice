package bao.servlet;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import com.nefu.bean.user;
/**
* Servlet implementation class loginservlet
*/
@WebServlet("/loginservlet")
public class loginservlet extends HttpServlet {
private static final long serialVersionUID = 1L;
/**
* Default constructor. */
public loginservlet() {
// TODO Auto-generated constructor stub
}
/**
* @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
*/
protected void doGet(HttpServletRequest request, HttpServletResponse
response) throws ServletException, IOException {
// TODO Auto-generated method stub
//response.getWriter().append("Served at: ").append(request.getContextPath());
request.getRequestDispatcher("login.html").forward(request, response);
}
/**
* @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
*/
protected void doPost(HttpServletRequest request, HttpServletResponse
response) throws ServletException, IOException {
// TODO Auto-generated method stub
//doGet(request, response);
String name=request.getParameter("u");
String ps=request.getParameter("ps");
user u1=new user();
u1.setU(name);
u1.setPs(ps);
if(name.equals("admin")&ps.equals("admin")) {
HttpSession s1=request.getSession();
s1.setAttribute("user", u1);
response.sendRedirect("welcome.jsp");
}
else {
response.getWriter().append("您 输 入 的 用 户 名 密 码 不 正 确").append("<a href='login.html'>返回</a>");
}
}
}
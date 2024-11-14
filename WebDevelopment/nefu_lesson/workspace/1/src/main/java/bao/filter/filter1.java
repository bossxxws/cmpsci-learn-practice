package bao.filter;
import java.io.IOException;
import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
/**
* Servlet Filter implementation class filter1
*/
@WebFilter("/*")
public class filter1 implements Filter {
private String str="loginservlet";
/**
* Default constructor. */
public filter1() {
// TODO Auto-generated constructor stub
}
/**
* @see Filter#destroy()
*/
public void destroy() {
// TODO Auto-generated method stub
}
/**
* @see Filter#doFilter(ServletRequest, ServletResponse, FilterChain)
*/
public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
// TODO Auto-generated method stub
// place your code here
// pass the request along the filter chain
HttpServletRequest r1=(HttpServletRequest)request;
HttpServletResponse r2=(HttpServletResponse )response;
if(r1.getSession().getAttribute("user")!=null) {
chain.doFilter(request, response);}
else if(r1.getRequestURI().contains(str)){
chain.doFilter(request, response);
}
else {
r2.sendRedirect("loginservlet");
}
}
/**
* @see Filter#init(FilterConfig)
*/
public void init(FilterConfig fConfig) throws ServletException {
// TODO Auto-generated method stub
}
}
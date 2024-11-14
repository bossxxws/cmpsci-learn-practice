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
/**
* Servlet Filter implementation class filter
*/
@WebFilter("/*")
public class filter implements Filter {
/**
* Default constructor. */
public filter() {
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
response.setContentType("text/html; charset=gbk");
chain.doFilter(request, response);
}
/**
* @see Filter#init(FilterConfig)
*/
public void init(FilterConfig fConfig) throws ServletException {
// TODO Auto-generated method stub
}
}
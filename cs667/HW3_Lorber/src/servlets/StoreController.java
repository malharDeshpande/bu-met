package servlets;

import java.util.*;
import javax.faces.bean.*;

@ManagedBean(eager=true)
public class StoreController {
  private List<ProductBean> products; 
  
  public StoreController() {
      products = new ArrayList<ProductBean>();
      products.add(new ProductBean("radiator", 354.60));
      products.add(new ProductBean("strut", 150.75));
      products.add(new ProductBean("carburetor", 99.99));
      products.add(new ProductBean("spark plug", 5.99));
      products.add(new ProductBean("windshield wiper", 15.99));

  }
  
  public List<ProductBean> getProducts() {
    return(products);
  }
}
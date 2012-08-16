package tgl.project.util;

public class CompanyDetails implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
	
    private String id;
    private String name;

    public CompanyDetails(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public String getString() {
        String s = this.id + " " + this.name;
        return s;
    }

}
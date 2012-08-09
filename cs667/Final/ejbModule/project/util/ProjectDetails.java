package project.util;

public class ProjectDetails implements java.io.Serializable {
	private static final long serialVersionUID = 1L;

	private String id;
    private String code;

    public ProjectDetails(String id, String code) {
        this.id = id;
        this.code = code;
    }

    public String getId() {
        return this.id;
    }

    public String getCode() {
        return this.code;
    }

    public String getString() {
        String s = this.id + " " + this.code;
        return s;
    }

}
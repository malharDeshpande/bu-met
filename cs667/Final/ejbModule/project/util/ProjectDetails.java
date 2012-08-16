package tgl.project.util;

public class ProjectDetails implements java.io.Serializable {
	private static final long serialVersionUID = 1L;

	private String code;
    private String name;

    public ProjectDetails(String code, String name) {
        this.code = code;
        this.name = name;
    }

    public String getCode() {
        return this.code;
    }

    public String getName() {
        return this.name;
    }

    public String getString() {
        String s = this.code + " " + this.name;
        return s;
    }

}
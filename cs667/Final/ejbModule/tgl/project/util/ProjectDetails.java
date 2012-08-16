package tgl.project.util;

import java.util.List;

public class ProjectDetails implements java.io.Serializable {
	private static final long serialVersionUID = 1L;

	private String code;
    private String name;
    private List<EmployeeDetails> employees;
    
    public ProjectDetails(String code, String name, List<EmployeeDetails> employees) {
        this.code = code;
        this.name = name;
        this.employees = employees;
    }

    public String getCode() {
        return this.code;
    }

    public String getName() {
        return this.name;
    }

    public List<EmployeeDetails> getEmployees() {
        return this.employees;
    }

    public String getString() {
        String s = this.code + " " + this.name;
        return s;
    }

}
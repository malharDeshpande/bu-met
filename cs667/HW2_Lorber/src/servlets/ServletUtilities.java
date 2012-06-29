package servlets;


public class ServletUtilities {
    public static final String DOCTYPE =
        "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\">\n";
	
    public static String headWithTitle(String title) {
        return(DOCTYPE + "\n" +
               "<HTML>\n" + 
               "<HEAD><TITLE>HW2_Lorber | " + title + "</TITLE></HEAD>\n");
    }
	
    public static String filter(String input) {
        if (input != null) {
            StringBuffer filtered = new StringBuffer(input.length());
            char c;
            for(int i=0; i<input.length(); i++) {
                c = input.charAt(i);
                if (c == '<') {
                    filtered.append("&lt;");
                } else if (c == '>') {
                    filtered.append("&gt;");
                } else if (c == '"') {
                    filtered.append("&quot;");
                } else if (c == '&') {
                    filtered.append("&amp;");
                } else {
                    filtered.append(c);
                }
            }
            return(filtered.toString());
        } else {
            return input;
        }
    }
	
    public static String inputElement(String prompt,
                                      String name,
                                      String value,
                                      boolean required,
                                      boolean shouldPrompt) {
        String style = "";
        if (shouldPrompt && ((value == null) || value.equals(""))) {
            style = "STYLE=\"background: red\"";
        }
        String starred = "";
        if (required) {
            starred = "<SPAN STYLE=\"color: red; font: bold;\">*</SPAN>";
        }
        return("<TR " + style + "><TD>" + starred + "<LABEL FOR=\"" + name + "\">" + prompt + ":</LABEL></TD>\n" +
               "<TD><INPUT TYPE=\"TEXT\" NAME=\"" + name + "\"" + " VALUE=\"" + value + "\"></TD></TR>\n");
    }
    
    public static String inputElementValueTaken(String prompt,
                                                String name,
                                                String value) {
        return("<TR><TD COLSPAN=\"2\">Customer ID taken, choose new value.</TD></TR><TR STYLE=\"background: red\"><TD><LABEL FOR=\"" + name + "\">" + prompt + ":</LABEL></TD>\n" +
               "<TD><INPUT TYPE=\"TEXT\" NAME=\"" + name + "\"" + " VALUE=\"" + value + "\"></TD></TR>\n");
    }
	
    public static String displayRow(String prompt,
                                    String value) {
        return("<TR><TD>" + prompt + ":</TD><TD>" + value + "</TD></TR>\n");
    }
}

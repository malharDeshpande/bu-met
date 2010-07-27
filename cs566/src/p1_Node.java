
// TERRY LORBER <tgl@bu.edu>
// CS566 Summer 2010
// Extra Credit

public class p1_Node {

	/**
	 * Constructor
	 * @param symbol
	 * @param frequency
	 */
	public p1_Node(String symbol, int frequency) {
		_symbol = symbol;
		_frequency = frequency;
		_left = null;
		_right = null;
	}
	
	public String getSymbol() { return _symbol; }
	public int getFrequency() { return _frequency; }
	public p1_Node getLeft() { return _left; }
	public p1_Node getRight() { return _right; }
	
	public void setSymbol(String symbol) { _symbol = symbol; }
	public void setFrequency(int frequency) { _frequency = frequency; }
	public void setLeft(p1_Node left) { _left = left; }
	public void setRight(p1_Node right) { _right = right; }
	
	// PRIVATE //
	
	private String _symbol;
	private int _frequency;
	private p1_Node _left;
	private p1_Node _right;
}

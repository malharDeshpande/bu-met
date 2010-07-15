import java.io.*;
import java.util.Scanner;


public class p1_HuffmanCode {

	public class Node {

		/**
		 * Constructor
		 * @param symbol
		 * @param frequency
		 */
		public Node(String symbol, int frequency) {
			_symbol = symbol;
			_frequency = frequency;
			_left = null;
			_right = null;
		}
		
		public String getSymbol() { return _symbol; }
		public int getFrequency() { return _frequency; }
		public Node getLeft() { return _left; }
		public Node getRight() { return _right; }
		
		public void setSymbol(String symbol) { _symbol = symbol; }
		public void setFrequency(int frequency) { _frequency = frequency; }
		public void setLeft(Node left) { _left = left; }
		public void setRight(Node right) { _right = right; }
		
		// PRIVATE //
		
		private String _symbol;
		private int _frequency;
		private Node _left;
		private Node _right;
	}
	
	public Throwable HeapUnderflowException;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		p1_HuffmanCode parser = new p1_HuffmanCode(new File(args[0]), new File(args[1]));
		try {
			log("Read file...");
			parser.readFileIn();
			log("Sort min-priority queue...");
			parser.sortNodes();
			log("Construct tree...");
			parser.constructTree();
			log("Write file out...");
			parser.writeFileOut();
		} catch (FileNotFoundException fnf) {
			log("ERROR");
			log(fnf.getMessage());
			
		}
		log("Done");
	}

	
	public p1_HuffmanCode(File aInput, File aOutput) {
		_input = aInput;
		_output = aOutput;
		_nodes = new Node[50];
		_nodes[0] = new Node(null, 0);
		_nodeCounter = 1;
	}

	// PRIVATE //
	
	private final void readFileIn() throws FileNotFoundException {
		Scanner scanner = new Scanner(_input);
		try {
			while (scanner.hasNextLine()) {
				processLine(scanner.nextLine());
			}
		} catch (Exception e) {
			log("ERROR: " + e.getMessage());
		} finally {
			scanner.close();
		}
	}

	private void processLine(String aLine) {
		//use a second Scanner to parse the content of each line 
	    Scanner scanner = new Scanner(aLine);
	    scanner.useDelimiter(" ");
	    if (scanner.hasNext()) {
	      String symbol = scanner.next();
	      String frequency = scanner.next();
	      log("Symbol is " + quote(symbol.trim()) + ", and frequency is " + quote(frequency.trim()) );

	      p1_HuffmanCode.Node node = new p1_HuffmanCode.Node(symbol, Integer.parseInt(frequency));
	      if (_nodeCounter > _nodes.length) {
	    	  int newSize = 2 * _nodes.length;
	    	  p1_HuffmanCode.Node[] newNodes = new p1_HuffmanCode.Node[newSize];
	    	  System.arraycopy(_nodes, 0, newNodes, 0, _nodes.length);
	    	  _nodes = newNodes;
	    	  log("Size of nodes array increased to: " + newSize);
	      }
	      
    	  _nodes[_nodeCounter++] = node;

	    } else {
	      log("Empty or invalid line. Unable to process.");
	    }
	    scanner.close();
	}

	private final void sortNodes() {
		for (int loop = _nodeCounter / 2; loop > 0; loop--) {
			minHeapify(loop);
		}
		printNodes();
	}

	private void minHeapify(int index) {
		int left = left(index);
		int right = right(index);
		int smallest = index;
		if (left < _nodeCounter && _nodes[left].getFrequency() < _nodes[index].getFrequency()) {
			smallest = left;
		}
		if (right < _nodeCounter && _nodes[right].getFrequency() < _nodes[smallest].getFrequency()) {
			smallest = right;
		}
		if (smallest != index) {
			Node temp = _nodes[index];
			_nodes[index] = _nodes[smallest];
			_nodes[smallest] = temp;
			minHeapify(smallest);
		}
	}
	
	private static int parent(int index) {
		return index / 2;
	}

	private static int left(int index) {
		return index * 2;
	}

	private static int right(int index) {
		return index * 2 + 1;
	}

	
	private final void constructTree() {
		int n = _nodeCounter - 1;
		for (int loop = 1; loop < n; loop++) {
			Node z = new Node(null, 0);
			log("Extract two min nodes...");
			Node x = extractMin();
			log("x is " + x.getFrequency() + " with " + x.getLeft() + " " + x.getRight());
			Node y = extractMin();
			log("y is " + y.getFrequency() + " with " + y.getLeft() + " " + y.getRight());
			z.setLeft(x);
			z.setRight(y);
			z.setFrequency(x.getFrequency() + y.getFrequency());
			printNodes();
			log("Insert new node...");
			insert(z);
			printNodes();
		}
	}
	
	private Node extractMin() {
		Node min = null;
		if (_nodeCounter > 0) {
			min = _nodes[1];
			_nodes[1] = _nodes[--_nodeCounter];
			minHeapify(1);
		}
		return min;
	}
	
	private void insert(Node node) {
		if (_nodeCounter > _nodes.length) {
			int newSize = _nodes.length * 2;
			Node newNodes[] = new Node[newSize];
			System.arraycopy(_nodes, 0, newNodes, 0, _nodes.length);
			_nodes = newNodes;
	    	log("Size of nodes array increased to: " + newSize);
	    }
		_nodes[_nodeCounter++] = node;
		int index = _nodeCounter - 1;
		while (index > 1 && 
				_nodes[parent(index)].getFrequency() > _nodes[index].getFrequency()) {
			Node temp = _nodes[index];
			_nodes[index] = _nodes[parent(index)];
			_nodes[parent(index)] = temp;
			index = parent(index);
		}
	}
	
	private final void writeFileOut() {
		inorderPrint(_nodes[1]);
	}
	
	private void printNodes() {
		for (int loop = 1; loop < _nodeCounter; loop++) {
		      log("Symbol is " + quote(_nodes[loop].getSymbol()) + ", and frequency is " + quote(String.valueOf(_nodes[loop].getFrequency())) );			
		}

	}
	
	private void inorderPrint(Node n) {
		if (n != null) {
			inorderPrint(n.getLeft());
			if (n.getSymbol() != null) {
				log(n.getSymbol() + ":" + n.getFrequency());
			} else {
				log(n.getFrequency());
			}
			inorderPrint(n.getRight());
		}
	}
	private final File _input;
	private final File _output;
	private p1_HuffmanCode.Node[] _nodes;
	private int _nodeCounter;
	
	private static void log(Object aObject) {
		System.out.println(String.valueOf(aObject));
	}
		  
	private String quote(String aText){
		String QUOTE = "'";
		return QUOTE + aText + QUOTE;
	}
		  
}



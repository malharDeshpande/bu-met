import java.lang.String;

import Jama.Matrix;
import Jama.EigenvalueDecomposition;

public class MarkovRoulette
{
    static private class Option
    {
	String flag;
	String opt;
	public Option(String flag, String opt) 
	{ 
	    this.flag = flag; 
	    this.opt = opt;
	}
    }

    public static void usage()
    {
	System.out.println("USAGE: java -jar MarkovRoulette.jar initialStake wager goal runs\n");
	System.out.println("Via a conservative betting strategy, try to reach the goal from the initial");
        System.out.println("stake by wagering on red or black.  The same wager is used each time.");
        System.out.println("What are the probable outcomes after each round of betting?\n");
    }
    
    public static void main(String[] args)
    {
	if (args.length != 4) {
	    usage();
	    throw new IllegalArgumentException("Must have four arguments.");
	}
	
	double initial_stake = Double.parseDouble(args[0]);
	double wager = Double.parseDouble(args[1]);
	double goal = Double.parseDouble(args[2]);
	int runs = Integer.parseInt(args[3]);

	int states = ((int)goal / (int)wager) + 1;
	
	Matrix T = new Matrix(states, states);
	
	for (int idx = 0; idx < states; idx++) {
	    if (idx > 0 && idx < (states - 1)) {
		T.set(idx - 1, idx, 20./38.); // a loss
		T.set(idx + 1, idx, 18./38.); // a win
	    }
	}


	T.set(0, 0, 1.); // no change, a loser is a loser
	T.set(states-1, states-1, 1.); // no change, a winner is a winner
	
	// look see
	System.out.println("This is the transition matrix...");
	T.print(10, 3);

	// trust, but verify
	for (int col = 0; col < states; col++) {
	    double sr = 0.0;
	    for (int row = 0; row < states; row++) {
		sr += T.get(row, col);
	    }
	    if (Math.abs(sr - 1.) > 1.0e-15) {
		throw new RuntimeException("Somthing is wrong, Markov conditions do not compute.");
	    }
	}


	Matrix P = new Matrix(states, 1);
	P.set(states/2, 0, 1.);
	
	System.out.println("Here are the probability vectors for each run...");
	for (int idx = 0; idx < runs; idx++) {
	    System.out.printf("P%d: ", 0);
	    P.print(states, 3);

	    P = T.times(P);
	}
	
	System.out.printf("P%d: ", runs);
	P.print(states, 3);

	// use eigenvalue decomposition
	System.out.println("OK, now see what eigenvalue decomposition gives us...");

	EigenvalueDecomposition E = T.eig();

	System.out.println("Eigenvalues:");
	E.getD().print(states, 3);

	System.out.println("Eigenvectors:");
	E.getV().print(states, 3);

	System.out.println("Now for imaginary & real eigenvalue values (respectively)...");

        // find the dominant eigenvector, ignore imaginary
        // values when comparing.
        double e = 0.0;
        double v[] = new double[states];
	for (int idx = 0; idx <  E.getRealEigenvalues().length; idx++) {
	    System.out.printf("%d : %f %f\n", 
			      idx, 
			      E.getImagEigenvalues()[idx],
			      E.getRealEigenvalues()[idx]);
            
            if (Math.abs(E.getImagEigenvalues()[idx]) > 1.0e-15) {
		throw new RuntimeException("Somthing is wrong, should not have non-zero imaginary component of the eigenvalue.");
            }

            double ei = E.getRealEigenvalues()[idx];

            if (Math.abs(ei) > Math.abs(e)) {
                e = ei;

                for (int row = 0; row < E.getV().getRowDimension(); row++) {
                    v[row] = E.getV().get(row, idx);
                }
            }
	}

        System.out.printf("The selected eigenvector for eigenvalue %.3f:\n", e);

        // normalize
        double sv = 0.0;
        for (int idx = 0; idx < states; idx++) {
            System.out.printf("%d -> %.3f\n", idx, v[idx]);
            sv += v[idx];
        }

        System.out.printf("Scale by %.3f\n", sv);

        double[] p = new double[states];
        for (int idx = 0; idx < states; idx++) {
            p[idx] = v[idx] / sv;
        }

        System.out.println("Probabilities by eigenvalue decomposition...");
        for (int indx = 0; indx < states; indx++) {
            System.out.printf("%d -> %.3f\n", indx, p[indx]);
        }
        
        System.out.println("\n\nFINI");
    }// Main
    
    
    
}// MarkovRoulette



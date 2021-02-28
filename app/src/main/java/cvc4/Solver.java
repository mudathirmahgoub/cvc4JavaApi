package cvc4;

public class Solver
{
    private long solverPointer;

    public Solver()
    {
        solverPointer = newSolver();
    }

    private native long newSolver();

    public void deleteSolver()
    {
        deleteSolver(solverPointer);
    }

    private native void deleteSolver(long solverPointer);

    public void setLogic(String logic)
    {
        setLogic(solverPointer, logic);
    }

    private native void setLogic(long solverPointer, String logic);

    public Sort getRealSort()
    {
        return getRealSort(solverPointer);
    }

    private native Sort getRealSort(long solverPointer);

    public native Sort getIntegerSort();

    public native Term mkConst(Sort sort, String symbol);

    public native Term mkInteger(int val);

    public native Term mkReal(int num, int den);
}

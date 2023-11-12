using System.Diagnostics;

class Program
{
    private static readonly Random random = new();

    static void Main()
    {
        int queensCount = int.Parse(Console.ReadLine()!);
        Solve(queensCount);
    }

    static void Solve(int queensCount)
    {
        var timer = Stopwatch.StartNew();
        var solution = MinConflicts(Enumerable.Range(0, queensCount).ToArray(), queensCount);

        if (solution == null)
        {
            Console.WriteLine(-1);
        }
        else
        {
            if (queensCount > 100)
            {
                var time = timer.Elapsed;
                Console.WriteLine("{0:m\\.ss}", time);
            }
            else
            {
                PrintChessBaord(solution, queensCount);
                // PrintQueens(solution);
            }
        }

    }

    static void PrintChessBaord(int[] solution, int queensCount)
    {
        for (int i = 0; i < queensCount; i++)
        {
            for (int col = 0; col < queensCount; col++)
            {
                Console.Write((solution[col] == queensCount - i - 1) ? "* " : "_ ");
            }

            Console.WriteLine();
        }
    }

    static void PrintQueens(int[] solution)
    {
        Console.WriteLine($"[{string.Join(", ", solution.Reverse())}]");
    }

    static int[]? MinConflicts(int[] solution, int queensCount, int iterations = 10000)
    {
        for (int k = 0; k < iterations; k++)
        {
            int[] conflicts = FindConflicts(solution, queensCount);
            if (conflicts.Sum() == 0)
            {
                return solution;
            }

            int col = GetRandomPosition(conflicts, queensCount, x => x > 0);
            int[] newConflicts = Enumerable
                .Range(0, queensCount)
                .Select(row => Hits(solution, queensCount, col, row))
                .ToArray();

            solution[col] = GetRandomPosition(newConflicts, queensCount, x => x == newConflicts.Min());
        }

        return null;
    }

    static int GetRandomPosition(int[] collection, int queensCount, Func<int, bool> filter)
    {
        var indicies = Enumerable.Range(0, queensCount).Where(x => filter(collection[x])).ToList();
        return indicies[random.Next(indicies.Count)];
    }

    static int[] FindConflicts(int[] solution, int queensCount)
        => Enumerable
            .Range(0, queensCount)
            .Select(col => Hits(solution, queensCount, col, solution[col]))
            .ToArray();

    static int Hits(int[] solution, int queensCount, int col, int row)
    {
        int total = 0;
        for (int i = 0; i < queensCount; i++)
        {
            if (i == col)
            {
                continue;
            }
            if (solution[i] == row || Math.Abs(i - col) == Math.Abs(solution[i] - row))
            {
                total += 1;
            }
        }

        return total;
    }
}

// Slow solution but the code is more readable
//using System.Diagnostics;
//using static System.Net.Mime.MediaTypeNames;

//int n = int.Parse(Console.ReadLine()!);

//var board = new ChessBoard(n);

//var timer = Stopwatch.StartNew();
//while (!board.IsSolved())
//{
//    int minAttacks = n + 1;
//    Position pickedQueen = board.SelectRandomQueen();
//    var positions = board.GetAvailablePositions(pickedQueen);

//    var minConflictPosition = new Position(-1, -1);

//    // iterate through all positions of pickedQueen and move to position of minimum conflict
//    foreach (var position in positions)
//    {
//        board.MoveQueen(pickedQueen, position);
//        var newNumberOfConflicts = board.CountQueenConflicts(position);

//        if (newNumberOfConflicts < minAttacks)
//        {
//            minConflictPosition = position;
//            minAttacks = newNumberOfConflicts;
//        }

//        // move queen back
//        board.MoveQueen(position, pickedQueen);
//    }

//    // move queen to least conflict spot
//    board.MoveQueen(pickedQueen, minConflictPosition);
//}

//if (n > 9)
//{
//    var time = timer.Elapsed;
//    Console.WriteLine("{0:m\\.ss}", time);
//}
//board.PrintBoard();
//// board.PrintQueens();

//internal class ChessBoard
//{
//    private int size;
//    private const int Queen = 1;
//    private const int Empty = 0;
//    private int[][] board = null!;
//    private HashSet<Position> queens = null!;
//    private Random random = new();

//    public ChessBoard(int n)
//    {
//        this.size = n;
//        IntializeBoard();
//    }

//    private void IntializeBoard()
//    {
//        this.board = new int[size][];
//        for (int i = 0; i < size; i++)
//        {
//            board[i] = new int[size];
//        }

//        this.queens = new HashSet<Position>();
//        for (int row = 0; row < size; row++)
//        {
//            var col = random.Next(size);
//            board[row][col] = Queen;
//            queens.Add(new Position(row, col));
//        }
//    }

//    /// <summary>
//    /// Takes a queen positoin and returns all the positions that the queen can move to
//    /// </summary>
//    /// <param name="position">The row and col of the queen</param>
//    /// <returns>Returns a list of all the positions that the queen can move to</returns>
//    internal List<Position> GetAvailablePositions(Position position)
//        => Enumerable.Range(0, size).Select(x => new Position(position.Row, x)).ToList();

//    /// <summary>
//    /// Checks if there are no conflicts
//    /// </summary>
//    /// <returns>Returns true if problem is solved and all queens safe, false otherwise</returns>
//    internal bool IsSolved()
//    {
//        foreach (var queen in queens)
//        {
//            if (UnderAttack(queen))
//            {
//                return false;
//            }
//        }

//        return true;
//    }

//    /// <summary>
//    /// Takes the queen position and empty position and swaps them
//    /// </summary>
//    /// <param name="startPosition">The position of the queen</param>
//    /// <param name="endPosition">The empty position where we want to move the queen</param>
//    /// <exception cref="NotImplementedException"></exception>
//    internal void MoveQueen(Position startPosition, Position endPosition)
//    {
//        if (board[startPosition.Row][startPosition.Col] != Queen)
//        {
//            throw new InvalidOperationException($"On row: {startPosition.Row} and col: {startPosition.Col} is not located a queen");
//        }

//        board[startPosition.Row][startPosition.Col] = Empty;
//        board[endPosition.Row][endPosition.Col] = Queen;
//        queens.Remove(startPosition);
//        queens.Add(endPosition);
//    }

//    /// <summary>
//    /// Select a random queen and returns its position
//    /// </summary>
//    /// <returns>Row and Col of the queen</returns>
//    internal Position SelectRandomQueen()
//    {
//        int index = this.random.Next(size);
//        foreach (var queen in queens)
//        {
//            if (index == 0)
//            {
//                return queen;
//            }

//            index--;
//        }

//        return queens.First();
//    }

//    /// <summary>
//    /// Print the board to the console
//    /// </summary>
//    internal void PrintBoard()
//    {
//        for (int i = 0; i < board.Length; i++)
//        {
//            for (int j = 0; j < board.Length; j++)
//            {
//                Console.Write(board[i][j] == Queen ? "* " : "_ ");
//            }

//            Console.WriteLine();
//        }

//    }

//    internal void PrintQueens()
//    {
//        var finalQueens = queens.OrderBy(x => x.Col).Select(x => x.Row).ToList();
//        Console.WriteLine($"[{string.Join(", ", finalQueens)}]");
//    }

//    /// <summary>
//    /// Returns the number of conflicts a given queen has
//    /// </summary>
//    /// <param name="position"></param>
//    /// <returns></returns>
//    internal int CountQueenConflicts(Position position)
//    {
//        if (!queens.Contains(position))
//        {
//            throw new InvalidOperationException($"Queen is not located in the passed position: {position}");
//        }

//        var count = 0;
//        foreach (var queen in queens)
//        {
//            if (OnTheSameCol(position, queen)) count++;
//            if (OnTheSameDiagonal(position, queen)) count++;
//            if (OnTheSameRow(position, queen)) count++;
//        }

//        return count;
//    }

//    private bool UnderAttack(Position queenPosition)
//       => AttackViaDiagonal(queenPosition) ||
//       AttackViaRow(queenPosition) ||
//       AttackViaCol(queenPosition);

//    private bool AttackViaCol(Position position)
//        => queens.Any(q => OnTheSameCol(position, q));

//    private static bool OnTheSameCol(Position p1, Position p2) => p1.Col == p2.Col && p2 != p1;

//    private bool AttackViaRow(Position position)
//        => queens.Any(q => OnTheSameRow(position, q));

//    private static bool OnTheSameRow(Position p1, Position p2) => p2.Row == p1.Row && p2 != p1;

//    private bool AttackViaDiagonal(Position position)
//        => queens.Any(q => OnTheSameDiagonal(position, q));

//    private static bool OnTheSameDiagonal(Position p1, Position p2)
//        => p2 != p1 && Math.Abs(p2.Row - p1.Row) == Math.Abs(p2.Col - p1.Col);
//}

//internal record Position(int Row, int Col);

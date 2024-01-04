using System.Diagnostics;

class Program
{
    static void Main(string[] args)
    {
        List<int> board = new();
        int numberOfBlocks = int.Parse(Console.ReadLine()!);
        int boardSize = (int)Math.Sqrt(numberOfBlocks + 1);

        int emptyBlockFinalPosition = int.Parse(Console.ReadLine()!);
        // -1 means the the empty block in the final solution should be in the right-down corner
        if (emptyBlockFinalPosition == -1)
        {
            emptyBlockFinalPosition = numberOfBlocks;
        }

        for (int i = 0; i < boardSize; i++)
        {
            // Represent the board as one-dimension array: [2 ,3, 1, 5, 4, 0, 7, 6, 8] - just for simplicity
            board.AddRange(
                Console.ReadLine()!
                .Split(' ', StringSplitOptions.RemoveEmptyEntries)
                .Select(int.Parse)
                .ToList());
        }

        if (!IsPuzzleSolvable(board))
        {
            Console.WriteLine(-1);
        }
        else
        {
            Stopwatch stopwatch = Stopwatch.StartNew();
            var answer = SolvePuzzle(board, emptyBlockFinalPosition, boardSize);
            // Console.WriteLine("The puzzle if solved for: ", stopwatch.Elapsed.TotalSeconds);

            Console.WriteLine(answer.Steps);
            if (answer.Solution != null)
            {
                foreach (var item in answer.Solution)
                {
                    Console.WriteLine(item);
                }
            }

        }
    }

    static bool IsMoveAllowed(int boardSize, int currentPosition, int newPosition)
    {
        // check if the new position is in the board range
        if (newPosition < 0 || newPosition >= boardSize * boardSize)
        {
            return false;
        }

        int currentRow = currentPosition / boardSize;
        int currentCol = currentPosition % boardSize;
        int newRow = newPosition / boardSize;
        int newCol = newPosition % boardSize;

        // Return true if the move is to the neighbour cell
        return Math.Abs(currentRow - newRow) + Math.Abs(currentCol - newCol) <= 1;
    }

    static int GetEmptyBlockFinalPosition(int number, int emptyBlockFinalPosition)
    {
        if (emptyBlockFinalPosition <= number - 1)
        {
            return number;
        }

        return number - 1;
    }

    static int GetPath(int firstPosition, int secondPosition, int boardSize)
    {
        return Math.Abs(firstPosition / boardSize - secondPosition / boardSize) + Math.Abs(firstPosition % boardSize - secondPosition % boardSize);
    }

    static int CalculateManhattanDistance(List<int> board, int emptyBlockFinalPosition, int boardSize)
    {
        int distance = 0;
        for (int i = 0; i < board.Count; i++)
        {
            if (board[i] != 0)
            {
                distance += GetPath(i, GetEmptyBlockFinalPosition(board[i], emptyBlockFinalPosition), boardSize);
            }
        }

        return distance;
    }

    static (bool Solved, int Steps, List<string>? Solution) IdaStar(
        List<int> board,
        int currentEmptyPosition,
        int bound,
        int g,
        List<string> solution,
        List<string> paths,
        int emptyBlockFinalPosition,
        int boardSize,
        Dictionary<string, int> directions)
    {
        int h = CalculateManhattanDistance(board, emptyBlockFinalPosition, boardSize);
        int f = g + h;
        int min = int.MaxValue;

        if (h == 0)
        {
            return (true, g, solution);
        }
        if (f > bound)
        {
            return (false, f, null);
        }

        foreach (var kvp in directions)
        {
            string directionName = kvp.Key;
            int direction = kvp.Value;

            if (solution.Count != 0 && directions[solution.Last()] == -1 * direction)
            {
                continue;
            }

            int newEmptyPosition = currentEmptyPosition + direction;

            if (!IsMoveAllowed(boardSize, currentEmptyPosition, newEmptyPosition))
            {
                continue;
            }

            Swap(board, currentEmptyPosition, newEmptyPosition);

            string newPath = string.Join('_', board);
            if (paths.Contains(newPath))
            {
                Swap(board, currentEmptyPosition, newEmptyPosition);
                continue;
            }

            paths.Add(string.Join('_', board));
            solution.Add(directionName);
            var response = IdaStar(board, newEmptyPosition, bound, g + 1, solution, paths, emptyBlockFinalPosition, boardSize, directions);
            if (response.Solved)
            {
                return (response.Solved, response.Steps, solution);
            }

            Swap(board, currentEmptyPosition, newEmptyPosition);
            if (solution.Any())
            {
                solution.RemoveAt(solution.Count - 1);
            }
            if (paths.Any())
            {
                paths.RemoveAt(paths.Count - 1);
            }

            if (min > response.Steps)
            {
                min = response.Steps;
            }
        }

        return (false, min, null);
    }

    private static int FindEmptyPosition(List<int> board) => board.IndexOf(0);

    static int GetInversionsCount(List<int> arr)
    {
        int inversions = 0;
        for (int i = 0; i < arr.Count - 1; i++)
        {
            for (int j = i + 1; j < arr.Count; j++)
            {
                if (arr[i] > arr[j] && arr[i] != 0 && arr[j] != 0)
                {
                    inversions++;
                }
            }
        }

        return inversions;
    }

    static bool IsPuzzleSolvable(List<int> arr)
    {
        int inversions = GetInversionsCount(arr);
        int boardSize = (int)Math.Sqrt(arr.Count);
        if (boardSize % 2 == 1)
        {
            return inversions % 2 != 1;
        }
        else
        {
            int emptyPosition = FindEmptyPosition(arr);
            int emptyRow = emptyPosition / boardSize;
            return (inversions + emptyRow) % 2 == 1;
        }
    }

    static (bool IsSolvable, int Steps, List<string>? Solution) SolvePuzzle(List<int> arr, int z, int boardSize)
    {
        Dictionary<string, int> directions = new()
        {
            ["right"] = -1,
            ["left"] = 1,
            ["down"] = -1 * boardSize, // becuase the board is represented as one-dimension array
            ["up"] = boardSize
        };

        int bound = CalculateManhattanDistance(arr, z, boardSize);

        int zero_pos = FindEmptyPosition(arr);
        var dirs = new List<string>();
        var paths = new List<string>();
        var response = IdaStar(arr, zero_pos, bound, 0, dirs, paths, z, boardSize, directions);

        while (!response.Solved)
        {
            bound = response.Steps;
            var l = new List<string>();
            var p = new List<string>();
            response = IdaStar(arr, zero_pos, bound, 0, l, p, z, boardSize, directions);
        }

        return response;
    }

    public static void Swap<T>(List<T> list, int sourceIndex, int destinationIndex)
    {
        if (sourceIndex < 0 || sourceIndex >= list.Count || destinationIndex < 0 || destinationIndex >= list.Count)
        {
            throw new ArgumentOutOfRangeException($"Index out of range trying to swap the elements at index: {destinationIndex} and {sourceIndex}");
        }

        (list[destinationIndex], list[sourceIndex]) = (list[sourceIndex], list[destinationIndex]);
    }
}

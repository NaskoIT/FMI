using System.Text;

int n = int.Parse(Console.ReadLine()!);

var towns = GenerateTowns(n).ToList();

const int POPULATION_SIZE = 20;
const int MAX_GENERATIONS = 10;
const int MUTATION_RATE = 2;

var population = CreateInitialPopulation(towns, POPULATION_SIZE).ToList();

Solution bestSolution = null;

for (int i = 0; i < MAX_GENERATIONS; i++)
{
    var parents = SelectParents(population);

    var nextPopulation = Reproduction(parents);

    Mutate(nextPopulation, MUTATION_RATE);

    Evaluate(nextPopulation);

    population = GetNextPopulation(POPULATION_SIZE, nextPopulation);

    if (bestSolution == null || bestSolution.Distance > population.First().Distance)
    {
        bestSolution = population.First();
    }

    Console.WriteLine(population.First());
}

Console.WriteLine(bestSolution);

static List<Solution> GetNextPopulation(int POPULATION_SIZE, IList<Solution> nextPopulation)
    => nextPopulation.OrderBy(x => x.Distance).Take(POPULATION_SIZE).ToList();

static IList<Solution> SelectParents(IList<Solution> population)
{
    return population
        .OrderBy(x => x.Distance)
        .Take(population.Count / 2)
        .ToList();
}

static void Evaluate(IList<Solution> nextPopulation)
{
    foreach (var solution in nextPopulation)
    {
        solution.RecalculateDistance();
    }
}

static IList<Solution> Reproduction(IList<Solution> parents)
{
    var nextPopulation = new List<Solution>();

    for (int i = 0; i < parents.Count; i++)
    {
        for (int j = 0; j < parents.Count; j++)
        {
            if (i != j)
            {
                nextPopulation.Add(CrossOver(parents[i], parents[j]));
                nextPopulation.Add(CrossOver(parents[j], parents[i]));
            }
        }
    }

    return nextPopulation;
}

static Solution CrossOver(Solution firstParent, Solution secondParent)
{
    var random = new Random();
    int length = firstParent.Towns.Count;
    int startIndex = random.Next(length - 1);
    int endIndex = random.Next(startIndex + 1, length);

    var child = new Town[length];

    for (int i = startIndex; i <= endIndex; i++)
    {
        child[i] = firstParent.Towns[i];
    }

    int sourceIndex = endIndex + 2;
    for (int i = 0; i < length; i++)
    {
        if (child[i] == null)
        {
            while (Array.IndexOf(child, secondParent.Towns[sourceIndex % length]) != -1)
            {
                sourceIndex++;
            }

            child[i] = secondParent.Towns[sourceIndex % length];
            sourceIndex++;
        }
    }

    return new Solution(child);
}

static void Mutate(IList<Solution> solutions, int mutationRate)
{
    foreach (Solution solution in solutions)
    {
        MutateSolution(solution, mutationRate);
    }
}

static void MutateSolution(Solution solution, int mutationRate)
{
    var random = new Random();
    for (int i = 0; i < solution.Towns.Count; i++)
    {
        if (random.Next(1, 11) <= MUTATION_RATE)
        {
            int destinationIndex = random.Next(0, solution.Towns.Count);
            var temp = solution.Towns[destinationIndex];
            solution.Towns[destinationIndex] = solution.Towns[i];
            solution.Towns[i] = temp;
        }
    }
}

static IEnumerable<Solution> CreateInitialPopulation(IList<Town> towns, int populationSize)
{
    for (int i = 0; i < populationSize; i++)
    {
        yield return new Solution(Randomize(towns));
    }
}

static IList<Town> Randomize(IList<Town> towns)
{
    var random = new Random();
    return towns.Select(x => new { Town = x, Order = random.Next(0, towns.Count * 10) })
        .OrderBy(x => x.Order)
        .Select(x => x.Town)
        .ToList();
}

static IEnumerable<Town> GenerateTowns(int n)
{
    var x = GetUniqueRandomRange(0, n);
    var y = GetUniqueRandomRange(0, n);

    for (var i = 0; i < x.Count; i++)
    {
        yield return new Town(x[i], y[i], i.ToString());
    }
}

static IList<int> GetUniqueRandomRange(int start, int count)
{
    var random = new Random();
    return Enumerable.Range(start, count)
        .Select(x => new { Number = x, Order = random.Next(0, count * 10) })
        .OrderBy(x => x.Order)
        .Select(x => x.Number)
        .ToList();
}

record Town(int X, int Y, string Identifier)
{
    public double GetDistance(Town town)
    {
        double deltaX = town.X - this.X;
        double deltaY = town.Y - this.Y;

        double distance = Math.Sqrt(Math.Pow(deltaX, 2) + Math.Pow(deltaY, 2));
        return distance;
    }

    public override string ToString()
    {
        return Identifier;
    }
}

record Solution
{
    public IList<Town> Towns { get; private set; }

    public double Distance { get; private set; }

    public Solution(IList<Town> towns)
    {
        this.Towns = towns;
        this.Distance = GetTotalDistance();
    }

    public void RecalculateDistance()
    {
        this.Distance = GetTotalDistance();
    }

    public override string ToString()
    {
        StringBuilder sb = new();
        for (int i = 0; i < this.Towns.Count; i++)
        {
            sb.Append(this.Towns[i] + " -> ");
        }

        sb.Append(this.Towns.First() + " Total distance: ");
        sb.AppendLine(Distance.ToString());

        return sb.ToString();
    }

    public double GetTotalDistance()
    {
        double totalDistance = 0;
        for (int i = 0; i < this.Towns.Count - 1; i++)
        {
            totalDistance += this.Towns[i].GetDistance(this.Towns[i + 1]);
        }

        totalDistance += this.Towns.First().GetDistance(this.Towns.Last());

        return totalDistance;
    }
}
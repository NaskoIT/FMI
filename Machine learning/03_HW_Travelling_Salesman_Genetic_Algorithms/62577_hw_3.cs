using System.Text;

int n = int.Parse(Console.ReadLine()!);

var towns = GenerateTowns(n).ToList();

const int POPULATION_SIZE = 100;
const int MAX_GENERATIONS = 20;
const int MUTATION_RATE = 4;
Random random = new(183);
Solution bestSolution = null;

var population = CreateInitialPopulation(towns, POPULATION_SIZE * 100, random).ToList();

for (int i = 0; i < MAX_GENERATIONS; i++)
{
    var parents = SelectParents(population);

    var nextPopulation = Reproduction(parents, random);

    Mutate(nextPopulation, MUTATION_RATE, random);

    Evaluate(nextPopulation);

    population = GetNextPopulation(POPULATION_SIZE, nextPopulation);

    if (bestSolution == null || bestSolution.Distance > population.First().Distance)
    {
        bestSolution = population.First();
        //Console.WriteLine("Better solution found: " + bestSolution);
    }
}

Console.WriteLine(bestSolution);

static List<Solution> GetNextPopulation(int POPULATION_SIZE, IList<Solution> nextPopulation)
    => nextPopulation.OrderBy(x => x.Distance).Take(POPULATION_SIZE).ToList();

static IList<Solution> SelectParents(IList<Solution> population)
{
    return population
        .OrderBy(x => x.Distance)
        .Take(POPULATION_SIZE)
        .ToList();
}

static void Evaluate(IList<Solution> nextPopulation)
{
    foreach (var solution in nextPopulation)
    {
        solution.RecalculateDistance();
    }
}

static IList<Solution> Reproduction(IList<Solution> parents, Random random)
{
    var nextPopulation = new List<Solution>();

    for (int i = 0; i < parents.Count - 1; i++)
    {
        for (int j = 0; j < parents.Count; j++)
        {
            if (i != j)
            {
                nextPopulation.Add(CrossOver(parents[i], parents[j], random));
            }
        }
    }

    return nextPopulation;
}

static Solution CrossOver(Solution firstParent, Solution secondParent, Random random)
{
    int length = firstParent.Towns.Count;
    int startIndex = random.Next(length - length / 2);
    int endIndex = random.Next(startIndex + 5, length - 2);

    var child = new Town[length];


    var childGenesSet = new HashSet<Town>();
    for (int i = startIndex; i <= endIndex; i++)
    {
        child[i] = secondParent.Towns[i];
        childGenesSet.Add(secondParent.Towns[i]);
    }

    var townsToAdd = new List<Town>();
    foreach (var town in firstParent.Towns)
    {
        if (!childGenesSet.Contains(town))
        {
            townsToAdd.Add(town);
            childGenesSet.Add(town);
        }
    }

    int index = 0;
    for (int i = 0; i < child.Length; i++)
    {
        if (child[i] == null)
        {
            child[i] = townsToAdd[index++];
        }
    }

    return new Solution(child);
}

static void Mutate(IList<Solution> solutions, int mutationRate, Random random)
{
    foreach (Solution solution in solutions)
    {
        MutateSolution(solution, mutationRate, random);
    }
}

static void MutateSolution(Solution solution, int mutationRate, Random random)
{
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

static IEnumerable<Solution> CreateInitialPopulation(IList<Town> towns, int populationSize, Random random)
{
    for (int i = 0; i < populationSize; i++)
    {
        yield return new Solution(Randomize(towns, random));
    }
}

static IList<Town> Randomize(IList<Town> towns, Random random)
{
    return towns.Select(x => new { Town = x, Order = random.Next(0, towns.Count * 10) })
        .OrderBy(x => x.Order)
        .Select(x => x.Town)
        .ToList();
}

static IEnumerable<Town> GenerateTowns(int n)
{
    // ~1500
    var x = new List<double>()
    {
        1.90E-04,
        383.458,
        -27.0206,
        335.751,
        69.4331,
        168.521,
        320.35,
        179.933,
        492.671,
        112.198,
        306.32,
        217.343
    };


    var y = new List<double>()
    {
        -2.86E-04,
        -6.09E-04,
        -282.758,
        -269.577,
        -246.78,
        31.4012,
        -160.9,
        -318.031,
        -131.563,
        -110.561,
        -108.09,
        -447.089,
    };

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

record Town(double X, double Y, string Identifier)
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

    public override int GetHashCode()
    {
        return this.Identifier.GetHashCode();
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

        return totalDistance;
    }
}
// C and C++ user functions

int Biggest(int a, int b, int c)
{
  int big;

  if (a > b && a > c)
    big = a;
  if (b > c && b > a)
    big = b;
  else
    big = c;
  return big;
}

void swap_two_num(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
  return;
}

int base_conversion(int number, int base)
{
  int t = 1, out = 0, r, a;
  a = number;
  while (a != 0)
  {
    r = a % base;
    a = a / base;
    out = out + r * t;
    t = t * 10;
  }
  return out;
}

int factorial(int n)
{
  if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else if (n == 3)
    return 6;
  else
    return n * factorial(n - 1);
}

int gcd(int a, int b)
{
  // Everything divides 0
  if (a == 0)
    return b;
  if (b == 0)
    return a;

  // base case
  if (a == b)
    return a;

  // a is greater
  if (a > b)
    return gcd(a - b, b);
  return gcd(a, b - a);
}

void solve_equations(double a1, double b1, double c1, double a2, double b2,
                     double c2, double *x, double *y)
{
  //solving two linear equations : a1x+b1y=c1 and a1x+b2y=c2
  // declare double x, y in main and use --"\n"--
  //solve_equations(a1, b1, c1, a2, b2, c2, &x, &y);
  *x = (c1 * b2 - b1 * c2) / (a1 * b2 - a2 * b1);
  *y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
  return;
}

void dec_to_binary(int dec, char *bin)
{
  // also could have wrote char bin[] same thing
  int i = 0;
  while (dec != 0)
  {
    if (dec & 1 == 1)
      bin[i++] = '1';
    else
      bin[i++] = '0';
    dec = dec >> 1;
  }
  bin[i] = '\0';
}

int factors(int n, int list[])
{

  int count = 0, j = 0;
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      list[j] = i;
      count++;
      j++;
    }
  }
  return count;
}

int freq_counter(int n, int *arr)
{ //it figures out the most frequently appearing element in an array
  // if there is a tie then the smallest num would be returned
  int count = 0, max, count_prev = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
        count++;
    }
    if (count_prev < count)
      max = arr[i];
    if (count_prev == count)
      max = max < arr[i] ? max : arr[i];
    count_prev = count;
    count = 0;
  }
  return max;
}

void bubblesort(int n, int arr[])
{ //terrible sorting algo
  //     // if j=0 then sorts it in an ascending order (default)
  //     // if j=i then sorts in a descending order
  //     //i know know its because im comparing arr[i] and arr[j]
  //     // this is no bubble sort or maybe it is but there are better way to implement bubblesort
  //     for (int i = 0; i < n; i++)
  //     {
  //         for (int j = i; j < n ; j++) //this cannot be optimised by subtracting i in the condition
  //         {
  //             if (arr[j] > arr[i])  // usually ta comparison is arr[j] and arr[j+1] not arr[i]
  //                 std::swap(arr[i], arr[j]); // <algorithm>
  //         }
  //     }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - 1 - i; j++) // optimized sorting
    {
      if (arr[j] > arr[j + 1]) // just changing > to < will reverse it(descending order)
        swap_two_num(arr + j, arr + j + 1);
    }
  }
}

void terribleSortmethod(int n, int arr[])
{
  // only works if the elements are non duplicate serial non-negetive integer numbers
  // terrible method really
  int indices[n];
  for (int i = 0; i < n; i++) //indices recorded
    indices[arr[i] - 1] = i;
  for (int i = 0; i < n; i++) // after sort
  {
    std::cout << arr[indices[i]] << " ";
    //arr[i] = arr[indices[i]];  // need to verify if it works or not
  }
}

int binarySearch(int arr[], int low, int high, int target)
{
  // binary search in a sorted array
  // even i sort the array then the original indices will be gone
  //=================================================
  //std::sort(arr, arr + high);
  high = high - 1;
  while (low <= high)
  {
    if (arr[low] == target)
      return low;
    if (arr[high] == target)
      return high;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int lowerBound(int arr[], int high, int target)
{ // lower bound returns the elements position which element is equal or greater than the target
  //// so when arr[mid] is equal to target we make high = mid -1 and if arr[mid] is less then low = mid+1 and return low
  int low = 0;
  while (low <= high)
  { // DONT RETURN MID
    int mid = (low + high) / 2;
    if (arr[mid] < target) // if upper-bound then arr[mid]<=target then low = mid + 1;
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

int upperBound(int arr[], int high, int target)
{ // upper bound returns the elements position which element is greater than the target
  // so when arr[mid] is equal to target we make low = mid+1 and return that
  int low = 0;
  while (low <= high)
  { // DONT RETURN MID
    int mid = (low + high) / 2;
    if (arr[mid] <= target) // if lower-bound then arr[mid]<target then low = mid + 1;
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
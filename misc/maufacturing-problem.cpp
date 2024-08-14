#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

struct Product
{
  std::string Name;
  double Price;
  std::vector<std::string> Ingredients;
};

std::vector<std::string> SplitString(const std::string& str, const std::string& delimiter)
{
  std::vector<std::string> strs;
  size_t startPos = 0;
  size_t endPos = 0;
  while((endPos = str.find(delimiter, startPos)) != std::string::npos)
  {
    strs.emplace_back(str.substr(startPos, endPos - startPos));
    startPos = endPos + 1;
  }
  strs.emplace_back(str.substr(startPos));
  return strs;
}

std::vector<Product> GetProducts()
{
  std::vector<Product> products{};
  std::string input{};
  while(std::getline(std::cin, input))
  {
    if(input.empty())
    {
      break;
    }
    Product product{};
    auto inputs = SplitString(input, ",");
    if(inputs.size() != 3 && inputs.size() != 4)
    {
      std::cout << "Failed to parse input; Input=\"" << input << "\"" << std::endl;
      throw;
    }
    product.Name = inputs[0];
    if(inputs[1] != "null")
    {
      product.Price = stof(inputs[1]);
    }
    else product.Price = numeric_limits<double>::infinity();
    auto numIngredients = stoi(inputs[2]);
    if(numIngredients > 0)
    {
      if(inputs.size() != 4)
      {
        std::cout << "Failed to parse ingredients input; Input=\"" << input << "\"" << std::endl;
        throw;
      }
      product.Ingredients = SplitString(inputs[3], ";");
    }
    products.emplace_back(product);
  }

  return products;
}

unordered_map<string, double> dp;
//store computed costs
double mincost(const string name, const unordered_map<string, Product> products){
  if (dp.find(name) != dp.end()){
    return dp[name];
  }

  Product product = products.at(name);


  double minc = product.Price;

  if (!product.Ingredients.empty()){
    double bcost = 0;
    for (auto &n : product.Ingredients){
      bcost += mincost(n, products);
    }
    minc = min(minc, bcost);
  }

  dp[name] = minc;
  return minc;
}


double MySolution(const std::string& target, const std::vector<Product>& products)
{
  // ADD IMPLEMENTATION HERE
  unordered_map<string, Product> pm;
  for (auto &p : products){
    pm[p.Name] = p;
  }

  return mincost(target, pm);
}

int main()
{
  std::string targetProductName;
  std::getline(std::cin, targetProductName);
  auto products = GetProducts();

  double bestPrice = MySolution(targetProductName, products);
  printf("%.2f\n", bestPrice);
  return 1;
}

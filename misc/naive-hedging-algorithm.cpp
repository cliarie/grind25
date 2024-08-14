#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

struct MarketDataLevel
{
  int32_t Quantity;
  double Price;

  // Feel free to add whatever fields you want here
};

struct TradeEntity
{
  int32_t Quantity;
  double RiskPerUnit;

  // Feel free to add whatever fields you want here
};

std::vector<MarketDataLevel> ParseMarketData(std::string const& line)
{
  std::stringstream ss;
  ss << line;
  int32_t quantity1, quantity2, quantity3;
  double price1, price2, price3;
  ss >> quantity1 >> price1 >> quantity2 >> price2 >> quantity3 >> price3;
  std::vector<MarketDataLevel> ret = {{quantity1, price1}, {quantity2, price2}, {quantity3, price3}};
  return ret;
}

TradeEntity ParseTradeEntity(std::string const& line)
{
  std::stringstream ss;
  ss << line;
  int32_t quantity;
  double riskPerUnit;
  ss >> quantity >> riskPerUnit;
  return TradeEntity{quantity, riskPerUnit};
}

void OutputTrade(int32_t quantityTraded, double avgFillPrice)
{
  std::cout << std::fixed << std::setprecision(2) << quantityTraded << " " << avgFillPrice << std::endl;
}

int main()
{
  std::string line;

  // Parse out buy prices (first line)
  std::getline(std::cin, line);
  auto buyPrices = ParseMarketData(line);

  // Parse out sell prices (second line)
  std::getline(std::cin, line);
  auto sellPrices = ParseMarketData(line);

  // Parse incoming trade entities (rest of the lines)

  double accumulate = 0.0;
  while(std::getline(std::cin, line))
  {
    auto trade = ParseTradeEntity(line);

    accumulate += trade.Quantity * trade.RiskPerUnit;

    if (accumulate > 0){
      int sellq = static_cast<int>(accumulate);
      double price = 0.0;
      int quantity = 0;

      for (auto &sell : sellPrices){
        if (sell.Quantity >= sellq){
          price += sellq * sell.Price;
          quantity += sellq;
          accumulate -= sellq;
          sell.Quantity -= sellq;
          break;
        }
        else{
          price += sell.Quantity * sell.Price;
          quantity += sell.Quantity;
          sellq -= sell.Quantity;
          accumulate -= sell.Quantity;
          sell.Quantity = 0;
        }
      }

      if (quantity > 0){
        double avg = price / quantity;
        OutputTrade(-quantity, avg);
      }
    }

    if (accumulate < 0){
      int buyq = -static_cast<int>(accumulate);
      double price = 0.0;
      int quantity = 0;

      for (auto &buy : buyPrices){
        if (buy.Quantity >= buyq){
          price += buyq * buy.Price;
          quantity += buyq;
          buy.Quantity -= buyq;
          accumulate += buyq;
          break;
        }
        else{
          price += buy.Quantity * buy.Price;
          quantity += buy.Quantity;
          buyq -= buy.Quantity;
          accumulate += buy.Quantity;
          buy.Quantity = 0;
        }
      }

      if (quantity > 0){
        double avg = price / quantity;
        OutputTrade(quantity, avg);
      }
    }


  }
}

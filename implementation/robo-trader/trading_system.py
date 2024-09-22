import pandas as pd
import numpy as np
import logging
import requests
import time
from datetime import datetime

def fetch_market_data(symbol, interval='1min'):


class TradingSystem:
	def __init__(self):
		pass

	def mean_reversion_strategy(self, market_data):
		if market_data.empty:
			return 'hold'

		prices = market_data['close']
        mean_price = prices.rolling(window=20).mean().iloc[-1]
        std_dev = prices.rolling(window=20).std().iloc[-1]
        current_price = prices.iloc[-1]

        if current_price < mean_price - std_dev:
        	return 'buy'
        elif current_price > mean_price + std_dev:
        	return 'sell'
        else:
        	return 'hold'


    def fetch_market_data(symbol):
	    try:
	        order_data = {'symbol': symbol, 'qty': qty, 'side': side}
	        response = requests.post('http://localhost:5000/order', json=order_data)
	        if response.status_code == 200:
	            result = response.json()
	            return result['avg_price']
	        else:
	            logging.warning(f"Order failed for {symbol}: {response.json()}")
	            return None
	    except Exception as e:
	        logging.error(f"Error sending order for {symbol}: {e}")
	        return None

	def update_portfolio(symbol, qty, avg_price, side):
		try:
	        portfolio_data = {'symbol': symbol, 'qty': qty, 'avg_price': avg_price, 'side': side}
	        response = requests.post('http://localhost:5000/portfolio', json=portfolio_data)
	        if response.status_code == 200:
	            logging.info(f"Updated portfolio for {symbol}: {side} {qty} shares at {avg_price:.2f}")
	        else:
	            logging.warning(f"Failed to update portfolio for {symbol}")
	    except Exception as e:
	        logging.error(f"Error updating portfolio for {symbol}: {e}")




    def send_order(symbol, qty, side):
    	try:
    		order_data = {'symbol: symbol'}


if __name__ == "__main__":
	trading_system = TradingSystem()
	trading_system.run()
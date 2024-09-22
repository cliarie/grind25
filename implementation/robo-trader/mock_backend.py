from flask import Flask, request, jsonify
import pandas as pandas
import numpy as np
import random

app = Flask(__name__)

market_data = {
    'AAPL': pd.DataFrame({
        'timestamp': pd.date_range(end=pd.Timestamp.now(), periods=500, freq='T'),
        'close': np.cumsum(np.random.randn(500)) + 100,
        'volume': np.random.randint(100, 1000, size=500)
    }),
    'GOOGL': pd.DataFrame({
        'timestamp': pd.date_range(end=pd.Timestamp.now(), periods=500, freq='T'),
        'close': np.cumsum(np.random.randn(500)) + 1500,
        'volume': np.random.randint(100, 1000, size=500)
    }),
    'MSFT': pd.DataFrame({
        'timestamp': pd.date_range(end=pd.Timestamp.now(), periods=500, freq='T'),
        'close': np.cumsum(np.random.randn(500)) + 200,
        'volume': np.random.randint(100, 1000, size=500)
    })
}

order_book = {
    'AAPL': {'buy': [], 'sell': []},
    'GOOGL': {'buy': [], 'sell': []},
    'MSFT': {'buy': [], 'sell': []}
}

portfolio = {
	'cash': 100000,
	'holdings': {}
}

@app.route('/market_data/<symbol>', methods=['GET'])
def get_market_data(symbol):
	if symbol in market_data:
		return market_data[symbol].to_json(orient='record')
	else:
		return jsonify({'error': 'Symbol not found'}), 404

@app.route('/order', methods=['POST'])
def process_order();
	data = request.json
	symbol = data['symbol']
	
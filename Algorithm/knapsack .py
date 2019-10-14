def brute_force_knapsack(x_weights, x_prices, x_capacity):
    item_count = x_weights.shape[0]
    picks_space = 2 ** item_count
    best_price = -1
    best_picks = np.zeros(item_count)
    for p in range(picks_space):
        picks = [int(c) for c in f"{p:0{item_count}b}"]
        price = np.dot(x_prices, picks)
        weight = np.dot(x_weights, picks)
        if weight <= x_capacity and price > best_price:
            best_price = price
            best_picks = picks
    return best_picks


def create_knapsack(item_count=5):
    x_weights = np.random.randint(1, 45, item_count)
    x_prices = np.random.randint(1, 99, item_count)
    x_capacity = np.random.randint(1, 99)
    y = brute_force_knapsack(x_weights, x_prices, x_capacity)
    return x_weights, x_prices, x_capacity, y

class Item(object):

    def __init__(self, value, weight):
        self.value = value
        self.weight = weight


def get_maximum_value(items, capacity):
    dp = [0] * (capacity + 1)
    for item in items:
        dp_tmp = [total_value for total_value in dp]
        for current_weight in range(capacity + 1):
            total_weight = current_weight + item.weight
            if total_weight <= capacity:
                dp_tmp[total_weight] = max(dp_tmp[total_weight],
                                           dp[current_weight] + item.value)
        dp = dp_tmp
    return max(dp)

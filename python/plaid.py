# Example Coupon
#
# Exactly one of percent_discount and amount_discount will be non-null (error if not).
# The two 'minimum_...' values can each be null or non-null.
coupon = { 'category': 'fruit',
  'percent_discount': 15,
  'amount_discount': None,
  'minimum_num_items_required': 2,
  'minimum_amount_required': 10.00
}
coupon2 = { 'category': 'fruit',
  'percent_discount': None,
  'amount_discount': 36,
  'minimum_num_items_required': 2,
  'minimum_amount_required': 10.00
}

coupons = [
  { 'categories': ['clothing', 'toy'],
    'percent_discount': None,
    'amount_discount': 6,
    'minimum_num_items_required': None,
    'minimum_amount_required': None
  },
  { 'categories': ['fruit'],
    'percent_discount': 15,
    'amount_discount': None,
    'minimum_num_items_required': 2,
    'minimum_amount_required': 10.00
   }
]

coupons2 = [ { 'categories': ['clothing', 'toy'],
    'percent_discount': None,
    'amount_discount': 6,
    'minimum_num_items_required': None,
    'minimum_amount_required': None
  },
  { 'categories': ['toy'],
    'percent_discount': 15,
    'amount_discount': None,
    'minimum_num_items_required': 2,
    'minimum_amount_required': 10.00
   }
]

# Example Cart
shopping_cart = [ {'price': 2.00, 'category': 'fruit'},
  {'price': 20.00, 'category': 'toy'},
  {'price': 5.00, 'category': 'clothing'},
  {'price': 8.00, 'category': 'fruit'}
]

def apply_coupon(cart, coupon):
    if coupon["percent_discount"] is None and coupon["amount_discount"] is None:
        raise ValueError("invalid coupon")
    if coupon["percent_discount"] and coupon["amount_discount"]:
        raise ValueError("invalid coupon")

    applicable_items = [item for item in cart if item["category"] == coupon["category"]]
    total_price = sum(item["price"] for item in cart)
    total_price_on_applicable = sum(item["price"] for item in applicable_items)

    if coupon["minimum_num_items_required"] and len(applicable_items) < coupon["minimum_num_items_required"]:
        return total_price
    if coupon["minimum_amount_required"] and total_price_on_applicable < coupon["minimum_amount_required"]:
        return total_price

    new_applicable_price = total_price_on_applicable
    if coupon["amount_discount"]:
        # treat as constant value
        new_applicable_price -= coupon["amount_discount"]
    else:
        # treat as percentage
        discount = total_price_on_applicable * coupon["percent_discount"] / 100
        new_applicable_price -= discount

    total_price = total_price - (total_price_on_applicable - max(0, new_applicable_price))

    return total_price

def apply_all_coupons(cart, coupons):
    categories = []
    for coupon in coupons:
        for category in coupon["categories"]:
            if (category in categories):
                raise ValueError("invalid coupons")
            categories.append(category)

    total_price = 0

    for item in cart:
        total_price += item["price"]

    discounts = 0

    for coupon in coupons:
        best_price = float("inf")
        original_price = best_price
        for category in coupon["categories"]:
            # make a new coupon for each category
            cat_coupon = coupon
            cat_coupon["category"] = category
            price_after = apply_coupon(cart, cat_coupon)
            best_price = min(best_price, price_after)
            print("BEST PRICE", category, best_price)

        discounts += total_price - best_price
        print("TOTAL PRICE", total_price)

    return total_price - discounts

print(apply_all_coupons(shopping_cart, coupons2))

# toy gives minus 6
# fruit gives minus 1.5

from datetime import datetime
import heapq
def shippingCost(inputString, sourceCountry, targetCountry, method):
    # split input string by comma, includes source, target, method, and cost
    elements = inputString.split(',')

    for element in elements:
        source, target, method, cost = element.split(':')
        if source == sourceCountry and target == targetCountry and method == method:
            print(cost)
            return
    print("no shipping found")
    return

def intermediate(inputString, sourceCoutnry, targetCountry):
    elements = inputString.split(',')

    # map, key is possible intermediate node, value is [cost for to inter, cost from inter to target]
    map = {}
    for element in elements:
        source, target, method, cost = element.split(':')
        cost = int(cost)
        if source == sourceCountry and target != targetCountry:
            #target might be inter
            if target not in map:
                map[target] = [cost, -1]
            else:
                if map[target][0] == -1:
                    map[target] = [cost, map[target][1]]
                else:
                    map[target] = [min(cost, map[target][0]), map[target][1]]
        if source != sourceCountry and target == targetCountry:
            if source not in map:
                map[source] = [-1, cost]
            else:
                if map[source][1] == -1:
                    map[source] = [map[source][0], cost]
                else:
                    map[source] = [map[source][0], min(cost, map[source][1])]

    for mapval in map.values():
        if mapval[0] != -1 and mapval[1] != -1:
            print(mapval[0] + mapval[1])
            return

def mincost(inputString, sourceCountry, targetCountry):
    map = {}
    pq = []

    elements = inputString.split(',')
    for element in elements:
        source, target, method, cost = element.split(':')
        cost = int(cost)
        if source not in map:
            map[source] = []
        map[source].append((target, cost));

    heapq.heappush(pq, (0, sourceCountry))
    minpath = {sourceCountry: 0}
    while pq:
        cost, cur = heapq.heappop(pq)
        if cur == targetCountry:
            print(cost)
            return
        if cur in map:
            for next, nextcost in map[cur]:
                if next not in minpath or nextcost + cost < minpath[next]:
                    minpath[next] = nextcost + cost
                    heapq.heappush(pq, (cost + nextcost, next))

    print(-1)
    return


inputString = "US:UK:UPS:4,US:UK:DHL:5,UK:CA:FedEx:10,AU:JP:DHL:20"
sourceCountry = "US"
targetCountry = "UK"
method = "UPS"

shippingCost(inputString, sourceCountry, targetCountry, method)

inputString = "US:UK:UPS:4,US:UK:DHL:5,UK:CA:FedEx:10,AU:JP:DHL:20"
sourceCountry = "US"
targetCountry = "CA"

intermediate(inputString, sourceCountry, targetCountry)

inputString = "US:UK:UPS:4,US:UK:DHL:5,UK:CA:FedEx:10,AU:JP:DHL:20,US:AU:DHL:15,AU:CA:DHL:5"
sourceCountry = "US"
targetCountry = "CA"

mincost(inputString, sourceCountry, targetCountry)

import requests
from collections import defaultdict

jwt_token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6ImdpdGh1YjczMTU0MjkxIiwiZW1haWwiOm51bGwsInByb3ZpZGVyIjoiZ2l0aHViIiwicm9sZXMiOlsiVVNFUiJdLCJleHAiOjE3Mzg1NjM0MTguOTEyLCJpYXQiOjE3Mzg0NzcwMTh9.brgef2ntBYixwTd0DD1kyoNR7nb6fuO_t3DCT0Mk28k"
headers = {
    "Authorization": jwt_token,
    "Content-Type": "application/json"
}

response = requests.get("https://adonix.hackillinois.org/registration/challenge/", headers=headers)

if response.status_code != 200:
    print("Failed to fetch input data. Status code:", response.status_code)
    exit()

data = response.json()
alliances = data.get("alliances", [])
people = data.get("people", {})

print("Alliances:", alliances)
print("People:", people)

graph = defaultdict(list)
for u, v in alliances:
    graph[u].append(v)
    graph[v].append(u)

print("Graph:", graph)

visited = set()
max_divine_power = float('-inf')

def dfs(node, visited, graph, people, current_sum):
    visited.add(node)
    current_sum += people.get(node, 0)  # Add the divine power of the current node
    for neighbor in graph[node]:
        if neighbor not in visited:
            current_sum = dfs(neighbor, visited, graph, people, current_sum)
    return current_sum

for node in graph:
    if node not in visited:
        current_sum = dfs(node, visited, graph, people, 0)
        print("Pantheon:", node, "Sum:", current_sum)
        if current_sum > max_divine_power:
            max_divine_power = current_sum

for node, power in people.items():
    if node not in visited:
        print("Pantheon:", node, "Sum:", power)
        if power > max_divine_power:
            max_divine_power = power

print("Max Divine Power:", max_divine_power)

solution = {"solution": max_divine_power}
response = requests.post("https://adonix.hackillinois.org/registration/challenge/", headers=headers, json=solution)

if response.status_code == 200:
    print("Solution submitted successfully!")
    print("Max Divine Power:", max_divine_power)
    print("Response:", response.json())
else:
    print("Failed to submit solution. Status code:", response.status_code)
    print("Response:", response.text)

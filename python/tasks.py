import json
import requests
import time
from typing import Dict, Any

# load json data
def load_json(file_path):
    with open(file_path, 'r') as file:
        return json.load(file)

def extract_first_10_coordinates(data):
    coordinates = data['features'][0]['geometry']['coordinates'][:10]
    print("First 10 coordinates")
    for i, coord in enumerate(coordinates, 1):
        print(f"{i}: Latitude = {coord[1]}, Longitude = {coord[0]}")
    return coordinates

def create_markers_from_coordinates(coordinates):
    markers = []
    for i, coord in enumerate(coordinates):
        marker: Dict[str, Any] = {
            "coord": {
                "lat": coord[1],
                "lon": coord[0]
            }
        }
        if i == 0:
            marker["color"] = "white"
            marker["label"] = "Start"
        elif i == len(coordinates) - 1:
            marker["color"] = "blue"
            marker["label"] = "End"
        else:
            marker["color"] = "red"
        markers.append(marker)
    return markers

def extract_paths(staticmap_data):
    paths = []
    return paths

def build_map_payload(center, markers, paths=[], width=400, height=600, zoom=13):
    payload = {
        "center": center,
        "width": width,
        "height": height,
        "zoom": zoom,
        "markers": markers,
        # "paths": paths
    }
    return payload

def send_post_request(payload, api_url):
    response = requests.post(api_url, json=payload, stream=True)

    if response.status_code == 200:
        with open('bikemap_output.png', 'wb') as f:
            for chunk in response.iter_content(chunk_size=1024):
                f.write(chunk)
        print("Map saved as bikemap_output.png")
    else:
        print(f"Failed to render map. Status code: {response.status_code}. Error: {response.text}")

def modify_and_resend(ride_data, api_url):
    first_10_coords = extract_first_10_coordinates(ride_data)
    new_markers = create_markers_from_coordinates(first_10_coords)

    center = {"lat": 47.579, "lon": -122.31}

    payload = build_map_payload(center, new_markers)

    send_post_request(payload, api_url)

def safe_send_post_request(payload, api_url, retries=3, delay=2):
    attempts = 0
    while attempts < retries:
        try:
            send_post_request(payload, api_url)
            return
        except requests.RequestException as e:
            attempts += 1
            print(f"Error {e}: retrying {attempts}/{retries}...")
            time.sleep(delay)
    print(f"Failed to send request after {retries} retries")

def main():
    ride_data = load_json('ride-simple.json')
    first_10_coords = extract_first_10_coordinates(ride_data)
    markers = create_markers_from_coordinates(first_10_coords)

    center = {"lat": 47.579, "lon": -122.31}

    payload = build_map_payload(center, markers)

    api_url = 'https://stripe-bikemap.appspot.com/map.png'
    safe_send_post_request(payload, api_url)

    modify_and_resend(ride_data, api_url)

if __name__ == "__main__":
    main()

import json
import random
import csv


def generate_json(num_rows, time_interval):
    # Generate JSON data
    json_data = {"records": []}

    for i in range(num_rows):
        record = {
            "time": round(i * time_interval, 2),
            "ax": round(random.uniform(-9.8, 9.8), 2),
            "ay": round(random.uniform(-9.8, 9.8), 2),
            "az": round(random.uniform(-9.8, 9.8), 2)
        }
        json_data["records"].append(record)

    # Write to JSON file
    with open("data.json", mode='w') as file:
        json.dump(json_data, file, indent=4)

    print("data.json created.")


def generate_csv(num_rows, time_interval):
    csv_data = [["time", "ax", "ay", "az"]]

    for i in range(num_rows):
        time = round(i * time_interval, 2)
        ax = round(random.uniform(-9.8, 9.8), 2)
        ay = round(random.uniform(-9.8, 9.8), 2)
        az = round(random.uniform(-9.8, 9.8), 2)
        csv_data.append([time, ax, ay, az])

    # Write to CSV file
    with open("data.csv", mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(csv_data)

    print("data.csv created.")


if __name__ == '__main__':
    generate_csv(100, 0.01)
    generate_json(100, 0.01)

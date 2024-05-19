import threading
import time

class Tablet:
    def __init__(self, tablet_id):
        self.tablet_id = tablet_id

    def record_meal(self):
        meal_data = f"Meal recorded by Tablet {self.tablet_id} at {time.strftime('%H:%M:%S')}"
        return meal_data

class Server:
    def __init__(self):
        self.meal_records = []
        self.lock = threading.Lock()

    def add_meal_record(self, tablet_id):
        tablet = Tablet(tablet_id)
        meal_data = tablet.record_meal()

        with self.lock:
            self.meal_records.append(meal_data)

    def send_updates_to_tablet(self, tablet_id):
        tablet = Tablet(tablet_id)

        with self.lock:
            tablet_updates = self.meal_records[:]

        print(f"Tablet {tablet_id} received updates: {tablet_updates}")

if __name__ == "__main__":
    server = Server()

    tablet_ids = [1, 2, 3]

    # Creating threads for recording meals
    record_threads = [threading.Thread(target=server.add_meal_record, args=(tablet_id,)) for tablet_id in tablet_ids]
    for thread in record_threads:
        thread.start()

    # Creating threads for sending updates to tablets
    update_threads = [threading.Thread(target=server.send_updates_to_tablet, args=(tablet_id,)) for tablet_id in tablet_ids]
    for thread in update_threads:
        thread.start()

    # Waiting for all threads to finish
    for thread in record_threads + update_threads:
        thread.join()

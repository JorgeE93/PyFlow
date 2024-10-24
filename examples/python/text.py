# test.py
import pyflow

def on_event_a(event):
    print(f"Received EventA with data: {event.data}")

def on_event_b(event):
    print(f"Received EventB with message: {event.message}")

# Create an EventManager instance
manager = pyflow.EventManager()

# Subscribe to events
manager.subscribe_event_a(on_event_a)
manager.subscribe_event_b(on_event_b)

# Publish events
event_a = pyflow.EventA(42)
manager.publish(event_a)

event_b = pyflow.EventB("Hello, PyFlow!")
manager.publish(event_b)


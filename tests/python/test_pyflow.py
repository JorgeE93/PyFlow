# test_pyflow.py
import unittest
import pyflow

class TestPyFlow(unittest.TestCase):
    def test_event_a(self):
        received = []

        def on_event(event):
            received.append(event.data)

        manager = pyflow.EventManager()
        manager.subscribe_event_a(on_event)
        event = pyflow.EventA(100)
        manager.publish(event)
        self.assertEqual(received[0], 100)

    def test_event_b(self):
        received = []

        def on_event(event):
            received.append(event.message)

        manager = pyflow.EventManager()
        manager.subscribe_event_b(on_event)
        event = pyflow.EventB("Test Message")
        manager.publish(event)
        self.assertEqual(received[0], "Test Message")

if __name__ == '__main__':
    unittest.main()


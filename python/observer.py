import random

class Subscriber:
    def __init__(self, name):
        self.name = name
  
    def update(self, message):
        print(f'{self.name} got message {message}')


class Publisher:
    def __init__(self):
        self.subscribers = set()

    def register(self, subscriber):
        self.subscribers.add(subscriber)

    def unregister(self, subscriber):
        self.subscribers.discard(subscriber)
        
    def unregister_all(self):
        self.subscribers.clear()

    def dispatch(self, message):
        if not self.subscribers:
            return
        for subscriber in self.subscribers:
            subscriber.update(message)


publisher = Publisher()

first = Subscriber('first')
second = Subscriber('second')
third = Subscriber('third')

publisher.register(first)
publisher.register(second)
publisher.register(third)

publisher.dispatch("Hello subscribers!")

choice = random.choice(list(publisher.subscribers))
publisher.unregister(choice)

publisher.dispatch(f"Hello to all my subscribers, except for: {choice.name}.")

publisher.unregister_all()

publisher.dispatch('This message will never be delivered.')

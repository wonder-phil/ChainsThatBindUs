class Queue:
    def __init__(self):
        self.queue = []

    def insert(self,value):
        self.queue.append(value)

    def dequeue(self):
        if len(self.queue) == 0:
            return None
        first_elt = self.queue[0]
        del self.queue[0]
        return first_elt

    def empty(self):
        return self.queue == []
}

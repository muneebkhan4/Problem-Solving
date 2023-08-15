var MyCircularQueue = function(k) {
    this.queue = new Array(k);  // Array to store the circular queue
    this.front = 0;  // Index of the front element
    this.rear = -1;  // Index of the rear element
    this.size = 0;  // Current number of elements in the queue
};

MyCircularQueue.prototype.enQueue = function(value) {
    if (this.isFull()) {
        return false;  // Cannot enqueue if the queue is full
    }
    this.rear = (this.rear + 1) % this.queue.length;  // Increment rear circularly
    this.queue[this.rear] = value;  // Insert the value at the rear
    this.size++;
    return true;
};

MyCircularQueue.prototype.deQueue = function() {
    if (this.isEmpty()) {
        return false;  // Cannot dequeue if the queue is empty
    }
    this.front = (this.front + 1) % this.queue.length;  // Increment front circularly
    this.size--;
    return true;
};

MyCircularQueue.prototype.Front = function() {
    return this.isEmpty() ? -1 : this.queue[this.front];  // Return front element if not empty, else return -1
};

MyCircularQueue.prototype.Rear = function() {
    return this.isEmpty() ? -1 : this.queue[this.rear];  // Return rear element if not empty, else return -1
};

MyCircularQueue.prototype.isEmpty = function() {
    return this.size === 0;  // Queue is empty if size is 0
};

MyCircularQueue.prototype.isFull = function() {
    return this.size === this.queue.length;  // Queue is full if size is equal to capacity
};

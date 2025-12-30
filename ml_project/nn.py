import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
import time




class LossFunction:
    @staticmethod
    def mse(y_true, y_pred):
        y_pred = np.array(y_pred).reshape(-1,1)
        y_true = np.array(y_true).reshape(-1,1)
        return np.mean((y_true - y_pred) ** 2)

    @staticmethod
    def rmse(y_true, y_pred):
        return np.sqrt(LossFunction.mse(y_true, y_pred))


class Neuron:
    def __init__(self, n_inputs):
        # Xavier/Glorot initialization
        self.weights = np.random.randn(n_inputs) * np.sqrt(2. / n_inputs)  # He initialization for ReLU
        self.bias = np.random.randn()

class Layer:

    def __init__(self, n_neurons, n_inputs, activation_function=None):
        self.neurons = [Neuron(n_inputs) for _ in range(n_neurons)]
        self.activation_function = activation_function
        self.output = None
        self.input = None

    def forward(self, inputs):
        self.input = inputs
        self.weighted_sum = np.array([np.dot(inputs, neuron.weights) + neuron.bias for neuron in self.neurons])
        if self.activation_function:
            self.output = self.activation_function(self.weighted_sum)
        else:
            self.output = self.weighted_sum
        return self.output

class Network:
    def __init__(self, loss_function=LossFunction.mse):
        self.layers = []
        self.loss_function = loss_function
        self.stock_y_pred = []

    def add(self, layer):
        self.layers.append(layer)

    def feedforward(self, X):
        output = X
        for layer in self.layers:
            output = layer.forward(output)
        return output

    def backpropagation(self, output, y, lr):
        # Compute error
        delta = y - output
        # Backward pass
        for i in reversed(range(len(self.layers))):
            layer = self.layers[i]

            # Compute gradient for weights and bias
            if layer.activation_function == ActivationFunction.sigmoid:
                gradient = delta * ActivationFunction.derivative_sigmoid(layer.output)
            elif layer.activation_function == ActivationFunction.relu:
                gradient = delta * ActivationFunction.derivative_relu(layer.weighted_sum)
            else:
                gradient = delta
            gradient = np.clip(gradient,-1,1)            
            # Update weights and bias
            for j, neuron in enumerate(layer.neurons):
                neuron.bias += lr * gradient[j]
                neuron.weights += lr * gradient[j] * layer.input
            # Propagate error to previous layer
            if i > 0:
                weights = np.array([neuron.weights for neuron in layer.neurons])
                delta = np.dot(gradient, weights)

    def fit(self, X, y, epochs=1000, lr=0.001, verbose = True):
        for epoch in range(epochs):
            total_error = 0
            for xi, yi in zip(X, y):
                output = self.feedforward(xi)
                self.stock_y_pred.append(output)
                self.backpropagation(output, yi, lr)
            computed_metrics = self.loss_function(y,self.stock_y_pred)
            self.stock_y_pred = []           
            if verbose:
              print(f'Epoch {epoch + 1}, Error: {computed_metrics}')

    def predict(self, X):
        return np.array([self.feedforward(x) for x in X])
    





class ActivationFunction:
    
    @staticmethod
    def relu(x):
        return np.maximum(0, x)

    @staticmethod
    def sigmoid(x):
        # Numerically stable sigmoid
        x = np.clip(x, -500, 500)  # Clip x to prevent overflow
        return np.where(x >= 0,
                        1 / (1 + np.exp(-x)),
                        np.exp(x) / (1 + np.exp(x)))
    @staticmethod
    def derivative_sigmoid(x):
        sx = ActivationFunction.sigmoid(x)
        return sx * (1 - sx)

    @staticmethod
    def derivative_relu(x):
        return 0


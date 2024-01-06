import numpy as np


class NeuralNetwork:
    def __init__(self, intput_size=2, hidden_size=4, output_size=1):
        self.hidden_delta = None
        self.hidden_error = None
        self.output_delta = None
        self.output_error = None
        self.hidden_input = None
        self.hidden_output = None
        self.final_input = None
        self.input_layer_size = intput_size
        self.hidden_layer_size = hidden_size
        self.output_layer_size = output_size

        # weights
        # (2x4) weight matrix from input to hidden layer
        self.weights_input_hidden = np.random.randn(self.input_layer_size, self.hidden_layer_size)
        # (4x1) weight matrix from hidden to output layer
        self.weights_hidden_output = np.random.randn(self.hidden_layer_size, self.output_layer_size)

    @staticmethod
    def sigmoid(x):
        # activation function
        return 1 / (1 + np.exp(-x))

    @staticmethod
    def sigmoid_derivative(s):
        # derivative of sigmoid
        return s * (1 - s)

    def forward(self, dataset):
        # forward propagation through our network

        # dot product of dataset (input) and first set of 4x2 weights
        self.hidden_input = np.dot(dataset, self.weights_input_hidden)
        # apply activation function
        self.hidden_output = self.sigmoid(self.hidden_input)

        # dot product of hidden layer and second set of 4x1 weights
        self.final_input = np.dot(self.hidden_output, self.weights_hidden_output)
        # final activation function apply
        output = self.sigmoid(self.final_input)
        return output

    def backward(self, dataset, target, output):
        # backward propagate through the network
        # error in output
        self.output_error = target - output
        # applying derivative of sigmoid to error
        self.output_delta = self.output_error * self.sigmoid_derivative(output)

        # hidden_error: how much our hidden layer weights contributed to output error
        self.hidden_error = self.output_delta.dot(self.weights_hidden_output.T)
        # applying derivative of sigmoid to hidden_error
        self.hidden_delta = self.hidden_error * self.sigmoid_derivative(self.hidden_output)

        # adjusting first set (input --> hidden) weights
        self.weights_input_hidden += dataset.T.dot(self.hidden_delta)
        # adjusting second set (hidden --> output) weights
        self.weights_hidden_output += self.hidden_output.T.dot(self.output_delta)

    def fit_predict(self, dataset, target, epochs=1000, show_training_progress=True):
        predictions = []
        for i in range(epochs):
            predictions = self.forward(dataset)
            self.backward(dataset, target, predictions)
            if show_training_progress:
                # mean sum squared loss
                print("Loss: \n" + str(np.mean(np.square(target - self.forward(dataset)))))
                print("Epoch " + str(i + 1) + "/" + str(epochs) + " : completed\n")

        return predictions


def accuracy_score(predictions, target):
    matches = 0
    for i in range(0, len(predictions)):
        predicted_value = predictions[i][0]
        original_value = target[i][0]

        if (predicted_value - original_value) < 0.01:
            matches = matches + 1

    return matches / len(predictions)


def get_train_data():
    return np.array([
        [0, 0, 0],  # 0 & 0 = 0
        [0, 1, 0],  # 0 & 1 = 0
        [1, 0, 0],  # 1 & 0 = 0
        [1, 1, 1],  # 1 & 1 = 1
        # [0, 0, 0],  # 0 | 0 = 0
        # [0, 1, 1],  # 0 | 1 = 1
        # [1, 0, 1],  # 1 | 0 = 1
        # [1, 1, 1],  # 1 | 1 = 1
        # [0, 0, 0],  # 0 ^ 0 = 0
        # [0, 1, 1],  # 0 ^ 1 = 1
        # [1, 0, 1],  # 1 ^ 0 = 1
        # [1, 1, 0],  # 1 ^ 1 = 0
    ])


def main():
    data = get_train_data()
    attributes = np.delete(data, 2, axis=1)
    print(attributes.shape)
    target = data[:, 2].reshape(-1, 1)

    print('Train attributes:')
    print(attributes)
    print('Target:')
    print(target)

    nn_model = NeuralNetwork()
    predictions = nn_model.fit_predict(attributes, target, epochs=100000, show_training_progress=False)
    print(predictions)
    print(accuracy_score(predictions, target))


if __name__ == "__main__":
    main()


# Reference: https://dev.to/shamdasani/build-a-flexible-neural-network-with-backpropagation-in-python
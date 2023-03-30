#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
#define _CRTDBG_MAP_ALLOC

float sigmoid(float x)
{
	return 1 / (1 + exp(-x));
}

float sigmoid_derivative(float x)
{
	return sigmoid(x) * (1 - sigmoid(x));
}

float random_float()
{
	return rand() / (float)RAND_MAX;
}

class neuron
{
public:
	int num_weights = 0;
	float* weights = nullptr;
	float activation_value = 0.0f;

	neuron() {}

	void activate()
	{

	}
};

class layer
{
public:
	int num_neurons = 0;
	neuron* neurons = nullptr;

	layer() {}
};

class neural_network
{
public:
	layer* layers = nullptr;
	
	int num_layers = 4;
	int nurons_per_layer[4] = { 784, 16, 16, 10 };

	neural_network()
	{
		layers = new layer[num_layers];
		for (int layer_index = 0; layer_index < num_layers; layer_index++)
		{
			layer& this_layer = layers[layer_index];
		
			this_layer.num_neurons = nurons_per_layer[layer_index];
			this_layer.neurons = new neuron[this_layer.num_neurons];
			
			if (layer_index == 0) { continue; }
		
			for (int neuron_index = 0; neuron_index < this_layer.num_neurons; neuron_index++)
			{
				neuron& this_neuron = this_layer.neurons[neuron_index];
				this_neuron.num_weights = nurons_per_layer[layer_index - 1];
				this_neuron.weights = new float[this_neuron.num_weights];

				for (int weight_index = 0; weight_index < this_neuron.num_weights; weight_index++)
				{
					this_neuron.weights[weight_index] = random_float();
				}
			}
		}
	}

	~neural_network()
	{
		for (int layer_index = 0; layer_index < num_layers; layer_index++)
		{
			layer& this_layer = layers[layer_index];
			for (int neuron_index = 0; neuron_index < this_layer.num_neurons; neuron_index++)
			{
				neuron& this_neuron = this_layer.neurons[neuron_index];
				delete[] this_neuron.weights;
			}
			delete[] this_layer.neurons;
		}
		delete[] layers;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello SFML", sf::Style::Close);
	sf::Event event;

	neural_network neural_network;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color(0, 0, 0));
		window.display();
	}

	return 0;
}


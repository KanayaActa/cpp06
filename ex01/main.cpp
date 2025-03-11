/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:04:00 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/11 21:04:24 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data data;
	data.num = 42;
	data.text = "Hello, Serialization!";

	Data* dataPtr = &data;

	uintptr_t raw = Serializer::serialize(dataPtr);
	Data* newPtr = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << dataPtr << std::endl;
	std::cout << "Serialized value: " << raw << std::endl;
	std::cout << "Deserialized pointer: " << newPtr << std::endl;

	if (newPtr == dataPtr)
		std::cout << "Serialization and deserialization successful!" << std::endl;
	else
		std::cout << "Something went wrong." << std::endl;

	return 0;
}

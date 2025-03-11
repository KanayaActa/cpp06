/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:16:40 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/11 21:16:53 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>

int main() {
	Base* p = generate();

	std::cout << "Identifying via pointer: ";
	identify(p);

	std::cout << "Identifying via reference: ";
	identify(*p);

	delete p;
	return 0;
}

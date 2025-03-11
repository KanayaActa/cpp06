/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:33:45 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/11 17:51:38 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cctype>

static bool isPseudoLiteral(const std::string &str) {
	return (str == "nan" || str == "nanf" ||
			str == "+inf" || str == "-inf" ||
			str == "+inff" || str == "-inff");
}

void ScalarConverter::convert(const std::string &literal) {
	// まず、入力が疑似リテラルかどうかをチェック
	if (isPseudoLiteral(literal)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		// 出力形式に注意：float には末尾に f, double にはそのまま
		std::cout << "float: " << literal;
		if (literal[literal.size() - 1] != 'f') {
			std::cout << "f";
			std::cout << std::endl;
			std::cout << "double: " << (literal[literal.size() - 1] == 'f' ? literal.substr(0, literal.size()-1) : literal) << std::endl;
			return;
		}
	}

	// 入力が1文字でかつ数字でないなら char とみなす
	char c = 0;
	double d = 0;
	bool conversionOk = true;

	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		c = literal[0];
		d = static_cast<double>(c);
	}
	else {
		// まずは double 型に変換する
		std::istringstream iss(literal);
		if (!(iss >> d)) {
			conversionOk = false;
		}
		c = static_cast<char>(d);
	}

	// char の出力：表示可能かどうかをチェック
	std::cout << "char: ";
	if (!conversionOk || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;

	// int の出力
	std::cout << "int: ";
	if (!conversionOk || d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	// float の出力：小数点以下1桁以上の出力フォーマット
	std::cout << "float: ";
	float f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	// double の出力
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

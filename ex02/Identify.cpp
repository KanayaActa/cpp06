/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:16:04 by miwasa            #+#    #+#             */
/*   Updated: 2025/03/11 21:19:58 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "Derived.hpp" // A, B, C の定義
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

// generate(): ランダムに A, B, C を生成して返す
Base* generate(void) {
    // 乱数のシードは1回だけ設定（※ 本例では generate() 内で初期化していますが、main() で行ってもよい）
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random = std::rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
}

// identify(Base*): dynamic_cast を使って各型にキャストして判定
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

// identify(Base&): dynamic_cast を使い、例外処理で判定
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch(...) { }
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch(...) { }
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch(...) { }
    std::cout << "Unknown" << std::endl;
}

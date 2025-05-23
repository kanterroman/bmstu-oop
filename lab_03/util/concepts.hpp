//
// Created by Roman Kanterov on 18.05.2025.
//

#ifndef CONCEPTS_HPP
#define CONCEPTS_HPP

#include <concepts>

template <typename Derived, typename Base>
concept DerivedFrom = std::derived_from<Derived, Base> && !std::is_abstract_v<Derived>;

#endif //CONCEPTS_HPP

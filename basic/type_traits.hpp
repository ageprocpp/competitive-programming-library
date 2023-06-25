#pragma once
#include "template.hpp"

class ModInt__Base {};
class StaticModInt__Base : ModInt__Base {};
class DynamicModInt__Base : ModInt__Base {};

template <class T>
class is_ModInt : public std::is_base_of<ModInt__Base, T> {};
template <class T>
constexpr bool is_ModInt_v = is_ModInt<T>::value;

template <class T>
class is_StaticModInt : public std::is_base_of<StaticModInt__Base, T> {};
template <class T>
constexpr bool is_StaticModInt_v = is_StaticModInt<T>::value;

template <class T>
class is_DynamicModInt : public std::is_base_of<DynamicModInt__Base, T> {};
template <class T>
constexpr bool is_DynamicModInt_v = is_DynamicModInt<T>::value;
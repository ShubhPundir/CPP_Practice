template<typename It>
void someAlgorithm(It begin, It end){
    auto temp1 = static_cast<typename std::iterator_traits<It>::value_type&&>(*begin)
    // permit to move from *begin to temp

    auto temp2 = (typename std::iterator_traits<It>::value_type&&)*begin;
    // C-STYLE casting

    auto temp3 = std::move(*begin);
    // std::move version
}

/*
    T&&    ==> T&
    T&& &  ==> T&
    T& &&  ==> T&
    T&& && ==> T&&
*/

template<typename T>
typename std::remove_reference<T>::type&&
move(MagicReferenceType obj) noexcept{
    using ReturnType = typename std::remove_reference<T>::type&&;
    return static_cast<ReturnType>(obj);
}
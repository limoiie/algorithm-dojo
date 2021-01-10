//
// Created on 2020/6/12.
//
// This file contains helper functions to pretty print any std::containers that
// have the field T::const_iterator, such as std::set, std::vector and so on.
// The std::tuple and std::pair also are supported.
//
// See reference from https://stackoverflow.com/questions/4850473/pretty-print-c-stl-containers
//

#ifndef ALGORITHM_DOJO_PRETTY_PRINT_H
#define ALGORITHM_DOJO_PRETTY_PRINT_H

#include <type_traits>
#include <iostream>
#include <utility>
#include <tuple>
#include <set>


namespace pretty_print {

    // SFINAE type trait to detect a container based on whether
    // T::const_iterator exists.
    // (Improvement idea: check also if begin()/end() exist.)
    template<typename T>
    struct is_container_helper {
    private:
        template<typename C>
        static char test(typename C::const_iterator *) { return 0; }

        template<typename C>
        static int test(...) { return 0; }

    public:
        static const bool value = sizeof(test<T>(0)) == sizeof(char);
    };

    // Basic is_container template; specialize to derive from std::true_type
    // for all desired container types
    template<typename T>
    struct is_container
            : public ::std::integral_constant<
                    bool, is_container_helper<T>::value> {};

}  // namespace pretty_print


namespace pretty_print {
    /*
     * Delimiters definition
     */

    // Holds the delimiter values for a specific character type
    template<typename TChar>
    struct delimiters_values {
        typedef TChar char_type;
        const char_type *prefix;
        const char_type *delimiter;
        const char_type *postfix;
    };

    // Defines the delimiter values for a specific container and character type
    template<typename T, typename TChar>
    struct delimiters {
        typedef delimiters_values<TChar> type;
        static const type values;
    };

    // Default delimiters
    template<typename T> struct delimiters<T, char> { static const delimiters_values<char> values; };
    template<typename T> const delimiters_values<char> delimiters<T, char>::values = { "[", ", ", "]" };
    template<typename T> struct delimiters<T, wchar_t> { static const delimiters_values<wchar_t> values; };
    template<typename T> const delimiters_values<wchar_t> delimiters<T, wchar_t>::values = { L"[", L", ", L"]" };

    // Delimiters for set
    template<typename T, typename TTraits, typename TAllocator> struct delimiters<::std::set<T, TTraits, TAllocator>, char> { static const delimiters_values<char> values; };
    template<typename T, typename TTraits, typename TAllocator> const delimiters_values<char> delimiters<::std::set<T, TTraits, TAllocator>, char>::values = { "{", ", ", "}" };
    template<typename T, typename TTraits, typename TAllocator> struct delimiters<::std::set<T, TTraits, TAllocator>, wchar_t> { static const delimiters_values<wchar_t> values; };
    template<typename T, typename TTraits, typename TAllocator> const delimiters_values<wchar_t> delimiters<::std::set<T, TTraits, TAllocator>, wchar_t>::values = { L"{", L", ", L"}" };

    // Delimiters for pair (reused for tuple, see below)
    template<typename T1, typename T2> struct delimiters<::std::pair<T1, T2>, char> { static const delimiters_values<char> values; };
    template<typename T1, typename T2> const delimiters_values<char> delimiters<::std::pair<T1, T2>, char>::values = { "(", ", ", ")" };
    template<typename T1, typename T2> struct delimiters<::std::pair<T1, T2>, wchar_t> { static const delimiters_values<wchar_t> values; };
    template<typename T1, typename T2> const delimiters_values<wchar_t> delimiters<::std::pair<T1, T2>, wchar_t>::values = { L"(", L", ", L")" };

} // namespace pretty_print


namespace pretty_print {

    // Functor to print containers. You can use this directly if you want to
    // specify a non-default delimiters type.
    template<typename T, typename TChar = char, typename TCharTraits = ::std::char_traits<TChar>, typename TDelimiters = delimiters<T, TChar>>
    struct container_printer {
        typedef TChar char_type;
        typedef TDelimiters delimiters_type;
        typedef std::basic_ostream<TChar, TCharTraits> &ostream_type;

        explicit container_printer(const T &container) : _container(container) {}

        inline void operator()(ostream_type &stream) const {
            if (delimiters_type::values.prefix != NULL)
                stream << delimiters_type::values.prefix;

            auto beg = _container.begin(), end = _container.end();
            for (auto it = beg; it != end; ++it) {
                if (it != beg && delimiters_type::values.delimiter != NULL)
                    stream << delimiters_type::values.delimiter;
                stream << *it;
            }

            if (delimiters_type::values.postfix != NULL)
                stream << delimiters_type::values.postfix;
        }

    private:
        const T &_container;
    };

}  // namespace pretty_print


namespace pretty_print {
    /*
     * Recursively print each item of a tuple
     */

    struct tuple_dummy_t {
    }; // Just if you want special delimiters for tuples.

    typedef std::pair<tuple_dummy_t, tuple_dummy_t> tuple_dummy_pair;

    template<typename Tuple, size_t N, typename TChar, typename TCharTraits>
    struct pretty_tuple_helper {
        static inline void
        print(::std::basic_ostream<TChar, TCharTraits> &stream, const Tuple &value) {
            pretty_tuple_helper<Tuple, N - 1, TChar, TCharTraits>::print(stream, value);
            if (delimiters<tuple_dummy_pair, TChar>::values.delimiter != NULL)
                stream << delimiters<tuple_dummy_pair, TChar>::values.delimiter;
            stream << std::get<N - 1>(value);
        }
    };

    template<typename Tuple, typename TChar, typename TCharTraits>
    struct pretty_tuple_helper<Tuple, 1, TChar, TCharTraits> {
        static inline void
        print(::std::basic_ostream<TChar, TCharTraits> &stream, const Tuple &value) {
            stream << ::std::get<0>(value);
        }
    };
} // namespace pretty_print


namespace std {

    // Prints a container_printer to the specified stream.
    template<typename T, typename TChar, typename TCharTraits, typename TDelimiters>
    inline basic_ostream<TChar, TCharTraits> &
    operator<<(basic_ostream<TChar, TCharTraits> &stream,
               const ::pretty_print::container_printer<T, TChar, TCharTraits, TDelimiters> &helper) {
        helper(stream);
        return stream;
    }

    // Prints a container to the stream using default delimiters
    template<typename T, typename TChar, typename TCharTraits>
    inline typename enable_if<::pretty_print::is_container<T>::value, basic_ostream<TChar, TCharTraits> &>::type
    operator<<(basic_ostream<TChar, TCharTraits> &stream, const T &container) {
        return stream << ::pretty_print::container_printer<T, TChar, TCharTraits>(container);
    }

    // Prints a pair to the stream using delimiters from
    // delimiters<std::pair<T1, T2>>.
    template<typename T1, typename T2, typename TChar, typename TCharTraits>
    inline basic_ostream<TChar, TCharTraits> &
    operator<<(basic_ostream<TChar, TCharTraits> &stream,
               const pair<T1, T2> &value) {
        if (::pretty_print::delimiters<pair<T1, T2>, TChar>::values.prefix != NULL)
            stream << ::pretty_print::delimiters<pair<T1, T2>, TChar>::values.prefix;
        stream << value.first;
        if (::pretty_print::delimiters<pair<T1, T2>, TChar>::values.delimiter != NULL)
            stream << ::pretty_print::delimiters<pair<T1, T2>, TChar>::values.delimiter;
        stream << value.second;
        if (::pretty_print::delimiters<pair<T1, T2>, TChar>::values.postfix != NULL)
            stream << ::pretty_print::delimiters<pair<T1, T2>, TChar>::values.postfix;
        return stream;
    }

    // Prints a tuple to the stream using delimiters from
    // delimiters<std::pair<tuple_dummy_t, tuple_dummy_t>>.
    template<typename TChar, typename TCharTraits, typename ...Args>
    inline basic_ostream<TChar, TCharTraits> &
    operator<<(basic_ostream<TChar, TCharTraits> &stream, const tuple<Args...> &value) {
        if (::pretty_print::delimiters<::pretty_print::tuple_dummy_pair, TChar>::values.prefix != NULL)
            stream << ::pretty_print::delimiters<::pretty_print::tuple_dummy_pair, TChar>::values.prefix;
        ::pretty_print::pretty_tuple_helper<const tuple<Args...> &, sizeof...(Args), TChar, TCharTraits>::print(stream, value);
        if (::pretty_print::delimiters<::pretty_print::tuple_dummy_pair, TChar>::values.postfix != NULL)
            stream << ::pretty_print::delimiters<::pretty_print::tuple_dummy_pair, TChar>::values.postfix;
        return stream;
    }
} // namespace std


namespace pretty_print {
    /*
     * Custom delimiter wrapper
     */

    // Type-erasing helper class for easy use of custom delimiters.
    //
    // Requires TCharTraits = std::char_traits<TChar> and
    // TChar = char or wchar_t, and MyDelims needs to be defined for TChar.
    //
    // Usage: "cout << pretty_print::custom_delims<MyDelims>(x)".
    struct custom_delimiter_base {
        virtual ~custom_delimiter_base() = default;

        virtual ::std::ostream &stream(::std::ostream &) = 0;

        virtual ::std::wostream &stream(::std::wostream &) = 0;
    };

    template<typename T, typename Delims>
    struct custom_delimiter_wrapper : public custom_delimiter_base {
        explicit custom_delimiter_wrapper(const T &t) : t(t) {}

        ::std::ostream &stream(::std::ostream &stream) override {
            return stream << ::pretty_print::container_printer<T, char, ::std::char_traits<char>, Delims>(t);
        }

        ::std::wostream &stream(::std::wostream &stream) override {
            return stream << ::pretty_print::container_printer<T, wchar_t, ::std::char_traits<wchar_t>, Delims>(t);
        }

    private:
        const T &t;
    };

    template<typename Delims>
    struct custom_delims {
        template<typename Container>
        explicit custom_delims(const Container &c) : base(
                std::make_shared<custom_delimiter_wrapper<Container, Delims>>(c)) {}
        std::shared_ptr<custom_delimiter_base> base;
    };

} // namespace pretty_print


template<typename TChar, typename TCharTraits, typename Delims>
inline std::basic_ostream<TChar, TCharTraits> &
operator<<(std::basic_ostream<TChar, TCharTraits> &stream,
           const pretty_print::custom_delims<Delims> &p) {
    return p.base->stream(stream);
}


namespace pretty_print {

    // A wrapper for raw C-style arrays.
    //
    // Usage:
    // ```
    // int arr[] = { 1, 2, 4, 8, 16 };
    // std::cout << wrap_array(arr) << ...
    // ```
    template<typename T, size_t N>
    struct array_wrapper {
        typedef const T *const_iterator;
        typedef T value_type;

        explicit array_wrapper(const T (&a)[N]) : _array(a) {}

        inline const_iterator begin() const { return _array; }

        inline const_iterator end() const { return _array + N; }

    private:
        const T *const _array;
    };
} // namespace pretty_print


template<typename T, size_t N>
inline pretty_print::array_wrapper<T, N> pretty_print_array(const T (&a)[N]) {
    return pretty_print::array_wrapper<T, N>(a);
}


#endif //ALGORITHM_DOJO_PRETTY_PRINT_H

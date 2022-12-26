#include <iostream>

template<typename fIt>
int distance_(fIt begin, fIt end) {
    int result = 0;
    while (begin != end) {
        begin++;
        result++;
    }
    
    return result;
}

template<typename fIt>
fIt advance_(fIt begin, int step) {
    for (int i = 0; i < step; ++i) {
        begin++;
    }
    return begin;
}

template<typename fIt, typename T>
fIt lower_bound_(fIt begin, fIt end, const T& val) {
    fIt it;
    int count = 0;
    int step = 0;
    count = distance_(begin, end);
 
    while (count > 0) {
        it = begin; 
        step = count / 2; 
        advance_(it, step);
 
        if (*it < val) {
            begin = ++it; 
            count -= step + 1; 
        }
        else
            count = step;
    }
 
    return begin;
}

template<typename fIt, typename T>
fIt upper_bound_(fIt begin, fIt end, const T& val) {
    fIt it;

    int count = 0;
    int step = 0;

    count = distance_(begin, end);
 
    while (count > 0) {
        it = begin; 
        step = count / 2; 
        advance_(it, step);
 
        if (val >= *it) {
            begin = ++it;
            count -= step + 1;
        } 
        else
            count = step;
    }
 
    return begin;
}

template<typename fIt, typename T>
bool binary_search_(fIt begin, fIt end, const T& val) {
    begin = lower_bound_(begin, end, val);
    return (!(begin == end) && !(val < *begin));
}

template<typename fIt, typename T>
std::pair<fIt, fIt> 
    equal_range_(fIt begin, fIt end, const T& val) {
    return std::make_pair(lower_bound_(begin, end, val),
                          upper_bound_(begin, end, val));
}

template<typename InIt1, typename InIt2, typename OutIt>
OutIt merge_(InIt1 begin1, InIt1 end1,
               InIt2 begin2, InIt2 end2,
               OutIt d_begin) {
    while (begin1 != end1) {
        if (begin2 == end2) {
            return std::copy(begin1, end1, d_begin);
        }
        if (*begin2 < *begin1) {
            ++begin2;
            *d_begin = *begin2;
        } else {
            ++begin1;
            *d_begin = *begin1;
            
        }
        ++d_begin;
    }
    return std::copy(begin2, end2, d_begin);
}

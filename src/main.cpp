#include <boost/concept_check.hpp>
#include <type_traits>

#include <vector>
#include <list>

template <typename T>
struct MyRandomAccesIteratorConcept
{
public:
  using value_type = typename std::iterator_traits<T>::value_type ;
  using difference_type = typename std::iterator_traits<T>::difference_type;
  using reference = typename std::iterator_traits<T>::reference;

  BOOST_CONCEPT_USAGE(MyRandomAccesIteratorConcept)
  {
    i++;
    ++i;
    i--;
    --i;
    
    r += n;           
    r = r -= n;
    
    a = a + n;
    a = n + a;
    b = i - n;
    
    n = b - a;
    
    auto tmp = * (i + n);
    std::is_same<decltype(i[n]), decltype(tmp)>();
    *i;
    *i++;
    *++i;
    *i--;
    *--i;
    
    a == b;
    a != b;
    a < b;    
    a > b;    
    a >= b;    
    a <= b;
    
  }

private:
  T i, a, b{a}; // default/copy/Constructible, copy-assignable
  T& r{i};
  difference_type n;
  value_type v;
};

template <class IT>
void testMyRandomAccesIteratorConcept(IT /* it */){  
  BOOST_CONCEPT_ASSERT((MyRandomAccesIteratorConcept<IT>));
}

int main() {
  
  testMyRandomAccesIteratorConcept(std::vector<int>::iterator());
//  testMyRandomAccesIteratorConcept(std::list<int>::iterator());
  return 0;
}
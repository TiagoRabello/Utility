namespace Concept
{
  template< typename A, typename... Bs > struct All;
  
  namespace Detail
  {
    template< bool A, typename... Bs > struct AllImpl;

    template< typename... Bs > struct AllImpl< true , Bs... > : All< Bs... >    { };
    template<                > struct AllImpl< true         > : std::true_type  { };
    template< typename... Bs > struct AllImpl< false, Bs... > : std::false_type { };

    // Dummy type used for Requires definition.
    enum class Enabler{ };
  }
  
  template< typename A, typename... Bs > struct All : Detail::AllImpl< A::value, Bs... > { };
  
  template< typename A > struct Not : std::integral_constant< bool, !A::value > { };
}

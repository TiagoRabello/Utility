namespace Concept
{
  template< typename A, typename... Bs > struct All;
  template< typename A, typename... Bs > struct Any;
  
  namespace Detail
  {
    template< bool A, typename... Bs > struct AllImpl;

    template< typename... Bs > struct AllImpl< true , Bs... > : All< Bs... >    { };
    template<                > struct AllImpl< true         > : std::true_type  { };
    template< typename... Bs > struct AllImpl< false, Bs... > : std::false_type { };

    template< bool A, typename... Bs > struct AnyImpl;

    template< typename... Bs > struct AnyImpl< false, Bs... > : Any< Bs... >    { };
    template<                > struct AnyImpl< false        > : std::false_type { };
    template< typename... Bs > struct AnyImpl< true , Bs... > : std::true_type  { };
    
    // Dummy type used for Requires definition.
    enum class Enabler{ };
  }
  
  template< typename A, typename... Bs > struct All : Detail::AllImpl< A::value, Bs... > { };
  template< typename A, typename... Bs > struct Any : Detail::AnyImpl< A::value, Bs... > { };
  
  template< typename A > struct Not : std::integral_constant< bool, !A::value > { };
}

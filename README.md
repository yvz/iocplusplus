# ioc++

A tiny IoC container with C++03 support.


### Overview

The ioc++ library provides tooling support to bring the prominent [IoC/DI practices](http://martinfowler.com/articles/injection.html) into C++ projects. It is truly simple and lightweight, and it fits even legacy C++03 code bases.

Key features of ioc++ are:
* Header-only library based on Boost.Bind and Boost.MPL
* Constructor injection DI approach
* Supports singleton and transient object lifestyles
* Objects are wired with smart pointers

### Quick Start

Consider a program that has two classes: OrderProcessor and OrderRepository. Assume there will be multiple instances of OrderProcessor making use of a single instance of OrderRepository. In other words, OrderRepository is a singleton, while OrderProcessor instances are created e.g. per each external request. 

```c++
class OrderRepository
{
};

class OrderProcessor
{
public:
    OrderProcessor(boost::shared_ptr<OrderRepository>& orderRepository) {}
};
```

Manual creation of the objects would be too painful in such system, so we'll take advantage of IoC container.

Usage of ioc++ starts with putting its sources on compiler's include path, along with Boost library. The key include file container.hpp should be added into the relevant locations.

Next, the type registration takes place. In ioc++, the elementary unit of registration is descriptor. One defines descriptor by specializing the template ioc::descriptor_t with type's name, lifestyle and possibly several dependency descriptors:

```c++
typedef ioc::descriptor_t< 
    OrderRepository,		// Type to construct
    ioc::singleton_t		// Unique instance
> _OrderRepository;

typedef ioc::descriptor_t< 
    OrderProcessor,		// Type to construct
    ioc::transient_t,		// New instance per each type resolution
    _OrderRepository		// Type depends on OrderRepository, so reference its descriptor
> _OrderProcessor;

```

Descriptors are registered in container instance using method ioc::container::registerType<desc>();

```c++
ioc::container container;
container.registerType<_OrderProcessor>();
```

Finally, the registered types can be resolved with ioc::container::resolve<T>() method. 

```c++
boost::shared_ptr<OrderProcessor> orderProcessor = container.resolve<OrderProcessor>();
```

### Motivation and History

This edition of ioc++ library is a personal fork, made from original location on Google Code: [link](http://code.google.com/p/iocplusplus/). 

I've become a user of ioc++ some time ago while working on a C++ project with decent amount of business logic, which could have benefited from a fine-grained object oriented design. The library didn't fit some of my scenarios out of the box, thus paving the way for the first patch. As the time passed, I've made some more improvements and simplifications over the original ioc++. 

Eventually it has become beneficial to frame this custom edition in order to settle down the random patches and provide ground for further improvements.
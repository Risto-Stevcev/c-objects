Object-Oriented Programming in C
================================

This repository provides an introduction to object-oriented programming in C. It shows two implementations that I have found on the Internet, Phil's way and Axel's way. Finally, I provide my own final implementation of object-oriented programming (and even memory management) that I think satisfies most of what you would want from objects in C in a clean way.


Implementation 1: Phil's way<sup>1</sup>
----------------------------------------

Phil's way provides a simple way to do object-oriented programming in C. It can be found in the **Phil/** folder of the repository. 

One thing I like that Phil does but Axel doesn't do, is that he uses ``struct``s to define the core of his object. To me, a ``struct`` describes an object much better than anything else does. However, his implementation is lacking in something I find absolutely crucial to object-oriented programming: ``methods``. In addition, his way also doesn't provide an example of how you would do more advanced tricks such as ``polymorphism`` or ``inheritance``. And probably most importantly, there is no example of how you might manage the memory of a more complex object. The good aspects of his implementation is that it's *simple* and easy to grasp as a primer to Axel's and my own implementation. He also provides a ``setter``, but unfortunately it's implemented as a ``function`` rather than a ``method``.


Implementation 2: Axel's way<sup>2</sup>
----------------------------------------

Axel's implementation in his book is actually *quite* clean and decent. It's definitely worth reading his book on object-oriented design in ANSI-C. However, I have found his implementation to be lacking in some features I really wanted in an object. It can be found in the **Axel/** folder of the repository.

Axel's interfaces are quite nice. His implementation looks cleaner than Phil's. However, there are some real disappointments to the implementation. The first thing that I think Axel did wrong that Phil did right, was that Axel didn't use ``struct``s to define the core of the object. He also didn't use ``typedef``s. Finally, in Axel's Bag implementation (an implementation of a Set that has a reference count), he shows how one would ``malloc`` and ``free`` items in the object. However, his form of memory management is clumsy, because all of the ``delete``s have to be made by the user of the object, almost making the implementation useless. And finally, like Phil, Axel's way uses ``function``s rather than ``method``s, which isn't very clean. 


Implementation 3: My way
------------------------

I think I have found a way to solve the issues from the previous implementations in a clean way. It does several things that the previous implementations don't do. 

1. It uses ``struct``s as the core of the object.  
2. It provides ``method``s rather than ``function``s.  
3. It looks pretty much like a Python object that has C++'s ``delete`` call to manage memory in a very simple way.  
4. It provides an example of complex memory managment.  
5. It provides an example of ``polymorphism`` and ``inheritance``.  
6. Towards the end, I'll describe how you can create more advanced object-oriented techniques, such as ``getter``s and ``setter``s.  

The following sections give an overview of my method of object-oriented programming in C.


A Simple String
---------------

The folder **Risto/String/** provides the basics of my implementation of an object. ``mystring.h`` provides the interface for the object, which is implemented in ``mystring.c``.

``mystring.h`` has several important features to keep in mind. Like promised, it uses a ``struct`` to define the core of the object. It also uses a ``typedef`` to define the struct as a ``String`` type, to make it clearer in its implementation that it looks and feels like a real object. Within the ``struct``, there are several attributes defined for the object, such as ``name``, ``bye``, and ``length``. In ``mystring.c``, you can see that these are accessed as ``self->name`` and ``self->bye``, and in ``main.c``, ``length`` is accessed as ``str->length``. As you can see, these are basically identical to writing ``self.name``, ``self.bye`` and ``string.length`` in Python.

What's also neat about this implementation, is that it actually has ``method``s rather than ``function``s, and they again look basically identical to Python's ``method``s. In ``mystring.h``, the function pointers ``say_hi``, ``say_bye`` and ``del`` are actually ``method``s. When ``initString`` is implemented, it sets these function pointers to their corresponding implementations, and then they can be called like regular methods are called. The implementations of these methods all call the instance of the object itself as its first argument, very much like Python's ``self`` when referring to methods. The ``self`` in this case is practially identical -- it's used to set or get attributes within that object instance. In ``main.c``, ``str->say_hi(str)`` is roughly equivalent to Python's ``str.say_hi()``, which implicitly has the ``self`` method inside. 

The ``initString`` function is the only non-``method`` portion of the object, for a good reason. The first four lines of it's implementation in ``mystring.c`` is the basic component of the object creation. It allocates the ``String`` in memory and it binds all of its function pointers to actual function implementations. The last five lines before the ``return`` act basically just like Python's ``__init__`` method, which is binding all of the ``self`` values of the ``String`` based on the arguments passed. The new object is then returned so that it can be used. At least part of its implementation *has to be* a function *because it's returning the object instance* where all method calls are. 

We could separate ``initString`` so that the first portion of its code creates the new object, and then we can provide a ``method`` called ``init`` that will initialize the object. However, there is a downside to this pattern. The pattern would require two lines to create and initialize the object, which is different from how object-oriented languages do this. It would end up being something like: ``String *str = newString(); str->init(str, name);`` in ``main.c``. There's nothing wrong with doing this, and this is just a small design decision. You can do it this way if you like. In some ways it's closer to the Python implementation, where the ``init`` method gets ``self`` that it can use to populate values among other arguments, much like Python's ``__init__``, and ``newString`` in this case would be closer to Python's ``__new__`` method. I'll leave that up to you to decide on.

The ``del`` method is something like a hybrid between Python's ``__del__`` method and C++'s ``delete`` call. Unlike the previous implementations, memory is managed elegantly in my solution. You might not want to *ever* use ``C++`` again after you read this implementation and description! The ``del`` method first ``free``s the memory allocated from other ``malloc``s, in this case the ``bye`` attribute, which was intentionally ``malloc``'d to show how this works. It ``free``s ``bye`` very simply by keeping it in ``del`` and just typing ``free(self->bye);``. Then the object is deleted using ``free(self);``. This makes memory management **very easy** in C! and now you have something that very much resembles C++, with all of the elegance and beauty of C! It looks like Linus Torvalds was right, you just don't need C++<sup>3</sup>.


Polymorphism and Inheritance
----------------------------

Polymorphism and inheritance work well with this implementation. This implementation uses the power of interfaces to describe an inheritance relationship, in this case with the ``Animal`` class. It's a clean way of doing inheritance that prevents multiple inheritance (*which is good*) and follows the *Interfaces Over Inheritance* argument. This fairly thorough example can be found under **Risto/Polymorphism/**.

The ``animal.h`` interface looks very much like the previous ``mystring.h`` interface, with a few important differences. An ``enum`` type called ``animal_type`` is defined so that internal ``method``s and users of the object can perform type-specific operations (for ``Dog``, ``Cat`` or ``Duck`` object types). The ``AnimalFunctions`` ``struct`` type provides a way to do inheritance. The ``Dog``, ``Cat`` and ``Duck`` subtypes inherit the ``says`` function type to provide their own implementations of ``dog_says``, ``cat_says`` and ``duck_says``. 

This is how polymorphism works with this implementation. When ``says`` is called by the user of the object, it calls the type-specific function that was bound to the ``says`` method when that object's initializer was called to create the object. In the case of ``dogInit``, it calls ``dog_says``, because in the implementation ``DogFunctions``--which overrides ``AnimalFunctions`` to provide extra methods if desired--calls ``dog_says`` specifically for that function call.   

Another important difference in ``animal.h`` is that, in addition to attributes shared by all types, such as ``name``, there is another special type called ``data``, which holds type-specific data. For example, ``DogData`` is defined in ``dog.h`` to provide an extra attribute that isn't shared among the other objects inheriting ``Animal``, which is called ``breed``. Similarly, ``CatData`` provides an additional ``bool`` (*boolean*) attribute called ``is_friendly``, and ``DuckData`` has an additional ``int`` type called ``number_of_feathers``.

As mentioned earlier, just like the data attributes, extra functions can be added to each type as part of extending the type to provide inheritance. ``DogFunctions``, which overrides ``AnimalFunctions``, provides the necessary ``says`` function, but with an additional function called ``guards``. Similarly, ``CatFunctions`` has an additional function called ``eats_mice``, and ``DuckFunctions`` has an additional function called ``are_smart``. 

These techniques provide a way to both extend a class and provide additional functionality (inheritance), and to call different functions for the same call, ``says``, based on the type of object created (polymorphism). ``main.c`` brings it all together to provide a detailed example of how both work when the objects are created.

Finally, type-specific operations can be defined using the ``type`` attribute. Suppose we added another attribute to ``DogData`` called ``owner_info``:

    /* dog.h */
    typedef struct
    owner_info_t
    {
        char *owner_name;
        int years_owned;
    } OwnerInfo;
    
    typedef struct
    dog_data_t
    {
        char *breed;
        OwnerInfo *owner_info;
    } DogData;
    ...
    
    
    /* animal.h */
    ...
    Animal *initDog(char *, char *, char *, int);
    ...
    
    
    /* dog.c */
    ...
    Animal *
    initDog (char *name, char *breed, char *owner_name, int years_owned)
    {
        ...
        OwnerInfo *owner_info = (OwnerInfo *) malloc(sizeof(OwnerInfo));
        owner_info->owner_name = owner_name;
        owner_info->years_owned = years_owned;
        dog_data->owner_info = owner_info;
        ...
    }

We can then elegantly deal with the ``malloc``'d ``struct`` in the ``del`` method by checking the object's type:

    /* animal.c */
    ...
    #import "dog.h"
    ...
    void
    del (void *animal)
    {
        Animal *self = (Animal *) animal;
        if (self->type == DOG)
            free(((DogData *) self->data)->owner_info);
        free(self->data);
        free(self);
    }

That's it! if the object subtype is ``Dog``, then the ``owner_info`` memory is ``free``d. Memory management made simple!

Setters and Getters
-------------------

Previously, ``setter``s and ``getter``s are not in the examples provided, but the implementation of this common programming paradigm is very simple. This section describes a way to get ``getter``s and ``setter``s that work very much like the way Python does it. In this quick tutorial, we'll change the ``String`` object example under the **Risto/String/** folder in the repository so that the ``name`` attribute is accessed using a ``getter`` and ``setter``.

The first step is to change the ``char *name`` attribute to ``char *_name`` in the ``String`` definition under ``mystring.h``, much like you would in Python. Then update the ``say_hi`` implementation to point to ``self->_name``, and ``initString`` to populate references of ``str->name`` to ``str->_name`` instead, under ``mystring.c``. 

The next step is to create the ``getter`` and ``setter``. Create two new function pointers in the ``String`` definition under ``mystring.h`` called ``char *(*name) ()`` and ``void (*set_name) ()``. Add the lines ``char *get_name(String *)`` and ``void set_name(String *, char *)`` to ``mystring.h`` so that their implementation is required. 

Next, we'll implement the functions in ``mystring.c``. For the ``getter``, type:

    char *
    get_name (String *self)
    {
        return self->_name;
    }

Which, again, is much like you would in Python. Then, for the ``setter``, type:

    void
    set_name (String *self, char *name)
    {
        self->_name = name;
    }

Which, once again, is much like you would in Python. Finally, add the new function pointers ``str->name = get_name;`` and ``str->set_name = set_name;`` to the ``initString`` implementation.

Now in ``main.c``, you can get the ``name`` attribute using ``str->name()``, and set the ``name`` attribute using, for example, ``str->set_name("hello")``! 


Conclusion
----------

I hope this was useful and inspiring to read and try. Hopefully it will open new doors for you with C programming that weren't there before. C is a beautiful language, but many people loose interest in programming in it for three main reasons:

1. C strings are a pain to use.  
2. Memory management is a pain to deal with.  
3. There are no objects.  

This tutorial solves all of these. C strings are pain to use because for any useful string manipulation using the ``string.h`` library, memory often needs to be allocated and then later freed. By encapsulating the code within an object, you can cleanly use the ``del`` ``method`` to free everything that was initialized by the object, which elegantly deals with any kind of memory management you might need. Now memory management is simplified, there's a simple way to use objects, and you still have inheritance and polymorphism!

<hr>
  <sup>1</sup> [Phil's guide](http://www.bolthole.com/OO-C-programming.html) provides an implementation he learned in Programming 101. Unfortunately, there are many limitations to his implementation.

  <sup>2</sup> [Object-Oriented Programming With ANSI-C](http://www.cs.rit.edu/~ats/books/ooc.pdf) by Axel Schreiner provides some pretty decent implementations of objects in C. However, there were still unsatisfactory aspects to its implementation. Nevertheless, I think the book is definitely worth the read and it covers many topics that I didn't.

  <sup>3</sup> Linus Torvalds, the creator of Linux, is famously known for bashing C++ in a [newsgroup post](http://article.gmane.org/gmane.comp.version-control.git/57918) in 2007.

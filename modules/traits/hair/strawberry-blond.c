//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "strawberry blond hair");
        addSpecification("description", "Your hair is blond with a rich, warm red tone.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }
}


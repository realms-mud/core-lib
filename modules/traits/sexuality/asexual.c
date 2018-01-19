//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "asexual");
        addSpecification("description", "You lack sexual attraction to others and have no desire for such activities.");
        addSpecification("root", "sexual identity");
        "baseTrait"::reset(arg);
    }
}


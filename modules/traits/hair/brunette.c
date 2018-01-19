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
        addSpecification("name", "brunette hair");
        addSpecification("description", "Your hair is a deep brown with a subtle cool hue.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }
}


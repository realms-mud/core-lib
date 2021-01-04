//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "burgundy hair");
        addSpecification("description", "Your hair is a deep, dark, very warm red-brown.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }
}


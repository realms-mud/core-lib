//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "caramel brown hair");
        addSpecification("description", "Your hair is warm mid-tone brown with golden hues.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }
}


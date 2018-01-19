//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "steel gray hair");
        addSpecification("description", "Your hair is a shiny gray with very cool, almost blue hue.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }
}


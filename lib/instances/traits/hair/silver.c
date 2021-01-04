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
        addSpecification("name", "silver hair");
        addSpecification("description", "Your hair is a lusterous gray with very cool, almost blue hue.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }
}


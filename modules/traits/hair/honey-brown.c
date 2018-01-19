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
        addSpecification("name", "honey brown hair");
        addSpecification("description", "Your hair is golden to light brown with a warm hue.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }
}


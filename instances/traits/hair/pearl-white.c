//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "pearl white hair");
        addSpecification("description", "Your hair is a lusterous white with a faint bluish sheen.");
        addSpecification("root", "hair");
        "baseTrait"::reset(arg);
    }
}


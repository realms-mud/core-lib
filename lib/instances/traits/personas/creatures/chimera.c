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
        addSpecification("type", "persona");
        addSpecification("name", "chimera");
        addSpecification("description", "You are a chimera.");
        addSpecification("root", "large creature persona");
        addSpecification("bonus resist physical", 15);
        "baseTrait"::reset(arg);
    }
}

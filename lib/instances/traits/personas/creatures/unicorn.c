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
        addSpecification("name", "unicorn");
        addSpecification("description", "You are a unicorn.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist physical", 100);
        addSpecification("bonus resist good", 100);
        addSpecification("bonus resist magical", 50);
        "baseTrait"::reset(arg);
    }
}

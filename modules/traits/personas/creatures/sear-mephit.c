//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "persona");
        addSpecification("name", "sear mephit");
        addSpecification("description", "You are a sear mephit.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist acid", 25);
        addSpecification("bonus resist physical", 20);
        "baseTrait"::reset(arg);
    }
}

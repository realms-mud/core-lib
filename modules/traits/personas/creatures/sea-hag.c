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
        addSpecification("name", "sea hag");
        addSpecification("description", "You are a sea hag.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist disease", 25);
        "baseTrait"::reset(arg);
    }
}

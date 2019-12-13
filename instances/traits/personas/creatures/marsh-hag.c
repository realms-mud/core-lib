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
        addSpecification("name", "marsh hag");
        addSpecification("description", "You are a marsh hag.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist disease", 25);
        "baseTrait"::reset(arg);
    }
}

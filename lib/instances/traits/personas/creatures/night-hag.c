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
        addSpecification("type", "persona");
        addSpecification("name", "night hag");
        addSpecification("description", "You are a night hag.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist disease", 25);
        "baseTrait"::reset(arg);
    }
}

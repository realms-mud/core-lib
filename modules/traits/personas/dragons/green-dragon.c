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
        addSpecification("name", "green dragon");
        addSpecification("description", "You are a green dragon.");
        addSpecification("root", "creature persona");
        addSpecification("bonus resist fire", 75);
        addSpecification("bonus resist poison", 75);
        "baseTrait"::reset(arg);
    }
}

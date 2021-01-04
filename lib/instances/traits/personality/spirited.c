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
        addSpecification("type", "personality");
        addSpecification("name", "spirited");
        addSpecification("description", "You are full of energy, entusiasm, "
            "and determination.");
        addSpecification("root", "passionate");
        addSpecification("opinion", 5);
        addSpecification("bonus persuasion", 1);
        "baseTrait"::reset(arg);
    }
}

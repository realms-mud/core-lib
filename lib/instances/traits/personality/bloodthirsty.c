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
        addSpecification("type", "personality");
        addSpecification("name", "bloodthirsty");
        addSpecification("description", "You have a rather savage demeanor and are "
            "apt to resolve personal issues through violence.");
        addSpecification("root", "brutal");
        addSpecification("opinion", -5);
        addSpecification("penalty to persuasion", 1);
        addSpecification("bonus intimidation", 1);
        "baseTrait"::reset(arg);
    }
}

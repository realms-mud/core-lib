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
        addSpecification("name", "reckless");
        addSpecification("description", "You're prone to react to situations "
            "without thinking through or caring about the consequences.");
        addSpecification("root", "reckless");
        addSpecification("opinion", -5);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        "baseTrait"::reset(arg);
    }
}

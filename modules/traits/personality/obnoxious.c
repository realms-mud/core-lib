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
        addSpecification("type", "personality");
        addSpecification("name", "obnoxious");
        addSpecification("description", "To say that you're annoying is unfair "
            "to annoying people. To say that you've been mercilessly spared "
            "from the ravages of tact and grace would be closer to the mark.");
        addSpecification("root", "annoying");
        addSpecification("opinion", -10);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("penalty to etiquette", 1);
        "baseTrait"::reset(arg);
    }
}

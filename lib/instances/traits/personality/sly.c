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
        addSpecification("name", "sly");
        addSpecification("description", "You are extremely cunning, but "
            "tend to use this cleverness in a deceitful manner.");
        addSpecification("root", "dishonorable");
        addSpecification("opposing root", "honorable");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -10);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("bonus bluff", 2);
        "baseTrait"::reset(arg);
    }
}

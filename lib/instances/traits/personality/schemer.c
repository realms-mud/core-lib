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
        addSpecification("name", "schemer");
        addSpecification("description", "You are extremely cunning (at least "
            "in your mind) and are always plotting and maneuvering others "
            "to fulfill your goals.");
        addSpecification("root", "dishonorable");
        addSpecification("opposing root", "honorable");
        addSpecification("opinion", -11);
        addSpecification("opposing opinion", -10);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("bonus bluff", 1);
        "baseTrait"::reset(arg);
    }
}

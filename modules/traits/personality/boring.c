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
        addSpecification("name", "boring");
        addSpecification("description", "Simply put, you're a rather tedious, "
            "uninteresting person to be around.");
        addSpecification("root", "boring");
        addSpecification("opposing root", "interesting");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -10);
        addSpecification("penalty to persuasion", 1);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("penalty to intimidation", 1);
        addSpecification("penalty to bluff", 1);
        "baseTrait"::reset(arg);
    }
}

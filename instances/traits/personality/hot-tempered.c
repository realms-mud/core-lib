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
        addSpecification("name", "hot-tempered");
        addSpecification("description", "You have a tendency to anger rather "
            "quickly and a less-than constructive manner with which you "
            "express said anger.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -5);
        addSpecification("penalty to diplomacy", 1);
        addSpecification("bonus intimidation", 1);
        addSpecification("penalty to etiquette", 1);
        "baseTrait"::reset(arg);
    }
}

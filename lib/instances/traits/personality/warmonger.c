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
        addSpecification("name", "warmonger");
        addSpecification("description", "You tend to calculate all actions "
            "as potential conflict. You embrace this aggression behavior "
            "and are very quick to beat the drums of war when anyone "
            "disagrees with you.");
        addSpecification("root", "cruel");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        addSpecification("bonus intimidation", 1);
        "baseTrait"::reset(arg);
    }
}

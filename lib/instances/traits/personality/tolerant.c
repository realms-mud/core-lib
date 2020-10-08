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
        addSpecification("name", "tolerant");
        addSpecification("description", "The world is peopled with those of "
            "great diversity. Their differences are their strengths. All "
            "people should be treated with kindness and respect.");
        addSpecification("root", "humble");
        addSpecification("opposing root", "arrogant");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", 5);
        addSpecification("bonus diplomacy", 2);
        "baseTrait"::reset(arg);
    }
}

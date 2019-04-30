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
        addSpecification("name", "ill-tempered");
        addSpecification("description", "You have a tendency to anger rather "
            "quickly and a malicious, cruel, and vindictive manner with which you "
            "express said anger.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -10);
        addSpecification("opposing opinion", -15);
        "baseTrait"::reset(arg);
    }
}

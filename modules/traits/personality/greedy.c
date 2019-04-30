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
        addSpecification("name", "greedy");
        addSpecification("description", "You like things. Yours, theirs... What you need is more.");
        addSpecification("root", "dishonorable");
        addSpecification("opposing root", "honorable");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -15);
        "baseTrait"::reset(arg);
    }
}

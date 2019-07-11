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
        addSpecification("name", "lecherous");
        addSpecification("description", "You tend to express your sexual "
            "desires in the most offensive manner possible.");
        addSpecification("root", "hedonist");
        addSpecification("opposing root", "celibate");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -25);
        "baseTrait"::reset(arg);
    }
}

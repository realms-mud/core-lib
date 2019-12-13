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
        addSpecification("name", "loutish");
        addSpecification("description", "You are a rather unrefined and "
            "uncouth lout.");
        addSpecification("root", "crude");
        addSpecification("opposing root", "kind");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -10);
        addSpecification("penalty to etiquette", 1);
        "baseTrait"::reset(arg);
    }
}

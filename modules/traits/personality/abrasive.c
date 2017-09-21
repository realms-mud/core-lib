//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "abrasive");
        addSpecification("description", "You have a knack for getting under the skin of others.");
        addSpecification("root", "jackass");
        addSpecification("opposing root", "nice");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -15);
        addSpecification("cost", -1);
        "baseTrait"::reset(arg);
    }
}


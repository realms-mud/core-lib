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
        addSpecification("name", "abrasive");
        addSpecification("description", "You have a knack for getting under the skin of others.");
        addSpecification("root", "harsh");
        addSpecification("opposing root", "eloquent");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -15);
        addSpecification("penalty to persuasion", 1);
        "baseTrait"::reset(arg);
    }
}

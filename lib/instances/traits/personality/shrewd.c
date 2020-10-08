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
        addSpecification("name", "shrewd");
        addSpecification("description", "You have astute powers of judgement.");
        addSpecification("root", "honorable");
        addSpecification("opposing root", "dishonorable");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        addSpecification("bonus diplomacy", 1);
        addSpecification("bonus persuasion", 1);
        "baseTrait"::reset(arg);
    }
}

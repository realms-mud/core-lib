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
        addSpecification("type", "genetic");
        addSpecification("name", "ugly");
        addSpecification("description", "You are considered a genetic defective. "
            "There are homely people and then there is you. You weren't beaten "
            "with the ugly stick; you are a primordial fragment from the genesis "
            "of ugly; the essence of ugly so pure as to go beyond the physics we know and love.");
        addSpecification("root", "homely");
        addSpecification("opposing root", "beautiful");
        addSpecification("opinion", -25);
        addSpecification("penalty to charisma", 5);
        addSpecification("penalty to persuasion", 5);
        addSpecification("cost", -2);
        "baseTrait"::reset(arg);
    }
}


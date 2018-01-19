//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "genetic");
        addSpecification("name", "attractive");
        addSpecification("description", "You are considered a truly striking person.");
        addSpecification("root", "beautiful");
        addSpecification("opposing root", "homely");
        addSpecification("opinion", 25);
        addSpecification("opposing opinion", -5);
        addSpecification("bonus charisma", 2);
        addSpecification("bonus persuasion", 5);
        addSpecification("cost", 1);
        "baseTrait"::reset(arg);
    }
}


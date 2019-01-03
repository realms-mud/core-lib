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
        addSpecification("name", "just");
        addSpecification("description", "You have a keen sense for what is morally right and fair.");
        addSpecification("root", "honorable");
        addSpecification("opposing root", "dishonorable");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        "baseTrait"::reset(arg);
    }
}


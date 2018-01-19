//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        addSpecification("type", "personality");
        addSpecification("name", "loyal");
        addSpecification("description", "You are steadfast in support of those you choose to support.");
        addSpecification("root", "honorable");
        addSpecification("opposing root", "dishonorable");
        addSpecification("opinion", 10);
        addSpecification("opposing opinion", -10);
        "baseTrait"::reset(arg);
    }
}


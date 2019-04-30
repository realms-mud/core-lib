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
        addSpecification("name", "duplicious");
        addSpecification("description", "You intentionally hide your true "
            "feelings toward others, relying on deceit to sway people.");
        addSpecification("root", "dishonorable");
        addSpecification("opposing root", "honorable");
        addSpecification("opinion", -5);
        addSpecification("opposing opinion", -15);
        "baseTrait"::reset(arg);
    }
}
